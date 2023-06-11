//
// Created by Marius on 11/06/2023.
//

#include "Player.h"
#include "TexturesLocations.h"

Player::Player() :
    GraphicElements(TexturesLocations::CHASTRONAUTE)
{
    sprite.setPosition(100, 100);
    sprite.setScale(0.3, 0.3);
}

void Player::update() {

}
