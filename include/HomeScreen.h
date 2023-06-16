//
// Created by marius.couvrat on 14/06/2023.
//

#ifndef CHASTRONAUTE_HOMESCREEN_H
#define CHASTRONAUTE_HOMESCREEN_H

#include "ResourcesLocations.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <string_view>
#include <memory>

class HomeScreen {
public:
    HomeScreen();
    void draw(sf::RenderWindow& window);
    void update();

    enum DIRECTION { Up, Down };
    void moveCursor(DIRECTION direction);
    long long getCursorPosition() const;
    enum CHOICES {
        Play,
        Kouglopf,
        Chloppa,
        Quit
    };
private:
    std::string_view font = ResourcesLocations::Fonts::GIDDYUPSTD;
    std::vector<std::string_view> menu_sentences = { "Play",
                                                     "Kouglopf",
                                                     "Chloppa",
                                                     "Quit"};

    std::vector<std::unique_ptr<sf::Text>> menu;
    std::vector<sf::Vector2f> cursor_available_positions;
    long long cursor_current_position = 0;
    short cursor_minimum_position = 0;
    unsigned int cursor_maximum_position;
    sf::Sprite cursor;
    std::string_view cursor_texture = ResourcesLocations::Textures::CURSOR;
    sf::Sprite title;
    std::string_view title_texture = ResourcesLocations::Textures::TITLE;
    sf::Sprite chastronaute;
    std::string_view chastronaute_texture = ResourcesLocations::Textures::CHASTRONAUTE;
    sf::Vector2f chastronaute_initial_position;
    sf::Clock clock;
};


#endif //CHASTRONAUTE_HOMESCREEN_H
