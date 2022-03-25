#include <QApplication>
#include <QPushButton>
#include <QCheckBox>
#include <iostream>
#include "Header.h"

int main(int argc, char **argv)
{
    string text;
    C obj;
    QApplication app (argc, argv);
    QPushButton button;
    QCheckBox box;
    QCheckBox Another_Box;
    Another_Box.setText("check to hide");
    button.setText("My text");
    text="My text";
    box.setText("check to show new changes");
    obj.p= &button;
    obj.box=&box;
    obj.t=&text;
    button.connect(&button,SIGNAL(clicked(bool)),&obj,SLOT(setValue(bool)));
    button.connect(&Another_Box,SIGNAL(isChecked()),&obj,SLOT(whenHidden(bool isChecked())));
    button.show();
    box.show();
    Another_Box.show();
    return app.exec();
}
