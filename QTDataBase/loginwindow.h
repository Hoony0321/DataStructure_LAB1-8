#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "mainwindow.h"
#include "jobseekermainwindow.h"
#include "jobofferermainwindow.h"
#include "loginfailedwindow.h"
#include "signupwindow.h"
#include <QDialog>
#include "adminmainwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QSqlDatabase* _DataBase,QWidget *parent = nullptr);
    ~LoginWindow();

    template<typename W>
    void MoveWindowButton(W window);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LoginWindow *ui;

    JobSeekerMainWindow* seekerMainWindow;
    JobOffererMainWindow* offererMainWindow;
    MainWindow* mainWindow;
    LoginFailedWindow* loginFailedWindow;
    QSqlDatabase* DataBase;
    SignUpWindow* signUpWindow;
    AdminMainWindow* adminWindow;
    bool LoginSuccess = false;
};

#endif // LOGINWINDOW_H
