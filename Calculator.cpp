//
// Created by mauri on 24.02.18.
//

#include <cassert>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Calculator.h"

int Calculator::invertMod(const int a, const int m) {
    std::vector<int> result = extendedEuclid(a, m);
    //assert(result[0] == 1);

    return result[1];
}

inline int Calculator::mod(const int a, const int b) {
    return a % b;
}

std::vector<int> Calculator::extendedEuclid(const int a, const int b) {
    std::vector<int> result(3);
    if (b != 0) {
        result = extendedEuclid(b, mod(a, b));
        int t, t2;
        t = result.at(1);
        t2 = result.at(2);
        result[1] = result[2];
        result[2] = t - a / b * t2;

        return result;
    }
    result[0] = a;
    result[1] = 1;
    result[2] = 0;
    return result;
}

int Calculator::calculateGcd(int a, int b) {
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