#include "surveywindow.h"
#include "ui_surveywindow.h"
#include "alertwindow.h"

SurveyWindow::SurveyWindow(QSqlDatabase* Data,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SurveyWindow)
{
    ui->setupUi(this);
    DataBase = Data;
}

SurveyWindow::~SurveyWindow()
{
    delete ui;
}

void SurveyWindow::on_pushButton_clicked()
{
    AlertWindow* alertwindow;
    alertwindow = new AlertWindow();
    QString qStr = "Thnak you!!!";
    alertwindow->SetText(qStr);
    alertwindow->show();
    this->close();
}

void SurveyWindow::on_pushButton_2_clicked()
{
    this->close();
}
