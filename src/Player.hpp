#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

#include "Direction.hpp"

class Player {
    private:
        float x_, y_;
        std::string texture_location_;

    public:
        Player(std::string texture_location);
        ~Player() = default;

        void handleInput(const Direciton direction) noexcept;

        std::string getTextureLocation() const noexcept;
        float xPos() const noexcept;
        float yPos() const noexcept;
};

#endif // PLAYER_H_

