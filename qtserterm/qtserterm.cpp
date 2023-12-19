#include "qtserterm.h"
#include "ui_qtserterm.h"

qtserterm::qtserterm(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::qtserterm)
{
    ui->setupUi(this);
    this->setFixedSize(size());

    serport = new QSerialPort(this);
    connect(serport,SIGNAL(readyRead()),SLOT(read_data()));

    ui->cmbBaud->setCurrentIndex(0);
    ui->txtSerTerm->installEventFilter(this);

    port_scan();
    port_set();

    isLocalEcho = false;
    isShowEnd = false;
}

qtserterm::~qtserterm()
{
    delete ui;
}

void qtserterm::app_exit()
{
    port_close();
    QApplication::quit();
}

void qtserterm::port_scan()
{
    ui->cmbPort->clear();

    foreach(const QSerialPortInfo &serportInfo, QSerialPortInfo::availablePorts()){
        ui->cmbPort->addItem(serportInfo.portName());
    }
}

void qtserterm::port_set()
{
    QString msg;
    QString dev_name="/dev/";

    if(serport->isOpen()){
        msg = "Serial Port still open";
        ui->sttbar->showMessage(msg);
        return;
    }

    dev_name += ui->cmbPort->currentText();
    serport->setPortName(dev_name);

    msg = "Port Set To: ";
    msg += ui->cmbPort->currentText();
    ui->sttbar->showMessage(dev_name);
}

void qtserterm::port_open()
{
    QString msg;

    if(serport->isOpen()){
        msg = "Serial Port already open";
        ui->sttbar->showMessage(msg);
        return;
    }

    int baud_index = ui->cmbBaud->currentIndex();
    QSerialPort::BaudRate dev_baud = QSerialPort::Baud9600;

    switch (baud_index) {
        case 0: dev_baud = QSerialPort::Baud9600;break;
        case 1: dev_baud = QSerialPort::Baud19200;break;
        case 2: dev_baud = QSerialPort::Baud38400;break;
        case 3: dev_baud = QSerialPort::Baud57600;break;
        case 4: dev_baud = QSerialPort::Baud115200;break;
    }

    serport->setBaudRate(dev_baud);
    serport->setDataBits(QSerialPort::Data8);
    serport->setStopBits(QSerialPort::OneStop);
    serport->setFlowControl(QSerialPort::NoFlowControl);
    serport->setParity(QSerialPort::NoParity);

    if(serport->open(QIODevice::ReadWrite)){
        ui->btnPortOpen->setText("Close");

        msg = "Serial Port Opened: ";
        msg += serport->portName();
        ui->sttbar->showMessage(msg);
    }
    else{
        msg = "Serial Port Failed: ";
        msg += serport->portName();
        ui->sttbar->showMessage(msg);
    }
}

void qtserterm::port_close()
{
    QString msg;

    if(serport->isOpen()){
        msg = "Closing serial port: ";
        msg += serport->portName();
        ui->sttbar->showMessage(msg);

        serport->close();
        ui->btnPortOpen->setText("Open");
    }
}

void qtserterm::read_data()
{
    QByteArray rawdata = serport->readAll();

    if(isShowEnd){
        rawdata.replace("\r","<CR>");
        rawdata.replace("\n","<LF>\n");
    }

    ui->txtSerTerm->insertPlainText(rawdata);
}

bool qtserterm::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(serport->isOpen()){
            if((keyEvent->key()==Qt::Key_Enter) || (keyEvent->key()==Qt::Key_Return)){
                QString eolStr = "\r\n";
                QByteArray eolByte = eolStr.toUtf8();
                serport->write(eolByte);

                if(isLocalEcho) ui->txtSerTerm->insertPlainText(eolByte);
            }
            else{
                QString s = keyEvent->text();
                if(s.length()){
                    char ch = s.at(0).toLatin1();
                    QByteArray chb = QByteArray::fromRawData(&ch, 1);
                    serport->write(chb);

                    if(isLocalEcho) ui->txtSerTerm->insertPlainText(chb);
                }
            }
        }
        return true;
    }
    else{
        return QObject::eventFilter(obj,event);
    }
}

void qtserterm::on_actionExit_triggered()
{
    app_exit();
}

void qtserterm::on_actionQuit_triggered()
{
    app_exit();
}

void qtserterm::on_actionAbout_triggered()
{
    QMessageBox::information(this,
            "Qt Serial Terminal",
            "A Simple ASCII Serial Terminal build on top Qt Toolkit\n\nWritten by Achmadi",
            QMessageBox::Ok);
}

void qtserterm::on_actionAboutQt_triggered()
{
    QApplication::aboutQt();
}

void qtserterm::on_btnPortScan_clicked()
{
    port_scan();
}

void qtserterm::on_btnPortOpen_clicked()
{
    if(serport->isOpen()){
        port_close();
    }
    else{
        port_open();
    }
}

void qtserterm::on_cmbPort_currentIndexChanged()
{
    port_set();
}

void qtserterm::on_cmbLocalEcho_currentIndexChanged(){
    if(ui->cmbLocalEcho->currentIndex()==0){
        isLocalEcho = false;
    }
    else{
        isLocalEcho = true;
    }
}

void qtserterm::on_cmbShowEnd_currentIndexChanged(){
    if(ui->cmbShowEnd->currentIndex()==0){
        isShowEnd = false;
    }
    else{
        isShowEnd = true;
    }
}

