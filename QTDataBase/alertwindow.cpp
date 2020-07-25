#include "alertwindow.h"
#include "ui_alertwindow.h"

AlertWindow::AlertWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlertWindow)
{
    ui->setupUi(this);
}

AlertWindow::~AlertWindow()
{
    delete ui;
}

void AlertWindow::SetText(QString qStr){
    ui->label->setText(qStr);
}

void AlertWindow::on_pushButton_clicked()
{
    this->close();
}
