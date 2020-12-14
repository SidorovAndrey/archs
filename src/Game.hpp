#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <vector>

#include "Config.hpp"
#include "GameMap.hpp"

class Game {
    private:
        std::unique_ptr<GameMap> game_map_;
        std::unique_ptr<Config> config_;

    public:
        Game();

        void Run();
};

#endif // GAME_H_

