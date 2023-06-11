//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_PLAYER_H
#define CHASTRONAUTE_PLAYER_H

#include "GraphicElements.h"
#include <string_view>

class Player : public GraphicElements {
public:
    Player() = delete;
    explicit Player(sf::Vector2f position);
    void update() override;

    void reactCollision(TYPE type) override;

private:
    void handlePlayerInputs();

    void shoot();
    sf::Clock time_since_last_shoot;
    sf::Time shoot_cooldown = sf::milliseconds(500);
};


#endif //CHASTRONAUTE_PLAYER_H
