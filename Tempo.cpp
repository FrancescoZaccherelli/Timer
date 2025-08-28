//
// Created by francesco on 16/08/25.
//

#include "Tempo.h"
#include <stdexcept>

Tempo::Tempo(int ora, int minuto, int secondo, Data* data)
    : ora(ora), minuto(minuto), secondo(secondo), data(data) {
    if (ora < 0 || ora > 23) {
        throw std::invalid_argument("Tempo: ora non valida (0-23)");
    }
    if (minuto < 0 || minuto > 59) {
        throw std::invalid_argument("Tempo: minuto non valido (0-59)");
    }
    if (secondo < 0 || secondo > 59) {
        throw std::invalid_argument("Tempo: secondo non valido (0-59)");
    }
}

// Avanza di un secondo in base ai minuti e alle ore
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
int Tempo::getOra() const {
    return ora;
}
int Tempo::getMinuto() const {
    return minuto;
}
int Tempo::getSecondo() const {
    return secondo;
}

// Ritorna il temo in uno dei due formati
std::string Tempo::toString(FormatoTempo formato) const {
    int mostraOra = ora;
    std::string amPm = "";
    if (formato == h12) {
        amPm = (ora >= 12) ? " PM" : " AM";
        mostraOra = ora % 12;
        if (mostraOra == 0) mostraOra = 12;
    }
    std::string minStr = (minuto < 10) ? "0" + std::to_string(minuto) : std::to_string(minuto);
    std::string secStr = (secondo < 10) ? "0" + std::to_string(secondo) : std::to_string(secondo);
    std::string oraStr = (mostraOra < 10 && formato == h24) ? "0" + std::to_string(mostraOra) : std::to_string(mostraOra);

    return oraStr + ":" + minStr + ":" + secStr + amPm;
}



