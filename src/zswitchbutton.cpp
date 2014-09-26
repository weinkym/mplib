#include <QPainter>
#include <QMouseEvent>
#include <QRadialGradient>
#include "zswitchbutton.h"

ZSwitchButton::ZSwitchButton(QWidget *parent)
    : QWidget(parent)
{
    setCursor(QCursor(Qt::PointingHandCursor));
    m_isCheck=false;
}

void ZSwitchButton::onStateChanged()
{
    m_isCheck = !m_isCheck;
    repaint();
    emit sigStateChanged(m_isCheck);
}

void ZSwitchButton::setCheck(bool isCheck)
{
    if (this->m_isCheck!=isCheck)
    {
        onStateChanged();
    }
}

void ZSwitchButton::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.begin(this);
    QColor color = m_isCheck ? QColor("#00FF00") : QColor("#787878");
    QPen pen(Qt::NoPen);
    painter.setPen(pen);
    QBrush brush(color);
    painter.setBrush(brush);
    int h = this->height();
    int w = this->width();
    {
        QRect rect(0,0,h,h);
        painter.drawPie(rect,90*16,180*16);
    }
    {
        QRect rect(w - h,0,h,h);
        painter.drawPie(rect,270*16,180*16);
    }
    {
        QRect rect(h / 2,0,w - h + 1,h);
        painter.drawRect(rect);
    }
    {
        double rate = 0.03;
        double dh = rate*h;
        QRectF rect(dh,dh,h - 2*dh,h - 2 * dh);
        if(m_isCheck)
        {
            QPointF p(w - h / 2,h / 2);
            rect.moveCenter(p);
        }
        QConicalGradient radia(rect.center(),360);
//        radia.setColorAt(0,QColor(175,194,207));
//        radia.setColorAt(1,QColor(255,255,255));
        radia.setColorAt(0,QColor(197,213,223));
        radia.setColorAt(0.25,QColor(255,255,255));
        radia.setColorAt(0.5,QColor(175,194,207));
        radia.setColorAt(0.75,QColor(255,255,255));
//        radia.setColorAt(0.75,QColor(175,194,207));
        radia.setColorAt(1,QColor(197,213,223));
        painter.setBrush(radia);
        painter.drawEllipse(rect);
    }
    painter.end();
}

void ZSwitchButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        onStateChanged();
    }
}
