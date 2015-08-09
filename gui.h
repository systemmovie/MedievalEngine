#ifndef GUI_H
#define GUI_H
#include "config.h"
#include "renderwindow.h"
#include "assetsmanager.h"
#include "texthandle.h"

namespace ME{

class GUI
{

public:
    static GUI* getInstace();
    std::string messageBox(const std::string &title,const std::string &message);
protected:
    GUI();
    std::map<std::string,std::string> mMessagesBox;
    std::map<std::string,bool> mMessagesBoxOK;
};

}

#endif // GUI_H
