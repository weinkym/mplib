#ifndef ZRECIEVEPROGRESSBAR_H
#define ZRECIEVEPROGRESSBAR_H
#include <QDialog>
#include "mplib_global.h"

class Ui_ZRecieveProgressBar;

class MPLIBSHARED_EXPORT ZRecieveProgressBar : public QDialog
{
    Q_OBJECT

public:
    ZRecieveProgressBar(QWidget* parent = 0, Qt::WindowFlags f = 0);
    ~ZRecieveProgressBar();
    void setId(const QString& id);

public slots:
    void onRecieveButtonClicked();
    void onRejectButtonClicked();
    void onFileReceiveProgress(qint64 done, qint64 total);
    void onFinished();

signals:
    void sigRecieve();
    void sigRecieve(const QString& id);
    void sigCancel();
    void sigCancel(const QString& id);
    void sigRejected();
    void sigRejected(const QString& id);

private:
    enum E_STATUS_TYPE{E_RECIEVE,E_CANCEL};
    Ui_ZRecieveProgressBar* ui;
    E_STATUS_TYPE m_type;
    QString m_id;
};

#endif // ZRECIEVEPROGRESSBAR_H
