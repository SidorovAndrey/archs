#include <SFML/Graphics.hpp>

#include "Game.hpp"

Game::Game() {
    player_ = new Player("resources/mario.png", this);
    config_ = new Config();
}

Game::~Game() {
    delete player_;
    delete[] game_objects_;
    delete config_;
}

void Game::Run() {
    config_->load("resources/game.config");
    // TODO: use config values for player and ground sizes, add map parsing

    sf::Texture texture;
    if (!texture.loadFromFile(player_->getTextureLocation())) {
        throw std::exception();
    }

    sf::Sprite sprite;
    sprite.setPosition(player_->getPosition());
    sprite.setTexture(texture);
    sprite.setScale(0.05f, 0.05f);
    sprite.setTextureRect(sf::IntRect(0, 0, 800, 800));

    sf::RenderWindow window(sf::VideoMode(1024, 700), "archs");

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    player_->moveRight();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    player_->moveLeft();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    player_->jump();

            }
        }

        player_->tick();
        sprite.setPosition(player_->getPosition());

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

