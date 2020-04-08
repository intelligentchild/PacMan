#ifndef AGENT_H
#define AGENT_H

enum AgentType{
    pacman,
    ghost
};

enum Direction{
    north,
    east,
    south,
    west
};

class Agent{
    public:
        Agent(int x=0, int y=0, AgentType agentType=AgentType::ghost);
        bool isAlive() const;
        int getX() const;
        int getY() const;
        int getType() const;
        void move(Direction direction);

    private:
        AgentType _agentType;
        bool _isAlive;
        int _x;
        int _y;
};

#endif