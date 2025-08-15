#include <iostream>
#include <chrono>
#include <thread>

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
        int minuto;
        int secondo;
        bool operativo;

    void tick(){
        secondo++;
        if (secondo >= 60) {
            secondo = 0;
            minuto++;
            if (minuto >= 60) {
                minuto = 0;
                ora++;
                if (ora >= 24) {
                    ora = 0;
                }
            }
        }
    }
    public:
        Tempo (int ora, int minuto, int secondo) : ora(ora), minuto(minuto), secondo(secondo) , operativo(false) {
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

        void avanza() {
            operativo = true;
            while (operativo) {
                std::cout << "\r"
                         << std::setw(2) << std::setfill('0') << ora << ":"
                         << std::setw(2) << std::setfill('0') << minuto << ":"
                         << std::setw(2) << std::setfill('0') << secondo
                         << std::flush;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                tick();

            }
        }
   };
class Timer {
private:
    int ora;
    int minuto;
    int secondo;
    bool avviato;
    int secondiTotale;
public:
    Timer (int ora, int minuto, int secondo) : ora(ora), minuto(minuto), secondo(secondo), avviato(false) {
        if (ora < 0 || ora > 23) {
            std::cout << "Errore: ora non valida" << std::endl;
        }
        if (minuto < 0 || minuto > 59) {
            std::cout << "Errore: minuto non valido" << std::endl;
        }
        if (secondo < 0 || secondo > 59) {
            std::cout << "Errore: secondo non valido" << std::endl;
        }
        secondiTotale = secondo + minuto*60 + ora*3600;
    }

        void start() {
        std::chrono::seconds durataTotale(secondiTotale);
        auto start = std::chrono::steady_clock::now();
        if (avviato != true) {
            avviato = true;
        }
        while (avviato == true) {
            auto sOra = std::chrono::steady_clock::now();
            auto sPassati = duration_cast<std::chrono::seconds>(sOra - start);
            auto sRimanenti = durataTotale - sPassati;

            if (sRimanenti.count() <= 0) {
                std::cout <<"Tempo scaduto"<<std::endl;
                break;
            }
            std::cout<<sRimanenti.count()<< " secondi"<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }



    }
        void stop() {
        avviato = false;
        std::cout<<"Tempo fermato"<<std::endl;
    };
        void reset() {
            avviato = false;
            secondiTotale = 0;
            std::cout<<"Tempo resettato"<<std::endl;
        };
};

int main() {
    Timer timer(0, 0, 10);
    timer.start();
    Tempo Orario(20 , 59, 50);
    Orario.avanza();


}