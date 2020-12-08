#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <SFML/System/Vector2.hpp>

#include "GameObjectType.hpp"

class GameObject {
    private:
        sf::Vector2f position_;
        sf::Vector2f size_;

        GameObjectType object_type_;

    public:
        GameObject(const GameObjectType type, const sf::Vector2f position, const sf::Vector2f size);

        void SetType(GameObjectType type) noexcept;

        sf::Vector2f GetPosition() const noexcept;
        sf::Vector2f GetSize() const noexcept;

        void SetPosition(const sf::Vector2f& position) noexcept;
        void SetSize(const sf::Vector2f& size) noexcept;
};

#endif // GAME_OBJECT_H_

