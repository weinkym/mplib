#include <QApplication>
#include "mainwindow.h"
#include "ztextcodec.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZTextCodec codec;
    codec.init();
    MainWindow w;
//    w.show();
//   w.testZWheelWidget();
//    w.testPrinter();
    w.testScreenShot();
//    ZSwitchButton btn;
//    btn.show();
    w.show();

    return a.exec();
}
