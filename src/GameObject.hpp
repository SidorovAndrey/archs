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
        GameObject(GameObjectType type);
        GameObject(GameObjectType type, float x, float y, float width, float height);

        void setType(GameObjectType type) noexcept;

        sf::Vector2f getPosition() const noexcept;
        sf::Vector2f getSize() const noexcept;

        void setPosition(const sf::Vector2f& position) noexcept;
        void setSize(const sf::Vector2f& size) noexcept;
};

#endif // GAME_OBJECT_H_

