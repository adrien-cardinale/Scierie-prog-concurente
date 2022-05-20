#pragma once
#include "benne.hpp"
#include "ouvrier.hpp"
#include <thread>
#include <vector>
#include <memory>

class Usine{
    Ouvrier ouvrier;
    std::thread threadOuvrier;
    int boisAScier;
    int planchAStocker;
    int stockPlanche;
protected:
    std::vector<std::unique_ptr<Benne>> parkingExtractionBenne;
    std::vector<std::unique_ptr<Benne>> parkingTransportBenne;
public:
    Usine();
    void start();
    void stop();
    friend class Transporteur;
};