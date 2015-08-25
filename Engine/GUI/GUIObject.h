#ifndef GUIOBJECT_H
#define GUIOBJECT_H
#include <LogInc.h>
#include <Resources/ResourceManager.h>
#include <Graphics/Drawable.h>
#include <Graphics/Window.h>
#include <Events/Event.h>


namespace ME {

class GUIObject {
public:
    GUIObject();
    void registerAssetsManager(ResourceManager* assets);

    virtual void init() = 0;
    virtual void draw(Window& window) = 0;
    virtual void update() = 0;
    virtual void handleEvents(Event evt, Window& window) = 0;

    virtual void show();
    virtual void hide();

    virtual void onMouseOver(Event evt, Window& window);
    virtual void onMouseOut(Event evt, Window& window);

    virtual void onClick(Event evt, Window& window);

    virtual void setPosition(const Vect2f& pos);
    virtual Vect2f getPosition();

    virtual Vect2f getSize() = 0;

    virtual void setOpacity(const float& opacity);
    virtual float getOpacity();

    virtual void setColor(const Color& color);
    virtual Color getColor();

    virtual Area getLocalBounds() = 0;
    virtual Area getGlobalBounds() = 0;

    bool isVisible();
    bool isActive();
    bool isColorGradient();

    std::string getType();
protected:
    std::string mType;
    bool mIsVisible;
    bool mIsActive;
    bool mHasColorGradient;
    Vect2f mPos;
    float mOpacity;
    Color mColor;
    ColorGradient mColorGradient;
    ResourceManager* mAssets;
    ResourceID mDefaultFontID;
};

}

#endif // GUIOBJECT_H