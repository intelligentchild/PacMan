#ifndef PACMAN_H
#define PACMAN_H

#include "agent.h"
#include "layout.h"

class GameState;

class Layout;

class Pacman: public Agent{
    public:
        Pacman(int x, int y, Layout* layout);
        void move(Direction direction);
        void HandleCollision(GameState& gameState);
};

#endif