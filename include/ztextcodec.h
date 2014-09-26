#ifndef _ZTEXTCODEC_H_
#define _ZTEXTCODEC_H_

#include <QTextCodec>
#include <QMap>
#include "mplib_global.h"

class MPLIBSHARED_EXPORT ZTextCodec
{
public:
	static void init(const QString& codecName = "System");

    static QMap<QString, QTextCodec*> findCodecs();
};

#endif
