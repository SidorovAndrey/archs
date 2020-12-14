#ifndef GAME_MAP_H_
#define GAME_MAP_H_

#include <memory>
#include <string>
#include <vector>

#include "GameObject.hpp"
#include "Player.hpp"

class GameMap {
    private:
        std::vector<GameObject> map_objects_;
        std::unique_ptr<Player> player_;

        static sf::Vector2f PositionByIndex(
            const size_t& x,
            const size_t& y,
            const float& tile_width = 30.f,
            const float& tile_height = 30.f) noexcept;

    public:
        GameMap();

        void Load();
        Player& GetPlayer() const noexcept;
        std::vector<GameObject> GetGameObjects() const noexcept; // guess that compiler has Return Value Optimization and handles it wihout copy, better disassemble it and check it
};

#endif // GAME_MAP_H_

