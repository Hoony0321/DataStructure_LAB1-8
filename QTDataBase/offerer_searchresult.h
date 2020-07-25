#ifndef OFFERER_SEARCHRESULT_H
#define OFFERER_SEARCHRESULT_H

#include <QWidget>
#include <QtSql>
#include "alertwindow.h"

namespace Ui {
class offerer_searchResult;
}

class offerer_searchResult : public QWidget
{
    Q_OBJECT

public:
    explicit offerer_searchResult(QSqlDatabase* data, QString input,int _version, QWidget *parent = nullptr);
    ~offerer_searchResult();

    void SelectFunction();

    void SearchByPay();
    void SearchByJob();
    void SearchByCompany();
    void SearchByPosition();
    void SearchBySincerity();
    void SearchByCredibility();

    void ShowHireList();
    void ShowRequestList();

private slots:
    void on_pushButton_clicked();

    void itemDoubleClicked();


private:
    Ui::offerer_searchResult *ui;
    int version;
    QSqlDatabase* DataBase;
    QString input;
    enum SeekerColumns{NAME, PHONE_NUMBER, DESIRED_PAY, DESIRED_JOB, DESIRED_POSITION, DESIRED_COMPANY,CREDIBILITY, SINCERITY};

    AlertWindow* alertWindow;

};

#endif // OFFERER_SEARCHRESULT_H
