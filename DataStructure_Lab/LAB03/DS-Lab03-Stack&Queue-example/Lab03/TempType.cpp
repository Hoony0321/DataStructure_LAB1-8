#include "pch.h"
#include "TempType.h"

TempType::TempType() {
	numOfItems = 0;
}

TempType::~TempType() {
	
}

int TempType::Enqueue(ItemType item) {
	if (numOfItems == QUEUEMAXSIZE - 1) {
		return 0;
	}
	tItemList.EnQueue(item);
	numOfItems++;
	return 1;

	
	
}

int TempType::Dequeue(ItemType& item) {
	if (numOfItems == 0) {
		return 0;
	}
	tItemList.DeQueue(item);
	numOfItems--;
	return 1;
	
}