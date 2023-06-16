//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_RESOURCESLOCATIONS_H
#define CHASTRONAUTE_RESOURCESLOCATIONS_H

#include <string_view>

namespace ResourcesLocations::Textures {
    static constexpr std::string_view CHASTRONAUTE = "../resources/textures/chastronaute.png"; // Image by catalyststuff on Freepik
    static constexpr std::string_view MISSILE = "../resources/textures/missile.png";
    static constexpr std::string_view ASTEROID = "../resources/textures/asteroid.png";
    static constexpr std::string_view OVNI = "../resources/textures/ovni.png";
    static constexpr std::string_view WOOL = "../resources/textures/wool.png";
    static constexpr std::string_view IMPACT = "../resources/textures/impact.png";
    static constexpr std::string_view CURSOR = "../resources/textures/cursor.png";
    static constexpr std::string_view TITLE = "../resources/textures/title.png";
    static constexpr std::string_view BACKGROUND = "../resources/textures/background.jpg";
}

namespace ResourcesLocations::Fonts {
    static constexpr std::string_view GIDDYUPSTD = "../resources/fonts/GiddyupStd.otf";
}


#endif //CHASTRONAUTE_RESOURCESLOCATIONS_H
