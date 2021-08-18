#pragma once

#include <iostream>

#include "LinkedList.h"

using namespace std;

template <typename Data>
void testGreaterDataDoesNotExist(LinkedList<Data>& list, Node<Data>* maxNode);

template <typename Data>
void testListIsSorted(LinkedList<Data>& list);

template <typename Data>
void printLinkedList(LinkedList<Data>& linkedList);