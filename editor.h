#ifndef EDITOR_H
#define EDITOR_H
#include "Config.h"
#include "Debugger.h"
#include "TO.h"
#include "assetsmanager.h"
#include "RenderWindow.h"
#include "texthandle.h"
#include "gui.h"



namespace ME{

class Editor
{
public:
    static Editor *getInstance();
    void setEditMode(const bool &mode);
    void createMap(const std::string &name,const std::string &fileName);
    MapFile *openMap(const std::string &name);
    void render(sf::RenderWindow &mWindow);
protected:
    bool editModeEnable;
    bool mapOpen;
    bool assetsLoaded;
    bool debugNotOpenMap;
    std::string path;
    bool showBox;

    std::map<std::string,std::string> tilesNames;
    std::string curentMouseTileEnable;
    Coord curentCoordTileEnable;
    float curentRotateEnable,curentScaleEnable;
    int curentLayerEnable;



    Editor();
    void handleEvent(sf::RenderWindow &mWindow);
    Tile mTiles[10000];
    int Index;
    MapFile mMap;
    Debugger *mDebugger;
    AssetsManager *mAssets;
    RenderWindow* mRender;
};


}
#endif // EDITOR_H
