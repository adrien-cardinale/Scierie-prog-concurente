#include "superTimer.hpp"

std::mutex m;
std::condition_variable benneDisponibleBucheron;
std::condition_variable benneDisponibleTransporteurForet;
std::condition_variable benneDisponibleTransporteurUsine;
std::condition_variable benneDisponibleExtraction;

void SuperTimer::count(){
    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        tempsEcoule += 30;
        jours = tempsEcoule / 1440;
        heures = (tempsEcoule - jours * 1440) / 60;
        minutes = tempsEcoule - jours * 1440 - heures * 60;
        SuperAffichage::GetInstance()->updateTimer(jours, heures, minutes);
        if(bufferHeures != heures){
            bufferHeures = heures;
        }
    }
}

int SuperTimer::getJours(){
    return jours;
}

int SuperTimer::getHeures(){
   return heures;
}

int SuperTimer::getMinutes(){
    return minutes;
}

SuperTimer *SuperTimer::instance = nullptr;
SuperTimer *SuperTimer::GetInstance(){
    if(instance == nullptr){
        instance = new SuperTimer();
    }
    return instance;
}