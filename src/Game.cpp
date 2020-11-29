#include <SFML/Graphics.hpp>

#include "Game.hpp"

void Game::Run() {
    sf::RenderWindow window(sf::VideoMode(1024, 700), "archs");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Cyan);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    shape.move(1.f, 0.f);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    shape.move(-1.f, 0.f);
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

