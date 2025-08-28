#ifndef TIMER_GUI_H
#define TIMER_GUI_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "Data.h"
#include "Tempo.h"
#include "Timer.h"

class Gui : public QWidget {
public:
    // Costruttore che riceve i modelli inizializzati nel main
    explicit Gui(const Data& dataInit, const Tempo& tempoInit, const Timer& timerInit, QWidget* parent = nullptr);

private:
    // UI
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

    // Timers
    QTimer* orologio{};
    QTimer* orologioTimer{};

    // Modello (copie degli oggetti passati dal main)
    Data data;
    Tempo tempo;
    Timer timer;

    // Helpers
    FormatoData currentDataFmt() const;
    FormatoTempo currentTempoFmt() const;

private:
    void onTickOrologio();
    void onTickTimer();
    void onStart();
    void onStop();
    void onDataFmtChanged(int);
    void onTempoFmtChanged(int);
};

#endif //TIMER_GUI_H