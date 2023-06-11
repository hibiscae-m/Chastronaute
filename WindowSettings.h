//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_WINDOWSETTINGS_H
#define CHASTRONAUTE_WINDOWSETTINGS_H

#include <string_view>

class WindowSettings {
public:
    WindowSettings() = delete;
    static constexpr int WINDOW_WIDTH = 1600;
    static constexpr int WINDOW_HEIGHT = 1200;
    static constexpr float TIME_PER_FRAME = 1.f/60.f;
    static constexpr std::string_view WINDOW_NAME = "Chastronaute!";
};


#endif //CHASTRONAUTE_WINDOWSETTINGS_H
