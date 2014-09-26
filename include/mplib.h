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
    //pName:��ӡ������ pagesize:ֽ�Ź��,8ΪA3,9ΪA4,�����<wingdi.h> width:ֽ�ſ�� height:ֽ�Ÿ߶�,orientation:0����,1����copies:��ӡ����
    //ע��:��pagesize <= 0ʱ,����width��height������������Ч
    static bool setPrinterParam(const QString& pName,short pagesize, short width,short height,short orientation,short copies);
#endif
};
}


#endif // MPLIB_H
