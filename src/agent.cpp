
#include "agent.h"

Agent::Agent(int x, int y, AgentType agentType):
    _x(x),_y(y), _agentType(agentType),_isAlive(true){
}

void Agent::move(Direction direction) {
    //TODO: can move
    
    switch (direction)
    {
    case Direction::north:
        _y+=1;
        break;
    case Direction::east:
        _x+=1;
        break;
    case Direction::south:
        _y-=1;
        break;
    case Direction::west:
        _x-=1;
        break;    
    default:
        break;
    }
}

bool Agent::isAlive() const {return _isAlive; }
int Agent::getX() const { return _x;}
int Agent::getY() const { return _y;}
int Agent::getType() const { return _agentType;}