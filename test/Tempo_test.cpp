//
// Created by francesco on 29/08/25.
//

#include <gtest/gtest.h>
#include "Tempo.h"
#include "Data.h"

TEST(CostruttoreTempo, StatoIniziale) {
    Tempo tempo(14, 25, 15);
    EXPECT_EQ(tempo.getOra(), 14);
    EXPECT_EQ(tempo.getMinuto(), 25);
    EXPECT_EQ(tempo.getSecondo(), 15);
}

TEST(CostruttoreTempo, InputSbagliati) {
    EXPECT_THROW(Tempo(25, 00, 00),std::invalid_argument);
    EXPECT_THROW(Tempo(-1, 00, 00),std::invalid_argument);
    EXPECT_THROW(Tempo(00, 61, 00),std::invalid_argument);
    EXPECT_THROW(Tempo(00, -1, 00),std::invalid_argument);
    EXPECT_THROW(Tempo(00, 00, 61),std::invalid_argument);
    EXPECT_THROW(Tempo(00, 00, -1),std::invalid_argument);
}

TEST(TempoTick, SecondoDopo) {
    Tempo tempo(14, 25, 15);
    tempo.tick();
    EXPECT_EQ(tempo.getOra(), 14);
    EXPECT_EQ(tempo.getMinuto(), 25);
    EXPECT_EQ(tempo.getSecondo(), 16);
}

TEST(TempoTick, MinutoDopo) {
    Tempo tempo(14, 25, 59);
    tempo.tick();
    EXPECT_EQ(tempo.getOra(), 14);
    EXPECT_EQ(tempo.getMinuto(), 26);
    EXPECT_EQ(tempo.getSecondo(), 0);
}

TEST(TempoTick, OraDopo) {
    Tempo tempo(14, 59, 59);
    tempo.tick();
    EXPECT_EQ(tempo.getOra(), 15);
    EXPECT_EQ(tempo.getMinuto(), 00);
    EXPECT_EQ(tempo.getSecondo(), 00);
}



TEST(ToStringTempo, FormatiDiversi) {
    Tempo tempo(14, 24, 26);
    EXPECT_EQ(tempo.toString(FormatoTempo::h12),"2:24:26 PM");
    EXPECT_EQ(tempo.toString(FormatoTempo::h24),"14:24:26");
}

TEST(Tempo, SempreGiusto) {
    Tempo tempo(0, 0, 0);
    for (int i = 0; i < 366; ++i) {

        int ora = tempo.getOra();
        int minuto   = tempo.getMinuto();
        int secondo   = tempo.getSecondo();

        EXPECT_NO_THROW(Tempo(ora, minuto, secondo));
        tempo.tick();
    }
}

TEST(TempoTick,AvanzaLaData) {
    auto d = std::make_unique<Data>(30, 4, 2025);
    Data* dataRef = d.get();
    Tempo tempo(23, 59, 59, std::move(d));
    tempo.tick();
    EXPECT_EQ(tempo.getOra(), 0);
    EXPECT_EQ(tempo.getMinuto(), 0);
    EXPECT_EQ(tempo.getSecondo(), 0);

    EXPECT_EQ(dataRef->getGiorno(), 1);
    EXPECT_EQ(dataRef->getMese(), 5);
    EXPECT_EQ(dataRef->getAnno(), 2025);

}

TEST(TempoTick, CambiaAnno) {
    auto d = std::make_unique<Data>(31, 12, 2025);
    Data* dataRef = d.get();
    Tempo tempo(23, 59, 59, std::move(d));
    tempo.tick();
    EXPECT_EQ(tempo.getOra(), 0);
    EXPECT_EQ(tempo.getMinuto(), 0);
    EXPECT_EQ(tempo.getSecondo(), 0);

    EXPECT_EQ(dataRef->getGiorno(), 1);
    EXPECT_EQ(dataRef->getMese(), 1);
    EXPECT_EQ(dataRef->getAnno(), 2026);

}
