#include "ArrayList.h"

//constructor
ArrayList::ArrayList() {
	m_Length = 0;
	m_CurPointer = -1;
}
ArrayList::~ArrayList(){}

void ArrayList::MakeEmpty() {
	m_Length = 0;
}

int ArrayList::GetLength() {
	return m_Length;
}

bool ArrayList::IsFull() {
	if (m_Length >= MAXSIZE) return true;
	else return false;
}

int ArrayList::Add(ItemType data) {
	if (IsFull()) {
		cout << "\tList is Full." << endl;
		return 0;
	}

	m_Array[m_Length] = data;
	m_Length += 1;

	return 1;
}

void ArrayList::ResetList() {
	m_CurPointer = -1;
}

int ArrayList::GetNextItem(ItemType &data) {
	if (m_CurPointer >= MAXSIZE - 1) return 0;

	m_CurPointer += 1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}