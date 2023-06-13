//
// Created by marius.couvrat on 13/06/2023.
//

#include "../include/Enemies.h"

Enemies::Enemies() {
    type = TYPE::Enemies;
}

void Enemies::reactCollision(GraphicElements::TYPE type) {
    if (type == TYPE::Missile) {
        if (!resistant) {
            lives--;
            damaged_clock.restart();
            damaged = true;
            checkHealth();
        }
    }
}

void Enemies::checkHealth() {
    if (lives <= 0) {
        alive = false;
    }
}
