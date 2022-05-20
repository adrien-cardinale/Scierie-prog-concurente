#include "foret.hpp"

Foret::Foret():bucheron(){
    parkingRemplissageBenne.push_back(std::make_unique<Benne>(0));
}

void Foret::start(){
    threadBucheron = std::thread(&Bucheron::CouperDuBois, &bucheron, ref(parkingRemplissageBenne), ref(parkingTransportBenne));
}

void Foret::stop(){
    threadBucheron.join();
}

