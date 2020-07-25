#ifndef LISTWINDOW_H
#define LISTWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "alertwindow.h"

namespace Ui {
class ListWindow;
}

class ListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListWindow(QSqlDatabase* _DataBase, int version, QWidget *parent = nullptr);
    ~ListWindow();
    void SetList_FindSeeker();
    void SetList_FindOfferer();

private slots:
    void on_pushButton_clicked();

    void itemDoubleClicked1();
    void itemDoubleClicked2();

signals:
    void CloseWindow();


private:
    Ui::ListWindow *ui;
    QSqlDatabase* DataBase;
    int version;
    enum SeekerColumns{NAME, PHONE_NUMBER, DESIRED_PAY, DESIRED_JOB, DESIRED_POSITION, DESIRED_COMPANY,CREDIBILITY, SINCERITY};

    AlertWindow* alertWindow;


};

#endif // LISTWINDOW_H
