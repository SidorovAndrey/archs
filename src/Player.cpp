#include "Player.hpp"
#include "Game.hpp"

#include "Log.hpp"

Player::Player(const sf::Vector2f position, const sf::Vector2f size)
    : GameObject(GameObjectType::Player, position, size) {

    velocity_ = sf::Vector2f(0, 0);
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

