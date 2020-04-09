
#ifndef LAYOUT_H
#define LAYOUT_H

#include<iostream>
#include<memory>
#include<vector>

#include "pacman.h"
#include "ghost.h"

class Grid{
    public:
        Grid(int width, int height):_width(width), _height(height) {
            _matrix = new bool*[_height];
            for(int i(0); i<_height; i++)
                _matrix[i]=new bool[_width];
        }
        ~Grid(){
            for(int i(0); i<_height; i++)
                delete[] _matrix[i];
        }

        bool isActive(int x, int y){ 
            if(x>=0 &&x<_width && y>=0 && y<_height)
                return _matrix[y][x];
            return false;
        }
        void setValue(int x, int y, bool value){ 
            if(x>=0 &&x<_width && y>=0 && y<_height)
                _matrix[y][x]=value;
        }
    private:
        int _width, _height;
        bool **_matrix;
};


class Layout
{
    public:
        int getWidth(){return _width;}
        int getHeight(){return _height;}
        bool InitializeLayout(std::string filename);
        bool isWall(int x, int y) const;
        bool isFood(int x, int y) const;
        int foodCount() const;
        bool isCapsule(int x, int y);
        bool consumeFood(int x, int y);
        bool consumeCapsule(int x, int y);
        std::vector<std::pair<int, int>>& getCapsules();
        std::vector<Agent*>& getAgents();
        std::vector<Direction> getLegalMoves(int x, int y);
        
    private:
        std::shared_ptr<Grid> _wallgrid;
        std::unique_ptr<Grid> _foodgrid;
        std::vector<std::pair<int, int>> _capsules;
        std::vector<Agent*> _agents;
        int _width, _height;
};

#endif