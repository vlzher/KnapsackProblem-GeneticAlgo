#include <cstdlib>
#include <iostream>
#include "Individual.h"

Individual::Individual(std::vector<int> genotype, CKnapsackProblem problem) {
    mGenotype = genotype;
    mProblem = problem;
}



void Individual::mutate(double MUTPROB) {
    double number;
    for (int & i : mGenotype) {
        number = rand();
        if (number < MUTPROB * RAND_MAX) {
            if (i == 0) {
                i = 1;
            } else {
                i = 0;
            }
        }
    }
}



std::pair<Individual, Individual> Individual::cross(Individual other, double CROSSPROB) {
    double randNum = rand();
    if (randNum < CROSSPROB*RAND_MAX) {
        int crossPoint = rand() % mGenotype.size();
        std::vector<int> parent1Part1(mGenotype.begin(), mGenotype.begin() + crossPoint);
        std::vector<int> parent1Part2(mGenotype.begin() + crossPoint, mGenotype.end());
        std::vector<int> parent2Part1(other.mGenotype.begin(), other.mGenotype.begin() + crossPoint);
        std::vector<int> parent2Part2(other.mGenotype.begin() + crossPoint, other.mGenotype.end());
        std::vector<int> child1Genotype(parent1Part1);
        child1Genotype.insert(child1Genotype.end(), parent2Part2.begin(), parent2Part2.end());
        std::vector<int> child2Genotype(parent2Part1);
        child2Genotype.insert(child2Genotype.end(), parent1Part2.begin(), parent1Part2.end());
        Individual child1(child1Genotype,mProblem);
        Individual child2(child2Genotype, mProblem);
        return std::make_pair(child1, child2);
    }
    return std::make_pair(*this, other);
}

void Individual::calculateFitness() {
    mFitness = mProblem.calculateFitness(mGenotype);
}

#include "Individual.h"
