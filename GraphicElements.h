//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_GRAPHICELEMENTS_H
#define CHASTRONAUTE_GRAPHICELEMENTS_H

#include <string_view>
#include <SFML/Graphics.hpp>

class GraphicElements {
public:
    GraphicElements() = delete;
    GraphicElements(std::string_view texture_location, sf::Vector2f position);
    virtual ~GraphicElements() = default;
    void draw(sf::RenderWindow& window);
    virtual void update() = 0;

    enum class TYPE {
        Player,
        Missile,
        Other
    };

    // Getters
    bool isAlive() const { return alive; };
    TYPE getType() const { return type; };
protected:
    bool alive = true;
    TYPE type = TYPE::Other;
    sf::Sprite sprite;
private:
};


#endif //CHASTRONAUTE_GRAPHICELEMENTS_H
