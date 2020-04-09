#include <random>
#include <SDL2/SDL.h>
#include "controller.h"
#include "gameState.h"

#include "renderer.h"


#ifndef GAME_H
#define GAME_H

class Game {
 public:
  Game(std::string mapFilename);
  template <typename T>
  void Run(Controller<T> const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

 private:

  std::string _mapFilename;
  GameState _gameState;
  bool _running;
  
  void Update();
};

#include "game_impl.h"

#endif
