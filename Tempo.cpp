//
// Created by francesco on 16/08/25.
//

#include "Tempo.h"

Tempo::Tempo(int ora, int minuto, int secondo, Data* data) : ora(ora), minuto(minuto), secondo(secondo),
                                                                       operativo(false), data(data) {
    if (ora < 0 || ora > 23) {
        std::cout << "Errore: ora non valida" << std::endl;
    }
    if (minuto < 0 || minuto > 59) {
        std::cout << "Errore: minuto non valido" << std::endl;
    }
    if (secondo < 0 || secondo > 59) {
        std::cout << "Errore: secondo non valido" << std::endl;
    }
}
    void Tempo::tick(){
        secondo++;
        if (secondo >= 60) {
            secondo = 0;
            minuto++;
            if (minuto >= 60) {
                minuto = 0;
                ora++;
                if (ora >= 24) {
                    ora = 0;
                    if (data) {
                        data->avanzaData();
                    }
                }
            }
        }
    }

void Tempo::avanza() {
    operativo = true;
    while (operativo) {
        std::cout << "\r"
                 << std::setw(2) << std::setfill('0') << ora << ":"
                 << std::setw(2) << std::setfill('0') << minuto << ":"
                 << std::setw(2) << std::setfill('0') << secondo
                 << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        tick();

    }
}

void Tempo::ferma() {
    operativo = false;
}