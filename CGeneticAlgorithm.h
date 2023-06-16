//
// Created by vladz on 1/14/2023.
//

#ifndef MINIPROJECT_CGENETICALGORITHM_H
#define MINIPROJECT_CGENETICALGORITHM_H


#include <ostream>
#include "CKnapsackProblem.h"
#include "Individual.h"

class CGeneticAlgorithm {
public:
    CGeneticAlgorithm(CKnapsackProblem problem, int populationSize, double crossProb, double mutProb){
        if (populationSize <= 0 || crossProb < 0 || crossProb > 1 || mutProb < 0 || mutProb > 1) {
            throw std::invalid_argument("Invalid input data for genetic algorithm");
        }
        mProblem = problem;
        mPopulationSize = populationSize;
        mCrossProb = crossProb;
        mMutProb = mutProb;
    }
    void run(int numberOfGenerations);
    Individual getBestSolution();
    Individual findBestIndividual();
    void printInfo();

    std::vector<Individual> population;
    double mCrossProb;
    double mMutProb;
    int mPopulationSize;
    Individual mBestSolution;
    CKnapsackProblem mProblem;
};


#endif //MINIPROJECT_CGENETICALGORITHM_H
