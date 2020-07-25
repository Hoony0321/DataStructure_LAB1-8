#ifndef OFFERER_SEARCHBYCONDITION_H
#define OFFERER_SEARCHBYCONDITION_H

#include <QWidget>
#include <QtSql>
#include "inputwindow.h"

namespace Ui {
class offerer_searchbycondition;
}

class offerer_searchbycondition : public QWidget
{
    Q_OBJECT

public:
    explicit offerer_searchbycondition(QSqlDatabase* _DataBase, QWidget *parent = nullptr);
    ~offerer_searchbycondition();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

signals:
    void CloseWindow();

private:
    Ui::offerer_searchbycondition *ui;
    QSqlDatabase* DataBase;
    InputWindow* inputWindow;

};

#endif // OFFERER_SEARCHBYCONDITION_H
