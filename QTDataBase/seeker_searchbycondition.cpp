#include "seeker_searchbycondition.h"
#include "ui_seeker_searchbycondition.h"

Seeker_SearchByCondition::Seeker_SearchByCondition(QSqlDatabase* _DataBase, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Seeker_SearchByCondition)
{
    ui->setupUi(this);
    DataBase = _DataBase;
}

Seeker_SearchByCondition::~Seeker_SearchByCondition()
{
    delete ui;
}


void Seeker_SearchByCondition::on_pushButton_4_clicked()
{
    emit CloseWindow();
}

void Seeker_SearchByCondition::on_pushButton_clicked()
{
    inputWindow = new InputWindow(DataBase, 1);
    inputWindow->show();

}

void Seeker_SearchByCondition::on_pushButton_2_clicked()
{
    inputWindow = new InputWindow(DataBase, 2);
    inputWindow->show();
}

void Seeker_SearchByCondition::on_pushButton_3_clicked()
{
    inputWindow = new InputWindow(DataBase, 3);
    inputWindow->show();
}
