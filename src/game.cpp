#include "game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "gameState.h"
#include<thread>

#include "pacman.h"
#include "ghost.h"

Game::Game(std::string mapFilename)
    : _mapFilename(mapFilename){
}


void Game::Update() {
  //hang the screen so user can see how he died
  
  if (!_gameState.getPacman()->isAlive()){
    std::cout<<"You Loose!! Better Luck Next Time"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    _running= false;
  }
  if(_gameState.getLayout().foodCount()<=0){
    std::cout<<"You win!!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    _running=false;
  }
}

int Game::GetScore() const{return _gameState.getScore();}