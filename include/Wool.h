//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_WOOL_H
#define CHASTRONAUTE_WOOL_H

#include "GraphicElements.h"

class Wool : public GraphicElements {
public:
    Wool();
    void update() override;

    void reactCollision(TYPE type) override;
};


#endif //CHASTRONAUTE_WOOL_H
