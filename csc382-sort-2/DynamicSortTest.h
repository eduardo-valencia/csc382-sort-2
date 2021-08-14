#pragma once

#include <iostream>

#include "DynamicTest.h"
#include "testSorted.h"
#include "mergeSort.h"

using namespace std;

class DynamicSortTest : public DynamicTest
{
public:
	DynamicSortTest();

	void testOperation();
};