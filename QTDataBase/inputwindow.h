#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include <QWidget>
#include <QtSql>
#include "searchresultlist.h"
#include "offerer_searchresult.h"

namespace Ui {
class InputWindow;
}

class InputWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InputWindow(QSqlDatabase* _Data, int version, QWidget *parent = nullptr);
    ~InputWindow();

    void SetLabel();


private slots:
    void on_pushButton_clicked();

private:
    Ui::InputWindow *ui;
    QSqlDatabase* DataBase;
    int version;
    SearchResultList* resultListWindow;
    offerer_searchResult* offerer_searchList;
};

#endif // INPUTWINDOW_H
