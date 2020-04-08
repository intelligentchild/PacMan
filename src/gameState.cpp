#include "gameState.h"

GameState::GameState():_score(0){}

void GameState::Initialize(std::string filename){
    _layout.InitializeLayout(filename);
    _score=0;
    for(Agent& agent:_layout.getAgents()){
        if(agent.getType()==AgentType::pacman)
            _pacman=&agent;
        else
            _ghosts.push_back(&agent);        
    }
}

int GameState::getScore() const {return _score;}

Layout& GameState::getLayout() {return _layout;}

Agent* GameState::getPacman() { return _pacman; }