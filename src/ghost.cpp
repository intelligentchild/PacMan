#include "ghost.h"

Ghost::Ghost(int x, int y, Layout* layout):
    Agent(x, y, AgentType::ghost, layout){
}

void Ghost::move(Direction direction){
    Agent::move(direction);
}
void Ghost::HandleCollision(){
    ;
}