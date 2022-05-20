#pragma once
#include "benne.hpp"
#include "superAffichage.hpp"
#include "superTimer.hpp"
#include <memory>
#include <thread>
#include <list>
#include <iostream>


class Ouvrier{
    int etat;
public:
    Ouvrier();
    void gestion(std::list<std::unique_ptr<Benne>> &parkingExtractionBenne, std::list<std::unique_ptr<Benne>> &parkingTransportBenne, int &boisAScier, int &plancheAStocker, int &stockPlanche);
    void viderBenne(std::list<std::unique_ptr<Benne>> &parkingBenne,std::list<std::unique_ptr<Benne>> &parkingTransportBenne, int &boisAScier);
    void scier(int &boisAScier, int &plancheAStocker);
    void stocker(int &plancheAStocker,int &stockPlanche );
};