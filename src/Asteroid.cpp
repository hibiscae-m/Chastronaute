//
// Created by Marius on 11/06/2023.
//

#include "../include/Asteroid.h"
#include "../include/TexturesLocations.h"
#include "../include/WindowSettings.h"
#include <random>

Asteroid::Asteroid() : GraphicElements() {
    auto generator = std::random_device();

    auto window_height_distribution = std::uniform_real_distribution<float>(0, WindowSettings::WINDOW_HEIGHT);
    auto random_height_position = window_height_distribution(generator);

    auto texture_distribution = std::uniform_int_distribution(0, 1);
    auto random_texture_distribution = texture_distribution(generator);

    std::string_view texture;
    switch (random_texture_distribution) {
        case 0:
            texture = TexturesLocations::ASTEROID;
            break;
        case 1:
            texture = TexturesLocations::WOOL;
            break;
        default:
            break;
    }
    initializeSprite(texture,
                     {WindowSettings::WINDOW_WIDTH, random_height_position});
    sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width,
                       sprite.getPosition().y);

    type = TYPE::Enemies;
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
