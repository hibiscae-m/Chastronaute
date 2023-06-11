//
// Created by Marius on 11/06/2023.
//

#include "GameManager.h"
#include "Player.h"
#include "Missile.h"
#include "Asteroid.h"

void GameManager::update() {
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
        buffer.push_back(std::make_unique<Asteroid>(position));
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
