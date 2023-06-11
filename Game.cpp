//
// Created by Marius on 11/06/2023.
//

#include "Game.h"
#include "WindowSettings.h"
#include "Player.h"

Game::Game() :
        window(sf::VideoMode(WindowSettings::WINDOW_WIDTH, WindowSettings::WINDOW_HEIGHT),
               WindowSettings::WINDOW_NAME.data())
{}

void Game::run() {
    game_manager.add(GraphicElements::TYPE::Player);
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    sf::Time time_per_frame = sf::seconds(WindowSettings::TIME_PER_FRAME);
    while (window.isOpen()) {
        time_since_last_update += clock.restart();
        if (time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            processEvents();
            game_manager.update();
            display();
        }
    }
}

void Game::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::display() {
    window.clear();
    game_manager.draw(window);
    window.display();
}
