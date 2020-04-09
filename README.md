# CppND: Pacman game
Pacman game I developed from for udacity Cpp Nanodegree capstone project.

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

### `src\`
### `main.cpp`
sets init game params and starts game

###`game.h`
	class holds and drives the whole game
	It contains game state which has all state info
###`game_impl.h`
	contains definataion of run (since it is generic function)
###`game.cpp`
	defination of game class

###`gameState.h`
	Holds all state info
	Idea is to seperate out game state so it can be stored or loaded
	and be used for ai bot controller game as extension later on
###`gameState.cpp`
	contains all gamesate defination

### `renderer.h`
	this class is ment to hold all renderer related info
###`renderer.cpp`
	all object drawing on ui is handled in here
	it takes layout as input and draws 
	walls, food, capsule and agents

### `laout.h`
	holds all info as a map
	grid class is used to encapsulate and hold info about each cell
	capsule is stored as list since they are few
	has vector of pointer to agents giving access to all agents location
layout.cpp
	has map loading funtion and all other function to access members

### `agent.h`
	this is base class which encapsulates agent info
	location of agent. It also defines how agent can move
	It accesses layout to query legal position and moves
### `agent.cpp`
	contains all defination

### `controller.h`, `controller_impl.h`
Controller class handles input using keyboard input
VotController class gives random input

### `pacman.h`, `pacman.cpp`
Inherits from agent class and defines pacman specific behaviour
While moving on map

### `ghost.h`,`ghost.cpp`
Inherits from agent class and defines pacman specific behaviour

### `layouts/`
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
| The project makes use of references in function declarations.  |   []()
The project uses destructors appropriately. | []()
The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | Yes, check all the files
The project uses move semantics to move data, instead of copying it, where possible. | []()


## References
https://www.informit.com/articles/article.aspx?p=2928180&seqNum=4
