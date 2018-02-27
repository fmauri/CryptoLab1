//
// Created by mauri on 23.02.18.
//

#ifndef L1_RANDOMGENERATOR_H
#define L1_RANDOMGENERATOR_H

static const unsigned int lcgMod = 1812;
static unsigned long lcgNext = 1759; // seed

class PseudoRandomGenerator {
public:
    int glibc_rand_type1();

    int linearCongruentialGenerator();

private:
    const unsigned int multiplier = 1103517245;
    const unsigned int constant = 12345;
};

#endif //L1_RANDOMGENERATOR_H
