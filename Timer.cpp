//
// Created by francesco on 16/08/25.
//

#include "Timer.h"

Timer::Timer (int ora, int minuto, int secondo) : ora(ora), minuto(minuto), secondo(secondo), avviato(false) {
    if (ora < 0 || ora > 23) {
        std::cout << "Errore: ora non valida" << std::endl;
    }
    if (minuto < 0 || minuto > 59) {
        std::cout << "Errore: minuto non valido" << std::endl;
    }
    if (secondo < 0 || secondo > 59) {
        std::cout << "Errore: secondo non valido" << std::endl;
    }
    secondiTotale = secondo + minuto*60 + ora*3600;
}

void Timer::start() {
    std::chrono::seconds durataTotale(secondiTotale);
    auto start = std::chrono::steady_clock::now();
    if (avviato != true) {
        avviato = true;
    }
    while (avviato == true) {
        auto sOra = std::chrono::steady_clock::now();
        auto sPassati = duration_cast<std::chrono::seconds>(sOra - start);
        auto sRimanenti = durataTotale - sPassati;

        if (sRimanenti.count() <= 0) {
            std::cout <<"Tempo scaduto"<<std::endl;
            break;
        }
        std::cout<<sRimanenti.count()<< " secondi"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }



}
void Timer::stop() {
    avviato = false;
    std::cout<<"Tempo fermato"<<std::endl;
};
void Timer::reset() {
    avviato = false;
    secondiTotale = 0;
    std::cout<<"Tempo resettato"<<std::endl;
};
