#include "signupwindow.h"
#include "ui_signupwindow.h"


SignUpWindow::SignUpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_pushButton_clicked()
{
    alertWindow = new AlertWindow();
    alertWindow->SetText("Sing Up Success!!!");
    alertWindow->show();
    this->close();
}

void SignUpWindow::on_pushButton_2_clicked()
{
    this->close();
}
