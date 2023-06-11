//
// Created by Marius on 11/06/2023.
//

#include "Missile.h"
#include "TexturesLocations.h"

Missile::Missile(sf::Vector2f position) : GraphicElements(TexturesLocations::MISSILE, position) {
    type = TYPE::Missile;
    speed = 900.f;
    lifetime = sf::seconds(3);
    acceleration = {speed, 0.f};
}

void Missile::reactCollision(GraphicElements::TYPE type) {
    if (type == TYPE::Asteroid) {
        alive = false;
    }
}
