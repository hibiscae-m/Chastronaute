//
// Created by Marius on 11/06/2023.
//

#include "Missile.h"
#include "TexturesLocations.h"

Missile::Missile(sf::Vector2f position) : GraphicElements(TexturesLocations::MISSILE, position) {
    speed = 900.f;
    lifetime = sf::seconds(3);
    acceleration = {speed, 0.f};
}
