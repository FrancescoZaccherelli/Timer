// Gui.cpp
#include "Gui.h"
#include <QString>
#include <QChar>
#include <QMessageBox>

Gui::Gui(Data dataInit, Tempo tempoInit, Timer timerInit, QWidget* parent)
    : QWidget(parent),
      data(std::move(dataInit)),
      tempo(std::move(tempoInit)),
      timer(std::move(timerInit)) {


    setWindowTitle("App");

    resize(800, 600);

    // Layout principali e vari menù a tendina e etichette
    mainLayout = new QVBoxLayout(this);

    topLayout = new QHBoxLayout();
    dataLabel = new QLabel("Data");
    oraLabel = new QLabel("Ora"); // si riferisce al tempo


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

    dataLabel->setObjectName("dataLabel");
    oraLabel->setObjectName("oraLabel");



    // Display del Timer e pulsanti
    timerLabel = new QLabel("00:00:00");
    timerLabel->setObjectName("timerLabel");
    timerLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(timerLabel);

    rowBtns = new QHBoxLayout();
    startBtn = new QPushButton("Start");
    stopBtn = new QPushButton("Stop");
    rowBtns->addWidget(startBtn);
    rowBtns->addWidget(stopBtn);
    mainLayout->addLayout(rowBtns);

    // Stato iniziale etichette in base a come scritti
    dataLabel->setText(QString::fromStdString(data.toString(FormatoDataCorrente())));
    oraLabel->setText(QString::fromStdString(tempo.toString(FormatoTempoCorrente())));
    timerLabel->setText(QString("%1:%2:%3")
                            .arg(timer.getOra(), 2, 10, QChar('0'))
                            .arg(timer.getMinuto(), 2, 10, QChar('0'))
                            .arg(timer.getSecondo(), 2, 10, QChar('0')));

    // Creazione timer di Qt
    orologio = new QTimer(this);
    orologioTimer = new QTimer(this);

    connect(orologio, &QTimer::timeout, this, &Gui::onTickOrologio);
    orologio->start(1000);

    connect(orologioTimer, &QTimer::timeout, this, &Gui::onTickTimer);

    // Pulsanti
    connect(startBtn, &QPushButton::clicked, this, &Gui::onStart);
    connect(stopBtn, &QPushButton::clicked, this, &Gui::onStop);

    // Cambi formato in ase al menù a tendina
    connect(dataFmtCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Gui::CambioFormatoData);
    connect(tempoFmtCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Gui::CambioFormatoTempo);


    // Cambi grafici

    this->setStyleSheet( "#dataLabel { font-size: 30px;font.weight: 30px; color: #000000; }"
                           "#oraLabel  { font-size: 30px;font-weight: 30px; color: #000000; }"
                           "#timerLabel { ""font-size: 40px; ""color: #000000; background-image: url(:/immagini/timersfondo.png); background-position: center; background-repeat: no-repeat;}"
                           "QWidget { background-color: #AAF0D1;}"
                           "QPushButton { font-size: 20px; font-weight: 300px; color: #000000; }"
                           "QComboBox { font-size: 20px; font-weight: 300px; color: #000000; }"
                           );
}


FormatoData Gui::FormatoDataCorrente() const {
    switch (dataFmtCombo->currentIndex()) {
        case 0: return FormatoData::breve;
        case 1: return FormatoData::esteso;
        default: return FormatoData::americano;
    }
}

FormatoTempo Gui::FormatoTempoCorrente() const {
    return tempoFmtCombo->currentIndex() == 0 ? FormatoTempo::h24 : FormatoTempo::h12;
}

//Avanza di un secondo e eventualmente avanza la data
void Gui::onTickOrologio() {
    tempo.tick();

    if (tempo.getOra() == 0 && tempo.getMinuto() == 0 && tempo.getSecondo() == 0) {
        data.avanzaData();
    }

    dataLabel->setText(QString::fromStdString(data.toString(FormatoDataCorrente())));
    oraLabel->setText(QString::fromStdString(tempo.toString(FormatoTempoCorrente())));
}

// Indietreggia di 1
void Gui::onTickTimer() {
    timer.tick();
    timerLabel->setText(QString("%1:%2:%3")
                            .arg(timer.getOra(), 2, 10, QChar('0'))
                            .arg(timer.getMinuto(), 2, 10, QChar('0'))
                            .arg(timer.getSecondo(), 2, 10, QChar('0')));
    if (!timerFinito&& timer.getOra() == 0&& timer.getMinuto() == 0&& timer.getSecondo() == 0){
        orologioTimer->stop();
        timerFinito = true;
        QMessageBox::about(this, "Timer", "Il timer è terminato.");
        }

}


// Avvia se fermo
void Gui::onStart() {
    if (!orologioTimer->isActive()) {
        timerFinito = false;
        orologioTimer->start(1000);
    }
}

// Ferma se attivo
void Gui::onStop() {
    if (orologioTimer->isActive()) {
        orologioTimer->stop();
    }
}

// Cambia formato al label data
void Gui::CambioFormatoData(int) {
    dataLabel->setText(QString::fromStdString(data.toString(FormatoDataCorrente())));
}

// Cambia formato al label tempo
void Gui::CambioFormatoTempo(int) {
    oraLabel->setText(QString::fromStdString(tempo.toString(FormatoTempoCorrente())));
}