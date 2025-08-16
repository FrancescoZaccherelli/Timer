//
// Created by francesco on 16/08/25.
//

#ifndef TIMER_DATA_H
#define TIMER_DATA_H
#include <iostream>
#include <vector>

class Data {
private:
    int giorno;
    int mese;
    int anno;
    friend class Tempo;
    void avanzaData();

    std::vector<int> giorniFinali={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Data (int giorno, int mese, int anno);
    void stampaData();
};


#endif //TIMER_DATA_H