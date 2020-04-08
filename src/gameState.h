#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include <vector>
#include "layout.h"
#include "agent.h"

class GameState
{
    public:
        GameState();
        int getScore() const;
        Layout& getLayout();
        Agent* getPacman();
        void Initialize(std::string filename);
        
    private:
        Layout _layout;
        Agent* _pacman;
        std::vector<Agent*> _ghosts;
        long _score;
};

#endif