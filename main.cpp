#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QString>

#include "Data.h"
#include "Tempo.h"
#include "Timer.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("App");
    window.resize(800, 600);

    auto *mainLayout = new QVBoxLayout(&window);

    auto *top = new QHBoxLayout();
    auto *dataLabel = new QLabel("Data");
    auto *oraLabel = new QLabel("Ora");
    top->addWidget(dataLabel);
    top->addStretch();
    top->addWidget(oraLabel);
    mainLayout->addLayout(top);

    auto *timerLabel = new QLabel("00:00:00");
    timerLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(timerLabel);

    auto *rowBtns = new QHBoxLayout();
    auto *startBtn = new QPushButton("Start");
    auto *stopBtn = new QPushButton("Stop");

    rowBtns->addWidget(startBtn);
    rowBtns->addWidget(stopBtn);
    mainLayout->addLayout(rowBtns);

    Data data(28, 2, 2025);
    Tempo tempo(23, 59, 56);
    Timer timer(0, 0, 10);

    dataLabel->setText(QString::fromStdString(data.toString(FormatoData::esteso)));
    oraLabel->setText(QString::fromStdString(tempo.toString(FormatoTempo::h24)));
    timerLabel->setText(QString("%1,%2,%3")
        .arg(timer.getOra(),2, 10, QChar('0'))
        .arg(timer.getMinuto(),2,10,QChar('0'))
        .arg(timer.getSecondo(),2,10,QChar('0')));

    auto *orologio = new QTimer(&window);
    QObject::connect(orologio, &QTimer::timeout, [&]() {
        tempo.tick();

        if (tempo.getOra()== 0 && tempo.getMinuto()== 0 && tempo.getSecondo()== 0) {
            data.avanzaData();
        }

        dataLabel->setText(QString::fromStdString(data.toString(FormatoData::esteso)));
        oraLabel->setText(QString::fromStdString(tempo.toString(FormatoTempo::h24)));
    });
    orologio->start(1000);

    auto orologioTimer = new QTimer(&window);
    QObject::connect(orologioTimer, &QTimer::timeout, [&]() {
        timer.tick();
        timerLabel->setText(QString("%1,%2,%3")
            .arg(timer.getOra(),2, 10, QChar('0'))
            .arg(timer.getMinuto(),2,10,QChar('0'))
            .arg(timer.getSecondo(),2,10,QChar('0')));
    });

    QObject::connect(startBtn, &QPushButton::clicked, [&]() {
        if (!orologioTimer->isActive()) {
            orologioTimer->start(1000);
        }
    });
    QObject::connect(stopBtn, &QPushButton::clicked, [&]() {
        if (orologioTimer->isActive()) {
            orologioTimer->stop();
        }
    });


    window.show();
    return app.exec();
}