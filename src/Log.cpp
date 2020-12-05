#include <iostream>

#include "Log.hpp"

void Log::write(std::string message) {
    std::cout << message << std::endl;
}

void Log::write(sf::Vector2f value) {
    std::cout << value.x << ":" << value.y << std::endl;
}
