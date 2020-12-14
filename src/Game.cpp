#include "Game.hpp"
#include "Display.hpp"

Game::Game() {
    config_ = std::make_unique<Config>();
    game_map_ = std::make_unique<GameMap>();
}

void Game::Run() {
    config_->Load("resources/game.config");
    game_map_->Load();

    Player player = game_map_->GetPlayer();
    std::vector<GameObject> map_objects = game_map_->GetGameObjects();

    Display display;
    display.Start(player, map_objects);

    while (display.IsOpen()) {
        display.Tick(player, map_objects);
    }
}

