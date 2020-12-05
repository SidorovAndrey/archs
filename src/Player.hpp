#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

#include "GameObject.hpp"

class Game;

class Player : public GameObject {
    private:
        sf::Vector2f velocity_;
        std::string texture_location_;

    public:
        Player(std::string texture_location, const Game* game);
        ~Player() = default;

        void tick() noexcept;

        void moveLeft() noexcept;
        void moveRight() noexcept;
        void jump() noexcept;

        std::string getTextureLocation() const noexcept;
};

#endif // PLAYER_H_

