//
// Created by francesco on 16/08/25.
//

#ifndef TIMER_TEMPO_H
#define TIMER_TEMPO_H
#include <iostream>
#include <chrono>
#include <thread>
#include "Data.h"
enum FormatoTempo{h24, h12};

class Tempo {
private:
    int ora;
    int minuto;
    int secondo;
    bool operativo;
    Data* data;

    public:
    Tempo (int ora, int minuto, int secondo, Data* data = nullptr);
    void tick();
    void ferma();
    int getOra() const;
    int getMinuto() const;
    int getSecondo() const;
    std::string toString(FormatoTempo formato) const;
};


#endif //TIMER_TEMPO_H