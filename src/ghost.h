#ifndef GHOST_H
#define GHOST_H

#include "agent.h"
#include "layout.h"

class Layout;

class Ghost: public Agent{
    public:
        Ghost(int x, int y, Layout* layout);
        void move(Direction direction);
        void HandleCollision();
};

#endif