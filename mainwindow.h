#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "requestlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_Exit_clicked();

private:
    Ui::MainWindow *ui;
    requestList * requestlist;
};
#endif // MAINWINDOW_H
