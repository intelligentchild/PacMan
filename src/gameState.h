#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include <vector>
#include "layout.h"
#include "agent.h"

#include "pacman.h"
#include "ghost.h"


enum Score{
    capsule=2,
    food=30,
    ghostKill=200
};

class GameState
{
    public:
        GameState();
        ~GameState();
        int getScore() const;
        Layout& getLayout();
        std::unique_ptr<Pacman>& getPacman();
        std::vector<std::unique_ptr<Ghost>>& getGhosts();
        void Initialize(std::string filename);

        void HandleCollision(Pacman* agent);
        
    private:
        Layout _layout;
        std::unique_ptr<Pacman> _pacman;
        std::vector<std::unique_ptr<Ghost>> _ghosts;
        long _score;
};

#endif