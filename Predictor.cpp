//
// Created by mauri on 23.02.18.
//

#include "Predictor.h"
#include "PseudoRandomGenerator.h"
#include "Calculator.h"
#include <iostream>
#include <cmath>
#include <numeric>

int calculateGcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    if (a == 0) return b;
    while (b != 0) {
        auto remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int Predictor::predictLcgKnowingMod(const std::vector<int> &outputs, unsigned int mod) {
    if (outputs.size() < 3) throw std::invalid_argument("to predict are needed >= 3 outputs");

    const int r2 = outputs[outputs.size() - 1];
    const int r1 = outputs[outputs.size() - 2];
    const int r0 = outputs[outputs.size() - 3];
    auto calc = new Calculator();

    const int denominator = calc->invertMod((r0 - r1), mod);
    const int a = ((r1 - r2) * denominator) % mod;
    //const int c = calc->mod((r0 * r2 - r1 * r1) * denominator, lcgMod);
    const int c = calc->mod(r2 - r1 * a, mod);
    return calc->mod(a * r2 + c, mod);
}

int Predictor::predictLcgKnowingMultiplierAndMod(const std::vector<int> &outputs, int multiplier, int modulus) {
    if (outputs.size() < 2) throw std::invalid_argument("to predict are needed >= 2 outputs");

    const int r2 = outputs.at(outputs.size() - 3);
    const int r1 = outputs.at(outputs.size() - 2);
    int increment = (r2 - r1 * multiplier) % modulus;
    return (multiplier * r2 + increment) % modulus;
}

int Predictor::predictGlibc(const std::vector<int> &outputs) {
    if (outputs.size() < 31) throw std::invalid_argument("to predict are needed >= 31 outputs");

    const int o31 = outputs.at(outputs.size() - 31);
    const int o3 = outputs.at(outputs.size() - 3);
    const int prediction = (o31 + o3) % (1u << 31); //75% <- method to generate power of 2
    //const int prediction = (o31 + o3) % (1u << 31) + 1; //25%
    return prediction;
}

int Predictor::predictLCG(const std::vector<int> &outputs) {
    std::vector<int> t;
    std::vector<unsigned int> u;
    for (unsigned long i = 0; i < outputs.size() - 1; ++i) {
        t.push_back(outputs.at(i + 1) - outputs.at(i));
    }
    for (unsigned long i = 0; i < t.size() - 2; ++i) {
        u.push_back(abs(t.at(i + 2) * t.at(i) - pow(t.at(i + 1), 2)));
    }
    unsigned int m = std::accumulate(u.begin(), u.end(), u[0], calculateGcd);
    return predictLcgKnowingMod(outputs, m);

}
