#include "ghost.h"

Ghost::Ghost(int x, int y, Layout* layout): _scareTime(0),
    Agent(x, y, AgentType::ghost, layout){
        _isScareTime=false;
        
}

void Ghost::move(Direction direction){
    Agent::move(direction);
    UpdateScareTime();
}

void Ghost::UpdateScareTime(){
    if(_isScareTime && _scareTime>0){
        _scareTime--;
        if(_scareTime<=0){
            _isScareTime=false;
        }
    }
}

void Ghost::StartScareTime(int scareTime){
    _isScareTime=true;
    _scareTime+=scareTime;
}

void Ghost::HandleCollision(Pacman* agent){
    if(isAlive()){
        if(_isScareTime){
            killSelf();
        }else{
            ((Agent*)agent)->killSelf();
        }
    }
};