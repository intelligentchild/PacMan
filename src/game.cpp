#include "game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "gameState.h"

#include "pacman.h"
#include "ghost.h"

Game::Game(std::string mapFilename)
    : _mapFilename(mapFilename){
}


void Game::Update() {
  //TODO:
}


int Game::GetScore() const{return _gameState.getScore();}