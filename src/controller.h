#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "agent.h"

class Controller {
 public:
  void HandleInput(bool &running, Agent *agent) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif