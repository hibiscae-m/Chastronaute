//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_GRAPHICELEMENTS_H
#define CHASTRONAUTE_GRAPHICELEMENTS_H

#include <string_view>
#include "SFML/Graphics.hpp"

class GraphicElements {
public:
    GraphicElements() = default;
    virtual ~GraphicElements() = default;

    enum class TYPE {
        Player,
        Missile,
        Enemies,
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
    void initializeSprite(std::string_view texture_location, sf::Vector2f position = {100.f, 100.f});
    float speed{};
    const float FRICTION = 5.F;
    sf::Vector2f acceleration = {0.f, 0.f};
    sf::Clock damaged_clock;
    bool damaged = false;
    bool alive = true;
    TYPE type = TYPE::Other;
    sf::Sprite sprite;
    sf::Clock time_since_spawned;
    sf::Time lifetime;
    sf::CircleShape hitbox;
private:
    sf::Time damaged_animation_lifetime = sf::milliseconds(200);
};


#endif //CHASTRONAUTE_GRAPHICELEMENTS_H
