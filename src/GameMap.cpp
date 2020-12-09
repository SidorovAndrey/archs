#include <fstream>
#include <iostream>

#include "GameMap.hpp"

GameMap::GameMap() {
    player_ = new Player(sf::Vector2f(), sf::Vector2f());
}

GameMap::~GameMap() {
    delete player_;
    for (size_t i = 0; i < map_objects_.size(); ++i)
        delete map_objects_[i];
}

void GameMap::Load() {
    std::string file_path = "resources/map.txt";
    std::fstream file;
    file.open(file_path, std::ios::in);
    if (!file.is_open())
        throw std::invalid_argument("Cannot open config file with path: " + file_path);

    std::string buff;
    for (size_t y = 0; std::getline(file, buff); ++y) {
        for (size_t x = 0; x < buff.size(); ++x) {
            if (buff[x] == 'p') {
                sf::Vector2f position = GameMap::PositionByIndex(x, y);
                sf::Vector2f size(30.f, 30.f);
                player_->SetPosition(position);
                player_->SetSize(size);
            }

            if (buff[x] == 'g') {
                sf::Vector2f position = GameMap::PositionByIndex(x, y);
                sf::Vector2f size(30.f, 30.f);
                GameObject* obj = new GameObject(GameObjectType::Ground, position, size);
                map_objects_.push_back(obj);
            }
        }
    }
}

sf::Vector2f GameMap::PositionByIndex(
    const size_t& x,
    const size_t& y,
    const float& tile_width,
    const float& tile_height) noexcept {

    sf::Vector2f result(x * tile_width, y * tile_height);
    return result;
}

Player* GameMap::GetPlayer() const noexcept {
    return player_;
}

std::vector<GameObject*> GameMap::GetGameObjects() const noexcept {
    return map_objects_;
}
