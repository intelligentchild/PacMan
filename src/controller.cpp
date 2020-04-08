#include "controller.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running , Agent *player) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          player->move(Direction::south);
          break;

        case SDLK_DOWN:
          player->move(Direction::north);
          break;

        case SDLK_LEFT:
          player->move(Direction::west);
          break;

        case SDLK_RIGHT:
          player->move(Direction::east);
          break;
      }
    }
  }
}