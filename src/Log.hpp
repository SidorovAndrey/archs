#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <SFML/System/Vector2.hpp>

class Log {
    public:
        static void write(std::string message);
        static void write(sf::Vector2f value);
};

#endif // LOG_H_

