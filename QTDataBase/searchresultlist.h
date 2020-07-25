#ifndef SEARCHRESULTLIST_H
#define SEARCHRESULTLIST_H

#include <QWidget>
#include <QtSql>
#include "alertwindow.h"

namespace Ui {
class SearchResultList;
}

class SearchResultList : public QWidget
{
    Q_OBJECT

public:
    explicit SearchResultList(QSqlDatabase* data, QString _input,int version, QWidget *parent = nullptr);
    ~SearchResultList();

    void SelectFunction();
    void SearchByPay();
    void SearchByJob();
    void SearchByCompany();

    void ShowProficiencyTable();
    void ShowJobTable();
    void ShowRequestTable();

    void ShowCompanyTable();
    void ShowHireTable();


private slots:
    void on_pushButton_clicked();

    void itemDoubleClicked();

private:
    Ui::SearchResultList *ui;
    QSqlDatabase* DataBase;
    int version;
    QString input;
    AlertWindow* alertWindow;
};

#endif // SEARCHRESULTLIST_H
