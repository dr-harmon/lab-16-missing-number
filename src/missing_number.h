#pragma once

#include <vector>

// Returns the missing number in a vector of unique numbers in the range [1,n] where
// the vector size is n-1. Note: The input vector will be modified as a side-effect.
int findMissingNumberBySorting(std::vector<int>& sequence);

// Returns the missing number in a vector of unique numbers in the range [1,n] where
// the vector size is n-1. Returns -1 if the missing number cannot be determined.
int findMissingNumberByIndexing(const std::vector<int>& sequence);

// Returns the missing number in a vector of unique numbers in the range [1,n] where
// the vector size is n-1.
int findMissingNumberByGauss(const std::vector<int>& sequence);
