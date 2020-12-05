#include "GameObject.hpp"

GameObject::GameObject(GameObjectType type) {
    object_type_ = type;
    position_ = sf::Vector2f(0, 0);
    size_ = sf::Vector2f(0, 0);
}

GameObject::GameObject(GameObjectType type, float x, float y, float width, float height) {
    object_type_ = type;
    position_ = sf::Vector2f(x, y);
    size_ = sf::Vector2f(width, height);
}

sf::Vector2f GameObject::getPosition() const noexcept {
    return position_;
}

sf::Vector2f GameObject::getSize() const noexcept {
    return size_;
}

void GameObject::setPosition(const sf::Vector2f& position) noexcept {
    position_ = position;
}

void GameObject::setSize(const sf::Vector2f& size) noexcept {
    size_ = size;
}
