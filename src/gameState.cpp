#include "gameState.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


GameState::GameState():_score(0){}

void GameState::Initialize(std::string filename){
    _layout.InitializeLayout(filename);
    _score=0;
    
    for(Agent* agent:_layout.getAgents()){
        if(agent->getType()==AgentType::pacman)
            _pacman=(Pacman*) agent;
        else
            _ghosts.push_back((Ghost*)agent);        
    }
}

void GameState::HandleCollision(Pacman* agent){
    //eat food
    if(_layout.consumeFood(agent->getX(),agent->getY())){
        _score += Score::food;
    }
    if(_layout.consumeCapsule(agent->getX(),agent->getY())){
        _score += Score::capsule;
        for(Ghost* ghost:_ghosts){
                ghost->StartScareTime(50);
        }
    }
    for(Ghost* ghost: _ghosts){
        if(ghost->getX()==agent->getX() && ghost->getY() ==agent->getY())
            ghost->HandleCollision(agent);
    }
};

int GameState::getScore() const {return _score;}

Layout& GameState::getLayout() {return _layout;}

Pacman* GameState::getPacman() { return _pacman; }

std::vector<Ghost*>& GameState::getGhosts(){ return _ghosts; }