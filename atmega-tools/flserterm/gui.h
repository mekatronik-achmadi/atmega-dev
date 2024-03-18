#ifndef GUI_H
#define GUI_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Pack.H>

class Gui
{
public:
    Gui ();

    Fl_Window *mainWnd;
    Fl_Pack *mainFrm;

    void show(int argc, char* argv[]);
    void close(void);

private:
    /* data */
};

#endif
