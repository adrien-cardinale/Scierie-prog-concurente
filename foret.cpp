#include "foret.hpp"

Foret::Foret():bucheron(){
    }

void Foret::start(){
    threadBucheron = std::thread(&Bucheron::CouperDuBois, &bucheron, ref(parkingRemplissageBenne), ref(parkingTransportBenne));
}

void Foret::stop(){
    threadBucheron.join();
}

