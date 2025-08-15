#include <iostream>

class Data {
private:
    int giorno;
    int mese;
    int anno;
public:
    Data (int giorno, int mese, int anno) : giorno(giorno), mese(mese), anno(anno) {
        if (anno < 1900 || anno > 2100) {
            std::cout << "Errore: anno non valido" << std::endl;
        }
        switch (mese) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (giorno > 31 || giorno < 1) {
                    std::cout << "Errore: giorno non valido" << std::endl;
                }
            case 4:
            case 6:
            case 9:
            case 11:
                if (giorno > 30 || giorno < 1) {
                    std::cout << "Errore: giorno non valido" << std::endl;
                }
            case 2:
                if (anno % 4 == 0 && giorno > 29 && giorno < 1) {

                    std::cout << "Errore: giorno non valido" << std::endl;
                }
                if (anno % 4 != 0 && giorno > 28 && giorno < 1) {

                    std::cout << "Errore: giorno non valido" << std::endl;
                }
        }
    }

};

class Tempo{
    private:
        int ora;
        int minuti;
        int secondi;
    public:
        Tempo (int ora, int minuto, int secondo) : ora(ora), minuti(minuto), secondi(secondo) {
            if (ora < 0 || ora > 23) {
                std::cout << "Errore: ora non valida" << std::endl;
            }
            if (minuto < 0 || minuto > 59) {
                std::cout << "Errore: minuto non valido" << std::endl;
            }
            if (secondo < 0 || secondo > 59) {
                std::cout << "Errore: secondo non valido" << std::endl;
            }
        }
        void avanza(){};
   };

int main() {
    Data data(14, 8, 2025);

}