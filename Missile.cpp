//
// Created by Marius on 11/06/2023.
//

#include "Missile.h"
#include "TexturesLocations.h"

Missile::Missile(sf::Vector2f position) : GraphicElements(TexturesLocations::MISSILE, position) {
    speed = 300.f;
    acceleration = {speed, 0.f};
}

void Missile::update() {
    GraphicElements::update();
}
