//
// Created by mauri on 23.02.18.
//

#include "Predictor.h"
#include "PseudoRandomGenerator.h"
#include "Calculator.h"
#include <iostream>

int Predictor::predictLinearCongruentialGenerator(const std::vector<int> &outputs) {
    if (outputs.size() < 3) throw std::invalid_argument("to predict are needed >= 3 outputs");

    const int r2 = outputs[outputs.size() - 1];
    const int r1 = outputs[outputs.size() - 2];
    const int r0 = outputs[outputs.size() - 3];
    auto calc = new Calculator();

    const int denominator = calc->invertMod((r0 - r1), lcgMod);
    const int a = ((r1 - r2) * denominator) % lcgMod;
    const int c = calc->mod((r0 * r2 - r1 * r1) * denominator, lcgMod);
    return (a * r2 + c) % lcgMod;
}

int Predictor::predictLCGconstant(const std::vector<int> &outputs, const int multiplier, const int modulus) {
    if (outputs.size() < 2) throw std::invalid_argument("to predict are needed >= 2 outputs");

    const int r1 = outputs.at(outputs.size() - 1);
    const int r0 = outputs.at(outputs.size() - 2);
    int increment = (r1 - r0 * multiplier) % modulus;
    return (multiplier * r1 + increment) % lcgMod;
}

int Predictor::predictGlibc(const std::vector<int> &outputs) {
    if (outputs.size() < 31) throw std::invalid_argument("to predict are needed >= 31 outputs");

    const int o31 = outputs.at(outputs.size() - 31);
    const int o3 = outputs.at(outputs.size() - 3);
    const int prediction = (o31 + o3) % (1u << 31); //75%
    //const int prediction = (o31 + o3) % (1u << 31) + 1; //25%
    return prediction;
}
