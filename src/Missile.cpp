//
// Created by Marius on 11/06/2023.
//

#include "../include/Missile.h"
#include "../include/TexturesLocations.h"
#include "../include/GameManager.h"

Missile::Missile(sf::Vector2f position) : GraphicElements() {
    initializeSprite(TexturesLocations::MISSILE, position);
    type = TYPE::Missile;
    speed = 900.f;
    lifetime = sf::seconds(3);
    acceleration = {speed, 0.f};
}

void Missile::reactCollision(GraphicElements::TYPE type) {
    if (type == TYPE::Enemies) {
        hitbox_active = false;
        destruction_delay_clock.restart();
    }
}

void Missile::update() {
    if (!hitbox_active) {
        if (destruction_delay_clock.getElapsedTime() > destruction_delay_timer) {
            GameManager::add(TYPE::Impact, sprite.getPosition());
            alive = false;
        }
    }
    GraphicElements::update();
}
