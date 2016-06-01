#include "Font.h"

using namespace ME;

ResourceID Font::DEFAULT_FONT = 0;

Font::Font() {
    mType    = Resource::Type::FONT;
}

bool Font::loadFromFile(const std::string& fileName){
    if (!mFont.loadFromFile(ENGINE_DEFAULTS::ASSETS_PATH + fileName)) {
        LOG << Log::WARNING << "[Font::loadFromFile] Error while opening font: "
            << ENGINE_DEFAULTS::ASSETS_PATH + fileName
            << std::endl;
    } else {
        mIsValid = true;
    }

    return mIsValid;
}

bool Font::loadFromMemory(MEByte* bytes, std::size_t size){
    if (!mFont.loadFromMemory(static_cast<void*>(bytes), size)) {
        LOG << Log::WARNING << "[Font::loadFromMemory] Error while opening font from memory"
            << std::endl;
    } else {
        mIsValid = true;
    }

    return mIsValid;
}

sf::Font* Font::getResourcePointer() {
    return &mFont;
}

int Font::getLineSpacing(const unsigned int& size) {
    return mFont.getLineSpacing(size);
}
