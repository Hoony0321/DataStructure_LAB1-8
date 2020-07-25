#include "pch.h"
#include "TempType.h"

TempType::TempType()
{
	numOfItems = 0;
}

TempType::~TempType()
{
}

void TempType::AddtItem(ItemType _tItem)
{
	tItemList.AddToCircularQueue(_tItem);
	numOfItems++;
}

void TempType::DequeueFromtItemList(ItemType& item)
{
	tItemList.DeleteFrCircularQueue(item);
	numOfItems--;
}

void TempType::PrinttItemList()
{
	tItemList.PlayInsertOrder();
}
