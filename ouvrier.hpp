#pragma once
#include "benne.hpp"
#include "superAffichage.hpp"
#include "superTimer.hpp"
#include <memory>
#include <thread>
#include <vector>
#include <iostream>


class Ouvrier{
    int etat;
public:
    Ouvrier();
    void gestion(std::vector<std::unique_ptr<Benne>> &parkingExtractionBenne, std::vector<std::unique_ptr<Benne>> &parkingTransportBenne, int &boisAScier, int &plancheAStocker, int &stockPlanche);
    void viderBenne(std::vector<std::unique_ptr<Benne>> &parkingBenne,std::vector<std::unique_ptr<Benne>> &parkingTransportBenne, int &boisAScier);
    void scier(int &boisAScier, int &plancheAStocker);
    void stocker(int &plancheAStocker,int &stockPlanche );
};