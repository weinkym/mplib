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

    //����ͼ��ʹ��QTextCursor API�ĵ���
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
    QTextCharFormat fmt;//�ı��ַ���ʽ
    fmt.setForeground(m_timeTextColor);// ǰ��ɫ(������ɫ)��Ϊcolɫ
    fmt.setFont(m_timeTextFont);
    fmt.setBackground(m_timeTextBackgroundColor);
    QTextCursor cursor = this->textCursor();//��ȡ�ı����
    cursor.mergeCharFormat(fmt);//��������־��øø�ʽ��ʾ
    this->mergeCurrentCharFormat(fmt);//textEditʹ�õ�ǰ���ַ���ʽ
    append(QDateTime::currentDateTime().toString("yyyy-M-d h:m:s"));

    fmt.setForeground(m_textColor);// ǰ��ɫ(������ɫ)��Ϊcolɫ
    fmt.setFont(m_textFont);
    fmt.setBackground(m_textBackgroundColor);
    this->mergeCurrentCharFormat(fmt);//textEditʹ�õ�ǰ���ַ���ʽ
}

