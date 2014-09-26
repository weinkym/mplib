#ifndef MPLIB_GLOBAL_H
#define MPLIB_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QDebug>

#if defined(MPLIB_LIBRARY)
#  define MPLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MPLIBSHARED_EXPORT Q_DECL_IMPORT
//#  define MPLIBSHARED_EXPORT
#endif

#define DEBUG_CURRENT_LINE qDebug()<<QString("<file:%1 line:%2 fun:%3>") \
.arg(__FILE__).arg(__LINE__).arg(__FUNCTION__);

#endif // MPLIB_GLOBAL_H
