#pragma once

#include "DoublySortedLinkedList.h"

class ContainerType;
class ItemType;
class SimpleItemType;
class TempType;
class StorageType;

template<typename T>
class Stack;

template<typename T>
class SortedList;

class Base {

public:
	static DoublySortedLinkedList<ItemType> MasterList;
	static SortedList<StorageType> StorageList;
	static SortedList<ContainerType> ContainerList;
	static TempType TempList;
	static Stack<SimpleItemType> SearchList;
	
};

