#pragma once
#include "benne.hpp"
#include "superAffichage.hpp"
#include "superTimer.hpp"
#include <memory>
#include <thread>
#include <list>


class Bucheron{
public:
    void CouperDuBois(std::list<std::unique_ptr<Benne>> &parkingBenneVide, std::list<std::unique_ptr<Benne>> &parkingBennePlein);
};