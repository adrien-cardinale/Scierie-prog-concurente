#include "usine.hpp"

Usine::Usine():ouvrier(), boisAScier(0), planchAStocker(0), stockPlanche(0){
    parkingTransportBenne.push_back(std::make_unique<Benne>(0));
    parkingTransportBenne.push_back(std::make_unique<Benne>(0));
    parkingTransportBenne.push_back(std::make_unique<Benne>(0));
}

void Usine::start(){
    threadOuvrier = std::thread(&Ouvrier::gestion, &ouvrier, std::ref(parkingExtractionBenne), std::ref(parkingTransportBenne), std::ref(boisAScier), std::ref(planchAStocker), std::ref(stockPlanche));
}

void Usine::stop(){
    threadOuvrier.join();
}