#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <string>
#include <QtSql>
LoginWindow::LoginWindow(QSqlDatabase* _DataBase,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    DataBase = _DataBase;
    loginFailedWindow = new LoginFailedWindow();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    int index = ui->comboBox->currentIndex();

    //ID & PASSWORD 읽어옴
    QString id = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    //DATABASE와 입력된 정보 비교
    QSqlQuery query(*DataBase);

    if(index == 0){
        query.prepare("select * "
                      "from JobSeekerTable");
        query.exec();
        while(query.next()){
            if(QString::compare(id,query.value(0).toString()) == 0){
                if(QString::compare(password,query.value(1).toString()) == 0){
                    LoginSuccess = true;
                }
            }

        }
        if(LoginSuccess){
            seekerMainWindow = new JobSeekerMainWindow(DataBase,id);
            MoveWindowButton(seekerMainWindow);
        }
        else{
             loginFailedWindow->show();
        }

    }
    else if(index == 1){
        query.prepare("select * "
                      "from JobOffererTable");
        query.exec();
        while(query.next()){
            if(QString::compare(id,query.value(0).toString()) == 0){
                if(QString::compare(password,query.value(1).toString()) == 0){
                    LoginSuccess = true;
                }
            }

        }
        if(LoginSuccess){
            offererMainWindow = new JobOffererMainWindow(DataBase,id);
            MoveWindowButton(offererMainWindow);
        }
        else{
             loginFailedWindow->show();
        }
    }
    else if(index == 2){
        query.prepare("select * "
                      "from adminTable");
        query.exec();
        while(query.next()){
            if(QString::compare(id,query.value(0).toString()) == 0){
                if(QString::compare(password,query.value(1).toString()) == 0){
                    LoginSuccess = true;
                }
            }

        }
        if(LoginSuccess){
            adminWindow = new AdminMainWindow(DataBase);
            MoveWindowButton(adminWindow);
        }
        else{
             loginFailedWindow->show();
        }
    }


}
template<typename W>
void LoginWindow::MoveWindowButton(W window){
    window->show();
    this->hide();

    QEventLoop loop;

    QObject::connect(window, SIGNAL(CloseWindow()), &loop, SLOT(quit()));
    loop.exec();
    this->show();
    window->hide();
}

void LoginWindow::on_pushButton_2_clicked()
{
    signUpWindow = new SignUpWindow();
    signUpWindow->show();
}
