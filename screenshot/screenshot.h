#ifndef SCREENSHOT_H
#define SCREENSHOT_H
#include <QComboBox>
#include <QPixmap>
#include <QWidget>
#include <QtCore>
#include <QFuture>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGridLayout;
class QGroupBox;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpinBox;
class QVBoxLayout;
QT_END_NAMESPACE

//! [0]
class Screenshot : public QWidget
{
    Q_OBJECT

public:
    Screenshot();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void SCREENSHOT_();
    void newScreenshot();
    void saveScreenshot();
    void shootScreen();
    void updateCheckBox();
   QPixmap scale(QPixmap);

private:
    void updateScreenshotLabel();

    QPixmap originalPixmap, opnew;
    QFuture<QPixmap>  f;
    QPixmap n;
    QString fileName;
    QLabel *screenshotLabel;
    QSpinBox *delaySpinBox;
    QCheckBox *hideThisWindowCheckBox;
    QPushButton *newScreenshotButton;

    QComboBox *ComboBox;
};
//! [0]

#endif // SCREENSHOT_H
