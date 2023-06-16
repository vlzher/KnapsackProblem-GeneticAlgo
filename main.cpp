#include <iostream>
#include <vector>
#include "CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"

int main() {
    std::cout << "Test 1 expected value 7" << std::endl;
    std::vector<int> itemValues = {5, 1, 4, 3};
    std::vector<int> itemSizes = {4, 1, 3, 2};
    CKnapsackProblem problem(4, 5, itemSizes, itemValues);
    problem.printInfo();
    CGeneticAlgorithm geneticAlgorithm(problem, 4, 0.8, 0.1);
    geneticAlgorithm.printInfo();
    geneticAlgorithm.run(100);
    Individual bestSolution = geneticAlgorithm.getBestSolution();
    std::cout<< "Best solution: "<<bestSolution.getFitness()<<std::endl;
    for (int i : bestSolution.getGenotype()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Test 2 expected value 1024" << std::endl;
    std::vector<int> itemSizes1 = {92, 4, 43, 83, 84, 68, 92, 82, 6, 44, 32, 18, 56, 83, 25, 96, 70, 48, 14, 58};
    std::vector<int> itemValues1 = {44, 46, 90, 72, 91, 40, 75, 35, 8, 54, 78, 40, 77, 15, 61, 17, 75, 29, 75, 63};

    CKnapsackProblem problem1(20, 878, itemSizes1, itemValues1);
    problem1.printInfo();
    CGeneticAlgorithm geneticAlgorithm1(problem1, 20, 0.8, 0.1);
    geneticAlgorithm1.printInfo();
    geneticAlgorithm1.run(10000);
    Individual bestSolution1 = geneticAlgorithm1.getBestSolution();
    std::cout<< "Best solution: "<<bestSolution1.getFitness()<<std::endl;
    for (int i : bestSolution1.getGenotype()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Test 3 from file test1 expected value 60" << std::endl;
    CKnapsackProblem problem2("C:/Users/vladz/CLionProjects/miniproject/tests/test1.txt");
    problem2.printInfo();
    CGeneticAlgorithm geneticAlgorithm2(problem2, 6, 0.8, 0.1);
    geneticAlgorithm2.printInfo();
    geneticAlgorithm2.run(10000);
    Individual bestSolution2 = geneticAlgorithm2.getBestSolution();
    std::cout<< "Best solution: "<<bestSolution2.getFitness()<<std::endl;
    for (int i : bestSolution2.getGenotype()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "Test 4 from file test1 expected value 295" << std::endl;
    CKnapsackProblem problem3("C:/Users/vladz/CLionProjects/miniproject/tests/test2.txt");
    problem3.printInfo();
    CGeneticAlgorithm geneticAlgorithm3(problem3, 6, 0.8, 0.1);
    geneticAlgorithm3.printInfo();
    geneticAlgorithm3.run(10000);
    Individual bestSolution3 = geneticAlgorithm3.getBestSolution();
    std::cout<< "Best solution: "<<bestSolution3.getFitness()<<std::endl;
    for (int i : bestSolution3.getGenotype()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;


    return 0;
}
