#include <SFML/Graphics.hpp>

#include "Game.hpp"

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

    // TODO: come up with better idea of how to draw game objects
    // Possibly create something called "Drawer" that will draw all the GameMap objects and player
    // so I can get rid of SFML/Graphics.hpp dependency

    Player* player = game_map_->GetPlayer();
    sf::Texture texture;
    if (!texture.loadFromFile(player->GetTextureLocation())) {
        throw std::exception();
    }

    sf::Sprite sprite;
    sprite.setPosition(player->GetPosition());
    sprite.setTexture(texture);
    sprite.setScale(0.05f, 0.05f);
    sprite.setTextureRect(sf::IntRect(0, 0, 800, 800));

    sf::RenderWindow window(sf::VideoMode(1024, 700), "archs");

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // TODO: come up with idea how I can pass events to player
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    player->MoveRight();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    player->MoveLeft();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    player->Jump();

            }
        }

        player->Tick();
        sprite.setPosition(player->GetPosition());

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

