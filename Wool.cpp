//
// Created by Marius on 11/06/2023.
//

#include "Wool.h"
#include "TexturesLocations.h"

Wool::Wool(sf::Vector2f position) : GraphicElements(TexturesLocations::ASTEROID, position) {
    type = TYPE::Asteroid;
    speed = -200.f;
    lifetime = sf::seconds(10);
    acceleration = {speed, 0.f};
}

void Wool::update() {
    sprite.rotate(-1.f);
    GraphicElements::update();
}

void Wool::reactCollision(GraphicElements::TYPE type) {
    if (type == TYPE::Missile) {
        alive = false;
    }
}
