#ifndef JOBSEEKERMAINWINDOW_H
#define JOBSEEKERMAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "listwindow.h"
#include "seeker_searchbycondition.h"
#include "alertwindow.h"

namespace Ui {
class JobSeekerMainWindow;
}

class JobSeekerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit JobSeekerMainWindow(QSqlDatabase* _DataBase,QString _userID,QWidget *parent = nullptr);
    ~JobSeekerMainWindow();

    template<typename W>
    void MoveWindowButton(W window);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_5_clicked();

signals:
    void CloseWindow();

private:
    Ui::JobSeekerMainWindow *ui;
    QSqlDatabase* DataBase;
    QString userID;
    ListWindow* listWindow;
    Seeker_SearchByCondition* seeker_searchWindow;
    AlertWindow* alertWindow;
};

#endif // JOBSEEKERMAINWINDOW_H
