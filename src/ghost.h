#ifndef GHOST_H
#define GHOST_H

#include "agent.h"
#include "layout.h"
#include "pacman.h"

class Layout;
class Pacman;

class Ghost: public Agent{
    public:
        Ghost(int x, int y, Layout* layout);
        void move(Direction direction);
        void StartScareTime(int scareTime);
        void UpdateScareTime();
        void HandleCollision(Pacman* agent);
    private:
        int _scareTime;
};

#endif