//
// Created by Marius on 11/06/2023.
//

#ifndef CHASTRONAUTE_RESOURCESMANAGER_H
#define CHASTRONAUTE_RESOURCESMANAGER_H

#include <string_view>
#include <unordered_map>
#include <iostream>

template <typename T>
class ResourcesManager
{
public:
    ResourcesManager() = delete;
    static T const& getResource(std::string_view const& texture_location) {
        auto result = resources.find(texture_location);
        if (result == std::end(resources)) {
            if (!resources[texture_location].loadFromFile(texture_location.data())) {
                std::cout << "Impossible de charger l'image" << std::endl;
            }
            return resources[texture_location];
        }
        return result->second;
    }
private:
    static std::unordered_map<std::string_view, T> resources;
};

#endif //CHASTRONAUTE_RESOURCESMANAGER_H
