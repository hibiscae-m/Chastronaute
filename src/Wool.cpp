//
// Created by Marius on 11/06/2023.
//

#include "../include/Wool.h"
#include "../include/TexturesLocations.h"
#include "../include/WindowSettings.h"
#include <random>

Wool::Wool() : GraphicElements() {
    auto generator = std::random_device();
    auto window_height_distribution = std::uniform_real_distribution<float>(0, WindowSettings::WINDOW_HEIGHT);
    auto random_height_position = window_height_distribution(generator);
    initializeSprite(TexturesLocations::WOOL, {WindowSettings::WINDOW_WIDTH, random_height_position});
    type = TYPE::Enemies;
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
