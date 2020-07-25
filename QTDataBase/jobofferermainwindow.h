#ifndef JOBOFFERERMAINWINDOW_H
#define JOBOFFERERMAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "listwindow.h"
#include "alertwindow.h"
#include "offerer_searchbycondition.h"
#include "surveywindow.h"
#include "offerer_searchresult.h"
namespace Ui {
class JobOffererMainWindow;
}

class JobOffererMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit JobOffererMainWindow(QSqlDatabase* _DataBase,QString _userID,QWidget *parent = nullptr);
    ~JobOffererMainWindow();

    template <typename W>
    void MoveWindowButton(W window);

private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

signals:
    void CloseWindow();

private:
    Ui::JobOffererMainWindow *ui;
    QSqlDatabase* DataBase;
    QString userID;
    ListWindow* listWindow;
    AlertWindow* alertWindow;
    offerer_searchbycondition* searchWindow;
    SurveyWindow* surveyWindow;
    offerer_searchResult* hireList;
    offerer_searchResult* requestList;
};

#endif // JOBOFFERERMAINWINDOW_H
