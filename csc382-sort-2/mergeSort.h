#pragma once

#include <utility>

#include "Node.h"
#include "LinkedList.h"

template <typename Data>
void moveNodeIntoSortedList(LinkedList<Data>& list, LinkedList<Data>& sortedItems, Node<Data> & node);

template <typename Data>
Node<Data>* getHeadOfListWithRemainingElements(LinkedList<Data>& leftList, LinkedList<Data>& rightList);

template <typename Data>
void moveRemainingElements(LinkedList<Data>& sortedItems, LinkedList<Data>& leftList, LinkedList<Data>& rightList);

template <typename Data>
LinkedList<Data> mergeLists(LinkedList<Data>& leftList, LinkedList<Data>& rightList);

template <typename Data>
Node<Data>* getMiddleNode(LinkedList<Data>& list);

template <typename Data>
LinkedList<Data> mergeSort(LinkedList<Data>& list);