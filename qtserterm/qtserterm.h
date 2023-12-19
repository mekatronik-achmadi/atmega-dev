#ifndef QTSERTERM_H
#define QTSERTERM_H

#include <QMainWindow>
#include <QMessageBox>

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
    void on_actionExit_triggered();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();

public:
    explicit qtserterm(QWidget *parent = 0);
    ~qtserterm();
};

#endif /* QTSERTERM_H */
