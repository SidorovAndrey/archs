#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

#include "GameObject.hpp"

class Game;

class Player : public GameObject {
    private:
        sf::Vector2f velocity_;

    public:
        Player(const sf::Vector2f position, const sf::Vector2f size);

        void Tick() noexcept;

        void MoveLeft() noexcept;
        void MoveRight() noexcept;
        void Jump() noexcept;

};

#endif // PLAYER_H_

