#include "ArrayList.h"

//constructor
ArrayList::ArrayList() {
	m_CurPointer = NULL;
	m_Length = 0;
}
//destructor
ArrayList::~ArrayList(){}

//Clear List
void ArrayList::MakeEmpty() {
	m_Length = 0; // <- 현재 list 길이를 0으로 바꿈.
}

//return list  size
int ArrayList::GetLength() {
	return m_Length;
}

//check list is full
bool ArrayList::IsFull() {
	if (m_Length >= MAXSIZE) return true;
	else return false;
}

//check list is empty
bool ArrayList::IsEmpty() {
	if (m_Length == 0) return true;
	else return false;
}

// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data) {
	m_CurPointer++;			//pointer 증가(다음아이템으로 pointer 이동)
	if (m_CurPointer == m_Length) return -1;		//pointer가 list 끝에 도달하면 -1 리턴
	data = m_Array[m_CurPointer];	//data에 pass by reference로 데이터 넘겨줌

	return m_CurPointer;    // pointer 리턴
}

//Reset m_CurPointer
void ArrayList::ResetList() {
	m_CurPointer = -1;
}

//리스트에 아이템을 정렬된 방식으로 추가
//정상적으로 작동하면 1을 리턴, 그렇지 않으면 0을 리턴
int ArrayList::Add(ItemType data) {
	if (IsFull()) return 0; // list가 꽉 차면 return 0
	if (IsEmpty()) {
		m_Array[0] = data;  // list가 비어있으면 검색할 필요없이 바로 첫번째 index에 입력.
		m_Length += 1;
		return 1;
	}
	// 새 항목의 삽입 위치 iPos를 검색.
	/*
	*	1. 끝에 도달하면 종료. (리스트 끝에 데이터 입력)
	*	2. 동일한 ID를 가진 아이템을 가지면 종료(return 0)
	*	3. 입력 data id보다 큰 data를 발견하면 종료. (넣을 위치 찾음)
	*/
	int iPos = 0;
	bool found = false;
	ItemType curItem;
	ResetList();
	iPos = GetNextItem(curItem);  // 끝에 도달하면 -1을 리턴
	while (iPos > -1 && !found)
	{
		switch (curItem.CompareID(data))
		{
		case EQUAL:			//동일한 ID 발견
			cout << " %%% same item exist in the list %%%\n";
			return 0;
		case GREATER:		//큰 ID 발견. search 중단
			found = true;
			break;
		case LESS:			//작은 ID 발견. 계속 진행.
			iPos = GetNextItem(curItem);
			break;
		}
	}

	//끝에 도달하면 iPos==-1. 이경우 맨 뒤에 추가
	if (iPos == -1) {
		// 인덱스 length에 추가, length++, 1리턴
		m_Array[m_Length++] = data;
		return 1;
	}

	// iPost<length이면 iPos부터 length-1 사이의 모든 항목을 뒤로 한 칸씩 이동
	for (int i = m_Length; i > iPos; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	// iPos에 추가
	m_Array[iPos] = data;

	m_Length++;
	return 1;
}

//정렬된 리스트를 이용하여 순차적으로 아이템 검색해서 찾음.
int ArrayList::Retrieve_SeqS(ItemType& data) {
	
	ItemType CurItem;

	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while (m_CurPointer < m_Length)	//처음부터 끝까지
	{
		switch (CurItem.CompareID(data))	//입력 아이템과 현재 아이템을 비교
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

//정렬된 리스트에서 아이템 삭제
int ArrayList::Delete(ItemType data) {
	if (Retrieve_BinaryS(data))	//Primary key가 일치하는 item을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//Primary key일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//Binary Search를 통해 찾고자하는 ID 검색 후 Replace.
int ArrayList::Replace(ItemType data)
{
	ItemType tmp(data);	//입력받은 item을 백업


	if (Retrieve_BinaryS(data))	//일치하는 아이템을 찾은 경우
	{
		m_Array[m_CurPointer] = tmp;	//배열에서 현재포인터가 가르키는 것을 백업했던 아이템으로 교체시킴
		return 1;	//성공(1)을 리턴
	}
	return 0;	//Primary key와 일치하는 item을 찾지 못한다면 실패(0)을 리턴
}


//정렬된 리스트에서 이진검색을 통해 아이템을 찾음.
int ArrayList::Retrieve_BinaryS(ItemType& data)
{
	int First = 0;  //찾고자 하는 영역의 첫 위치.
	int Last = m_Length -1;		//찾고자 하는 영역의 마지막 위치.
	int midPoint = 0;		//첫 위치와 마지막 위치의 중간.(반내림)
	bool Found = false;     //찾았는 지 못 찾았는 지 확인 용도 bool
	bool MoreToSearch = true;      //계속 Search를 진행해야하는 지 확인 용도 bool

	while (MoreToSearch && !Found)  //못 찾았고 계속 Search해야한다면 진행
	{
		midPoint = (First + Last) / 2;
		switch (m_Array[midPoint].CompareID(data))//ID 비교
		{
		case LESS:      //midPoint 오른쪽에 찾고자 하는 ID 존재 가능.
			First = midPoint + 1;
			break;
		case EQUAL:    //찾고자 하는 ID 찾음. Found = true -> while문 종료 (이번에는 그냥 return으로 함수 종료시킴)
			Found = true;
			data = m_Array[midPoint];
			m_CurPointer = midPoint;
			return 1;
		case GREATER:    //midPoint 왼쪽에 찾고자 하는 ID 존재 가능.
			Last = midPoint - 1;
			break;
		}
		if (First > Last) { MoreToSearch = false; }     //First가 Last보다 커지면 더 검색할 필요 x -> 다 검색함.
	}
	return 0;
}


//1. 입력된 데이터와 일치하는 kind를 가진 Item 검색
//2. 그 Item들의 index를 result 배열에 저장
//3. result배열의 크기를 나타내는 변수 num에 currentIndex 입력
//4. 종료
int ArrayList::SearchByKind(int* result, int kind, int& num) {
	int currentIndex = 0; //result 배열 index - 0부터 점점 증가하여 result 배열 0번부터 차곡차곡 아이템 index가 저장됨.
	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i].GetType() == kind) {
			result[currentIndex] = i;     // 같은 kind 아이템을 발견하면 해당 index(i)를 result 배열에 입력.
			currentIndex++;
		}
	}
	num = currentIndex; // 현재 result 배열에 저장된 index 수.
	if (currentIndex == 0) return 0; // currentIndex가 0이면 동일한 kind를 지닌 아이템 존재 x return 0
	else return 1; // 성공적으로 함수 종료됨. return 1
}




