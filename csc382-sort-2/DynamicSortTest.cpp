#include "DynamicSortTest.h"

///
/// Creates a dynamic test with the name "Sort"
///
DynamicSortTest::DynamicSortTest() : DynamicTest("Sort")
{
}

///
/// Sorts the user's list and prints out the results.
///
void DynamicSortTest::testOperation()
{
	cout << "Sorting list...\n";
	LinkedList<string> sortedList = mergeSort<string>(linkedList);
	testListIsSorted<string>(sortedList);
	printLinkedList<string>(sortedList);
	cout << "If you did not see errors, the list was sorted successfully.\n";
}