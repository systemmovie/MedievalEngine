#include "ButtonWidget.h"

using namespace ME;

ButtonWidget::ButtonWidget(const sf::String& text, Vect2f pos,  ResourceID fontID) {
    mType   = "ButtonWidget";
    mText   = text;
    mPos    = pos;
    mFontID = fontID;
}

void ButtonWidget::init() {
    if (mFontID == 0) {
        mTextID  = mResources->createText(mText, 22, mDefaultFontID);
    }else {
        mTextID  = mResources->createText(mText, 22, mFontID);
    }
    mTextRef = mResources->getResource<Text>(mTextID);

    float width = 80.0f;

    if (mTextRef->getSize().x > 75.f) {
        width = mTextRef->getSize().x + 20.0f;
    }

    mShapeID  = mResources->createShape(Vect2f(width, 30.0f), Color(0, 0, 0), mPos);
    mShapeRef = mResources->getResource<Shape>(mShapeID);
    mShapeRef->setColor(ColorGradient(Color::BUTTON_C1, Color::BUTTON_C2));
    mShapeRef->setRadius(2.0f);

    mTextRef->setOriginCenter();
    mTextRef->setPosition(
                Vect2f(mShapeRef->getPosition().x+(mShapeRef->getSize().x/2),
                       mShapeRef->getPosition().y+(mTextRef->getSize().y/2)));

    mTextRef->setColor(Color::BLACK);
}

void ButtonWidget::draw(Window& window) {
    // TODO(Pedro): If its visible
    window.draw(mShapeRef);
    window.draw(mTextRef);
}

void ButtonWidget::update() {

}

void ButtonWidget::handleEvents(Event evt) {
    // TODO(Pedro): If its active
}

void ButtonWidget::setPosition(const Vect2f& pos) {
    mShapeRef->setPosition(pos);
    mTextRef->setPosition(
                Vect2f(mShapeRef->getPosition().x+(mShapeRef->getSize().x/2),
                       mShapeRef->getPosition().y+(mTextRef->getSize().y/2)));
}

Vect2f ButtonWidget::getPosition() {
    return mShapeRef->getPosition();
}

Vect2f ButtonWidget::getSize() {
    return mShapeRef->getSize();
}

void ButtonWidget::setOpacity(const float& opacity) {
    mShapeRef->setOpacity(opacity);
    mTextRef->setOpacity(opacity);
}

float ButtonWidget::getOpacity() {
    return mShapeRef->getOpacity();
}

void ButtonWidget::setColor(const Color& color) {
    mShapeRef->setColor(color);
}

Color ButtonWidget::getColor() {
    return mShapeRef->getColor();
}

void ButtonWidget::setColor(const ColorGradient& color) {
    mShapeRef->setColor(color);
}

ColorGradient ButtonWidget::getColorGradient() {
    return mShapeRef->getColorGradient();
}

bool ButtonWidget::isColorGradient() {
    return mShapeRef->isColorGradient();
}

void ButtonWidget::setTextColor(const Color& color) {
    mTextRef->setColor(color);
}

Color ButtonWidget::getTextColor() {
    return mTextRef->getColor();
}

Area ButtonWidget::getLocalBounds() {
    return mShapeRef->getLocalBounds();
}

Area ButtonWidget::getGlobalBounds() {
    return mShapeRef->getGlobalBounds();
}