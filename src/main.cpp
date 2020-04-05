
#include <iostream>
#include "game.h"

int main(int argc, char** argv){
    Game game;
    bool sucess = game.Initialize();
    std::cout<<"Starting game"<< std::endl;
    if(sucess){
        game.RunLoop();
    }
    std::cout<<"shutting down.."<< std::endl;
    game.Shutdown();
    return 0;
}