#pragma once
#include "benne.hpp"
#include "bucheron.hpp"
#include <list>
#include <memory>
#include <thread>

class Foret{
    Bucheron bucheron;
    std::thread threadBucheron;
protected:
    std::list<std::unique_ptr<Benne>> parkingRemplissageBenne;
    std::list<std::unique_ptr<Benne>> parkingTransportBenne;
public:
    Foret();
    void start();
    void stop();
    friend class Transporteur;
};