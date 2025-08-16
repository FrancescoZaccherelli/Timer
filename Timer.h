//
// Created by francesco on 16/08/25.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H
#include <iostream>
#include<chrono>
#include <thread>

class Timer {
private:
    int ora;
    int minuto;
    int secondo;
    bool avviato;
    int secondiTotale;
public:
    Timer (int ora, int minuto, int secondo);
    void start();
    void stop();
    void reset();
};


#endif //TIMER_TIMER_H