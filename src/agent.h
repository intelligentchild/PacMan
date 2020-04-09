#include "layout.h"

#ifndef AGENT_H
#define AGENT_H

class Layout;

enum AgentType{
    pacman,
    ghost
};

enum Direction{
    north,
    east,
    south,
    west,
    stop
};

class Agent{
    public:
        Agent(int x, int y, AgentType agentType, Layout* layout);
        bool isAlive() const;
        int getX() const;
        int getY() const;
        int getType() const;
        Layout* getLayout() const;
        virtual void move(Direction direction);

    private:
        AgentType _agentType;
        Layout* _layout;
        bool _isAlive;
        int _x;
        int _y;
};

#endif