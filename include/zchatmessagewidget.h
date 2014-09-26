#ifndef ZCHATMESSAGEWIDGET_H
#define ZCHATMESSAGEWIDGET_H
#include <QTextEdit>
#include "mplib_global.h"

class MPLIBSHARED_EXPORT ZChatMessageWidget : public QTextEdit
{
    Q_OBJECT

public:
    ZChatMessageWidget(QWidget * parent = 0);
    ~ZChatMessageWidget();
    bool insertImage(const QString& fileName);
    void setTimeAddable(bool addable);
    void addText(const QString &text,bool isSend = false);

private:
    void addTimeText();

private:
    bool m_timeAddable;

    QColor m_timeTextBackgroundColor;
    QColor m_timeTextColor;
    QColor m_textBackgroundColor;
    QColor m_textColor;

    QFont m_timeTextFont;
    QFont m_textFont;
};

#endif // ZCHATMESSAGEWIDGET_H
