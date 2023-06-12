//
// Created by Marius on 11/06/2023.
//

#include "../include/GraphicElements.h"
#include "../include/ResourcesManager.h"
#include "../include/WindowSettings.h"
#include <cmath>

GraphicElements::GraphicElements(const std::string_view texture_location, sf::Vector2f position) {
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource(texture_location));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    hitbox.setRadius(sprite.getGlobalBounds().height / 1.8f);
    hitbox.setOrigin(hitbox.getGlobalBounds().width / 2, hitbox.getGlobalBounds().height / 2);
    hitbox.setFillColor(sf::Color(255, 0, 0, 125));
    sprite.setPosition(position);
    hitbox.setPosition(sprite.getPosition());
}

void GraphicElements::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    //window.draw(hitbox);
}

void GraphicElements::update() {
    sprite.move(acceleration * WindowSettings::TIME_PER_FRAME);
    hitbox.setPosition(sprite.getPosition());
    if (time_since_spawned.getElapsedTime() > lifetime) {
        alive = false;
    }
}

void GraphicElements::checkCollisions(const GraphicElements &other) {
    double distance = sqrt(std::pow(sprite.getPosition().x - other.getPosition().x, 2) +
                           std::pow(sprite.getPosition().y - other.getPosition().y, 2));
    if (distance < (hitbox.getRadius() + other.getHitboxRadius())) {
        reactCollision(other.getType());
    }
}
