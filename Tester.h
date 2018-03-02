//
// Created by mauri on 24.02.18.
//

#ifndef L1_TESTER_H
#define L1_TESTER_H

#include <vector>
#include <iostream>

#include "PseudoRandomGenerator.h"
#include "Predictor.h"


class Tester {
public:
    void testPredictorLCG();

    void testPredictorLCGnoMod();

    void testPredictorLCGconstant();

    void testPredictGlibc();

private:
    int testNum = 10000;
    int initLCG = 8;
    int initGlibc = 34;
};


#endif //L1_TESTER_H
