#ifndef GAME_H_
#define GAME_H_

#include <vector>

#include "Config.hpp"
#include "GameMap.hpp"

class Game {
    private:
        GameMap* game_map_;
        Config* config_;

    public:
        Game();
        ~Game();

        void Run();
};

#endif // GAME_H_

