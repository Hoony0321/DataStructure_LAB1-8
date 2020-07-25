#ifndef SURVEYWINDOW_H
#define SURVEYWINDOW_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class SurveyWindow;
}

class SurveyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SurveyWindow(QSqlDatabase* Data, QWidget *parent = nullptr);
    ~SurveyWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void CloseWindow();

private:
    Ui::SurveyWindow *ui;
    QSqlDatabase* DataBase;
};

#endif // SURVEYWINDOW_H
