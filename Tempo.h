//
// Created by francesco on 16/08/25.
//

#ifndef TIMER_TEMPO_H
#define TIMER_TEMPO_H
#include <iostream>
#include <chrono>
#include <thread>
#include "Data.h"

class Tempo {
private:
    int ora;
    int minuto;
    int secondo;
    bool operativo;
    Data* data;
    void tick();

    public:
    Tempo (int ora, int minuto, int secondo, Data* data = nullptr);
    void avanza();
    void ferma();
};


#endif //TIMER_TEMPO_H