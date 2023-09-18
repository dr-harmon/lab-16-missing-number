#include "missing_number.h"
#include <algorithm>
#include <numeric>

using namespace std;

int findMissingNumberBySorting(vector<int>& sequence)
{
    sort(sequence.begin(), sequence.end());

    int expectedNumber = 1;
    for (auto i = sequence.begin(); i != sequence.end(); i++) {
        int actualNumber = *i;
        if (expectedNumber != actualNumber) {
            return expectedNumber;
        }
        expectedNumber++;
    }

    return expectedNumber;
}

int findMissingNumberByIndexing(const vector<int>& sequence)
{
    vector<int> indices(sequence.size() + 1);
    fill(indices.begin(), indices.end(), 0);
    for (auto i = sequence.begin(); i != sequence.end(); i++) {
        int number = *i;
        indices[number] = number;
    }
    for (int i = 1; i <= indices.size(); i++) {
        if (indices[i] != i) {
            return i;
        }
    }

    return -1;
}

int findMissingNumberByGauss(const vector<int>& sequence)
{
    int actualSum = accumulate(sequence.begin(), sequence.end(), 0);
    int n = sequence.size() + 1;
    int expectedSum = (n * (n + 1)) / 2;
    return expectedSum - actualSum;
}
