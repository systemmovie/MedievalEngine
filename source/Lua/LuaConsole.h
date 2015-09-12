#ifndef LUACONSOLE_H
#define LUACONSOLE_H
#include "Lua/LuaAPI.h"
#include "Graphics/Window.h"
#include "Resources/ResourceManager.h"


namespace ME {

class MedievalEngine;

class LuaConsole : public LogObserver {
public:
    LuaConsole();

    void registerEngine(MedievalEngine* engine);

    void handleEvents(Event& evt);
    bool isVisible();
    void setVisible(bool visible);
    void draw(Window& window);

    void update(const sf::String& buffer);

private:
    bool mIsVisible;
    
    ResourceManager* mResources;
        
    // buffer for the text been typed
    sf::String mBuffer;
    // buffer for the output
    sf::String mBufferOutput;
    
    Text* mText;
    Text* mOutput;
    Shape* mBG;
    Shape* mLineEdit;

    float mLineHeight;
    int mNumberLines;
    
    Vect2i mWindowSize;
    Vect2i mConsoleSize;
    Vect2f mMargin;
    
    Color mBGColor;

    // scroll content
    bool mHasScrolled;
    int mStepScroll;

    // to the tab autocompletion
    sf::String cmd_check;

    // TODO(pedro): keep the cursor position 

    Clock mClockBlinkCursor;
    sf::String mCursor;
    sf::String mDefaultText;
    unsigned int mCusorBlinkTime;
};

}

#endif // LUACONSOLE_H
