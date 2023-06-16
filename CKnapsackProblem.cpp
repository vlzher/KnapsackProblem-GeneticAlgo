#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem(int numItems, int capacity, std::vector<int> itemSizes, std::vector<int> itemValues) {
    if (numItems <= 0 || capacity <= 0 || itemSizes.size() != numItems || itemValues.size() != numItems) {
        throw std::invalid_argument("Invalid input data for knapsack problem");
    }
    mNumItems = numItems;
    mCapacity = capacity;
    mItemSizes = itemSizes;
    mItemValues = itemValues;
}

int CKnapsackProblem::calculateFitness(std::vector<int> genotype) {
    if (genotype.size() != mNumItems) {
        throw std::invalid_argument("Invalid genotype size");
    }
    int totalValue = 0;
    int totalSize = 0;
    for (int i = 0; i < mNumItems; i++) {
        if (genotype[i] == 1) {
            totalValue += mItemValues[i];
            totalSize += mItemSizes[i];


            if (totalSize > mCapacity) {
                return 0;
            }
        }

    }
    return totalValue;
}

void CKnapsackProblem::loadFromFile(std::string fileName) {
    std::cout<< "Loading from file " << fileName << std::endl;
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file " + fileName);
    }
    file >> mNumItems;
    file >> mCapacity;
    mItemSizes.resize(mNumItems);
    mItemValues.resize(mNumItems);
    for (int i = 0; i < mNumItems; i++) {
        file >> mItemSizes[i];
        file >> mItemValues[i];
    }
    file.close();
}

int CKnapsackProblem::getNumItems() {
    return mNumItems;
}

int CKnapsackProblem::getCapacity() {
    return mCapacity;
}

std::vector<int> CKnapsackProblem::getItemSizes() {
    return mItemSizes;
}

std::vector<int> CKnapsackProblem::getItemValues() {
    return mItemValues;
}

void CKnapsackProblem::printInfo() {
    std::cout << "Number of items: " << mNumItems << std::endl;
    std::cout << "Capacity: " << mCapacity << std::endl;
    std::cout << "Item sizes: ";
    for (int i = 0; i < mNumItems; i++) {
        std::cout << mItemSizes[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Item values: ";
    for (int i = 0; i < mNumItems; i++) {
        std::cout << mItemValues[i] << " ";
    }
    std::cout << std::endl;

}


#include "CKnapsackProblem.h"
