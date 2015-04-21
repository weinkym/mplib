#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>
#include "mplib.h"
#include "zwheelwidget.h"
#include "zscreenshot.h"
#include "zswitchbutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void testZWheelWidget();
    void testPrinter();
    void testScreenShot();

private slots:
    void on_btn_test_clicked();

private:
    Ui::MainWindow *ui;
#if QT_VERSION > QT_VERSION_CHECK(5, 0, 0)
    ZStringWheelWidget* m_wheelWidget;
#endif
//    ZScreenshotDlg m_screenShot;
};

#endif // MAINWINDOW_H
