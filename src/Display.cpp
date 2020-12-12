#include "Controller.hpp"
#include "Display.hpp"

Display::Display() {
    window_ = new sf::RenderWindow(sf::VideoMode(1024, 700), "archs");
    
    player_texture_ = new sf::Texture();
    ground_texture_ = new sf::Texture();

    player_sprite_ = new sf::Sprite();
}

Display::~Display() {
    delete window_;
    delete player_texture_;
    delete ground_texture_;
    delete player_sprite_;

    for (auto s : ground_sprites_) {
        delete s;
    }
}

void Display::Start(const Player& player, const std::vector<GameObject*>& map) {
    if (!player_texture_->loadFromFile("resources/mario.png")) {
        throw std::exception();
    }

    player_sprite_->setPosition(player.GetPosition());
    player_sprite_->setTexture(*player_texture_);
    player_sprite_->setScale(0.05f, 0.05f);
    player_sprite_->setTextureRect(sf::IntRect(0, 0, 800, 800));

    if (!ground_texture_->loadFromFile("resources/hiclipart.com.png")) {
        throw std::exception();
    }

    for (GameObject* obj : map) {
        sf::Sprite* ground_sprite = new sf::Sprite();
        ground_sprite->setPosition(obj->GetPosition());
        ground_sprite->setTexture(*ground_texture_);
        ground_sprite->setScale(0.05f, 0.05f);
        ground_sprite->setTextureRect(sf::IntRect(0, 0, 800, 800));
        ground_sprites_.push_back(ground_sprite);
    }
}

void Display::Tick(Player& player, const std::vector<GameObject*>& map) {
    sf::Event event;
    while (window_->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window_->close();

        Controller::HandleInput(event, player, map);
   }

    player.Tick();
    player_sprite_->setPosition(player.GetPosition());

    window_->clear();
    window_->draw(*player_sprite_);
    for (auto ground_sprite : ground_sprites_) {
        window_->draw(*ground_sprite);
    }
    window_->display();
}

bool Display::IsOpen() const noexcept {
    return window_->isOpen();
}

