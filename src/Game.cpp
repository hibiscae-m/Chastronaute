//
// Created by Marius on 11/06/2023.
//

#include "../include/Game.h"
#include "../include/WindowSettings.h"
#include "../include/Player.h"
#include "../include/GameManager.h"

Game::Game() :
        window(sf::VideoMode(WindowSettings::WINDOW_WIDTH, WindowSettings::WINDOW_HEIGHT),
               WindowSettings::WINDOW_NAME.data())
{
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
}

void Game::run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    sf::Time time_per_frame = sf::seconds(WindowSettings::TIME_PER_FRAME);
    while (window.isOpen()) {
        time_since_last_update += clock.restart();
        if (time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            processEvents();
            GameManager::update();
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
        if (event.type == sf::Event::KeyPressed) {
            if (!GameManager::isGameStarted()) {
                if (event.key.code == sf::Keyboard::Enter) {
                    auto choice = home_screen.getCursorPosition();
                    if (choice == HomeScreen::CHOICES::Play) {
                        GameManager::startGame();
                    }
                    if (choice == HomeScreen::CHOICES::Quit) {
                        window.close();
                    }
                }
                if (event.key.code == sf::Keyboard::Up) {
                    home_screen.moveCursor(HomeScreen::DIRECTION::Up);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    home_screen.moveCursor(HomeScreen::DIRECTION::Down);
                }
            }
        }
    }
}

void Game::display() {
    window.clear();
    if (GameManager::isGameStarted()) {
        GameManager::draw(window);
    }
    else {
        home_screen.draw(window);
    }
    window.display();
}
