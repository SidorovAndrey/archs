#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Game;

class Player {
    private:
        int height_, width_;
        int x_, y_;
        double x_velocity_, y_velocity_;

        std::string texture_location_;

    public:
        Player(std::string texture_location, const Game* game);
        ~Player() = default;

        void tick() noexcept;

        void moveLeft() noexcept;
        void moveRight() noexcept;
        void jump() noexcept;

        std::string getTextureLocation() const noexcept;

        int height() const noexcept;
        int width() const noexcept;
        int xPos() const noexcept;
        int yPos() const noexcept;
};

#endif // PLAYER_H_

