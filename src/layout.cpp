#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "layout.h"

enum class LayoutSymbol: char{
    wall = '%',
    food = '.',
    capsule = 'o',
    pacman = 'P',
    ghost1 = '1',
    ghost2 = '2',
    ghost3 = '3',
    ghost4 = '4'

};

bool Layout::InitializeLayout(std::string filename){
    
    std::ifstream layoutFile(filename);
    if(!layoutFile.is_open()){
        std::cerr<<"Could not open file: "<< filename<<std::endl;
        return false;
    }
    std::vector<std::string> layoutStr;
    std::string str;
    while(getline(layoutFile,str)){
        layoutStr.push_back(str);
    }
    layoutFile.close();

    if(layoutStr.size()<=0 || layoutStr[0].size()<=0){
        std::cerr<<"file is empty: "<< filename<<std::endl;
        return false;
    }
    _width=layoutStr[0].size();
    _height=layoutStr.size();
    // initialize grids
    _wallgrid = std::make_shared<Grid>(_width, _height);
    _foodgrid = std::make_unique<Grid>(_width, _height);

    const std::vector<char> ghostSym = {'1','2','3','4'};
    for(int y(0); y<_height; y++){
        for(int x(0); x<_width; x++){
            char symb = layoutStr[y][x];
            // wall
            if(symb == '%' ) {
                //std::cout<<layoutStr[y][x];
                _wallgrid->setValue(x, y, true);
                std::cout<< _wallgrid->isActive(x, y);
            }else{
                std::cout<<' ';
                _wallgrid->setValue(x, y, false);
            } 

            // food
            if(symb == '.' ) _foodgrid->setValue(x, y, true);
            else _foodgrid->setValue(x, y, false);

            if(symb == 'o' ) { // capsule
                _capsules.push_back(std::pair<int, int>(x,y));
            }else if(symb == 'P' ) { // pacman
                Agent pacman(x, y, AgentType::pacman);
                _agents.emplace_back(pacman);
            }else if(symb == 'G' ) { // ghost
                Agent ghost(x, y, AgentType::ghost);
                _agents.emplace_back(ghost);
            }else if(ghostSym.end() != std::find(ghostSym.begin(), ghostSym.end(), symb)) { //ghosts
                Agent ghost(x, y, AgentType::ghost);
                _agents.emplace_back(ghost);
            }
        }std::cout<<std::endl;
    }
    return true;
}

bool Layout::isWall(int x, int y) const{
    return _wallgrid->isActive(x, y);
}

bool Layout::isFood(int x, int y) const {
    return _foodgrid->isActive(x, y);
}

bool Layout::isCapsule(int x, int y) {
    for(std::pair<int, int> &capsule: _capsules){
        if(capsule.first==x && capsule.second==y)
            return true;
    }
    return false;
}

std::vector<std::pair<int, int>>& Layout::getCapsules() {
    return _capsules;
}

std::vector<Agent>& Layout::getAgents(){
    return _agents;
}


// int main(){
//     Layout layout;
//     //std::string filename ="../layouts/tinyMaze.lay";
//     //std::string filename ="../layouts/smallClassic.lay";
//     std::string filename = "../layouts/tinySafeSearch.lay";
//     layout.InitializeLayout(filename);
    
//     std::cout<<std::endl;
//     std::cout<<"x:y::"<<layout.getWidth()<<":"<<layout.getHeight()<<std::endl;

//     for(int i(0); i<layout.getHeight(); i++){
//         for(int j(0); j<layout.getWidth(); j++){
//             std::cout<< layout.isWall(i,j);
//         }std::cout<<std::endl;
//     }std::cout<<std::endl;

//     for(int i(0); i<layout.getHeight(); i++){
//         for(int j(0); j<layout.getWidth(); j++){
//             std::cout<< layout.isFood(i,j);
//         }std::cout<<std::endl;
//     }std::cout<<std::endl;

//     for(int i(0); i<layout.getHeight(); i++){
//         for(int j(0); j<layout.getWidth(); j++){
//             std::cout<< layout.isCapsule(i,j);
//         }std::cout<<std::endl;
//     }std::cout<<std::endl;

//     std::cout<<"Size: "+layout.getAgents().size()<<std::endl;

//     for(int i(0); i<layout.getHeight(); i++){
//         for(int j(0); j<layout.getWidth(); j++){
//             for(Agent& agent:layout.getAgents()){
//                 if(agent.getX()==i && agent.getY()==j){
//                     std::cout<<(agent.getType()==AgentType::pacman?'P':'G');
//                 }
//             }
//         }std::cout<<std::endl;
//     }std::cout<<std::endl;
// }