#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "Player.hpp"
#include "GameObject.hpp"

class Controller {
    private:
        static bool CollideWithMap(const std::vector<GameObject>& map, const sf::Vector2f& position, const sf::Vector2f& size) noexcept;

    public:
        static void HandleInput(const sf::Event& event, Player& player, const std::vector<GameObject>& map);
};

#endif // CONTROLLER_H_
