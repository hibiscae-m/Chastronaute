//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_PLAYER_H
#define CHASTRONAUTE_PLAYER_H

#include "GraphicElements.h"
#include <string_view>

class Player : public GraphicElements {
public:
    Player();
    void update() override;
};


#endif //CHASTRONAUTE_PLAYER_H
