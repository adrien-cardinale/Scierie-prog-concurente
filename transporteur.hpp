#pragma once
#include "benne.hpp"
#include "superAffichage.hpp"
#include "superTimer.hpp"
#include "foret.hpp"
#include "usine.hpp"
#include <mutex>
#include <condition_variable>
#include <memory>
#include <thread>
#include <vector>

class Transporteur{
    std::vector<std::unique_ptr<Benne>> &parkingExtractionUsine;
    std::vector<std::unique_ptr<Benne>> &parkingTransportUsine;
    std::vector<std::unique_ptr<Benne>> &parkingRemplissageForet;
    std::vector<std::unique_ptr<Benne>> &parkingTransportForet;
    std::unique_ptr<Benne> benne;
public:
    Transporteur(Usine &usine, Foret &foret);
    void transporter();
};