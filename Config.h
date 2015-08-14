#ifndef ENGINE_CONFIG_H
#define ENGINE_CONFIG_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <fstream>

namespace ME {

namespace ENGINE_DEFAULTS {

    // GLOBAL
    const std::string ENGINE_NAME = "Medieval Engine";
    const float ENGINE_VERSION    = 1.2f;

    const int WIDTH_WINDOW          = 700;
    const int HEIGHT_WINDOW         = 500;
    const int BITS_PER_PIXEL_WINDOW = 32;
    const bool FULLSCREEN_WINDOW    = false;
    const int FRAME_LIMIT           = 60;
    const bool VSYNC                = true;
    const std::string CONFIG_FILE   = "config.cfg";
}

const bool _LOG_WRITE_TO_FILE    = false;
const std::string _LOG_FILE_NAME = "output.log";
const bool _LOG_LOG_TIME         = false;


}

#endif // ENGINE_CONFIG_H
