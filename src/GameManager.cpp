//
// Created by Marius on 11/06/2023.
//

#include "../include/GameManager.h"
#include "../include/Player.h"
#include "../include/Missile.h"
#include "../include/Asteroid.h"
#include "../include/Impact.h"
#include "../include/WindowSettings.h"
#include <random>

void GameManager::update() {
    if (!game_over) {
        spawn();
        checkCollision();
    }
    for (auto& element: elements) {
        element->update();
    }
    clean();
}

void GameManager::clean() {
    for (auto& buffered_element : buffer)
        elements.push_back(std::move(buffered_element));
    buffer.clear();
    for (auto i = 0u; i < elements.size(); i++) {
        if (!(elements[i]->isAlive()))
            elements.erase(elements.begin() + i);
    }
}

void GameManager::draw(sf::RenderWindow &window) {
    for (auto& element: elements)
        element->draw(window);
}

void GameManager::add(GraphicElements::TYPE type, sf::Vector2f position = {100.f, 100.f}) {
    if (type == GraphicElements::TYPE::Player) {
        buffer.push_back(std::make_unique<Player>(position));
    }
    if (type == GraphicElements::TYPE::Missile) {
        buffer.push_back(std::make_unique<Missile>(position));
    }
    if (type == GraphicElements::TYPE::Enemies) {
        buffer.push_back(std::make_unique<Asteroid>());
    }
    if (type == GraphicElements::TYPE::Impact) {
        buffer.push_back(std::make_unique<Impact>(position));
    }
}

void GameManager::checkCollision() {
    for (auto& element: elements) {
        for (auto& other_element: elements) {
            if (element != other_element) {
                element->checkCollisions(*other_element);
            }
        }
    }
}

void GameManager::spawn() {
    if (time_since_last_asteroid.getElapsedTime() > asteroid_cooldown) {
        time_since_last_asteroid.restart();
        GameManager::add(GraphicElements::TYPE::Enemies);
    }
}

void GameManager::start() {
    game_over = false;
    GameManager::add(GraphicElements::TYPE::Player, {150, 100});
}

void GameManager::gameOver() {
    for (auto& element: elements) {
        element->setAlive(false);
    }
    game_over = true;
}

bool GameManager::isGameOver() {
    return game_over;
}
