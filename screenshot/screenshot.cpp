#include <QtWidgets>
#include <QComboBox>
#include "screenshot.h"
#include <iostream>
using namespace std;
int  i=1;
//! [0]
Screenshot::Screenshot()
    :  screenshotLabel(new QLabel(this))
{
    screenshotLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    screenshotLabel->setAlignment(Qt::AlignCenter);

    const QRect screenGeometry = screen()->geometry();
    screenshotLabel->setMinimumSize(screenGeometry.width() /4 , screenGeometry.height() /4 );

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(screenshotLabel);

    QGroupBox *optionsGroupBox = new QGroupBox(tr("Options"), this);
    delaySpinBox = new QSpinBox(optionsGroupBox);
    delaySpinBox->setSuffix(tr(" s"));
    delaySpinBox->setMaximum(60);
    connect(delaySpinBox, &QSpinBox::valueChanged,
            this, &Screenshot::updateCheckBox);

//
    ComboBox = new QComboBox;
    QStringList list=(QStringList()<<"1"<<"1/2"<<"1/4"<<"1/8");
    ComboBox->addItems(list);
//    connect(ComboBox, QOverload<int>::of(&QComboBox::highlighted),
//        [=](int index){ i=2^index; cout<< i; });


//    connect(ComboBox, SIGNAL(currentIndexChanged(int)), [=](int index)
//        {
//            i=2^index;
//            cout<< i;
//        });

//



    hideThisWindowCheckBox = new QCheckBox(tr("Hide This Window"), optionsGroupBox);

    QGridLayout *optionsGroupBoxLayout = new QGridLayout(optionsGroupBox);
    optionsGroupBoxLayout->addWidget(new QLabel(tr("Screenshot Delay:"), this), 0, 0);
    optionsGroupBoxLayout->addWidget(delaySpinBox, 0, 1);
    optionsGroupBoxLayout->addWidget(new QLabel(tr("Screeshot Size:"), this));
    optionsGroupBoxLayout->addWidget(ComboBox);
    optionsGroupBoxLayout->addWidget(hideThisWindowCheckBox);

    mainLayout->addWidget(optionsGroupBox);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    newScreenshotButton = new QPushButton(tr("New Screenshot"), this);
    connect(newScreenshotButton, &QPushButton::clicked, this, &Screenshot::newScreenshot);
    buttonsLayout->addWidget(newScreenshotButton);

//  connect(ComboBox, QOverload<int>::of(&QComboBox::highlighted),
//          [=](int index) , &QWidget::close);

//            connect(ComboBox, QOverload<int>::of(&QComboBox::highlighted),
//                [=](int index)
//    {
//        i = &index;
//    });

 //   buttonsLayout->addWidget(ComboBox);

    QPushButton *saveScreenshotButton = new QPushButton(tr("Save Screenshot"), this);
    connect(saveScreenshotButton, &QPushButton::clicked, this, &Screenshot::saveScreenshot);
    buttonsLayout->addWidget(saveScreenshotButton);
    QPushButton *quitScreenshotButton = new QPushButton(tr("Quit"), this);
    quitScreenshotButton->setShortcut(Qt::CTRL | Qt::Key_Q);
    connect(quitScreenshotButton, &QPushButton::clicked, this, &QWidget::close);
    buttonsLayout->addWidget(quitScreenshotButton);





    buttonsLayout->addStretch();
    mainLayout->addLayout(buttonsLayout);





    shootScreen();
    delaySpinBox->setValue(5);

    setWindowTitle(tr("Screenshot"));
 //   qDebug() << i;
 //   resize(300, 200);
}
//! [0]

//! [1]
void Screenshot::resizeEvent(QResizeEvent * /* event */)
{
//    if (i=0)
//    {
        QSize scaledSize = originalPixmap.size();

        scaledSize.scale(screenshotLabel->size(), Qt::KeepAspectRatio);
        if (scaledSize != screenshotLabel->pixmap(Qt::ReturnByValue).size())
            updateScreenshotLabel();
//    }

}
//! [1]

//! [2]
void Screenshot::newScreenshot()
{
    if (hideThisWindowCheckBox->isChecked())
        hide();
    newScreenshotButton->setDisabled(true);

    QTimer::singleShot(delaySpinBox->value() * 1000, this, &Screenshot::shootScreen);
}
//! [2]

//! [3]
void Screenshot::saveScreenshot()
{
//    cout<<"ComboBox->currentIndex():"<<
//          ComboBox->currentIndex()<<endl;
    cout<<"ComboBox->currentIndex():"<<
          ComboBox->currentIndex()<<endl;
    i=pow(2,(ComboBox->currentIndex()));
    cout<<"i="<<i<<endl;

    const QString format = "png";
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += tr("/untitled.") + format;

    QFileDialog fileDialog(this, tr("Save As"), initialPath);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory(initialPath);
    QStringList mimeTypes;
    const QList<QByteArray> baMimeTypes = QImageWriter::supportedMimeTypes();
    for (const QByteArray &bf : baMimeTypes)
        mimeTypes.append(QLatin1String(bf));
    fileDialog.setMimeTypeFilters(mimeTypes);
    fileDialog.selectMimeTypeFilter("image/" + format);
    fileDialog.setDefaultSuffix(format);
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fileName = fileDialog.selectedFiles().first();

    opnew =originalPixmap.scaled(int (1366/i),int (768/i),
                                 Qt::KeepAspectRatio);

    if (!opnew.save(fileName)) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(fileName)));
    }
}
//! [3]

//! [4]
void Screenshot::shootScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;

    if (delaySpinBox->value() != 0)
        QApplication::beep();

   originalPixmap = screen->grabWindow(0);

    updateScreenshotLabel();

    newScreenshotButton->setDisabled(false);
    if (hideThisWindowCheckBox->isChecked())
        show();
}
//! [4]

//! [6]
void Screenshot::updateCheckBox()
{
    if (delaySpinBox->value() == 0) {
        hideThisWindowCheckBox->setDisabled(true);
        hideThisWindowCheckBox->setChecked(false);
    } else {
        hideThisWindowCheckBox->setDisabled(false);
    }
}
//! [6]


//! [10]
void Screenshot::updateScreenshotLabel()
{
    screenshotLabel->setPixmap(originalPixmap.scaled(screenshotLabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
}
//! [10]
