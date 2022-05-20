#pragma once
#include "benne.hpp"
#include "superAffichage.hpp"
#include "superTimer.hpp"
#include <memory>
#include <thread>
#include <vector>


class Bucheron{
public:
    void CouperDuBois(std::vector<std::unique_ptr<Benne>> &parkingBenneVide, std::vector<std::unique_ptr<Benne>> &parkingBennePlein);
};