//
// Created by Marius on 11/06/2023.
//

#include "Player.h"
#include "TexturesLocations.h"
#include "WindowSettings.h"
#include "GameManager.h"

Player::Player(sf::Vector2f position) :
    GraphicElements(TexturesLocations::CHASTRONAUTE, position)
{
    sprite.setScale(0.3, 0.3);
    speed = 70.f;
}

void Player::update() {
    handlePlayerInputs();
    acceleration -= acceleration * FRICTION * WindowSettings::TIME_PER_FRAME;
    sprite.move(acceleration * WindowSettings::TIME_PER_FRAME);
    sprite.setRotation(static_cast<float>(acceleration.y * 0.03));
}

void Player::handlePlayerInputs() {
    { // Movement
        sf::Vector2f movement = {0.f, 0.f};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            movement += {0.f, -speed };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            movement += {0.f, speed };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            movement += {-speed, 0.f };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            movement += {speed, 0.f };
        acceleration += movement;
    }
    { // Shooting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            shoot();
    }
}

void Player::shoot() {
    if (time_since_last_shoot.getElapsedTime() > shoot_cooldown) {
        time_since_last_shoot.restart();
        GameManager::add(TYPE::Missile, sprite.getPosition());
    }
}
