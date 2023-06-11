//
// Created by Marius on 11/06/2023.
//

#include "GraphicElements.h"
#include "ResourcesManager.h"

GraphicElements::GraphicElements(const std::string_view texture_location) {
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource(texture_location));
    sprite.setOrigin((sprite.getGlobalBounds().width / 2), (sprite.getGlobalBounds().height / 2));
}

void GraphicElements::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
