#include "LoadingScreen.h"
#include "Engine/MedievalEngine.h"

using namespace ME;

LoadingScreen::LoadingScreen(MedievalEngine* engine) {
    mEngine = engine;
    LOG << Log::VERBOSE << "[LoadingScreen::LoadingScreen]" << std::endl;
}

void LoadingScreen::init() {
    LOG << Log::VERBOSE << "[LoadingScreen::init]" << std::endl;

    Vect2i winSize         = mEngine->getWindow()->getSize();
    ResourceManager* mAssets = mEngine->getAssetsManager();


    spriteMario                 = mAssets->createSpriteAnimation();
    SpriteAnimation* marioSptAn = mAssets->getAsset<SpriteAnimation>(spriteMario);

    ResourceID idAn1 = mAssets->loadTexture("/animation/1.png");
    ResourceID idAn2 = mAssets->loadTexture("/animation/2.png");
    ResourceID idAn3 = mAssets->loadTexture("/animation/3.png");
    ResourceID idAn4 = mAssets->loadTexture("/animation/4.png");

    marioSptAn->addFrame(100, mAssets->getAsset<Texture>(idAn1));
    marioSptAn->addFrame(100, mAssets->getAsset<Texture>(idAn2));
    marioSptAn->addFrame(100, mAssets->getAsset<Texture>(idAn3));
    marioSptAn->addFrame(100, mAssets->getAsset<Texture>(idAn4));

    marioSptAn->setPosition(Vect2f((winSize.x/2)-(marioSptAn->getSize().x/2),
    winSize.y-marioSptAn->getSize().y));


    idBackground            = mAssets->createShape(winSize);
    Shape* mShapeBackground = mAssets->getAsset<Shape>(idBackground);

    mShapeBackground->setColor(Color::DODGER_BLUE);

    mEngine->getGUI()->addObject("engine_title", new TextObject(L"MedievalEngine", 72));
    mEngine->getGUI()->addObject("button_iniciar", new ButtonObject(L"Iniciar", Vect2f(mEngine->getWindow()->getSize().x - 150.f, mEngine->getWindow()->getSize().y - 200.f)));
    mEngine->getGUI()->addObject("button_opcoes", new ButtonObject(L"Opções", Vect2f(mEngine->getWindow()->getSize().x - 150.f, mEngine->getWindow()->getSize().y - 160.f)));
    mEngine->getGUI()->addObject("button_sair", new ButtonObject(L"Sair", Vect2f(mEngine->getWindow()->getSize().x - 150.f, mEngine->getWindow()->getSize().y - 120.f)));
    mEngine->getGUI()->addObject("debugger_info", new TextScrollListObject());

    mEngine->getGUI()->getObject<TextScrollListObject>("debugger_info")->addText(L"teste");
    mEngine->getGUI()->getObject<TextScrollListObject>("debugger_info")->addText(L"teste segunda linha");

    c =0;
}

void LoadingScreen::onEnable(Window &window) {
    setCurrentStatus(GAME_STATUS::ON_PLAYING);
}

void LoadingScreen::onDisable(Window &window) {

}

void LoadingScreen::onPlaying(Window &window) {
    window.draw(mEngine->getAssetsManager()->getAsset<Shape>(idBackground));
    window.draw(mEngine->getAssetsManager()->getAsset<Shape>(spriteMario));

}

void LoadingScreen::update() {

}

void LoadingScreen::handleEvents(Event& evt) {
    if(evt.type == Event::Closed) {
        mEngine->getWindow()->close();
    }



    if (evt.type == Event::KeyPressed ) {

        if (evt.key.code == Keyboard::Space) {
            std::string tmp("teste outra linha" + Data2::int_to_str(c++));
            mEngine->getGUI()->getObject<TextScrollListObject>("debugger_info")->addText(Data2::str_to_wstr(tmp));
        }

        if (evt.key.code == Keyboard::A) {
            mEngine->getGUI()->getObject<TextScrollListObject>("debugger_info")->setTextAutoScroll(true);
        }


        if (evt.key.code == Keyboard::F) {
            mEngine->getAssetsManager()->getAsset<Shape>(spriteMario)->addEffect(new Fade(500, Fade::FADEIN));
        }

        if (evt.key.code == Keyboard::D) {
            mEngine->getAssetsManager()->getAsset<Shape>(spriteMario)->addEffect(new Strobe(500, 0.5));
        }


    }
}



