#include "offerer_searchresult.h"
#include "ui_offerer_searchresult.h"


offerer_searchResult::offerer_searchResult(QSqlDatabase* data, QString _input,int _version, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::offerer_searchResult)
{
    ui->setupUi(this);

    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this, SLOT(itemDoubleClicked()));

    DataBase = data;
    version = _version;
    input =_input;


    SelectFunction();
}

offerer_searchResult::~offerer_searchResult()
{
    delete ui;
}

void offerer_searchResult::on_pushButton_clicked()
{
    this->close();
}

void offerer_searchResult::SelectFunction(){

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
        SearchByPosition();
        break;
    case 5:
        SearchBySincerity();
        break;
    case 6:
        SearchByCredibility();
        break;
    case 7:
        ShowHireList();
        break;
    case 8:
        ShowRequestList();
        break;

    }


}

void offerer_searchResult::SearchByPay(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER"<< "DESIRED_PAY" << "DESIRED_JOB" << "DESIRED_POSITION" << "DESIRED_COMPANY" << "CREDIBILITY"
                << "SINCERITY";
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);


    QString queryStr;
    queryStr=QString("select* FROM JobSeekerTable");
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    int index;
    while(query.next()){
        if(query.value(4).toInt() <= input.toInt()){
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
}

void offerer_searchResult::SearchByJob(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER"<< "JOB_NAME" << "PROFICENCY" << "SPEED";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QString queryStr;
    queryStr=QString("select JobSeekerTable.NAME, JobSeekerTable.PHONENUMBER, JOB_NAME, PROFICIENCY, SPEED FROM ProficiencyTable INNER JOIN JobTable ON ProficiencyTable.JOB_ID = JobTable.JOB_ID "
                     "INNER JOIN JobSeekerTable ON ProficiencyTable.USER_ID = JobSeekerTable.ID");


    QSqlQuery query;
    query.prepare(queryStr);
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

void offerer_searchResult::SearchByCompany(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER"<< "DESIRED_COMPANY";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QString queryStr;
    queryStr=QString("select JobSeekerTable.NAME, PHONENUMBER, CompanyTable.NAME "
                     "from JobSeekerTable INNER JOIN CompanyTable "
                     "ON CompanyTable.ID = JobSeekerTable.DESIRED_COMPANY_ID");

    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    int index;
    while(query.next()){
        if(query.value(2).toString() == input){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            index = ui->tableWidget->rowCount() - 1;
            ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
        }

    }
}

void offerer_searchResult::SearchByPosition(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER"<< "DESIRED_POSITION";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QString queryStr;
    queryStr=QString("select NAME, PHONENUMBER, DESIRED_POSITION "
                     "from JobSeekerTable");
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    int index;
    while(query.next()){
        if(query.value(2).toString() == input){
               ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            index = ui->tableWidget->rowCount() - 1;
            ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
       }

    }
}

void offerer_searchResult::SearchBySincerity(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER"<< "SINCERITY";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);


    QString queryStr;
    queryStr=QString("select NAME, PHONENUMBER, SINCERITY "
                     "from JobSeekerTable");
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    int index;
    while(query.next()){
        if(query.value(2).toInt() >= input.toInt()){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            index = ui->tableWidget->rowCount() - 1;
            ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
        }


    }
}

void offerer_searchResult::SearchByCredibility(){
    QStringList tableHeader;
    tableHeader << "NAME" <<"PHONE NUMBER"<< "CREDIBILITY";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QString queryStr;
    queryStr=QString("select NAME, PHONENUMBER, CREDIBILITY "
                     "from JobSeekerTable");
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    int index;
    while(query.next()){
        if(query.value(2).toInt() >= input.toInt())
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        index = ui->tableWidget->rowCount() - 1;
        ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(index, 2, new QTableWidgetItem(query.value(2).toString()));
    }
}

void offerer_searchResult::ShowHireList(){
    QString UserID = input;

    ui->label->setText("HireList");
    QStringList tableHeader;
    tableHeader << "ID" <<"NAME";
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QString queryStr;
    queryStr=QString("select * from HireTable");
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    int index;
    while(query.next()){
        if(query.value(0).toString() == input){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            index = ui->tableWidget->rowCount() - 1;
            ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(2).toString()));
        }

    }
}

void offerer_searchResult::ShowRequestList(){
    QString UserID = input;

    ui->label->setText("Requset List");
    QStringList tableHeader;
    tableHeader << "ID" <<"NAME";
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    QString queryStr;
    queryStr=QString("select * from RequestTable");
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    int index;
    while(query.next()){
        if(query.value(1).toString() == input){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            index = ui->tableWidget->rowCount() - 1;
            ui->tableWidget->setItem(index, 0, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(index, 1, new QTableWidgetItem(query.value(2).toString()));
        }

    }
}



void offerer_searchResult::itemDoubleClicked(){
    alertWindow = new AlertWindow();
    alertWindow->SetText("Hire Success!!!");
    alertWindow->show();
}
