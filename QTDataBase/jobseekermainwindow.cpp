#include "jobseekermainwindow.h"
#include "ui_jobseekermainwindow.h"

JobSeekerMainWindow::JobSeekerMainWindow(QSqlDatabase* _DataBase,QString _userID,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JobSeekerMainWindow)
{
    ui->setupUi(this);
    DataBase = _DataBase;
    userID = _userID;
    ui->label_3->setText(userID);
}

JobSeekerMainWindow::~JobSeekerMainWindow()
{
    delete ui;
}

template <typename W>
void JobSeekerMainWindow::MoveWindowButton(W window) {
    window->show();
    this->hide();

    QEventLoop loop;

    QObject::connect(window, SIGNAL(CloseWindow()), &loop, SLOT(quit()));
    loop.exec();
    this->show();
    window->hide();
}

void JobSeekerMainWindow::on_pushButton_clicked()
{
    listWindow = new ListWindow(DataBase, 1);
    MoveWindowButton(listWindow);
}

void JobSeekerMainWindow::on_pushButton_4_clicked()
{
    seeker_searchWindow = new Seeker_SearchByCondition(DataBase);
    MoveWindowButton(seeker_searchWindow);
}

void JobSeekerMainWindow::on_pushButton_2_clicked(bool checked)
{
    QString qStr;

    qStr = "Recommand coco6783- PAUL - 01012341234. ";

    alertWindow = new AlertWindow();
    alertWindow->SetText(qStr);
    alertWindow->show();

}

void JobSeekerMainWindow::on_pushButton_5_clicked()
{
    emit CloseWindow();
}
