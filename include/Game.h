//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_GAME_H
#define CHASTRONAUTE_GAME_H

#include "SFML/Graphics.hpp"
#include "HomeScreen.h"

class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void display();
    sf::RenderWindow window;
    HomeScreen home_screen;
    sf::Sprite background;
    std::string_view background_texture = ResourcesLocations::Textures::BACKGROUND;
};


#endif //CHASTRONAUTE_GAME_H
