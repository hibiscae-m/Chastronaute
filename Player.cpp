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
    type = TYPE::Player;
    speed = 70.f;
}

void Player::update() {
    handlePlayerInputs();
    acceleration -= acceleration * FRICTION * WindowSettings::TIME_PER_FRAME;
    sprite.move(acceleration * WindowSettings::TIME_PER_FRAME);
    if (sprite.getPosition().y < sprite.getGlobalBounds().height / 2) {
        sprite.setPosition(sprite.getPosition().x, sprite.getGlobalBounds().height / 2);
    }
    if (sprite.getPosition().y > WindowSettings::WINDOW_HEIGHT - sprite.getGlobalBounds().height / 2) {
        sprite.setPosition(sprite.getPosition().x, WindowSettings::WINDOW_HEIGHT - sprite.getGlobalBounds().height / 2);
    }
    hitbox.setPosition(sprite.getPosition());
    sprite.setRotation(static_cast<float>(acceleration.y * 0.03));
}

void Player::handlePlayerInputs() {
    { // Movement
        sf::Vector2f movement = {0.f, 0.f};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            movement += {0.f, -speed };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            movement += {0.f, speed };
        acceleration += movement;
    }
    { // Shooting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            shoot();
    }
    { // Spawn asteroids
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        }
    }
}

void Player::shoot() {
    if (time_since_last_shoot.getElapsedTime() > shoot_cooldown) {
        time_since_last_shoot.restart();
        GameManager::add(TYPE::Missile, sprite.getPosition());
    }
}

void Player::reactCollision(GraphicElements::TYPE type) {
    if (type == TYPE::Asteroid) {
        alive = false;
    }
}
