# Knapsack problem genetic algorithm

This project is a genetic algorithm implementation for solving the Knapsack Problem. The Knapsack Problem is a classic optimization problem where a set of items with certain values and sizes need to be selected to maximize the total value while staying within a given capacity constraint.

## Prerequisites

- C++ compiler
- Standard Template Library (STL)
- CKnapsackProblem.h
- CGeneticAlgorithm.h
- Individual.h

## Classes

### CKnapsackProblem
- Represents the Knapsack Problem.
- Constructor:
  - `CKnapsackProblem(int numItems, int capacity, std::vector<int> itemSizes, std::vector<int> itemValues)`
    - Creates a Knapsack Problem with the specified parameters.
  - `CKnapsackProblem(std::string fileName)`
    - Loads the Knapsack Problem from a file.
- Methods:
  - `int calculateFitness(std::vector<int> genotype)`
    - Calculates the fitness value for a given genotype.
  - `void loadFromFile(std::string fileName)`
    - Loads the Knapsack Problem from a file.
  - `int getNumItems()`
    - Returns the number of items in the problem.
  - `int getCapacity()`
    - Returns the capacity constraint of the problem.
  - `std::vector<int> getItemSizes()`
    - Returns a vector of item sizes.
  - `std::vector<int> getItemValues()`
    - Returns a vector of item values.
  - `void printInfo()`
    - Prints information about the problem.

### Individual
- Represents an individual solution.
- Constructor:
  - `Individual()`
    - Creates an empty individual.
  - `Individual(std::vector<int> genotype, CKnapsackProblem problem)`
    - Creates an individual with the given genotype and associated problem.
- Methods:
  - `void calculateFitness()`
    - Calculates the fitness value of the individual based on its genotype and the associated problem.
  - `void mutate(double MUTPROB)`
    - Applies mutation to the individual's genotype with the specified mutation probability.
  - `std::pair<Individual, Individual> cross(Individual other, double CROSSPROB)`
    - Performs crossover with another individual and returns two offspring individuals.
  - `int getFitness()`
    - Returns the fitness value of the individual.
  - `std::vector<int> getGenotype()`
    - Returns the genotype of the individual.
  - `void setGenotype(std::vector<int> genotype)`
    - Sets the genotype of the individual.

### CGeneticAlgorithm
- Represents the genetic algorithm for solving the Knapsack Problem.
- Constructor:
  - `CGeneticAlgorithm(CKnapsackProblem problem, int populationSize, double crossProb, double mutProb)`
    - Creates a genetic algorithm with the specified parameters.
- Methods:
  - `

void run(int numberOfGenerations)`
    - Runs the genetic algorithm for the specified number of generations.
  - `Individual getBestSolution()`
    - Returns the best solution found by the genetic algorithm.
  - `Individual findBestIndividual()`
    - Finds the best individual in the current population.
  - `void printInfo()`
    - Prints information about the genetic algorithm.

## License

This project is licensed under the [MIT License](LICENSE).
