#include "DynamicSortTest.h"

DynamicSortTest::DynamicSortTest() : DynamicTest("Sort") {

}

void DynamicSortTest::testOperation() {
	cout << "Sorting list...\n";
	LinkedList<string> sortedList = mergeSort<string>(linkedList);
	testListIsSorted<string>(sortedList);
	cout << "If you did not see errors, the list was sorted successfully.\n";
}