//
// Created by francesco on 29/08/25.
//
#include <gtest/gtest.h>

#include "Timer.h"

TEST(CostruttoreTimer, StatoIniziale) {
    Timer t(12,34,56);
    EXPECT_EQ(t.getOra(), 12);
    EXPECT_EQ(t.getMinuto(), 34);
    EXPECT_EQ(t.getSecondo(), 56);
}

TEST(CostruttoreTimer, InputSbagliati) {
    EXPECT_THROW(Timer(-1,0,0), std::invalid_argument);
    EXPECT_THROW(Timer(24,0,0), std::invalid_argument);
}

TEST(TimerTick, Indietreggia) {
    Timer t(0,1,0);
    t.tick();
    EXPECT_EQ(t.getOra(), 0);
    EXPECT_EQ(t.getMinuto(), 0);
    EXPECT_EQ(t.getSecondo(), 59);
}

TEST(TimerTick, FermoAZero) {
    Timer t(0,0,0);
    t.tick();
    EXPECT_EQ(t.getOra(), 0);
    EXPECT_EQ(t.getMinuto(), 0);
    EXPECT_EQ(t.getSecondo(), 0);
}

