#ifndef GAME_MAP_H_
#define GAME_MAP_H_

#include <string>
#include <vector>

#include "GameObject.hpp"
#include "Player.hpp"

class GameMap {
    private:
        // I don't know how should I store map_objects_ and player_. For now, gonna keep them as pointers
        std::vector<GameObject*> map_objects_;
        Player* player_;

        static sf::Vector2f PositionByIndex(
            const size_t& x,
            const size_t& y,
            const float& tile_width = 30.f,
            const float& tile_height = 30.f) noexcept;

    public:
        GameMap();
        ~GameMap();

        void Load();
        Player* GetPlayer() const noexcept;
        std::vector<GameObject*> GetGameObjects() const noexcept;
};

#endif // GAME_MAP_H_

