#include "pacman.h"

Pacman::Pacman(int x, int y, Layout* layout):
    Agent(x, y, AgentType::pacman, layout){
}

void Pacman::move(Direction direction){
    Agent::move(direction);

}

void Pacman::HandleCollision(){

}