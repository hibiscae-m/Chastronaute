//
// Created by marius.couvrat on 14/06/2023.
//

#include "../include/HomeScreen.h"
#include "../include/ResourcesManager.h"
#include "../include/WindowSettings.h"

HomeScreen::HomeScreen() {
    for (auto i = 0u; i < menu_sentences.size(); i++) {
        menu.push_back(std::make_unique<sf::Text>());
    }
    for (auto i = 0u; i < menu.size(); i++) {
        menu[i]->setFont(ResourcesManager<sf::Font>::getResource(font));
        menu[i]->setCharacterSize(32);
        menu[i]->setString(menu_sentences[i].data());
        menu[i]->setOrigin(menu[i]->getGlobalBounds().width / 2, menu[i]->getGlobalBounds().height / 2);
        menu[i]->setPosition(WindowSettings::WINDOW_WIDTH / 2.f,
                             WindowSettings::WINDOW_HEIGHT / 2.f + (static_cast<float>(menu[i]->getCharacterSize() * 2 * i)));
        cursor_available_positions.emplace_back(menu[i]->getPosition().x - menu[i]->getGlobalBounds().width / 2 - menu[i]->getLetterSpacing() * 10,
                                             menu[i]->getPosition().y);
    }
    cursor_maximum_position = cursor_available_positions.size() - 1;
    cursor.setTexture(ResourcesManager<sf::Texture>::getResource(cursor_texture));
    cursor.setOrigin(cursor.getGlobalBounds().width, cursor.getGlobalBounds().height / 2);
    cursor.setPosition(cursor_available_positions[cursor_current_position]);
}

void HomeScreen::draw(sf::RenderWindow &window) {
    for (auto& line: menu) {
        window.draw(*line);
        window.draw(cursor);
    }
}

void HomeScreen::moveCursor(HomeScreen::DIRECTION direction) {
    if (direction == DIRECTION::Up) {
        cursor_current_position--;
        if (cursor_current_position < 0) {
            cursor_current_position = cursor_maximum_position;
        }
    }
    if (direction == DIRECTION::Down) {
        cursor_current_position++;
        if (cursor_current_position > cursor_maximum_position) {
            cursor_current_position = cursor_minimum_position;
        }
    }
    cursor.setPosition(cursor_available_positions[cursor_current_position]);
}

long long HomeScreen::getCursorPosition() const {
    return cursor_current_position;
}

