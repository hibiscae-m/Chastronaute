//
// Created by Marius on 11/06/2023.
//

#include "../include/Impact.h"
#include "../include/ResourcesLocations.h"


Impact::Impact(sf::Vector2f position) : GraphicElements(){
    initializeSprite(ResourcesLocations::Textures::IMPACT, position);
    sprite.setScale(0.1, 0.1);
    lifetime = sf::seconds(2);
}

void Impact::update() {
    if (time_since_spawned.getElapsedTime() < lifetime / 20.f) {
        sprite.setScale(time_since_spawned.getElapsedTime().asSeconds() / (lifetime.asSeconds() / 20.f),
                        time_since_spawned.getElapsedTime().asSeconds() / (lifetime.asSeconds() / 20.f));
    }
    else {
        sprite.setColor(sf::Color(255, 255, 255,
                                  time_since_spawned.getElapsedTime().asSeconds() * lifetime.asSeconds() / 255));
    }
    GraphicElements::update();
}

void Impact::reactCollision(GraphicElements::TYPE type) {

}
