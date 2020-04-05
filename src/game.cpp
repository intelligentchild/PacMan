#include<iostream>

#include "game.h"

Game::Game(){

}

void Game::RunLoop() {
    while(mIsRunning){
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

bool Game::Initialize() {
    bool mIsRunning = false;
    // Initializing video subsystem
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if(sdlResult !=0){
        SDL_Log("Unabl to initialize SDL: %s", SDL_GetError());
        return mIsRunning;
    }
    // Creating window
    mWindow = SDL_CreateWindow(
        "PacMan",   // Window title
        100,    // Top left x-coordinate of window
        100,    // Top left y-coordinate of window
        1024,   // Width of window
        768,    // Heigh of window
        SDL_WINDOW_SHOWN       // Flags (0 for no flags set)
    );
    if(!mWindow){
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return mIsRunning;
    }
    
    mIsRunning = true;
    return mIsRunning;
}

void Game::ProcessInput(){
}

void Game::UpdateGame(){
}
void Game::GenerateOutput(){
}

void Game::Shutdown(){
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

