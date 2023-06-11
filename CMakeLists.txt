cmake_minimum_required(VERSION 3.25)
project(Chastronaute)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chastronaute main.cpp Game.cpp Game.h WindowSettings.h ResourcesManager.cpp ResourcesManager.h GraphicElements.cpp GraphicElements.h Player.cpp Player.h GameManager.cpp GameManager.h TexturesLocations.h Missile.cpp Missile.h Asteroid.cpp Asteroid.h Impact.cpp Impact.h)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
target_link_libraries(Chastronaute PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)