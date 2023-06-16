//
// Created by vladz on 1/14/2023.
//

#ifndef MINIPROJECT_INDIVIDUAL_H
#define MINIPROJECT_INDIVIDUAL_H


#include <vector>
#include "CKnapsackProblem.h"

class Individual {
public:
    Individual(){mFitness =0;};
    Individual(std::vector<int> genotype, CKnapsackProblem problem);
    void calculateFitness();
    void mutate(double MUTPROB);
    std::pair<Individual, Individual> cross(Individual other, double CROSSPROB);


    int getFitness(){return mFitness;};
    std::vector<int> getGenotype(){ return mGenotype;};
    void setGenotype(std::vector<int> genotype){ mGenotype = genotype;};

    int mFitness;
    CKnapsackProblem mProblem;
    std::vector<int> mGenotype;
};


#endif //MINIPROJECT_INDIVIDUAL_H
