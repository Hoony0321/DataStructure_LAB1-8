#pragma once
class TempType
{
private:
	int numOfItems;
	CircularQueue<ItemType> tItemList;

public:
	TempType();
	~TempType();

	bool IsEmpty();
	void AddtItem(ItemType _tItem);
	void DequeueFromtItemList(ItemType& item);
	void PrinttItemList();

};