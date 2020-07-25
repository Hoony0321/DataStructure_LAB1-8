#include "listwindow.h"
#include "ui_listwindow.h"

ListWindow::ListWindow(QSqlDatabase* _DataBase, int _version, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
    DataBase = _DataBase;
    version = _version;



    if(version == 1){ // 구직자 전용
        ui->label->setText("JobOfferer List");
        SetList_FindOfferer();
        connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this, SLOT(itemDoubleClicked1()));

    }
    else if(version == 2){ //구인자 전용
        ui->label->setText("JobSeeker List");
        SetList_FindSeeker();
        connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this, SLOT(itemDoubleClicked2()));
    }

}

ListWindow::~ListWindow()
{
    delete ui;
}

void ListWindow::SetList_FindSeeker(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER"<< "DESIRED_PAY" << "DESIRED_JOB" << "DESIRED_POSITION" << "DESIRED_COMPANY" << "CREDIBILITY"
                << "SINCERITY";
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QString queryStr;
    queryStr=QString("select *"
                     "from JobSeekerTable");
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

}

void ListWindow::SetList_FindOfferer(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER" << "JOB" << "PAY" << "COMPANY";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QString queryStr;
    queryStr=QString("select * from JobOffererTable;");
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    int index;
    while(query.next()){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        index = ui->tableWidget->rowCount() - 1;
        ui->tableWidget->setItem(index, NAME, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(index, PHONE_NUMBER, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(index, 3, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(index, 4, new QTableWidgetItem(query.value(6).toString())); //COMPANY 이름이 나오도록 해야 함 나중에 수정
    }

}

void ListWindow::on_pushButton_clicked()
{
    emit CloseWindow();
}

void ListWindow::itemDoubleClicked1(){
    alertWindow = new AlertWindow();
    alertWindow->SetText("Request Success!!!");
    alertWindow->show();
}

void ListWindow::itemDoubleClicked2(){
    alertWindow = new AlertWindow();
    alertWindow->SetText("Hire Success!!!");
    alertWindow->show();
}
