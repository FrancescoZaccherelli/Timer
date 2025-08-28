// Gui.cpp
#include "Gui.h"
#include <QString>
#include <QChar>

Gui::Gui(const Data& dataInit, const Tempo& tempoInit, const Timer& timerInit, QWidget* parent)
    : QWidget(parent),
      data(dataInit),
      tempo(tempoInit),
      timer(timerInit) {

    setWindowTitle("App");
    resize(800, 600);

    // Layout principali
    mainLayout = new QVBoxLayout(this);

    topLayout = new QHBoxLayout();
    dataLabel = new QLabel("Data");
    oraLabel = new QLabel("Ora");

    dataFmtCombo = new QComboBox();
    dataFmtCombo->addItems({"Breve", "Esteso", "Americano"});
    dataFmtCombo->setCurrentIndex(1); // Esteso

    tempoFmtCombo = new QComboBox();
    tempoFmtCombo->addItems({"24h", "12h"});
    tempoFmtCombo->setCurrentIndex(0); // 24h

    topLayout->addWidget(dataLabel);
    topLayout->addWidget(dataFmtCombo);
    topLayout->addStretch();
    topLayout->addWidget(oraLabel);
    topLayout->addWidget(tempoFmtCombo);
    mainLayout->addLayout(topLayout);

    timerLabel = new QLabel("00:00:00");
    timerLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(timerLabel);

    rowBtns = new QHBoxLayout();
    startBtn = new QPushButton("Start");
    stopBtn = new QPushButton("Stop");
    rowBtns->addWidget(startBtn);
    rowBtns->addWidget(stopBtn);
    mainLayout->addLayout(rowBtns);

    // Stato iniziale etichette
    dataLabel->setText(QString::fromStdString(data.toString(currentDataFmt())));
    oraLabel->setText(QString::fromStdString(tempo.toString(currentTempoFmt())));
    timerLabel->setText(QString("%1,%2,%3")
                            .arg(timer.getOra(), 2, 10, QChar('0'))
                            .arg(timer.getMinuto(), 2, 10, QChar('0'))
                            .arg(timer.getSecondo(), 2, 10, QChar('0')));

    // Timers
    orologio = new QTimer(this);
    orologioTimer = new QTimer(this);

    connect(orologio, &QTimer::timeout, this, &Gui::onTickOrologio);
    orologio->start(1000);

    connect(orologioTimer, &QTimer::timeout, this, &Gui::onTickTimer);

    // Pulsanti
    connect(startBtn, &QPushButton::clicked, this, &Gui::onStart);
    connect(stopBtn, &QPushButton::clicked, this, &Gui::onStop);

    // Cambi formato
    connect(dataFmtCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Gui::onDataFmtChanged);
    connect(tempoFmtCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Gui::onTempoFmtChanged);
}

FormatoData Gui::currentDataFmt() const {
    switch (dataFmtCombo->currentIndex()) {
        case 0: return FormatoData::breve;
        case 1: return FormatoData::esteso;
        default: return FormatoData::americano;
    }
}

FormatoTempo Gui::currentTempoFmt() const {
    return tempoFmtCombo->currentIndex() == 0 ? FormatoTempo::h24 : FormatoTempo::h12;
}

void Gui::onTickOrologio() {
    tempo.tick();

    if (tempo.getOra() == 0 && tempo.getMinuto() == 0 && tempo.getSecondo() == 0) {
        data.avanzaData();
    }

    dataLabel->setText(QString::fromStdString(data.toString(currentDataFmt())));
    oraLabel->setText(QString::fromStdString(tempo.toString(currentTempoFmt())));
}

void Gui::onTickTimer() {
    timer.tick();
    timerLabel->setText(QString("%1,%2,%3")
                            .arg(timer.getOra(), 2, 10, QChar('0'))
                            .arg(timer.getMinuto(), 2, 10, QChar('0'))
                            .arg(timer.getSecondo(), 2, 10, QChar('0')));
}

void Gui::onStart() {
    if (!orologioTimer->isActive()) {
        orologioTimer->start(1000);
    }
}

void Gui::onStop() {
    if (orologioTimer->isActive()) {
        orologioTimer->stop();
    }
}

void Gui::onDataFmtChanged(int) {
    dataLabel->setText(QString::fromStdString(data.toString(currentDataFmt())));
}

void Gui::onTempoFmtChanged(int) {
    oraLabel->setText(QString::fromStdString(tempo.toString(currentTempoFmt())));
}