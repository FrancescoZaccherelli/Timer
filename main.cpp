#include "Data.h"
#include "Tempo.h"
#include "Timer.h"

int main() {
    Data d(31, 12, 2025);
    Tempo t(23, 59, 55, &d); // legato alla data

    d.stampaData();   // stampa data iniziale
    t.avanza();       // quando scatta mezzanotte vedrai nuova data

    return 0;

    return 0;


}