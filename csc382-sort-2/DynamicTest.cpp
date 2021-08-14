#include "DynamicTest.h"

// Add dynamic test constructor.
// Takes the test name and makes a linked list for testing
DynamicTest::DynamicTest(string name) : name{ name }, linkedList{ LinkedList<string>{""} }
{
}

// Prompts the user and returns their answer
string DynamicTest::prompt(string question)
{
	cout << question << endl;
	string answer;
	cin >> answer;
	return answer;
}

// Asks the user what letter they want to insert, then inserts it.
void DynamicTest::promptUserToInsertDataItem(bool& shouldContinue)
{
	string itemToInsert = prompt("What letter do you want to insert?");
	linkedList.Insert(itemToInsert);
	string shouldContinueAnswer = prompt("Do you want to insert another item? (yes/no)");
	shouldContinue = shouldContinueAnswer == "yes";
}

// Asks the user what letters they want to insert.
// Continues until they stop saying yes.
void DynamicTest::promptUserToInsertData()
{
	bool shouldContinue = true;
	while (shouldContinue)
	{
		promptUserToInsertDataItem(shouldContinue);
	}
}

// Asks the user what letter they want to find, then returns the match
Node<string>* DynamicTest::promptUserToFindItem()
{
	string letterToFind = prompt("Type in the letter to find.");
	return linkedList.Find(&letterToFind);
}

// Shows whether the match was found, given a pointer.
void DynamicTest::showWhetherItemWasFound(Node<string>* item)
{
	if (item == nullptr)
	{
		cout << "Item not found\n";
	}
	else
	{
		cout << "Item found.\n";
	}
}

// Says the name of the test, asks the user to insert data, and tests the operation.
void DynamicTest::startTest()
{
	cout << "Beginning test " << name << endl;
	promptUserToInsertData();
	testOperation();
}
