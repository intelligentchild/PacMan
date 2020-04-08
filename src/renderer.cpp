#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Layout& layout) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Draw walls
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0xFF, 0xFF);
  for(int x(0); x<layout.getWidth(); x++){
    for(int y(0); y<layout.getHeight(); y++){
      if(layout.isWall(x, y)){
        block.x = x * block.w;
        block.y = y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
      }
    }
  }
  // Draw Food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xA5, 0x00, 0xFF);
  for(int x(0); x<layout.getWidth(); x++){
    for(int y(0); y<layout.getHeight(); y++){
      if(layout.isFood(x, y)){
        block.x = x * block.w;
        block.y = y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
      }
    }
  }
  // Draw Capsule
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xC0, 0xCB, 0xFF);
  for(std::pair<int, int>& caps: layout.getCapsules()){
    block.x = caps.first * block.w;
    block.y = caps.second * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }
  // Draw Agents
  for(Agent& agent: layout.getAgents()){
    
    if(agent.getType()==AgentType::pacman)  // pacman
     SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0x00, 0xFF);
    else                                    // ghost
     SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xC0, 0xCB, 0xFF);
    block.x = agent.getX() * block.w;
    block.y = agent.getY() * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }



  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Pacman Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
