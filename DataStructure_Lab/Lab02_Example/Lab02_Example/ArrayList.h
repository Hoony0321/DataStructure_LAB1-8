#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <string>
#include <fstream>

#include "ItemType.h"
using namespace std;

#define MAXSIZE 5

class ArrayList {
public:
	ArrayList();
	~ArrayList();

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	int Add(ItemType data);
	void ResetList();
	int GetNextItem(ItemType& data);

private:
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;


};


#endif // !ARRAYLIST_H

