#include <iostream>

#include "Log.hpp"

void Log::Write(std::string message) {
    std::cout << message << std::endl;
}

void Log::Write(sf::Vector2f value) {
    std::cout << value.x << ":" << value.y << std::endl;
}
