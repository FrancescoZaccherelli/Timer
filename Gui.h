#ifndef TIMER_GUI_H
#define TIMER_GUI_H

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTimer>
#include <QHBoxLayout>

#include "Data.h"
#include "Tempo.h"
#include "Timer.h"

class Gui : public QWidget {
public:
    // Riceve i dati dei costruttori dal main
    explicit Gui(const Data dataInit, const Tempo tempoInit, const Timer timerInit, QWidget* parent = nullptr);

private:
    // vari parti della ui
    QVBoxLayout* mainLayout{};
    QHBoxLayout* topLayout{};
    QLabel* dataLabel{};
    QLabel* oraLabel{};
    QComboBox* dataFmtCombo{};
    QComboBox* tempoFmtCombo{};

    QLabel* timerLabel{};
    QHBoxLayout* rowBtns{};
    QPushButton* startBtn{};
    QPushButton* stopBtn{};

    // Timer basati su QTimer
    QTimer* orologio{};
    QTimer* orologioTimer{};

    //  copia degli oggetti presi dal main
    Data data;
    Tempo tempo;
    Timer timer;

    // Ritorna i formato corrente presente nel menù a tendina
    FormatoData FormatoDataCorrente() const;
    FormatoTempo FormatoTempoCorrente() const;

private:
    void onTickOrologio();
    void onTickTimer();
    void onStart();
    void onStop();
    void CambioFormatoData(int);
    void CambioFormatoTempo(int);
};

#endif //TIMER_GUI_H