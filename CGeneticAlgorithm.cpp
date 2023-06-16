#include <stdexcept>
#include <iostream>
#include "CGeneticAlgorithm.h"

Individual CGeneticAlgorithm::
getBestSolution() {
    return mBestSolution;
}

void CGeneticAlgorithm::run(int maxIterations) {
    for (int i = 0; i < mPopulationSize; i++) {
        std::vector<int> genotype;
        for(int j = 0; j < mProblem.getNumItems(); j++) {
            genotype.push_back(rand() % 2);
        }
        population.push_back(Individual(genotype,mProblem));
    }
    for (Individual& ind : population) {
        ind.calculateFitness();
    }
    Individual bestSolution = getBestSolution();

    for (int i = 0; i < maxIterations; i++) {
        std::vector<Individual> newPopulation;
        while (newPopulation.size() < mPopulationSize) {
            int parent1Index = rand() % mPopulationSize;
            int parent2Index = rand() % mPopulationSize;
            Individual parent1 = population[parent1Index].getFitness() > population[parent2Index].getFitness()
                    ? population[parent1Index]
                    : population[parent2Index];

            parent1Index = rand() %  mPopulationSize;
            parent2Index = rand() %  mPopulationSize;
            Individual parent2 = population[parent1Index].getFitness() > population[parent2Index].getFitness()
                    ? population[parent1Index]
                    : population[parent2Index];

            if (rand() < mCrossProb * RAND_MAX) {
                std::pair<Individual, Individual> children = parent1.cross(parent2,mCrossProb);
                children.first.calculateFitness();
                children.second.calculateFitness();
                newPopulation.push_back(children.first);
                newPopulation.push_back(children.second);
            } else {
                newPopulation.push_back(parent1);
                newPopulation.push_back(parent2);
            }
        }
        for (int i = 0; i< newPopulation.size(); i++) {
            if (((double)rand()) / RAND_MAX  < mMutProb) {
                newPopulation[i].mutate(mMutProb);
                newPopulation[i].calculateFitness();
            }
        }
        population = newPopulation;
        mBestSolution = findBestIndividual();
    }
}

Individual CGeneticAlgorithm::findBestIndividual() {
    Individual bestIndividual = mBestSolution;
    for (Individual& ind : population) {
        if (ind.getFitness() > bestIndividual.getFitness()) {
            bestIndividual = ind;
        }
    }
    return bestIndividual;
}

void CGeneticAlgorithm::printInfo() {
    std::cout << "Mut prob "+std::to_string(mMutProb) << std::endl;
    std::cout << "Cross prob "+std::to_string(mCrossProb) << std::endl;
    std::cout << "Population size "+std::to_string(mPopulationSize) << std::endl;
}


#include "CGeneticAlgorithm.h"
