//
// Created by marius.couvrat on 13/06/2023.
//

#ifndef CHASTRONAUTE_ENEMIES_H
#define CHASTRONAUTE_ENEMIES_H

#include "GraphicElements.h"

class Enemies : public GraphicElements {
public:
    Enemies();
protected:
    int lives = 1;
private:
    bool resistant = false;
    bool destructible = true;
    void reactCollision(TYPE type) override;
    void checkHealth();
};


#endif //CHASTRONAUTE_ENEMIES_H
