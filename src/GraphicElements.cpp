//
// Created by Marius on 11/06/2023.
//

#include "../include/GraphicElements.h"
#include "../include/ResourcesManager.h"
#include "../include/WindowSettings.h"
#include "../include/Collision.h"

void GraphicElements::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void GraphicElements::update() {
    if (time_since_spawned.getElapsedTime() > lifetime) {
        alive = false;
    }
    sprite.move(acceleration * WindowSettings::TIME_PER_FRAME);
    if (damaged) {
        if (damaged_clock.getElapsedTime() < damaged_animation_lifetime) {
            int color_value = damaged_clock.getElapsedTime().asMilliseconds() * 255 / damaged_animation_lifetime.asMilliseconds();
            sprite.setColor(sf::Color(255, color_value, color_value));
        }
        else {
            damaged = false;
        }
    }
}

void GraphicElements::checkCollisions(const GraphicElements &other) {
    if (Collision::PixelPerfectTest(sprite, other.sprite)) {
        reactCollision(other.getType());
    }
}

void GraphicElements::initializeSprite(const std::string_view texture_location,
                                       const sf::Vector2f position) {
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource(texture_location));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(position);
}
