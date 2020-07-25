#include "jobofferermainwindow.h"
#include "ui_jobofferermainwindow.h"

JobOffererMainWindow::JobOffererMainWindow(QSqlDatabase* _DataBase,QString _userID,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JobOffererMainWindow)
{
    ui->setupUi(this);
    DataBase = _DataBase;
    userID = _userID;
    ui->label_7->setText(userID);


}

JobOffererMainWindow::~JobOffererMainWindow()
{
    delete ui;
}

template <typename W>
void JobOffererMainWindow::MoveWindowButton(W window) {
    window->show();
    this->hide();

    QEventLoop loop;

    QObject::connect(window, SIGNAL(CloseWindow()), &loop, SLOT(quit()));
    loop.exec();
    this->show();
    window->hide();
}

void JobOffererMainWindow::on_pushButton_clicked(bool checked)
{
    listWindow = new ListWindow(DataBase, 2);
    MoveWindowButton(listWindow);

}

void JobOffererMainWindow::on_pushButton_2_clicked()
{
    QString qStr;

    qStr = "Recommand eogns0321- Jacob - 01012341235. ";

    alertWindow = new AlertWindow();
    alertWindow->SetText(qStr);
    alertWindow->show();
}

void JobOffererMainWindow::on_pushButton_4_clicked()
{
    searchWindow = new offerer_searchbycondition(DataBase);
    MoveWindowButton(searchWindow);
}

void JobOffererMainWindow::on_pushButton_5_clicked()
{
    emit CloseWindow();
}

void JobOffererMainWindow::on_pushButton_3_clicked()
{
    surveyWindow = new SurveyWindow(DataBase);
    surveyWindow->show();
}

void JobOffererMainWindow::on_pushButton_6_clicked()
{
    hireList = new offerer_searchResult(DataBase, userID, 7);
    hireList->show();

}

void JobOffererMainWindow::on_pushButton_7_clicked()
{
    requestList = new offerer_searchResult(DataBase, userID, 8);
    requestList->show();
}
