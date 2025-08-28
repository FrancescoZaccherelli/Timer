//
// Created by francesco on 16/08/25.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H

class Timer {
private:
    int ora;
    int minuto;
    int secondo;
    bool avviato;
    int secondiTotale;
public:
    Timer (int ora, int minuto, int secondo);
    void tick();
    void stop();
    void reset();
    int getOra();
    int getMinuto();
    int getSecondo();
};


#endif //TIMER_TIMER_H