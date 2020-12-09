#include "Game.hpp"
#include "Display.hpp"

Game::Game() {
    config_ = new Config();
    game_map_ = new GameMap();
}

Game::~Game() {
    delete config_;
    delete game_map_;
}

void Game::Run() {
    config_->Load("resources/game.config");
    game_map_->Load();

    Player* player = game_map_->GetPlayer();
    std::vector<GameObject*> map_objects = game_map_->GetGameObjects();

    Display display;
    display.Start(*player, map_objects);

    while (display.IsOpen()) {
        display.Tick(*player);
    }
}

