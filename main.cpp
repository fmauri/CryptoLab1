#include "Tester.h"
#include "Calculator.h"

int main() {
    auto *tester = new Tester();
    //auto *calc = new Calculator();
    //std::cout << calc->extendedEuclid(3, 11)[1];
    tester->testPredictorLCG();
    tester->testPredictGlibc();

}