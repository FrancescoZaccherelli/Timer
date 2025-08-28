//
// Created by francesco on 16/08/25.
//

#include "Data.h"


#include <sstream>
#include <stdexcept>

Data::Data(int giorno, int mese, int anno)
    : giorno(giorno), mese(mese), anno(anno) {
    if (anno < 1900 || anno > 2100) {
        throw std::invalid_argument("Data: anno non valido (1900-2100)");
    }
    if (anno % 4 == 0) {
        giorniFinali[1] = 29;
    }

    if (mese < 1 || mese > 12) {
        throw std::invalid_argument("Data: mese non valido (1-12)");
    }


    if (giorno < 1 || giorno > giorniFinali[mese - 1]) {
        throw std::invalid_argument("Data: giorno non valido per il mese specificato");
    }
}

void Data::avanzaData() {
    giorno++;
    if (giorno >= giorniFinali[mese-1]){
        giorno = 1;
        mese++;
        if (mese++ >= 12) {
            mese = 1;
            anno++;
        }
    }
}



int Data::getGiorno() const{
    return giorno;
}
int Data::getMese() const {
    return mese;
}
int Data::getAnno() const{
    return anno;
}

std::string Data::toString(FormatoData formato) const {

    switch (formato) {
        case FormatoData::breve:
            return std::to_string(giorno)+" "+ std::to_string(mese)+ " "+std::to_string(anno);
            break;
        case FormatoData::esteso:
            return std::to_string(giorno) +" "+ m[mese-1] +" "+ std::to_string(anno);
            break;
        case FormatoData::americano:
            return std::to_string(mese)+" "+ std::to_string(giorno)+" "+ std::to_string(anno);
            break;
    }
    return "C'è stato un errore imprevisto";
}



