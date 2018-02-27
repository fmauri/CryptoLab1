//
// Created by mauri on 23.02.18.
//

#include <cstdlib>
#include "PseudoRandomGenerator.h"

int PseudoRandomGenerator::linearCongruentialGenerator() {
    lcgNext = ((lcgNext * multiplier) + constant)%lcgMod;
    return static_cast<int>(lcgNext);
}

int PseudoRandomGenerator::glibc_rand_type1() {
    return rand();
}
