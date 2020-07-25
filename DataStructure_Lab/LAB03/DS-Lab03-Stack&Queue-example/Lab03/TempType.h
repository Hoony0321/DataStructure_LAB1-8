#ifndef TEMPTYPE_H
#define TEMPTYPE_H

class TempType {
private:
	int numOfItems;
	Queue<ItemType> tItemList;

public:
	TempType();
	~TempType();
	int Enqueue(ItemType item);
	int Dequeue(ItemType& itme);

};


#endif // !TEMPTYPE_H

