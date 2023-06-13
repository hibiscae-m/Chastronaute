//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_MISSILE_H
#define CHASTRONAUTE_MISSILE_H

#include "GraphicElements.h"

class Missile : public GraphicElements {
public:
    Missile() = delete;
    explicit Missile(sf::Vector2f position);
    void reactCollision(TYPE type) override;
    void update() override;
private:
    sf::Clock destruction_delay_clock;
    sf::Time destruction_delay_timer = sf::milliseconds(20);
};


#endif //CHASTRONAUTE_MISSILE_H
