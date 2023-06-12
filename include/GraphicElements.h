//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_GRAPHICELEMENTS_H
#define CHASTRONAUTE_GRAPHICELEMENTS_H

#include <string_view>
#include "SFML/Graphics.hpp"

class GraphicElements {
public:
    GraphicElements() = delete;
    GraphicElements(std::string_view texture_location, sf::Vector2f position);
    virtual ~GraphicElements() = default;

    enum class TYPE {
        Player,
        Missile,
        Asteroid,
        Impact,
        Other
    };

    void draw(sf::RenderWindow& window);
    virtual void update();
    void checkCollisions(const GraphicElements& other);
    virtual void reactCollision(TYPE type) = 0;

    // Getters
    bool isAlive() const { return alive; };
    TYPE getType() const { return type; };
    sf::Vector2f getPosition() const { return sprite.getPosition(); };
    float getHitboxRadius() const { return hitbox.getRadius(); };
protected:
    float speed{};
    const float FRICTION = 5.F;
    sf::Vector2f acceleration = {0.f, 0.f};
    bool alive = true;
    TYPE type = TYPE::Other;
    sf::Sprite sprite;
    sf::Clock time_since_spawned;
    sf::Time lifetime;
    sf::CircleShape hitbox;
private:
};


#endif //CHASTRONAUTE_GRAPHICELEMENTS_H