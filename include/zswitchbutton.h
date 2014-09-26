#ifndef ZSWITCHBUTTON_H
#define ZSWITCHBUTTON_H
#include <QWidget>
#include "mplib_global.h"

class MPLIBSHARED_EXPORT ZSwitchButton : public QWidget
{
    Q_OBJECT
public:
    explicit ZSwitchButton(QWidget *parent = 0);
    bool getCheck() const {return m_isCheck;}
    void setCheck(bool isCheck);

protected:
//    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
private slots:
    void onStateChanged();
signals:
    void sigStateChanged(bool isCheck);

private:
    bool m_isCheck;
};
#endif // ZSWITCHBUTTON_H
