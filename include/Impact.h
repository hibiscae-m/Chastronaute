//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_IMPACT_H
#define CHASTRONAUTE_IMPACT_H

#include "GraphicElements.h"

class Impact : public GraphicElements {
public:
    Impact() = delete;
    explicit Impact(sf::Vector2f position);

    void reactCollision(TYPE type) override;

    void update() override;
};


#endif //CHASTRONAUTE_IMPACT_H
