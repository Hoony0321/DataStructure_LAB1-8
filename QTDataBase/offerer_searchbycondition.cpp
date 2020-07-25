#include "offerer_searchbycondition.h"
#include "ui_offerer_searchbycondition.h"

offerer_searchbycondition::offerer_searchbycondition(QSqlDatabase* _DataBase,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::offerer_searchbycondition)
{
    ui->setupUi(this);
    DataBase = _DataBase;
}

offerer_searchbycondition::~offerer_searchbycondition()
{
    delete ui;
}

void offerer_searchbycondition::on_pushButton_4_clicked()
{
    emit CloseWindow();
}

void offerer_searchbycondition::on_pushButton_clicked()
{
    inputWindow = new InputWindow(DataBase, 4);
    inputWindow->show();

}

void offerer_searchbycondition::on_pushButton_2_clicked()
{
    inputWindow = new InputWindow(DataBase, 5);
    inputWindow->show();
}

void offerer_searchbycondition::on_pushButton_3_clicked()
{
    inputWindow = new InputWindow(DataBase, 6);
    inputWindow->show();
}

void offerer_searchbycondition::on_pushButton_5_clicked()
{
    inputWindow = new InputWindow(DataBase, 7);
    inputWindow->show();
}

void offerer_searchbycondition::on_pushButton_6_clicked()
{
    inputWindow = new InputWindow(DataBase, 8);
    inputWindow->show();
}

void offerer_searchbycondition::on_pushButton_7_clicked()
{
    inputWindow = new InputWindow(DataBase, 9);
    inputWindow->show();
}

void offerer_searchbycondition::on_pushButton_8_clicked()
{
    inputWindow = new InputWindow(DataBase, 10);
    inputWindow->show();
}
