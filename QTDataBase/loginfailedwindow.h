#ifndef LOGINFAILEDWINDOW_H
#define LOGINFAILEDWINDOW_H

#include <QDialog>

namespace Ui {
class LoginFailedWindow;
}

class LoginFailedWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginFailedWindow(QWidget *parent = nullptr);
    ~LoginFailedWindow();

private:
    Ui::LoginFailedWindow *ui;
};

#endif // LOGINFAILEDWINDOW_H
