#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

AdminMainWindow::AdminMainWindow(QSqlDatabase* data,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
    DataBase = data;

    SetList();
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::SetList(){
    //seeker
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER"<< "DESIRED_PAY" << "DESIRED_JOB" << "DESIRED_POSITION" << "DESIRED_COMPANY" << "CREDIBILITY"
                << "SINCERITY";
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QString queryStr;
    queryStr=QString("select * from JobSeekerTable");
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    int index;
    while(query.next()){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        index = ui->tableWidget->rowCount() - 1;
        ui->tableWidget->setItem(index, NAME, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(index, PHONE_NUMBER, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(index, DESIRED_PAY, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(index, DESIRED_JOB, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(index, DESIRED_POSITION, new QTableWidgetItem(query.value(6).toString()));
        ui->tableWidget->setItem(index, DESIRED_COMPANY, new QTableWidgetItem(query.value(7).toString()));
        ui->tableWidget->setItem(index, CREDIBILITY, new QTableWidgetItem(query.value(8).toString()));
        ui->tableWidget->setItem(index, SINCERITY, new QTableWidgetItem(query.value(9).toString()));
    }


    //offerer
    QStringList tableHeader1;
    tableHeader1 << "NAME" <<"PHONE NUMBER" << "JOB" << "PAY" << "COMPANY";
    ui->tableWidget_2->setColumnCount(5);
    ui->tableWidget_2->setHorizontalHeaderLabels(tableHeader1);


    queryStr=QString("select * from JobOffererTable;");
    QSqlQuery query1;
    query1.prepare(queryStr);
    query1.exec();

    while(query1.next()){
        ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
        index = ui->tableWidget_2->rowCount() - 1;
        ui->tableWidget_2->setItem(index, 0, new QTableWidgetItem(query1.value(2).toString()));
        ui->tableWidget_2->setItem(index, 1, new QTableWidgetItem(query1.value(3).toString()));
        ui->tableWidget_2->setItem(index, 2, new QTableWidgetItem(query1.value(4).toString()));
        ui->tableWidget_2->setItem(index, 3, new QTableWidgetItem(query1.value(5).toString()));
        ui->tableWidget_2->setItem(index, 4, new QTableWidgetItem(query1.value(6).toString())); //COMPANY 이름이 나오도록 해야 함 나중에 수정
    }

}

void AdminMainWindow::on_pushButton_2_clicked()
{
    QString qStr = "";
    List = new SearchResultList(DataBase,qStr,4);
    List->show();
}

void AdminMainWindow::on_pushButton_6_clicked()
{
    QString qStr = "";
    List = new SearchResultList(DataBase,qStr,5);
    List->show();
}

void AdminMainWindow::on_pushButton_clicked()
{
    QString qStr = "";
    List = new SearchResultList(DataBase,qStr,6);
    List->show();
}

void AdminMainWindow::on_pushButton_3_clicked()
{
    QString qStr = "";
    List = new SearchResultList(DataBase,qStr,7);
    List->show();
}

void AdminMainWindow::on_pushButton_5_clicked()
{
    QString qStr = "";
    List = new SearchResultList(DataBase,qStr,8);
    List->show();
}
