#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "missing_number.h"

#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

const int SIZE = 10;

random_device rd;
mt19937 rng(rd());

void generateSequence(vector<int>& sequence, int size, int missingNumber)
{
    iota(sequence.begin(), sequence.begin() + size, 1);
    sequence.erase(sequence.begin() + missingNumber - 1);
    shuffle(sequence.begin(), sequence.begin() + size - 1, rng);
}

TEST_CASE("The missing number can be found by sorting")
{
    vector<int> sequence1(SIZE);
    generateSequence(sequence1, SIZE, 1);
    REQUIRE(findMissingNumberBySorting(sequence1) == 1);

    vector<int> sequence2(SIZE);
    generateSequence(sequence2, SIZE, 5);
    REQUIRE(findMissingNumberBySorting(sequence2) == 5);

    vector<int> sequence3(SIZE);
    generateSequence(sequence3, SIZE, SIZE);
    REQUIRE(findMissingNumberBySorting(sequence3) == SIZE);
}

TEST_CASE("The missing number can be found by indexing")
{
    vector<int> sequence1(SIZE);
    generateSequence(sequence1, SIZE, 1);
    REQUIRE(findMissingNumberByIndexing(sequence1) == 1);

    vector<int> sequence2(SIZE);
    generateSequence(sequence2, SIZE, 5);
    REQUIRE(findMissingNumberByIndexing(sequence2) == 5);

    vector<int> sequence3(SIZE);
    generateSequence(sequence3, SIZE, SIZE);
    REQUIRE(findMissingNumberByIndexing(sequence3) == SIZE);
}

TEST_CASE("The missing number can be found by Gauss")
{
    vector<int> sequence1(SIZE);
    generateSequence(sequence1, SIZE, 1);
    REQUIRE(findMissingNumberByGauss(sequence1) == 1);

    vector<int> sequence2(SIZE);
    generateSequence(sequence2, SIZE, 5);
    REQUIRE(findMissingNumberByGauss(sequence2) == 5);

    vector<int> sequence3(SIZE);
    generateSequence(sequence3, SIZE, SIZE);
    REQUIRE(findMissingNumberByGauss(sequence3) == SIZE);
}
