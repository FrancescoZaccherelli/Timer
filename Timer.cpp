//
// Created by francesco on 16/08/25.
//

#include "Timer.h"

Timer::Timer (int ora, int minuto, int secondo) : ora(ora), minuto(minuto), secondo(secondo) {
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


void Timer::tick() { // un passo di 1 secondo
    if (secondiTotale <= 0) return;
    secondiTotale--;
    ora = secondiTotale / 3600;
    minuto = (secondiTotale % 3600) / 60;
    secondo = secondiTotale % 60;
}

int Timer::getOra() {
    return ora;
}
int Timer::getMinuto() {
    return minuto;
}
int Timer::getSecondo() {
    return secondo;
}
