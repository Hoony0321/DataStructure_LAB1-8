#include "ArrayList.h"

void ArrayList::MakeEmpty() {
	m_Length = 0;
}

int ArrayList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool ArrayList::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int ArrayList::Add(ItemType inData)
{
	if (IsFull()) return 0;
	if (IsEmpty()) {
		cout << "실행됨" << endl;
		m_Array[0] = inData;
		m_Length++;
		return 1;
	}

	bool Found = false;
	int iPos = 0;
	while (!Found && iPos < m_Length) {
		switch (m_Array[iPos].CompareByID(inData)) {
		case EQUAL:
			cout << "the same item exist in the list" << endl;
			return 0;
		case GREATER:
			Found = true;
			break;
		case LESS:
			iPos++;
			break;
		}
	}

	if (iPos == m_Length) {
		m_Array[iPos] = inData;
	}
	else {
		for (int i = m_Length - 1; i >= iPos; i--) {
			m_Array[i + 1] = m_Array[i];
		}
		m_Array[iPos] = inData;
	}


	m_Length++;

	return 1;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	//Pointer를 -1로 바꿈. 그래야 GetNextItem에서 첫번째 아이템 가리킴.
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}


bool ArrayList::IsEmpty() {
	if (m_Length == 0)
		return true;
	return false;
}


int ArrayList::Retrieve(ItemType& data) {
	for (m_CurPointer = 0; m_CurPointer < m_Length; ++m_CurPointer) {
		switch (m_Array[m_CurPointer].CompareByID(data))
		{
		case EQUAL:
			data = m_Array[m_CurPointer];
			return 1;

		case GREATER:
			return 0;

		case LESS:
			break;
		}
	}
	return 0;
}

int ArrayList::Retrieve_Binary(ItemType& data) {
	int midPoint = 0;
	int First = 0;
	int Last = m_Length - 1;
	bool Found = false;
	bool MoreToSearch = (First <= Last);

	while (MoreToSearch && !Found) {
		midPoint = (First + Last) / 2;
		switch (m_Array[midPoint].CompareByID(data)) {
		case LESS:
			First = midPoint + 1;
			break;
		case EQUAL:
			Found = true;
			data = m_Array[midPoint];
			return 1;
		case GREATER:
			Last = midPoint - 1;
			break;
		}

		if (First > Last) { MoreToSearch = false; }
	}

	return 0;
}

int ArrayList::RetrieveByName(ItemType& data,int result[]) {
	string str;
	int curPoint = 0;
	for (int i = 0; i < m_Length; i++) {
		str = m_Array[i].GetSong;
		if (str.find(data.GetSong()) != string::npos) {
			result[curPoint] = i;
			curPoint++;
		}
	}

	if (curPoint == 0) return 0;

	return 1;
}




int ArrayList::Delete(ItemType data) {
	bool isFind = false;
	m_CurPointer = 0;
	while (!isFind && m_CurPointer < m_Length) {
		switch (m_Array[m_CurPointer].CompareByID(data))
		{
		case EQUAL:
			isFind = true;
			for (int i = m_CurPointer; i < m_Length - 1; i++) {
				m_Array[i] = m_Array[i + 1];
			}
			break;
		case GREATER:
			return 0;
		case LESS:
			m_CurPointer++;
			break;
		}
	}
	
	//m_Length 감소(데이터 하나 삭제됨)
	
	if (isFind) m_Length--; return 1;

	return 0;
}

//number가 같은 item의 정보를 바꿈.
int ArrayList::Replace(ItemType data) {
	for (m_CurPointer = 0; m_CurPointer < m_Length; ++m_CurPointer) {
		if (data == m_Array[m_CurPointer]) {
			m_Array[m_CurPointer] = data;
			return 1;
		}
	}
	return -1;
}
