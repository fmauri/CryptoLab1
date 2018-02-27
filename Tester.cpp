//
// Created by mauri on 24.02.18.
//

#include "Tester.h"
#include "Calculator.h"

void Tester::testPredictorLCG() {
    auto *predictor = new Predictor();
    auto *randomGenerator = new PseudoRandomGenerator();
    const int sizeInitializer = 3;

    std::vector<int> outputs;
    int correct_guesses = 0, guesses = 0;
    for (int i = 0; i < testNum + initLCG; ++i) {
        const int output = randomGenerator->linearCongruentialGenerator();
        if (i >= initLCG) {
            const int prediction = predictor->predictLinearCongruentialGenerator(outputs);
            if (prediction == output) { correct_guesses++; }
            ++guesses;
        }
        outputs.push_back(output);
    }
    std::cout << "Predicting Linear congruential generator:" << std::endl;
    std::cout << "Successful predictions: " << correct_guesses << " / " << guesses;
    std::cout << " (" << (static_cast<float>(correct_guesses) / guesses * 100) << "%)" << std::endl;
    std::cout << std::endl;
}

void Tester::testPredictorLCGconstant() {
    auto *predictor = new Predictor();
    auto *randomGenerator = new PseudoRandomGenerator();

    std::vector<int> outputs;
    int correct_guesses = 0, guesses = 0;
    for (int i = 0; i < testNum + 2; ++i) {
        const int output = randomGenerator->linearCongruentialGenerator();
        if (i >= 2) {
            const int prediction = predictor->predictLinearCongruentialGenerator(outputs);
            if (prediction == output) { correct_guesses++; }
            ++guesses;
        }

        outputs.push_back(output);
    }

    std::cout << "Successful predictions " << correct_guesses << " / " << guesses;
    std::cout << " (" << (static_cast<float>(correct_guesses) / guesses) << ")" << std::endl;

    std::cout << std::endl;
}

void Tester::testPredictGlibc() {
    auto *predictor = new Predictor();
    auto *randomGenerator = new PseudoRandomGenerator();

    std::vector<int> outputs;
    int correct_guesses = 0, guesses = 0;
    for (int i = 0; i < testNum + initGlibc; ++i) {
        const int output = randomGenerator->glibc_rand_type1();
        if (i >= initGlibc) {
            const int prediction = predictor->predictGlibc(outputs);
            if (prediction == output) { correct_guesses++; }
            ++guesses;
        }
        outputs.push_back(output);
    }
    std::cout << "Predicting Gnu C library random():" << std::endl;
    std::cout << "Successful predictions: " << correct_guesses << " / " << guesses;
    std::cout << " (" << (static_cast<float>(correct_guesses) / guesses * 100) << "%)" << std::endl;
    std::cout << std::endl;
}
