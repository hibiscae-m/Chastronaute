cmake_minimum_required(VERSION 3.25)
project(Chastronaute)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chastronaute main.cpp src/Game.cpp include/Game.h include/WindowSettings.h src/ResourcesManager.cpp include/ResourcesManager.h src/GraphicElements.cpp include/GraphicElements.h src/Player.cpp include/Player.h src/GameManager.cpp include/GameManager.h include/ResourcesLocations.h src/Missile.cpp include/Missile.h src/Asteroid.cpp include/Asteroid.h src/Impact.cpp include/Impact.h src/Enemies.cpp include/Enemies.h src/Collision.cpp include/Collision.h HomeScreen.cpp HomeScreen.h)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
target_link_libraries(Chastronaute PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)