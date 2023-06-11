//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_GAME_H
#define CHASTRONAUTE_GAME_H

#include <SFML/Graphics.hpp>
#include "GameManager.h"

class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void display();
    sf::RenderWindow window;
    GameManager game_manager;
};


#endif //CHASTRONAUTE_GAME_H
