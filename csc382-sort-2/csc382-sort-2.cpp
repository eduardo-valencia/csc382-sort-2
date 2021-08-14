#include <iostream>
#include "Test.h"
#include "timeSort.h"
#include "DynamicSortTest.h"

///
/// The function that runs the tests, times the algorithm, and starts the dynamic tests.
///
int main()
{
    std::cout << "Running automatic tests!\n";
    runTests();
    timeAlgorithm();
    DynamicSortTest sortTest{};
    sortTest.startTest();
}
