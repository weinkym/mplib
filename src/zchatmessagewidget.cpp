#include <QTextDocument>
#include <QUrl>
#include <QDateTime>
#include "zchatmessagewidget.h"


ZChatMessageWidget::ZChatMessageWidget(QWidget *parent)
    :QTextEdit(parent)
    ,m_timeAddable(true)
{
    m_timeTextBackgroundColor  = QColor("#EEE5DE");
    m_timeTextColor  = QColor(Qt::blue);
    m_timeTextFont.setPointSize(12);
    m_timeTextFont.setBold(false);

    m_textBackgroundColor  = QColor(Qt::white);
    m_textColor  = QColor("#0A0A0A");
    m_textFont.setPointSize(16);
    m_textFont.setBold(true);
}

ZChatMessageWidget::~ZChatMessageWidget()
{
    //
}

bool ZChatMessageWidget::insertImage(const QString &fileName)
{
    QImage image(fileName);
    if (image.isNull())
    {
        return false;
    }

    int width = this->viewport()->width();
    int height = this->viewport()->height();
    if (image.width() > width || image.height() > height) {
//        image = image.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    QTextCursor cursor = this->textCursor();
//    QTextDocument *document = this->document();
    cursor.movePosition(QTextCursor::End);


//    document->addResource(QTextDocument::ImageResource, QUrl(fileName),  QVariant(image));
//    QUrl url();
//    document->addResource(QTextDocument::ImageResource, QUrl(fileName),  QVariant(image));

    //插入图像，使用QTextCursor API文档：
    QTextImageFormat image_format;
    image_format.setName(fileName);
    cursor.insertImage(image_format);
    return true;
}

void ZChatMessageWidget::setTimeAddable(bool addable)
{
    m_timeAddable = addable;
}

void ZChatMessageWidget::addText(const QString &text, bool isSend)
{
    if(m_timeAddable)
    {
        addTimeText();
        setAlignment(Qt::AlignLeft);
        if(isSend)
        {
            setAlignment(Qt::AlignRight);
        }
    }
    append(text);
    if(!m_timeAddable)
    {
        setAlignment(Qt::AlignLeft);
        if(isSend)
        {
            setAlignment(Qt::AlignRight);
        }
    }
}

void ZChatMessageWidget::addTimeText()
{
    QTextCharFormat fmt;//文本字符格式
    fmt.setForeground(m_timeTextColor);// 前景色(即字体色)设为col色
    fmt.setFont(m_timeTextFont);
    fmt.setBackground(m_timeTextBackgroundColor);
    QTextCursor cursor = this->textCursor();//获取文本光标
    cursor.mergeCharFormat(fmt);//光标后的文字就用该格式显示
    this->mergeCurrentCharFormat(fmt);//textEdit使用当前的字符格式
    append(QDateTime::currentDateTime().toString("yyyy-M-d h:m:s"));

    fmt.setForeground(m_textColor);// 前景色(即字体色)设为col色
    fmt.setFont(m_textFont);
    fmt.setBackground(m_textBackgroundColor);
    this->mergeCurrentCharFormat(fmt);//textEdit使用当前的字符格式
}

