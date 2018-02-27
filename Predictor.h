//
// Created by mauri on 23.02.18.
//

#ifndef L1_PREDICTOR_H
#define L1_PREDICTOR_H

#include <stdexcept>
#include <vector>
#include <cassert>

class Predictor {
public:

    int predictLinearCongruentialGenerator(const std::vector<int> &outputs);

    int predictLCGconstant(const std::vector<int> &outputs, int multiplier, int modulus);

    int predictGlibc(const std::vector<int> &outputs);

};


#endif //L1_PREDICTOR_H
