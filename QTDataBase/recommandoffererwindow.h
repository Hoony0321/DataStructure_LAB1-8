#ifndef RECOMMANDOFFERERWINDOW_H
#define RECOMMANDOFFERERWINDOW_H

#include <QWidget>

namespace Ui {
class RecommandOffererWindow;
}

class RecommandOffererWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RecommandOffererWindow(QWidget *parent = nullptr);
    ~RecommandOffererWindow();

private:
    Ui::RecommandOffererWindow *ui;
};

#endif // RECOMMANDOFFERERWINDOW_H
