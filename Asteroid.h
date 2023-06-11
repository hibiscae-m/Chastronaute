//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_ASTEROID_H
#define CHASTRONAUTE_ASTEROID_H

#include "GraphicElements.h"

class Asteroid : public GraphicElements {
public:
    Asteroid() = delete;
    explicit Asteroid(sf::Vector2f position);
    void update() override;

    void reactCollision(TYPE type) override;
};


#endif //CHASTRONAUTE_ASTEROID_H
