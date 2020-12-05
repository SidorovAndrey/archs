#ifndef GAME_H_
#define GAME_H_

#include <vector>

#include "Config.hpp"
#include "GameObject.hpp"
#include "Player.hpp"

class Game {
    private:
        Player* player_;
        std::vector<GameObject>* game_objects_;
        Config* config_;

    public:
        const int x_screen_size = 1200;
        const int y_screen_size = 700;

        Game();
        ~Game();

        void Run();
};

#endif // GAME_H_

