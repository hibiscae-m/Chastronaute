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
};


#endif //CHASTRONAUTE_MISSILE_H
