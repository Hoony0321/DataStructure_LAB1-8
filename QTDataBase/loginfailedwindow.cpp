#include "loginfailedwindow.h"
#include "ui_loginfailedwindow.h"

LoginFailedWindow::LoginFailedWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginFailedWindow)
{
    ui->setupUi(this);
}

LoginFailedWindow::~LoginFailedWindow()
{
    delete ui;
}
