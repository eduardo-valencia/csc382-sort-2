#include "DynamicSortTest.h"

DynamicSortTest::DynamicSortTest() : DynamicTest("Sort") {

}

void DynamicSortTest::testOperation() {
	cout << "Sorting list...\n";
	LinkedList<string> sortedList = mergeSort<string>(linkedList);
	testListIsSorted<string>(sortedList);
}