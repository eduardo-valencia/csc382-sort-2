///
/// This program contains a merge sort algorithm that operates on a linked list.
/// It contains automatic tests, times the algorithm's performance with various datasets, and allows the user to test it manually.
/// Run this file to begin and test the algorithm manually.
///

#include <iostream>
#include "Test.h"
#include "timeSort.h"
#include "DynamicSortTest.h"

///
/// The function that runs the tests, times the algorithm, and starts the dynamic tests.
///
int main()
{
    std::cout << "This program uses mergeSort.\n";
    std::cout << "Running automatic tests!\n";
    runTests();
    timeAlgorithm();
    DynamicSortTest sortTest{};
    sortTest.startTest();
}
