#include "Controller.hpp"

void Controller::HandleInput(const sf::Event& event, Player& player, const std::vector<GameObject>& map) {
    sf::Vector2f position = player.GetPosition();
    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            position.x += 2.f;
            if (!Controller::CollideWithMap(map, position, player.GetSize()))
                player.SetPosition(position);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            position.x -= 2.f;
            if (!Controller::CollideWithMap(map, position, player.GetSize()))
                player.SetPosition(position);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            // pass
        }
   }
}

bool Controller::CollideWithMap(const std::vector<GameObject>& map, const sf::Vector2f& position, const sf::Vector2f& size) noexcept {
    for (GameObject obj : map) {
        auto obj_pos = obj.GetPosition();
        auto obj_size = obj.GetSize();
        bool collide_by_x = position.x + size.x >= obj_pos.x && position.x + size.x <= obj_pos.x + obj_size.x;
        bool collide_by_y = position.y + size.y >= obj_pos.y && position.y + size.y <= obj_pos.y + obj_size.y;

        if (collide_by_x && collide_by_y) return true;
    }

    return false;
}
