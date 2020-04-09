
#include <iostream>
#include <SDL2/SDL.h>

#ifndef CONTROLLER_IMPL_H
#define CONTROLLER_IMPL_H

template <typename AgentT>
void Controller<AgentT>::HandleInput(bool &running , AgentT *agent) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          agent->move(Direction::south);
          break;

        case SDLK_DOWN:
          agent->move(Direction::north);
          break;

        case SDLK_LEFT:
          agent->move(Direction::west);
          break;

        case SDLK_RIGHT:
          agent->move(Direction::east);
          break;
      }
    }
  }
}

template <typename AgentT>
void BotController<AgentT>::HandleInput(AgentT *agent) {
  std::vector<Direction> legalActions= agent->getLayout()->getLegalMoves(agent->getX(), agent->getY());
  if(legalActions.size()>0){
    int rand = getRandom(legalActions.size());
    agent->move(legalActions[rand]);
  }
}

template <typename AgentT>
int BotController<AgentT>::getRandom(int size) {
  std::uniform_int_distribution<> randomDist(0, size-1);
  return randomDist(_engine);
}

#endif