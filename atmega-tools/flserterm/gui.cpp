#include "gui.h"

Gui::Gui() {
    mainWnd = new Fl_Window(380,500, "FLTK Serial");
    btnOpen = new Fl_Button(5,10,85,20,"Open");
    btnOpen = new Fl_Button(95,10,85,20,"Send");
    txtBaud = new Fl_Input(5,35,175,20);
    txtSend = new Fl_Input(185,10,190,20);
    txtPort = new Fl_Input(185,35,190,20);
    txtOutput = new Fl_Text_Display(5, 65,370,400);
    txtStatus = new Fl_Text_Display(5,475,370,20);

    txtBaud->insert("9600");
    txtSend->insert("test");
    txtPort->insert("/dev/ttyUSB0");

    mainWnd->end();

    Fl::scheme("none");
}

void Gui::show(int argc, char* argv[]){
    mainWnd->show(argc,argv);
}

void Gui::close(){
    mainWnd->hide();
}
