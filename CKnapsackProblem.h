//
// Created by vladz on 1/14/2023.
//

#ifndef MINIPROJECT_CKNAPSACKPROBLEM_H
#define MINIPROJECT_CKNAPSACKPROBLEM_H


#include <vector>

class CKnapsackProblem {
public:
    CKnapsackProblem(int numItems, int capacity, std::vector<int> itemSizes, std::vector<int> itemValues);

    CKnapsackProblem(std::string fileName){ loadFromFile(fileName);};

    CKnapsackProblem(){};

    int calculateFitness(std::vector<int> genotype);

    void loadFromFile(std::string fileName);
    int getNumItems();
    int getCapacity();
    std::vector<int> getItemSizes();
    std::vector<int> getItemValues();
    void printInfo();
private:
    int mNumItems;
    int mCapacity;
    std::vector<int> mItemSizes;
    std::vector<int> mItemValues;
};


#endif //MINIPROJECT_CKNAPSACKPROBLEM_H
