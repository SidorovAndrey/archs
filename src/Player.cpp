#include "Player.hpp"
#include "Game.hpp"

#include "Log.hpp"

Player::Player(std::string texture_location, const Game* game)
    : GameObject(GameObjectType::Player, 5, game->y_screen_size - 50, 30, 30) {

    velocity_ = sf::Vector2f(0, 0);
    texture_location_ = texture_location;
}

void Player::tick() noexcept {
    auto position = this->getPosition();
    position += velocity_;
    setPosition(position);

    if (velocity_.x != 0) {
        velocity_.x = 0;
    }
}

void Player::moveLeft() noexcept {
    velocity_.x = -10;
}

void Player::moveRight() noexcept {
    velocity_.x = 10;
}

void Player::jump() noexcept {
    // TODO: implement
}

std::string Player::getTextureLocation() const noexcept {
    return texture_location_;
}

