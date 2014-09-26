#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
//  , m_wheelWidget(NULL)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testZWheelWidget()
{
#if QT_VERSION > QT_VERSION_CHECK(5, 0, 0)
    if(m_wheelWidget == NULL)
    {
        m_wheelWidget = new ZStringWheelWidget(false);
    }
    QStringList list;
    list.append("0");
    list.append("1");
    list.append("2");
    list.append("3");
    list.append("4");
    m_wheelWidget->setItems(list);
    QFont font = m_wheelWidget->font();
    font.setPointSize(32);
    m_wheelWidget->setFont(font);
    int index = 4;
    qDebug()<<"index = "<<index<<"key = "<<m_wheelWidget->key(index);
    m_wheelWidget->setCurrentIndex(index);
//    if(m_wheelWidget == NULL)
//    {
//        m_wheelWidget = new ZStringWheelWidget(false);
//    }
//    QStringList list;
//    list.append("0");
//    list.append("1");
//    list.append("2");
//    list.append("3");
//    list.append("4");
//    m_wheelWidget->setItems(list);
//    QFont font = m_wheelWidget->font();
//    font.setPointSize(32);
//    m_wheelWidget->setFont(font);
//    int index = 4;
//    qDebug()<<"index = "<<index<<"key = "<<m_wheelWidget->key(index);
//    m_wheelWidget->setCurrentIndex(index);
//    m_wheelWidget->show();
    m_wheelWidget->show();
#endif
}


void MainWindow::testPrinter()
{
#ifdef Q_CC_MSVC
    Mplib::MpStaticMethod t;
    QString name = t.getDefaultPrinter();
//    QString name = Mplib::MpStaticMethod::getDefaultPrinter();
    qDebug()<<"name = "<<name;
    QStringList list = Mplib::MpStaticMethod::getPrinters();
    foreach (QString str, list) {
        qDebug()<<"str = "<<str;
    }
    bool result = Mplib::MpStaticMethod::setDefaultPrinter("Fax");
    qDebug()<<"result "<<result;
#endif
}

void MainWindow::testScreenShot()
{
    ZScreenshotDlg dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
//        ui->label->setPixmap(dlg.getSelectedImg());
        ui->label->setPixmap(QApplication::clipboard()->pixmap());
    }
}

void MainWindow::on_btn_test_clicked()
{
    testScreenShot();
}
