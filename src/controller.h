#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "agent.h"
#include <random>

template <typename AgentT>
class Controller {
    public:
        void HandleInput(bool &running, AgentT *agent) const;
};

template <typename AgentT>
class BotController{
    public:
        BotController():_engine(_dev()){}
        void HandleInput(AgentT *agent) ;
        int getRandom(int size) ;
    private:
        std::random_device _dev;
        std::mt19937 _engine;

};
#endif

#include "controller_impl.h"