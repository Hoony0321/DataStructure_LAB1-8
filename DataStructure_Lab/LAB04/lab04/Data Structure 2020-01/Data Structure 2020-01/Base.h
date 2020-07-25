#pragma once

class ContainerType;
class ItemType;
class SimpleItemType;
class TempType;
class StorageType;


template<typename T>
class SortedList;

class Base {

public:

	static SortedList<ItemType> MasterList;
	static SortedList<ContainerType> ContainerList;
	static TempType TempList;
	static SortedList<StorageType> StorageList;
};

