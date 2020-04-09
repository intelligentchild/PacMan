
#include "agent.h"

Agent::Agent(int x, int y, AgentType agentType, Layout* layout):
    _x(x),_y(y), _agentType(agentType),_isAlive(true), _layout(layout){
}

void Agent::move(Direction direction) {
        
    switch (direction)
    {
    case Direction::north:{
        int newY =_y+1;
        if(!_layout->isWall(_x,newY))
            _y=newY;
        break;
    }
    case Direction::east:{
        int newX =_x+1;
        if(!_layout->isWall(newX,_y))
            _x=newX;
        break;
    }
    case Direction::south:{
        int newY =_y-1;
        if(!_layout->isWall(_x,newY))
            _y=newY;
        break;
    }
    case Direction::west:{
        int newX =_x-1;
        if(!_layout->isWall(newX,_y))
            _x=newX;
        break;    
    }
    case Direction::stop:
    default:
        break;
    }
}
bool Agent::killSelf(){
    std::cout<<"killing:"<<std::endl;
    if(isAlive()){
        _isAlive=false;
        return true;
    }
    return false;
}
bool Agent::isAlive() const {return _isAlive; }
bool Agent::isScareTime() const { return _isScareTime;}
int Agent::getX() const { return _x;}
int Agent::getY() const { return _y;}
int Agent::getType() const { return _agentType;}
Layout* Agent::getLayout() const { return _layout;}