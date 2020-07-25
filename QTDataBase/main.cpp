#include "loginwindow.h"
#include <QtSql>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //DB connect
    QString path = "C:/Users/rheogns/Desktop/QTTEST/QTDataBase/DataBase.db";
    QSqlDatabase localDB;
    localDB = QSqlDatabase::addDatabase("QSQLITE");
    localDB.setDatabaseName(path);
    if(!localDB.open()){
        qDebug() << "Can't Connect to DB! ";
        QSqlDatabase::removeDatabase(path);
        return 0;
    }
    qDebug() << "Connected Successfully to DB !";

    LoginWindow w(&localDB);
    w.show();
    return a.exec();
}
