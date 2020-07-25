#ifndef SEEKER_SEARCHBYCONDITION_H
#define SEEKER_SEARCHBYCONDITION_H

#include <QMainWindow>
#include <QtSql>
#include "inputwindow.h"

namespace Ui {
class Seeker_SearchByCondition;
}

class Seeker_SearchByCondition : public QMainWindow
{
    Q_OBJECT

public:
    explicit Seeker_SearchByCondition(QSqlDatabase* _DataBase,QWidget *parent = nullptr);
    ~Seeker_SearchByCondition();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

signals:
    void CloseWindow();

private:
    Ui::Seeker_SearchByCondition *ui;
    QSqlDatabase* DataBase;
    InputWindow* inputWindow;
};

#endif // SEEKER_SEARCHBYCONDITION_H
