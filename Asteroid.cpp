//
// Created by Marius on 11/06/2023.
//

#include "Asteroid.h"
#include "TexturesLocations.h"

Asteroid::Asteroid(sf::Vector2f position) : GraphicElements(TexturesLocations::ASTEROID, position) {
    type = TYPE::Asteroid;
    speed = -200.f;
    lifetime = sf::seconds(10);
    acceleration = {speed, 0.f};
}

void Asteroid::update() {
    sprite.rotate(-1.f);
    GraphicElements::update();
}

void Asteroid::reactCollision(GraphicElements::TYPE type) {
    if (type == TYPE::Missile) {
        alive = false;
    }
}
