#ifndef QTSERTERM_H
#define QTSERTERM_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class qtserterm;
}

class qtserterm : public QMainWindow
{
    Q_OBJECT

private:
    Ui::qtserterm *ui;
    QSerialPort *serport;
    bool isLocalEcho;
    bool isShowEnd;

private slots:
    void app_exit();
    void port_scan();
    void port_set();
    void port_open();
    void port_close();
    void read_data();
    bool eventFilter(QObject *obj, QEvent *event);

    void on_actionExit_triggered();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();

    void on_btnPortScan_clicked();
    void on_btnPortOpen_clicked();

    void on_cmbPort_currentIndexChanged();
    void on_cmbLocalEcho_currentIndexChanged();
    void on_cmbShowEnd_currentIndexChanged();

public:
    explicit qtserterm(QWidget *parent = 0);
    ~qtserterm();
};

#endif /* QTSERTERM_H */
