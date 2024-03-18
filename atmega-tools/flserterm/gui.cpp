#include "gui.h"

Gui::Gui() {
    mainWnd = new Fl_Window(400,300, "FLTK Serial");
    mainFrm = new Fl_Pack(0,0,10,10,"Frame");

    mainFrm->end();

    mainWnd->end();
}

void Gui::show(int argc, char* argv[]){
    mainWnd->show(argc,argv);
}

void Gui::close(){
    mainWnd->hide();
}
