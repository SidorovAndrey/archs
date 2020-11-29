#include "Player.hpp"

Player::Player(std::string texture_location) {
    x_ = 0.f;
    y_ = 0.f;

    texture_location_ = texture_location;
}

void Player::handleInput(const Direciton direction) noexcept {
    if (direction == Direciton::Left)
        x_ -= 5.f;

    if (direction == Direciton::Right)
        x_ += 5.f;
}

std::string Player::getTextureLocation() const noexcept {
    return texture_location_;
}

float Player::xPos() const noexcept {
    return x_;
}

float Player::yPos() const noexcept {
    return y_;
}
