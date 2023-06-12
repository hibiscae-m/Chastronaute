//
// Created by Marius on 11/06/2023.
//

#include "../include/GameManager.h"
#include "../include/Player.h"
#include "../include/Missile.h"
#include "../include/Wool.h"
#include "../include/Impact.h"
#include "../include/WindowSettings.h"
#include <random>

void GameManager::update() {
    spawn();
    checkCollision();
    for (auto& buffered_element : buffer)
        elements.push_back(std::move(buffered_element));
    buffer.clear();
    for (auto i = 0u; i < elements.size(); i++) {
        elements[i]->update();
        if (!(elements[i]->isAlive()))
            elements.erase(elements.begin() + i);
    }
}

void GameManager::draw(sf::RenderWindow &window) {
    for (auto& element: elements)
        element->draw(window);
}

void GameManager::add(GraphicElements::TYPE type, sf::Vector2f position) {
    if (type == GraphicElements::TYPE::Player) {
        buffer.push_back(std::make_unique<Player>(position));
    }
    if (type == GraphicElements::TYPE::Missile) {
        buffer.push_back(std::make_unique<Missile>(position));
    }
    if (type == GraphicElements::TYPE::Asteroid) {
        buffer.push_back(std::make_unique<Wool>(position));
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
        auto generator = std::random_device();
        auto window_height_distribution = std::uniform_real_distribution<float>(0, WindowSettings::WINDOW_HEIGHT);
        auto random_height_position = window_height_distribution(generator);
        GameManager::add(GraphicElements::TYPE::Asteroid,
                         {WindowSettings::WINDOW_WIDTH, random_height_position});
    }
}
