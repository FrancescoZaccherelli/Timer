//
// Created by francesco on 16/08/25.
//

#include "Timer.h"
#include <stdexcept>

Timer::Timer (int ora, int minuto, int secondo) : ora(ora), minuto(minuto), secondo(secondo) {
    if (ora < 0 || ora > 23) {
        throw std::invalid_argument("Timer: ora non valida (0-23)");
    }
    if (minuto < 0 || minuto > 59) {
        throw std::invalid_argument("Timer: minuto non valido (0-59)");
    }
    if (secondo < 0 || secondo > 59) {
        throw std::invalid_argument("Timer: secondo non valido (0-59)");
    }
    secondiTotale = secondo + minuto*60 + ora*3600;
}

// Va indietro du un scondo riaggiornando ora e minuti
void Timer::tick() {
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
