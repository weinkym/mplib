#include <QPixmap>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>
#include "zmplibpublic.h"

QPixmap ZMplibPublic::getFullScreen()
{

//    return QPixmap::grabWindow(qApp->desktop()->winId(),rect.x(),rect.y(),rect.width(),rect.height());
    QPixmap result = QPixmap();
    // 获取当前应用关联的所有screen，取得第一个，并进行全屏抓图
    // 如果是双屏或者多屏可能会有问题
    QList<QScreen *> screens = QApplication::screens();
    if(!screens.isEmpty())
    {
        QScreen *screen = screens.first();
        result = screen->grabWindow(QApplication::desktop()->winId());
    }
    return result;
}
