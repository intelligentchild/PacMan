

#ifndef GAME_IMPL_H
#define GAME_IMPL_H

template <typename T>
void Game::Run(Controller<T> const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 update_timestamp = SDL_GetTicks();
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  BotController<Ghost> botController;

  //Initialize GameState
  _gameState.Initialize(_mapFilename);

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    // slow down bot from moving very fast
    if (frame_start - update_timestamp >= 200) {
      Pacman *pacman = _gameState.getPacman();
      controller.HandleInput(running, pacman);
      for(Ghost* agent: _gameState.getGhosts()){
        botController.HandleInput(agent);
      }
      update_timestamp = frame_start;
    }
    Update();
    renderer.Render(_gameState.getLayout());

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(GetScore(), frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}



#endif
