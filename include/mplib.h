#ifndef MPLIB_H
#define MPLIB_H
#include <QColor>
#include <qglobal.h>
#include "mplib_global.h"

class QTextEdit;
void MPLIBSHARED_EXPORT ZMsgHandler(QtMsgType, const char *);
void MPLIBSHARED_EXPORT ZSetMsgHandlerDevice(QTextEdit* textEdit);

namespace Mplib
{
class MPLIBSHARED_EXPORT MpStaticMethod
{
public:
    MpStaticMethod();
    ~MpStaticMethod();
    static QList<int> getListInt(int count,int min,int max);
    static QList<int> getListInt(int min,int max);
    static QString getSizeString(qint64 size,int precn = 6);
    static QColor getCursorPosColor();

#ifdef Q_CC_MSVC
    static QStringList getPrinters();
    static QString getDefaultPrinter();
    static bool setDefaultPrinter(const QString& name);
    //pName:打印机名称 pagesize:纸张规格,8为A3,9为A4,具体见<wingdi.h> width:纸张宽度 height:纸张高度,orientation:0横线,1纵向　copies:打印份数
    //注意:当pagesize <= 0时,参数width、height两个参数才有效
    static bool setPrinterParam(const QString& pName,short pagesize, short width,short height,short orientation,short copies);
#endif
};
}


#endif // MPLIB_H
