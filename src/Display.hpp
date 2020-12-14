#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Player.hpp"

class Display {
    private:
        std::unique_ptr<sf::RenderWindow> window_;

        std::unique_ptr<sf::Texture> player_texture_;
        std::unique_ptr<sf::Texture> ground_texture_;

        std::unique_ptr<sf::Sprite> player_sprite_;
        std::vector<sf::Sprite> ground_sprites_;

    public:
        Display();

        void Start(const Player& player, const std::vector<GameObject>& map);
        void Tick(Player& player, const std::vector<GameObject>& map);

        bool IsOpen() const noexcept;
};

#endif // DISPLAY_H_

