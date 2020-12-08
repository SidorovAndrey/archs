#include "Player.hpp"
#include "Game.hpp"

#include "Log.hpp"

Player::Player(const std::string texture_location, const sf::Vector2f position, const sf::Vector2f size)
    : GameObject(GameObjectType::Player, position, size) {

    velocity_ = sf::Vector2f(0, 0);
    texture_location_ = texture_location;
}

void Player::Tick() noexcept {
    auto position = this->GetPosition();
    position += velocity_;
    SetPosition(position);

    if (velocity_.x != 0) {
        velocity_.x = 0;
    }
}

void Player::MoveLeft() noexcept {
    velocity_.x = -10;
}

void Player::MoveRight() noexcept {
    velocity_.x = 10;
}

void Player::Jump() noexcept {
    // TODO: implement
}

std::string Player::GetTextureLocation() const noexcept {
    return texture_location_;
}

