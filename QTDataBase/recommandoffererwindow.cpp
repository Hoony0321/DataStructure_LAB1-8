#include "recommandoffererwindow.h"
#include "ui_recommandoffererwindow.h"

RecommandOffererWindow::RecommandOffererWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecommandOffererWindow)
{
    ui->setupUi(this);
}

RecommandOffererWindow::~RecommandOffererWindow()
{
    delete ui;
}
