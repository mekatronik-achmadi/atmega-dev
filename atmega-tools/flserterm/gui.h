#ifndef GUI_H
#define GUI_H

#include <iostream>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/fl_ask.H>

class Gui
{
public:
    Gui ();

    Fl_Window *mainWnd;
    Fl_Button *btnOpen;
    Fl_Button *btnSend;

    Fl_Input *txtBaud;
    Fl_Input *txtSend;
    Fl_Input *txtPort;

    Fl_Text_Display *txtOutput;
    Fl_Text_Buffer *bufOutput;

    Fl_Box *statusBar;

    void show(int argc, char* argv[]);
    void close(void);
    void status(std::string msg);
};

#endif
