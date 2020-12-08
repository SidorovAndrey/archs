#include "GameObject.hpp"

GameObject::GameObject(const GameObjectType type, const sf::Vector2f position, const sf::Vector2f size) {
    object_type_ = type;
    position_ = position;
    size_ = size;
}

sf::Vector2f GameObject::GetPosition() const noexcept {
    return position_;
}

sf::Vector2f GameObject::GetSize() const noexcept {
    return size_;
}

void GameObject::SetPosition(const sf::Vector2f& position) noexcept {
    position_ = position;
}

void GameObject::SetSize(const sf::Vector2f& size) noexcept {
    size_ = size;
}
