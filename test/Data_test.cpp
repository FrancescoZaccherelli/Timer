//
// Created by francesco on 29/08/25.
//
#include "Data.h"
#include <gtest/gtest.h>

#include "Timer.h"

TEST(CostruttoreData, StatoIniziale) {
    Data data(29, 06, 2005);
    EXPECT_EQ(data.getGiorno(), 29);
    EXPECT_EQ(data.getMese(), 6);
    EXPECT_EQ(data.getAnno(), 2005);
}

TEST(CostruttoreData, InputSbagliati) {
    EXPECT_THROW(Data(29, 02, 2025),std::invalid_argument);
    EXPECT_NO_THROW(Data(29, 02, 2024));
    EXPECT_THROW(Data(32, 10, 2025),std::invalid_argument);
    EXPECT_THROW(Data(-1, 10, 2025),std::invalid_argument);
    EXPECT_THROW(Data(1, 13, 2025),std::invalid_argument);
    EXPECT_THROW(Data(29, -9, 2025),std::invalid_argument);
    EXPECT_THROW(Data(10, 02, 3000),std::invalid_argument);
    EXPECT_THROW(Data(4, 06, 1000),std::invalid_argument);
}

TEST(AvanzaData, GiornoDopo) {
    Data data(28, 02, 2025);
    data.avanzaData();
    EXPECT_EQ(data.getGiorno(), 1);
    EXPECT_EQ(data.getMese(), 3);
    EXPECT_EQ(data.getAnno(), 2025);


}

TEST(AvanzaData, GiornoDopo2) {
    Data data(28, 02, 2024);
    data.avanzaData();
    EXPECT_EQ(data.getGiorno(), 29);
    EXPECT_EQ(data.getMese(), 2);
    EXPECT_EQ(data.getAnno(), 2024);


}

TEST(AvanzaData, MeseDopo) {
    Data data(30, 06, 2025);
    data.avanzaData();
    EXPECT_EQ(data.getGiorno(), 1);
    EXPECT_EQ(data.getMese(), 7);
    EXPECT_EQ(data.getAnno(), 2025);


}
TEST(AvanzaData, Annodopo) {
    Data data(31, 12, 2025);
    data.avanzaData();
    EXPECT_EQ(data.getGiorno(), 1);
    EXPECT_EQ(data.getMese(), 1);
    EXPECT_EQ(data.getAnno(), 2026);


}

TEST(ToStringData, FormatiDiversi) {
    Data data(9, 7, 2025);
    EXPECT_EQ(data.toString(FormatoData::breve),    "9 7 2025");
    EXPECT_EQ(data.toString(FormatoData::americano),"7 9 2025");
    EXPECT_NE(data.toString(FormatoData::esteso), "7 luglio 2025");
}

TEST(Data, SempreGiusto) {
    Data data(1, 1, 2024);
    for (int i = 0; i < 366; ++i) {

        int giorno = data.getGiorno();
        int mese   = data.getMese();
        int anno   = data.getAnno();

        EXPECT_NO_THROW(Data(giorno, mese, anno));
        data.avanzaData();
    }
}




