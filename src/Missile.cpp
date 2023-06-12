//
// Created by Marius on 11/06/2023.
//

#include "../include/Missile.h"
#include "../include/TexturesLocations.h"
#include "../include/GameManager.h"

Missile::Missile(sf::Vector2f position) : GraphicElements(TexturesLocations::MISSILE, position) {
    type = TYPE::Missile;
    speed = 900.f;
    lifetime = sf::seconds(3);
    acceleration = {speed, 0.f};
}

void Missile::reactCollision(GraphicElements::TYPE type) {
    if (type == TYPE::Asteroid) {
        GameManager::add(TYPE::Impact, sprite.getPosition());
        alive = false;
    }
}
