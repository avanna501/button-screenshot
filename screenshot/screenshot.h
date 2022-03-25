#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QComboBox>
#include <QPixmap>
#include <QWidget>

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
    void newScreenshot();
    void saveScreenshot();
    void shootScreen();
    void updateCheckBox();

private:
    void updateScreenshotLabel();

    QPixmap originalPixmap, opnew;

    QLabel *screenshotLabel;
    QSpinBox *delaySpinBox;
    QCheckBox *hideThisWindowCheckBox;
    QPushButton *newScreenshotButton;

    QComboBox *ComboBox;
};
//! [0]

#endif // SCREENSHOT_H
