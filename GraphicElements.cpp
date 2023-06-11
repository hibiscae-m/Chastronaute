//
// Created by Marius on 11/06/2023.
//

#include "GraphicElements.h"
#include "ResourcesManager.h"
#include "WindowSettings.h"

GraphicElements::GraphicElements(const std::string_view texture_location, sf::Vector2f position) {
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource(texture_location));
    sprite.setOrigin((sprite.getGlobalBounds().width / 2), (sprite.getGlobalBounds().height / 2));
    sprite.setPosition(position);
}

void GraphicElements::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void GraphicElements::update() {
    sprite.move(acceleration * WindowSettings::TIME_PER_FRAME);
    if (time_since_spawned.getElapsedTime() > lifetime) {
        alive = false;
    }
}
