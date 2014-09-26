#include "zrecieveprogressbar.h"
#include "ui_zrecieveprogressbar.h"

ZRecieveProgressBar::ZRecieveProgressBar(QWidget *parent, Qt::WindowFlags f)
    :QDialog(parent,f)
    ,m_type(E_RECIEVE)
{
    ui = new Ui_ZRecieveProgressBar;
    ui->setupUi(this);
    connect(ui->pushButton_recieve,SIGNAL(clicked()),this,SLOT(onRecieveButtonClicked()));
    connect(ui->pushButton_reject,SIGNAL(clicked()),this,SLOT(onRejectButtonClicked()));
}

ZRecieveProgressBar::~ZRecieveProgressBar()
{
    delete ui;
    ui = NULL;
}

void ZRecieveProgressBar::setId(const QString &id)
{
    m_id = id;
}

void ZRecieveProgressBar::onRecieveButtonClicked()
{
    ui->progressBar->setHidden(false);
    emit sigRecieve();
    emit sigRecieve(m_id);
    ui->pushButton_recieve->setHidden(true);
    ui->pushButton_reject->setHidden(true);
}

void ZRecieveProgressBar::onRejectButtonClicked()
{
    ui->progressBar->setHidden(true);
    emit sigRejected();
    emit sigRejected(m_id);
    ui->pushButton_recieve->setHidden(true);
    ui->pushButton_reject->setHidden(true);
}

void ZRecieveProgressBar::onFileReceiveProgress(qint64 done, qint64 total)
{
    ui->progressBar->setMaximum(total);
    ui->progressBar->setValue(done);
    ui->progressBar->setHidden(false);
}

void ZRecieveProgressBar::onFinished()
{
    close();
}
