#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString user_ID = ui->user_ID->text();
    QString password = ui->password->text();

    if(user_ID == "7" && password == "4963")
    {
        QMessageBox::information(this, "Login", "User ID and password are correct");
        hide();
        requestlist = new requestList(this);
        requestlist->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "User ID and password are not correct");
    }
}


void MainWindow::on_pushButton_Exit_clicked()
{

}

