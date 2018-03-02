//
// Created by mauri on 23.02.18.
//

#ifndef L1_PREDICTOR_H
#define L1_PREDICTOR_H

#include <stdexcept>
#include <vector>
#include <cassert>
#include "Calculator.h"

class Predictor {
public:

    int predictLCG(const std::vector<int> &outputs);

    int predictLcgKnowingMod(const std::vector<int> &outputs, unsigned int mod);

    int predictLcgKnowingMultiplierAndMod(const std::vector<int> &outputs, int multiplier, int mod);

    int predictGlibc(const std::vector<int> &outputs);

};

#endif //L1_PREDICTOR_H
