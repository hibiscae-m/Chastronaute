//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_GAMEMANAGER_H
#define CHASTRONAUTE_GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include "GraphicElements.h"

static std::vector<std::unique_ptr<GraphicElements>> elements{};
static std::vector<std::unique_ptr<GraphicElements>> buffer{};

static sf::Clock time_since_last_asteroid;
static sf::Time asteroid_cooldown = sf::milliseconds(500);

class GameManager {
public:
    GameManager() = delete;
    static void update();
    static void draw(sf::RenderWindow& window);
    static void add(GraphicElements::TYPE type, sf::Vector2f position);
private:
    static void checkCollision();
    static void spawn();
};


#endif //CHASTRONAUTE_GAMEMANAGER_H
