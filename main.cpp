#include "Tester.h"
#include "Calculator.h"

int main() {
    auto *tester = new Tester();
    auto *calc = new Calculator();
    calc->extendedEuclid(17, 29);
    //tester->testPredictorLCG();
    //tester->testPredictGlibc();

}