#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <vector>

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Player.hpp"

class Display {
    private:
        sf::RenderWindow* window_;

        sf::Texture* player_texture_;
        sf::Texture* ground_texture_;

        sf::Sprite* player_sprite_;
        std::vector<sf::Sprite*> ground_sprites_;

    public:
        Display();
        ~Display();

        void Start(const Player& player, const std::vector<GameObject*>& map);
        void Tick(Player& player);

        bool IsOpen() const noexcept;
};

#endif // DISPLAY_H_

