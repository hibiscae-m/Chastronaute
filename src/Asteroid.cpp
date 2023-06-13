//
// Created by Marius on 11/06/2023.
//

#include "../include/Asteroid.h"
#include "../include/TexturesLocations.h"
#include "../include/WindowSettings.h"
#include <random>

Asteroid::Asteroid() : Enemies() {
    auto generator = std::random_device();

    auto window_height_distribution = std::uniform_real_distribution<float>(0, WindowSettings::WINDOW_HEIGHT);
    auto random_height_position = window_height_distribution(generator);

    auto texture_distribution = std::uniform_int_distribution(0, 2);
    enum ASTEROID_TYPE { Asteroid, SuperAsteroid, Wool };
    auto random_texture_distribution = texture_distribution(generator);

    switch (random_texture_distribution) {
        case ASTEROID_TYPE::Asteroid:
            initializeSprite(TexturesLocations::ASTEROID);
            break;
        case ASTEROID_TYPE::SuperAsteroid:
            initializeSprite(TexturesLocations::OVNI);
            resistant = true;
            break;
        case ASTEROID_TYPE::Wool:
            initializeSprite(TexturesLocations::WOOL);
            break;
        default:
            break;
    }
    sprite.setPosition(WindowSettings::WINDOW_WIDTH + sprite.getGlobalBounds().width,
                       random_height_position);

    lives = 2;
    speed = -200.f;
    lifetime = sf::seconds(10);
    acceleration = {speed, 0.f};
}

void Asteroid::update() {
    sprite.rotate(-1.f);
    Enemies::update();
}
