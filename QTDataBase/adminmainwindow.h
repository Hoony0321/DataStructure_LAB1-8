#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "searchresultlist.h"
namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QSqlDatabase* data, QWidget *parent = nullptr);
    ~AdminMainWindow();

    void SetList();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::AdminMainWindow *ui;
    QSqlDatabase* DataBase;
    SearchResultList* List;

     enum SeekerColumns{NAME, PHONE_NUMBER, DESIRED_PAY, DESIRED_JOB, DESIRED_POSITION, DESIRED_COMPANY,CREDIBILITY, SINCERITY};
};

#endif // ADMINMAINWINDOW_H
