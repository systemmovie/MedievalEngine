#include "MenuScreen.h"
#include "Engine/MedievalEngine.h"

using namespace ME;

MenuScreen::MenuScreen(MedievalEngine* engine) {
    mEngine = engine;
    LOG << Log::VERBOSE << "[MenuScreen::MenuScreen]" << std::endl;
}

void MenuScreen::create() {
    LOG << Log::VERBOSE << "[MenuScreen::create]" << std::endl;

    ResourceID bgTXT = mResources->loadTexture("menu/bg_menu.png");
    bgID             = mResources->createSprite(bgTXT);

    ResourceID bgOptionsTXT = mResources->loadTexture("menu/bg_options.png");
    bgOptionsID             = mResources->createSprite(bgOptionsTXT);

    ResourceID logoTXT = mResources->loadTexture("menu/title_menu.png");
    logoID             = mResources->createSprite(logoTXT);

    Sprite* logoSPT      = mResources->getResource<Sprite>(logoID);
    Sprite* bgSPT        = mResources->getResource<Sprite>(bgID);
    Sprite* bgOptionsSPT = mResources->getResource<Sprite>(bgOptionsID);

    // Set the background image to fullScreen
    Window::fullScreen(bgSPT);
    // Set the menu options background to the relative size
    Window::setRelative(bgOptionsSPT);
    // Do the same for the logo
    Window::setRelative(logoSPT);
    // Set the menu options background to the right center position
    Window::setPosition(bgOptionsSPT, Window::Position::Right, Window::Position::Center);
    // Set 11% of padding on top and bottom
    logoSPT->setPadding(0.11f, Padding::Top);
    logoSPT->setPadding(0.11f, Padding::Bottom);
    // Set the logo to the center top of the menu options background
    Window::setPosition(logoSPT, Window::Position::Center, Window::Position::Top, bgOptionsSPT);


    int fontSize = Window::fontSize(0.5f);

    // Create the new Game button Text Widget
    mNewGame = TextWidgetPtr(new TextWidget(Strings::get("new_game"), fontSize, Vect2f(0.f, 0.f), mEngine->gameFontID));
    // Add the Widget to the GUI
    mGUI.addWidget("new_game_btn", mNewGame);

    // Set 25% padding top of the first menu Object
    mNewGame->setPadding(0.25f, Padding::Top);
    mNewGame->setColor(Color::BLACK);
    // And We finally set the position of the Widget
    Window::setPosition(mNewGame, Window::Position::Center, Window::Position::Top, bgOptionsSPT);



    // Create the new Game button Text Widget
    mContinue = TextWidgetPtr(new TextWidget(Strings::get("continue"), fontSize, Vect2f(0.f, 0.f), mEngine->gameFontID));
    // Add the Widget to the GUI
    mGUI.addWidget("continue_btn", mContinue);

    // Set 25% padding top of the first menu Object
    mContinue->setPadding(0.35f, Padding::Top);
    mContinue->setColor(Color::BLACK);
    // And We finally set the position of the Widget
    Window::setPosition(mContinue, Window::Position::Center, Window::Position::Top, bgOptionsSPT);



    // Create the new Game button Text Widget
    mMultiplayer = TextWidgetPtr(new TextWidget(Strings::get("multiplayer"), fontSize, Vect2f(0.f, 0.f), mEngine->gameFontID));
    // Add the Widget to the GUI
    mGUI.addWidget("multiplayer_btn", mMultiplayer);

    // Set 25% padding top of the first menu Object
    mMultiplayer->setPadding(0.45f, Padding::Top);
    mMultiplayer->setColor(Color::BLACK);
    // And We finally set the position of the Widget
    Window::setPosition(mMultiplayer, Window::Position::Center, Window::Position::Top, bgOptionsSPT);



    // Create the new Game button Text Widget
    mOptions = TextWidgetPtr(new TextWidget(Strings::get("options"), fontSize, Vect2f(0.f, 0.f), mEngine->gameFontID));
    // Add the Widget to the GUI
    mGUI.addWidget("options_btn", mOptions);

    // Set 25% padding top of the first menu Object
    mOptions->setPadding(0.55f, Padding::Top);
    mOptions->setColor(Color::BLACK);
    // And We finally set the position of the Widget
    Window::setPosition(mOptions, Window::Position::Center, Window::Position::Top, bgOptionsSPT);



    // Create the new Game button Text Widget
    mExit = TextWidgetPtr(new TextWidget(Strings::get("exit"), fontSize, Vect2f(0.f, 0.f), mEngine->gameFontID));
    // Add the Widget to the GUI
    mGUI.addWidget("exit_btn", mExit);

    // Set 25% padding top of the first menu Object
    mExit->setPadding(0.65f, Padding::Top);
    mExit->setColor(Color::BLACK);
    // And We finally set the position of the Widget
    Window::setPosition(mExit, Window::Position::Center, Window::Position::Top, bgOptionsSPT);

    GUIEventPtr mExitEvent = GUIEventPtr(new GUIEvent());

    mExitEvent->setOnClick([this](Widget* widget) {
        // TODO(Pedro): Cleanup everything on the engine close event
        // including all the GUI releated stuff and game state
        // maybe do some exit animation
        this->mEngine->close();
    });

    mExitEvent->setOnMouseOut([this](Widget* widget) {
        mExit->setColor(Color::BLACK);
    });

    mExitEvent->setOnMouseOver([this](Widget* widget) {
        mExit->setColor(Color::BROWN);
    });

    mExit->addEventHandle(mExitEvent);

}

void MenuScreen::init() {
    LOG << Log::VERBOSE << "[MenuScreen::init]" << std::endl;

    mFadeTime = 200;
    mResources->getResource<Sprite>(bgID)->addEffect(new Fade(mFadeTime, Fade::Type::FADEIN));
    mResources->getResource<Sprite>(logoID)->addEffect(new Fade(mFadeTime, Fade::Type::FADEIN));
    mResources->getResource<Sprite>(bgOptionsID)->addEffect(new Fade(mFadeTime, Fade::Type::FADEIN, [this] (void) {
        this->setCurrentStatus(GAME_STATUS::ON_PLAYING);
    }));
}

void MenuScreen::onEnable(Window &window) {
    window.draw(mResources->getResource<Sprite>(bgID));
    window.draw(mResources->getResource<Sprite>(bgOptionsID));
    window.draw(mResources->getResource<Sprite>(logoID));
}

void MenuScreen::onDisable(Window &window) {

}

void MenuScreen::onPlaying(Window &window) {
    window.draw(mResources->getResource<Sprite>(bgID));
    window.draw(mResources->getResource<Sprite>(bgOptionsID));
    window.draw(mResources->getResource<Sprite>(logoID));
    window.draw(&mGUI);
}

void MenuScreen::update() {
    mGUI.update();
}

void MenuScreen::handleEvents(Event& evt) {
    if(evt.type == Event::Closed) {
        mEngine->getWindow()->close();
    }
    mGUI.handleEvents(evt);
}


MenuScreen::~MenuScreen() {
    // TODO(pedro): Dealocate all the memory used

}
