#include "gui.h"

static void onBtnOpen(Fl_Widget *w, void *p){
    ((Gui*)p)->portOpen();
}

static void onBtnSend(Fl_Widget *w, void *p){
    std::cout <<  ((Fl_Input*)p)->value() << std::endl;
}

Gui::Gui() {
    mainWnd = new Fl_Window(380,500, "FLTK Serial");
    btnOpen = new Fl_Button(5,10,85,20,"Open");
    btnSend = new Fl_Button(95,10,85,20,"Send");
    txtBaud = new Fl_Input(5,35,175,20);
    txtSend = new Fl_Input(185,10,190,20);
    txtPort = new Fl_Input(185,35,190,20);
    txtOutput = new Fl_Text_Display(5, 65,370,400);
    statusBar = new Fl_Box(5,475,370,20);

    txtBaud->insert("9600",0);
    txtPort->insert("/dev/ttyS0");

    bufOutput = new Fl_Text_Buffer();
    txtOutput->buffer(bufOutput);
    bufOutput->text("Received Data");

    statusBar->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    status("Ready");

    btnSend->callback(onBtnSend,txtSend);
    btnOpen->callback(onBtnOpen,this);

    sttOpen = false;
#ifdef ceWINDOWS
	comPort = new ceSerial("\\\\.\\COM1",9600,8,'N',1); // Windows
#else
	comPort = new ceSerial("/dev/ttyS0",9600,8,'N',1); // Linux
#endif

    Fl::scheme("none");
    mainWnd->end();
}

void Gui::portOpen(){
    if(sttOpen){
        if(comPort->IsOpened()) {
            comPort->Close();
            btnOpen->label("Open");
            sttOpen = false;

            status("Close Port: " + std::string(txtPort->value()));
        }
    }
    else {
        if(comPort->IsOpened()) return;

        comPort->SetPort(std::string(txtPort->value()));
        comPort->SetBaudRate(std::stoul(txtBaud->value()));

        if(comPort->Open()){
            btnOpen->label("Close");
            sttOpen = true;
            status("Open Port: " + std::string(txtPort->value()));
        }
        else {
            btnOpen->label("Open");
            sttOpen = false;
            status("Open Failed: " + std::string(txtPort->value()));
        }
    }
}

void Gui::status(std::string msg){
    statusBar->copy_label(msg.c_str());
    statusBar->redraw();
}

void Gui::show(int argc, char* argv[]){
    mainWnd->show(argc,argv);
}

void Gui::close(){
    mainWnd->hide();
}

