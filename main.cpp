#include "superAffichage.hpp"
#include "superTimer.hpp"
#include "benne.hpp"
#include "bucheron.hpp"
#include "foret.hpp"
#include "ouvrier.hpp"
#include "usine.hpp"
#include "transporteur.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>
#include <set>
#include <condition_variable>
#include <vector>
#include <memory>

using namespace std;
using namespace std::chrono;




int main(){
    SuperTimer* superTimer = SuperTimer::GetInstance();
    SuperAffichage* superAffichage = SuperAffichage::GetInstance();
    thread threadTimer(&SuperTimer::count, superTimer);
    thread threadAffichage(&SuperAffichage::affichage, superAffichage);
    Foret foret;
    foret.start();
    Usine usine;
    usine.start();
    Transporteur transporteur(ref(usine), ref(foret));
    thread threadTransporteur(&Transporteur::transporter, &transporteur);
    
   

    threadAffichage.join();
    threadTimer.detach();
    return 0;
}