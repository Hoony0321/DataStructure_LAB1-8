#include "SortedList.h"

// Make list empty.
void SortedList::MakeEmpty()
{
	m_Length = 0;
}

// Get a number of records in current list.
int SortedList::GetLength()
{
	return m_Length;
}

// Check capacity of list is full.
bool SortedList::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// search item by using primary key
int SortedList::Add(ItemType inData)
{
	// List가 꽉 차있는 경우 0을 리턴
	if (IsFull()) return 0;
	if (m_Length == 0) {    	// List가 비어 있으면 맨 얖에 추가, length++, 1을 리턴 
		m_Array[m_Length++] = inData;
		return 1;
	}
	// 새 항목의 삽입 위치 iPos를 검색. 끝에 도달하거나 현재 item이 inData보다 크면 종료
	int iPos = 0;
	bool found = false;
	ItemType curItem;
	ResetList();
	iPos = GetNextItem(curItem);  // 끝에 도달하면 -1을 리턴
	while (iPos > -1 && !found)
	{
		switch (curItem.Compare(inData))
		{
		case EQUAL:
			cout << " %%% same item exist in the list %%%\n";
			return 0;
		case GREATER:
			found = true;
			break;
		case LESS:
			iPos = GetNextItem(curItem);
			break;
		}
	}

	//끝에 도달하면 iPos==-1. 이경우 맨 뒤에 추가
	if (iPos == -1) {
		// 인덱스 length에 추가, length++, 1리턴
		m_Array[m_Length++] = inData;
		return 1;
	}
	
	// iPost<length이면 iPos부터 length-1 사이의 모든 항목을 뒤로 한 칸씩 이동
	for (int i = m_Length; i > iPos; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	// iPos에 추가
	m_Array[iPos] = inData;
	
	m_Length++;
	return 1;
}

// Initialize list iterator.
void SortedList::ResetList()
{
	m_CurPointer = -1;
}



// move list iterator to the next item in list and get that item.
int SortedList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == m_Length)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}




//Primary key가 일치하는 item을 찾아서 반환함
int SortedList::Retrieve_SeqS(ItemType& data)
{
	ItemType CurItem;

	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while (m_CurPointer < m_Length)	//처음부터 끝까지
	{
		switch (CurItem.Compare(data))	//입력 아이템과 현재 아이템을 비교
		{
		case EQUAL:	//일치하면
			data = CurItem;	//data에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 Primary key가 더 크면(정렬되있으므로 나머지에 찾는게 없다)
			return 0;	//실패(0)을 리턴
			break;
		default:	//현재 아이템의 Primary key가 더 작으면
			GetNextItem(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
			break;
		}
	}
	return 0; //실패시0
}



//Primary key가 일치하는 item을 찾아서 제거함
int SortedList::Delete(ItemType data)
{
	if (Retrieve_SeqS(data))	//Primary key가 일치하는 item을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//Primary key일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//Primary key가 일치하는 item의 내용을 교체시킴
int SortedList::Replace(ItemType data)
{
	ItemType tmp(data);	//입력받은 item을 백업

	if (Retrieve_SeqS(data))	//일치하는 아이템을 찾은 경우
	{
		m_Array[m_CurPointer] = tmp;	//배열에서 현재포인터가 가르키는 것을 백업했던 아이템으로 교체시킴
		return 1;	//성공(1)을 리턴
	}
	return 0;	//Primary key와 일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//Primary key가 일치하는 item을 이진탐색으로 검색해서 반환한다.
int SortedList::Retrieve_BinaryS(ItemType& data)
{
	if (m_Length == 0)	//만약 배열이 비었다면
		return 0;	//실패(0)을 리턴
	int currentPos = m_Length / 2;	//배열의 중간부터 시작
	while (1)
	{
		switch (m_Array[currentPos].Compare(data))
		{
		case EQUAL:	//현재 아이템과 입력 아이템의 Primary key가 일치한다면
			data = m_Array[currentPos];	//data에 발견한 값을 리턴
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 Primary key가 입력 아이템의 Primary key보다 크다면
			if (currentPos == 0)	//처음 배열의 값보다 작은경우
				return 0;	//실패(0)을 리턴
			currentPos /= 2;	//더 작은쪽 인덱스의 절반로 이동
			break;
		case LESS:	//현재 아이템의 Primary key가 입력 아이템의 Primary key보다 작다면
			if (currentPos == m_Length - 1)	//마지막 배열의 값보다 큰경우
				return 0;	//실패(0)을 리턴
			currentPos = (currentPos + m_Length) / 2;	//더 큰쪽 인덱스의 절반으로 이동
			break;
		}
	}
	return 0;	//호출될 일 없는 리턴(WARNING 방지용)
}
