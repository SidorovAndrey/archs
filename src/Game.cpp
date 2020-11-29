#include <SFML/Graphics.hpp>

#include "Game.hpp"

Game::Game() {
    player_ = new Player("resources/mario.png");
}

Game::~Game() {
    delete player_;
}

void Game::Run() {
    sf::Texture texture;
    if (!texture.loadFromFile(player_->getTextureLocation())) {
        throw std::exception();
    }

    sf::Sprite sprite;
    sprite.setPosition(player_->xPos(), player_->yPos());
    sprite.setTexture(texture);
    sprite.setScale(0.2f, 0.2f);
    sprite.setTextureRect(sf::IntRect(0, 0, 800, 800));

    sf::RenderWindow window(sf::VideoMode(1024, 700), "archs");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    player_->handleInput(Direciton::Right);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    player_->handleInput(Direciton::Left);

                sprite.setPosition(player_->xPos(), player_->yPos());
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

