//
// Created by mauri on 23.02.18.
//

#ifndef L1_RANDOMGENERATOR_H
#define L1_RANDOMGENERATOR_H

class PseudoRandomGenerator {
public:
    int glibcGenerator();

    int linearCongruentialGenerator();

private:
    const unsigned int multiplier = 654321;
    const unsigned int constant = 12345;
    const unsigned int lcgMod = (1u << 31) - 1;
    unsigned long lcgNext = 1759;
};

#endif //L1_RANDOMGENERATOR_H
