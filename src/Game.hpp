#ifndef GAME_H_
#define GAME_H_

#include "Player.hpp"

class Game {
    private:
        Player* player_;

    public:
        Game();
        ~Game();

        void Run();
};

#endif // GAME_H_

