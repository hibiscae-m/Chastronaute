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
private:
    void handlePlayerInputs();
    float speed = 70.f;
    const float FRICTION = 5.F;
    sf::Vector2f acceleration = {0.f, 0.f};
};


#endif //CHASTRONAUTE_PLAYER_H
