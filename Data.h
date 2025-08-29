//
// Created by francesco on 16/08/25.
//

#ifndef TIMER_DATA_H
#define TIMER_DATA_H

#include <vector>
#include <string>

enum class FormatoData{breve, esteso, americano};

class Data {
private:
    int giorno;
    int mese;
    int anno;
    FormatoData formato;



    std::vector<int> giorniFinali={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<std::string> m={ "Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};
public:
    Data(int giorno, int mese, int anno);

    void avanzaData();

    int getGiorno() const;
    int getMese() const;
    int getAnno() const;

    std::string toString(FormatoData formato) const;
};


#endif //TIMER_DATA_H