
#include "debug.h"

#include "gameState.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



GameState::GameState():_score(0){}
GameState::~GameState(){
    DEBUG(std::cout<<"Destroying game state"<<std::endl);
}

void GameState::Initialize(std::string filename){
    _layout.InitializeLayout(filename);
    _score=0;
    //Take ownership of object
    for(Agent* agent:_layout.getAgents()){
        if(agent->getType()==AgentType::pacman)
            _pacman=std::unique_ptr<Pacman>((Pacman*)agent);
        else
            _ghosts.push_back(std::unique_ptr<Ghost>((Ghost*)agent));        
    }
}

void GameState::HandleCollision(Pacman* agent){
    //eat food
    if(_layout.consumeFood(agent->getX(),agent->getY())){
        _score += Score::food;
    }
    if(_layout.consumeCapsule(agent->getX(),agent->getY())){
        _score += Score::capsule;
        for(std::unique_ptr<Ghost>& ghost:_ghosts){
                ghost->StartScareTime(50);
        }
    }
    for(std::unique_ptr<Ghost>& ghost: _ghosts){
        if(ghost->getX()==agent->getX() && ghost->getY() ==agent->getY())
            ghost->HandleCollision(agent);
    }
};

int GameState::getScore() const {return _score;}

Layout& GameState::getLayout() {return _layout;}

std::unique_ptr<Pacman>& GameState::getPacman() { return _pacman; }

std::vector<std::unique_ptr<Ghost>>& GameState::getGhosts(){ return _ghosts; }