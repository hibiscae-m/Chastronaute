//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_GAMEMANAGER_H
#define CHASTRONAUTE_GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include "GraphicElements.h"

class GameManager {
public:
    GameManager() = default;
    void update();
    void draw(sf::RenderWindow& window);
    void add(GraphicElements::TYPE type);
private:
    std::vector<std::unique_ptr<GraphicElements>> elements{};
    std::vector<std::unique_ptr<GraphicElements>> buffer{};
};


#endif //CHASTRONAUTE_GAMEMANAGER_H
