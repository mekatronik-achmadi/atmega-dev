#ifndef QTSERTERM_H
#define QTSERTERM_H

#include <QMainWindow>

namespace Ui {
class qtserterm;
}

class qtserterm : public QMainWindow
{
    Q_OBJECT

private:
    Ui::qtserterm *ui;

private slots:
    void app_exit();
    void on_actionQuit_triggered();

public:
    explicit qtserterm(QWidget *parent = 0);
    ~qtserterm();
};

#endif /* QTSERTERM_H */
