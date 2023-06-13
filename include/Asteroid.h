//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_ASTEROID_H
#define CHASTRONAUTE_ASTEROID_H

#include "Enemies.h"

class Asteroid : public Enemies {
public:
    Asteroid();
    void update() override;
};


#endif //CHASTRONAUTE_ASTEROID_H
