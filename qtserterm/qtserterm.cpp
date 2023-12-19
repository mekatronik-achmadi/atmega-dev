#include "qtserterm.h"
#include "ui_qtserterm.h"

qtserterm::qtserterm(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::qtserterm)
{
    ui->setupUi(this);
}

qtserterm::~qtserterm()
{
    delete ui;
}

void qtserterm::app_exit()
{
    QApplication::quit();
}

void qtserterm::on_actionQuit_triggered()
{
    app_exit();
}

