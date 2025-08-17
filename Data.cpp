//
// Created by francesco on 16/08/25.
//

#include "Data.h"

#include <sstream>


Data::Data(int giorno, int mese, int anno)
    : giorno(giorno), mese(mese), anno(anno) {
    if (anno < 1900 || anno > 2100) {
        std::cout << "Errore: anno non valido" << std::endl;
    }
    if (anno % 4 == 0) {
        giorniFinali[1]= 29;
    }

    switch (mese) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (giorno > 31 || giorno < 1) {
                std::cout << "Errore: giorno non valido" << std::endl;
            }
            break;
        case 4: case 6: case 9: case 11:
            if (giorno > 30 || giorno < 1) {
                std::cout << "Errore: giorno non valido" << std::endl;
            }
            break;
        case 2:
            if (anno % 4 == 0 && (giorno > 29 || giorno < 1)) {
                std::cout << "Errore: giorno non valido" << std::endl;
            }
            if (anno % 4 != 0 && (giorno > 28 || giorno < 1)) {
                std::cout << "Errore: giorno non valido" << std::endl;
            }
            break;
        default:
            std::cout << "Errore: mese non valido" << std::endl;
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
    std::cout <<"\nNuova data : ";
    stampaData();

}

void Data::stampaData() {
    std::cout<<giorno<<"/"<<mese<<"/"<<anno<<std::endl;
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
            return std::to_string(giorno)+ std::to_string(mese)+ std::to_string(anno);
            break;
        case FormatoData::esteso:
            return std::to_string(giorno) + m[mese-1] + std::to_string(anno);
            break;
        case FormatoData::americano:
            return std::to_string(mese)+ std::to_string(giorno)+ std::to_string(anno);
            break;
    }
    return "C'è stato un errore imprevisto";
}



