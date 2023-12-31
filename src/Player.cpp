//
// Created by Marius on 11/06/2023.
//

#include "../include/Player.h"
#include "../include/ResourcesLocations.h"
#include "../include/WindowSettings.h"
#include "../include/GameManager.h"

Player::Player(sf::Vector2f position) :
    GraphicElements()
{
    initializeSprite(ResourcesLocations::Textures::CHASTRONAUTE, position);
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
    sprite.setRotation(static_cast<float>(acceleration.y * 0.03));
}

void Player::handlePlayerInputs() {
    { // Movement
        float movement = 0.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            movement += -speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            movement += speed;
        acceleration += {0.f, movement};
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

void Player::reactCollision(GraphicElements::TYPE type) {
    if (type == TYPE::Enemies) {
        alive = false;
        GameManager::endGame();
    }
}
