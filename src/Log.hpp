#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <SFML/System/Vector2.hpp>

class Log {
    public:
        static void Write(std::string message);
        static void Write(sf::Vector2f value);
};

#endif // LOG_H_

