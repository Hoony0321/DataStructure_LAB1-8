#include "inputwindow.h"
#include "ui_inputwindow.h"

InputWindow::InputWindow(QSqlDatabase* _Data, int _version,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputWindow)
{
    ui->setupUi(this);
    DataBase = _Data;
    version = _version;

    SetLabel();

}

InputWindow::~InputWindow()
{
    delete ui;
}

void InputWindow::SetLabel(){
    switch (version) {
    case 1:
        ui->label->setText("SEARCH BY PAY");
        break;
    case 2:
        ui->label->setText("SEARCH BY JOB");
        break;
    case 3:
        ui->label->setText("SEARCH BY COMPANY");
        break;
        //고용자가 검색
    case 4:
        ui->label->setText("SEARCH BY PAY");
        break;
    case 5:
        ui->label->setText("SEARCH BY PROFICENCY");
        break;
    case 6:
        ui->label->setText("SEARCH BY COMPANY");
        break;
    case 7:
        ui->label->setText("SEARCH BY POSITION");
        break;
    case 8:
        ui->label->setText("SEARCH BY SINCERITY");
        break;
    case 9:
        ui->label->setText("SEARCH BY CREDIBILITY");
        break;
    }
}

void InputWindow::on_pushButton_clicked()
{
    QString input = ui->lineEdit->text();
    switch (version) {
    case 1:
        resultListWindow = new SearchResultList(DataBase, input,1);
        resultListWindow->show();
        this->close();
        break;
    case 2:
        resultListWindow = new SearchResultList(DataBase, input,2);
        resultListWindow->show();
        this->close();
        break;
    case 3:
        resultListWindow = new SearchResultList(DataBase, input,3);
        resultListWindow->show();
        this->close();
        break;
        //고용인이 시작
    case 4:
        offerer_searchList = new offerer_searchResult(DataBase, input,1);
        offerer_searchList->show();
        this->close();
        break;
    case 5:
        offerer_searchList = new offerer_searchResult(DataBase, input,2);
        offerer_searchList->show();
        this->close();
        break;
    case 6:
        offerer_searchList = new offerer_searchResult(DataBase, input,3);
        offerer_searchList->show();
        this->close();
        break;
    case 7:
        offerer_searchList = new offerer_searchResult(DataBase, input,4);
        offerer_searchList->show();
        this->close();
        break;
    case 8:
        offerer_searchList = new offerer_searchResult(DataBase, input,5);
        offerer_searchList->show();
        this->close();
        break;
    case 9:
        offerer_searchList = new offerer_searchResult(DataBase, input,6);
        offerer_searchList->show();
        this->close();
        break;
    }
}





