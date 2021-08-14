#pragma once

#include <iostream>

#include "DynamicTest.h"
#include "testSorted.h"
#include "mergeSort.h"

using namespace std;

///
/// The class that will handle testing the sort function manually.
///
class DynamicSortTest : public DynamicTest
{
public:
	DynamicSortTest();

	///
	/// The function that will test merge sort.
	///
	void testOperation();
};