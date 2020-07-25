#include "searchresultlist.h"
#include "ui_searchresultlist.h"

SearchResultList::SearchResultList(QSqlDatabase* data, QString _input, int _version, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchResultList)
{
    ui->setupUi(this);

    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this, SLOT(itemDoubleClicked()));

    DataBase = data;
    version = _version;
    input = _input;



    SelectFunction();
}

SearchResultList::~SearchResultList()
{
    delete ui;
}
void SearchResultList::SelectFunction(){
    switch (version) {
    case 1:
        SearchByPay();
        break;
    case 2:
        SearchByJob();
        break;
    case 3:
        SearchByCompany();
        break;
    case 4:
        ShowRequestTable();
        break;
    case 5:
        ShowJobTable();
        break;
    case 6:
        ShowProficiencyTable();
        break;
    case 7:
        ShowCompanyTable();
        break;
    case 8:
        ShowHireTable();
        break;
    }
}

void SearchResultList::SearchByPay(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER" << "JOB" << "PAY" << "COMPANY";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QSqlQuery query(*DataBase);

    query.prepare("select * "
                  "from JobOffererTable");

    query.exec();
    int index;
     while(query.next()){
         if(query.value(5).toInt() <= input.toInt()){
             ui->tableWidget->insertRow(ui->tableWidget->rowCount());
             index = ui->tableWidget->rowCount() - 1;
             ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(2).toString()));
             ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(3).toString()));
             ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(4).toString()));
             ui->tableWidget->setItem(index, 3, new QTableWidgetItem(query.value(5).toString()));
             ui->tableWidget->setItem(index, 4, new QTableWidgetItem(query.value(6).toString()));


     }
    }
}

void SearchResultList::SearchByJob(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER" << "JOB" << "PAY" << "COMPANY";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    QSqlQuery query(*DataBase);



    query.prepare("Select NAME,PHONENUMBER,JOB_NAME,PAY,COMPANY_ID FROM JobOffererTable "
                  "INNER JOIN JobTable ON JobOffererTable.JOB_ID = JobTable.JOB_ID");



    query.exec();
    int index;


     while(query.next()){
         if(query.value(2).toString() == input){
             ui->tableWidget->insertRow(ui->tableWidget->rowCount());
             index = ui->tableWidget->rowCount() - 1;
             ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
             ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
             ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
             ui->tableWidget->setItem(index, 3, new QTableWidgetItem(query.value(3).toString()));
             ui->tableWidget->setItem(index, 4, new QTableWidgetItem(query.value(4).toString()));


     }
    }
}
void SearchResultList::SearchByCompany(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER" << "JOB" << "PAY" << "COMPANY";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    QSqlQuery query(*DataBase);



    query.prepare("Select JobOffererTable.NAME,PHONENUMBER,JOB_ID,PAY,CompanyTable.NAME FROM JobOffererTable "
                  "INNER JOIN CompanyTable ON JobOffererTable.COMPANY_ID = CompanyTable.ID");

    query.exec();
    int index;

     while(query.next()){
         if(query.value(4).toString() == input){
             ui->tableWidget->insertRow(ui->tableWidget->rowCount());
             index = ui->tableWidget->rowCount() - 1;
             ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
             ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
             ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
             ui->tableWidget->setItem(index, 3, new QTableWidgetItem(query.value(3).toString()));
             ui->tableWidget->setItem(index, 4, new QTableWidgetItem(query.value(4).toString()));


     }
    }
}

void SearchResultList::on_pushButton_clicked()
{
    this->close();
}

void SearchResultList::itemDoubleClicked(){
    alertWindow = new AlertWindow();
    alertWindow->SetText("Request Success!!!");
    alertWindow->show();
}

void SearchResultList::ShowRequestTable(){
    QStringList tableHeader;
    tableHeader << "SEEKER_ID" <<"OFFERER_ID" << "NAME" << "PAY" << "COMPANY";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    ui->label->setText("Request TABLE");

    QSqlQuery query(*DataBase);



    query.prepare("Select * from RequestTable ");
    query.exec();
    int index;

     while(query.next()){
         ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         index = ui->tableWidget->rowCount() - 1;
         ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
         ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
         ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
     }

}

void SearchResultList::ShowJobTable(){
    ui->label->setText("JOB TABLE");

    QStringList tableHeader;
    tableHeader << "ID" << "NAME" << "DIFFICULTY";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QSqlQuery query(*DataBase);



    query.prepare("Select * from JobTable ");
    query.exec();
    int index;

     while(query.next()){
         ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         index = ui->tableWidget->rowCount() - 1;
         ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
         ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
         ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
     }
}

void SearchResultList::ShowProficiencyTable(){
    ui->label->setText("Proficiency TABLE");

    QStringList tableHeader;
    tableHeader << "ID" <<"JOB_ID" << "JOB_NAME" << "PROFICIENCY" << "SPEED";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QSqlQuery query(*DataBase);



    query.prepare("Select * from ProficiencyTable ");
    query.exec();
    int index;

     while(query.next()){
         ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         index = ui->tableWidget->rowCount() - 1;
         ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
         ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
         ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
         ui->tableWidget->setItem(index, 3, new QTableWidgetItem(query.value(3).toString()));
         ui->tableWidget->setItem(index, 4, new QTableWidgetItem(query.value(4).toString()));
     }
}

void SearchResultList::ShowCompanyTable(){
    ui->label->setText("Company TABLE");

    QStringList tableHeader;
    tableHeader << "ID" <<"NAME" << "LOCATION" << "GRADE";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QSqlQuery query(*DataBase);



    query.prepare("Select * from CompanyTable ");
    query.exec();
    int index;

     while(query.next()){
         ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         index = ui->tableWidget->rowCount() - 1;
         ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
         ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
         ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
         ui->tableWidget->setItem(index, 3, new QTableWidgetItem(query.value(3).toString()));
     }
}

void SearchResultList::ShowHireTable(){
    ui->label->setText("Hire TABLE");

    QStringList tableHeader;
    tableHeader << "OFFERER_ID" <<"SEEKER_ID" << "NAME";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QSqlQuery query(*DataBase);



    query.prepare("Select * from HireTable ");
    query.exec();
    int index;

     while(query.next()){
         ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         index = ui->tableWidget->rowCount() - 1;
         ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
         ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
         ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
     }
}


