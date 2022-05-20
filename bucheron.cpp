#include "bucheron.hpp"

void Bucheron::CouperDuBois(std::list<std::unique_ptr<Benne>> &parkingRemplissageBenne, std::list<std::unique_ptr<Benne>> &parkingTransportBenne){
        int etat = 0;
        SuperTimer* superTimer = SuperTimer::GetInstance();
        SuperAffichage* superAffichage = SuperAffichage::GetInstance();
        while(true){
            superAffichage->updateBenneForet(std::ref(parkingRemplissageBenne), std::ref(parkingTransportBenne));
            switch (etat)
            {
                case 0:{
                    if(superTimer->getHeures() >= 8 && superTimer->getHeures() <= 17)
                        etat = 1;
                    break;
                }case 1:{
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    etat = 2;
                    break;
                }case 2:{
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    etat = 3;
                    break;
                }case 3:{
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    etat = 4;
                    break;
                }case 4:{
                    std::unique_lock<std::mutex> lock(m);
                    if(parkingRemplissageBenne.empty()){
                        benneDisponibleBucheron.wait(lock);
                    }
                    etat = 5;
                    break;
                }case 5:{
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    if(parkingRemplissageBenne.front()->getEtat() == 10){
                        etat = 6;
                    }else{
                        etat = 7;
                    }
                    break;
                }case 6:{
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    parkingTransportBenne.push_back(std::move(parkingRemplissageBenne.front()));
                    parkingRemplissageBenne.pop_front();
                    benneDisponibleTransporteurForet.notify_one();
                    etat = 4;
                    break;
                }case 7:{
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    parkingRemplissageBenne.front()->remplirBenne();
                    etat = 0;
                    break;
                }
            }
            superAffichage->updateBucheron(etat);
            superAffichage->updateBenneForet(std::ref(parkingRemplissageBenne), std::ref(parkingTransportBenne));
        }
    }