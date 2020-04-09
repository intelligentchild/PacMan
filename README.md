# CppND: Pacman game
Pacman game I developed for udacity Cpp Nanodegree capstone project.

![Pacman Game gif](https://github.com/intelligentchild/PacMan/blob/master/pacman.gif)

##### Table of Contents 
- [Introduction](#introduction)
    - [Keyboard Interaction](#keyboard-interaction)
- [Dependencies](#dependencies-for-running-locally)
    - [Basic Build Instructions](#basic-build-instructions)
- [Project Files](#project-files)
- [Rubric Points](#rubic-points-addressed)

## Introduction
Capstone project for [Udacity's C++ Nanodegree program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213) 
 consisting on an implementation of the [2D Game Pacman](https://en.wikipedia.org/wiki/Pac-Man).
I used [CppND-Capstone-Snake-Game](https://github.com/udacity/CppND-Capstone-Snake-Game) as starter code.


#### Keyboard Interaction
The user can interact with the game using the following keys:

| Key             | Action                                  | 
| :-------------: |:----------------------------------------|
| Up              | move pacman up                          |
| Down            | move pacman down                        |
| Right           | move pacman right                       |
| Left            | move pacman left                        |

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
  * For arch linux run `sudo pacman -S sdl2`
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PacManGame`.

## Project Files

> ## `src\`

### `main.cpp`
[main.cpp](src/main.cpp) is the entry point for the game. It instaciates Game object, initializes and sets params and starts game by calling run function.

### `game.h` and `game.cpp`
[game.h](src/game.h), [game.cpp](src/game.h)
class handles main game loop. It contains game state as a member which has all state info.
### `game_impl.h`
contains definataion of `Game::Run`. It is a generic function that takes in generic controller.

### `gameState.h` and `gameState.cpp`
[gameState.h](src/gameState.h) and [gameState.cpp](src/gameState.cpp) Holds all game state info.
Intiuition is to seperate out game state so it can be stored or loaded and be used for ai bot
controller game as extension later on (future scope).
This class has all function defination needed to interact with the state info.

### `renderer.h` and `renderer.cpp`
[renderer.h](src/renderer.h) and [renderer.h](src/renderer.h)  class is ment to hold all renderer related functions.
This class takes Layout class as input, which contains all elements on map and renders it on ui.
Elements are walls, food, capsule and agents.

### `layout.h` and `layout.cpp`
[layout.h](src/layout.h) and [layout.cpp](src/layout.cpp) contains all elements and thier location on map.
Grid class is used to encapsulate and hold info about each cell. It is used to store food data and wall data.
Capsule is stored as vector of pair,  since they are few This saves space.
It also has vector of pointer to all agents, giving access to all agents location.
This class also defines map loading funtion to read map data from file.
It also defines collide function that handles pacmans collision with other objects(read #pacman section). 

### `agent.h` and `agent.cpp`
[agent.h](src/agent.h) and [agent.h](src/agent.h) This is a base class which encapsulates agents basic info like
co-ordinates, type of agent, is alive. It also defines function to move agents. It does this by quering the layout
if action is legal or not.

### `controller.h` and `controller_impl.h`
[controller.h](src/controller.h) and [controller_impl.h](src/controller_impl.h), Controller class is 
a generic class that takes an agent as parameter and controlles it. There are 2 controllers defined in here. 
`Controller` class handles input by reading keyboard input. While  
`BotController` class gives random input from possible legal moves.
More controllers can be defined to use ai to control agents(future scope)

### `pacman.h` and `pacman.cpp`
[pacman.h](src/pacman.h) and [pacman.cpp](src/pacman.cpp) This class inherits from `Agent` class and defines pacman 
specific behaviour. It calls collide function on `layout` class which handles its collission with all other objects
on map. This collision function is supposed to handle pacmans consumption of food and capsules and collision with ghosts.

### `ghost.h` and`ghost.cpp`
[ghost.h](src/ghost.h) and [ghost.cpp](src/ghost.cpp) class inherits from agent class and defines ghost specific behaviour.
It handles logic of if it hits pacman it kills it. But if scare time is running then it dies.


> ## `layouts/`
This folder contains bunch of pacman maps



## Rubic Points addressed
below are the rubic pints that are addressed/implemented in this project.
### Loops, Functions, I/O
| Rubric point  | Location |
| ------------- | ------------- |
| The project demonstrates an understanding of C++ functions and control structures.  |   Yes, check all the files
| The project reads data from a file and process the data, or the program writes data to a file.  | [Layout](src/layout.cpp) 
The project accepts user input and processes the input.  |   [controller](src/controller_impl.h)

### Object Oriented Programming
| Rubric point  | Location |
| ------------- | ------------- |
| The project uses Object Oriented Programming techniques.  |   Yes, check all the files
Classes use appropriate access specifiers for class members. | Yes, check all the files
Class constructors utilize member initialization lists. | Yes, check all the files
Classes abstract implementation details from their interfaces. | Yes, check all the files
Classes encapsulate behavior. | Yes, check all the files
Classes follow an appropriate inheritance hierarchy.| [agent](src/agent.h), [pacman](src/pacman.h) and [ghost](src/ghost.h) 
Templates generalize functions in the project.| [game](src/game_impl.h) and [controller](src/controller_impl.h) 

### Memory Management
| Rubric point  | Location |
| ------------- | ------------- |
| The project makes use of references in function declarations.  |   [pacman.cpp](src/pacman.cpp) Pacman::HandleCollision(GameState& gameState)
The project uses destructors appropriately. | [layout.cpp](src/layout.cpp) Grid class
The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | Yes, check all the files


## References
https://www.informit.com/articles/article.aspx?p=2928180&seqNum=4
