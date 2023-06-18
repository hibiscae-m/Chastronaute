//
// Created by Marius on 11/06/2023.
//

#include "../include/Asteroid.h"
#include "../include/ResourcesLocations.h"
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
            initializeSprite(ResourcesLocations::Textures::ASTEROID);
            break;
        case ASTEROID_TYPE::SuperAsteroid:
            initializeSprite(ResourcesLocations::Textures::OVNI);
            resistant = true;
            break;
        case ASTEROID_TYPE::Wool:
            initializeSprite(ResourcesLocations::Textures::WOOL);
            break;
        default:
            break;
    }
    sprite.setPosition(WindowSettings::WINDOW_WIDTH + sprite.getGlobalBounds().width,
                       random_height_position);

    auto speed_distribution = std::uniform_real_distribution<float>(175, 225);
    auto scale_distribution = std::uniform_real_distribution<float>(sprite.getScale().x * 0.8f, sprite.getScale().x * 1.2f);
    float random_scale = scale_distribution(generator);

    lives = 2;
    speed = -(speed_distribution(generator));
    sprite.setScale(random_scale, random_scale);
    lifetime = sf::seconds(10);
    acceleration = {speed, 0.f};
}

void Asteroid::update() {
    sprite.rotate(-1.f);
    Enemies::update();
}
