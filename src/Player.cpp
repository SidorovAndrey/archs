#include "Player.hpp"
#include "Game.hpp"

#include "Log.hpp"

Player::Player(std::string texture_location, const Game* game) {
    height_ = 30;
    width_ = 30;
    x_ = 5;
    y_ = game->y_screen_size - height_ - 20;

    x_velocity_ = 0;
    y_velocity_ = 0;

    texture_location_ = texture_location;
}

void Player::tick() noexcept {
    if (x_velocity_ != 0) {
        x_velocity_ = 0;
    }

    x_ += x_velocity_;
    y_ += y_velocity_;
    if (y_velocity_ > 0) y_velocity_ -= 3;
}

void Player::moveLeft() noexcept {
    x_velocity_ = -10;
}

void Player::moveRight() noexcept {
    x_velocity_ = 10;
}

void Player::jump() noexcept {
    y_velocity_ = 10;
}

std::string Player::getTextureLocation() const noexcept {
    return texture_location_;
}

int Player::height() const noexcept {
    return height_;
}

int Player::width() const noexcept {
    return width_;
}

int Player::xPos() const noexcept {
    return x_;
}

int Player::yPos() const noexcept {
    return y_;
}
