#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QObject>
#include "ztextcodec.h"
#include "zrecieveprogressbar.h"
#include "zchatmessagewidget.h"

int main(int argc,char** argv)
{
    QApplication a(argc,argv);
    ZTextCodec codec;
    codec.init();
    ZRecieveProgressBar bar;
//    bar.show();

/*    QString fileName = QFileDialog::getOpenFileName(0, QString("Open File"),
                                                    "/home",
                                                    QString("Images (*.png *.xpm *.jpg)"))*/;
    ZChatMessageWidget dlg;
    dlg.resize(600,400);
    dlg.show();
    dlg.addText("EEEEEEEEEEE");
//    dlg.insertImage(fileName);
    dlg.addText("TTTTTTT");
    dlg.addText("QQQQQQQQQ",true);
    dlg.setTextBackgroundColor(QColor(Qt::yellow));
    dlg.addText("BBBBBBBBBB");
    dlg.addText("TTTTTTT");
    dlg.addText("QQQQQQQQQ",true);
    dlg.setTextBackgroundColor(QColor(Qt::yellow));
    dlg.addText("BBBBBBBBBB");
    return a.exec();
}
