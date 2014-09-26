#include <QRegExp>
#include "ztextcodec.h"

void ZTextCodec::init(const QString& codecName)
{
    Q_UNUSED(codecName);
    QTextCodec* tc = NULL;
#if defined(WIN32)
    tc = QTextCodec::codecForLocale();
#elif defined(Q_OS_SOLARIS)
    tc = QTextCodec::codecForName("GB2312");
#else
    tc = QTextCodec::codecForName(codecName.toLocal8Bit());
#endif
    QTextCodec::setCodecForLocale(tc);
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QTextCodec::setCodecForCStrings(tc);
    QTextCodec::setCodecForTr(tc);
#endif
}

/*!
    返回当前系统中所有的字符编码集。
*/
QMap<QString, QTextCodec*> ZTextCodec::findCodecs()
{
    QMap<QString, QTextCodec *> codecMap;
    QRegExp iso8859RegExp("ISO[- ]8859-([0-9]+).*");

    foreach (int mib, QTextCodec::availableMibs()) {
        QTextCodec *codec = QTextCodec::codecForMib(mib);

        QString sortKey = codec->name().toUpper();
        int rank;

        if (sortKey.startsWith("UTF-8")) {
            rank = 1;
        } else if (sortKey.startsWith("UTF-16")) {
            rank = 2;
        } else if (iso8859RegExp.exactMatch(sortKey)) {
            if (iso8859RegExp.cap(1).size() == 1)
                rank = 3;
            else
                rank = 4;
        } else {
            rank = 5;
        }
        sortKey.prepend(QChar('0' + rank));

        codecMap.insert(sortKey, codec);
    }
    return codecMap;
}

