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
    endLine = "";

    tmrReq = new QTimer(this);
    connect(tmrReq,SIGNAL(timeout()),this,SLOT(request_data()));
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

void qtserterm::app_delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
    while (QTime::currentTime()<dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    };
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

void qtserterm::request_data()
{
    if(!serport->isOpen()) return;

    QString reqString = ui->txtDataSend->text();
    reqString += endLine;

    QByteArray reqBytes = reqString.toUtf8();
    serport->write(reqBytes);

    int finishWait = ui->txtSendWait->text().toInt();
    if(finishWait>0) app_delay(finishWait);
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

void qtserterm::on_btnClear_clicked()
{
    ui->txtSerTerm->clear();
}

void qtserterm::on_btnStringSend_clicked()
{
    request_data();
}

void qtserterm::on_btnFilePath_clicked()
{
    dumpFile = QFileDialog::getSaveFileName(this,"Dump File Path","dumpfile.txt","text (*.txt)");

    if(dumpFile.isEmpty()) return;
    ui->txtFilePath->setText(dumpFile);
}

void qtserterm::on_btnFileSave_clicked()
{
    QFile dumpText(dumpFile);
    dumpText.open(QIODevice::WriteOnly | QFile::Truncate | QIODevice::Text);

    QTextStream out(&dumpText);
    out << ui->txtSerTerm->toPlainText() << "\r\n";

    dumpText.flush();
    dumpText.close();
}

void qtserterm::on_btnAutoStart_clicked()
{
    int intervalReq = ui->txtInterval->text().toInt();

    if(intervalReq<10){
        ui->sttbar->showMessage("Interval must be 10ms or more");
        return;
    }

    if(tmrReq->isActive()){
        tmrReq->stop();
        ui->btnAutoStart->setText("Auto Send Start");
        ui->sttbar->showMessage("Auto Send Stopped");
    }
    else{
        tmrReq->start(intervalReq);
        ui->btnAutoStart->setText("Auto Send Stop");
        ui->sttbar->showMessage("Auto Send Started");
    }
}

void qtserterm::on_actionPlotter_triggered()
{
    QStringList appargs = {""};
    port_close();

    if(QFile::exists("/bin/serialplot")){
        QProcess::startDetached("/bin/serialplot",appargs);
    }
    else if(QFile::exists("/usr/bin/serialplot")){
        QProcess::startDetached("/usr/bin/serialplot",appargs);
    }
    else{
        ui->sttbar->showMessage("No Serial Plot program found");
    }
}

void qtserterm::on_actionPortInfo_triggered()
{
    QString strInfo = "";

    const auto serialPortInfos = QSerialPortInfo::availablePorts();

    for(const QSerialPortInfo &portInfo : serialPortInfos){
        strInfo += "\n";
        strInfo +=  "Port\t: " + portInfo.portName() + "\n";
        strInfo +=  "Location\t: " + portInfo.systemLocation() + "\n";
        strInfo +=  "Description\t: " + portInfo.description() + "\n";
        strInfo +=  "Vendor ID\t: ";
        strInfo +=  (portInfo.hasVendorIdentifier()
         ? QByteArray::number(portInfo.vendorIdentifier(), 16)
         : QByteArray()) + "\n";
        strInfo +=  "Product ID\t: ";
        strInfo +=  (portInfo.hasProductIdentifier()
         ? QByteArray::number(portInfo.productIdentifier(), 16)
         : QByteArray());

        strInfo += "\n\n";
    }

    QMessageBox::information(this,
            "Serial Port Info",
            strInfo,
            QMessageBox::Ok);
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

void qtserterm::on_cmbLineEnd_currentIndexChanged(){
    int idx = ui->cmbLineEnd->currentIndex();

    switch(idx) {
        case 0: endLine = "";break;
        case 1: endLine = "\r";break;
        case 2: endLine = "\n";break;
        case 3: endLine = "\r\n";break;
    }
}

