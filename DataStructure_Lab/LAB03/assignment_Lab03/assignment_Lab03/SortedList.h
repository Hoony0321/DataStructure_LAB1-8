#ifndef SortedList_H
#define SortedList_H



template<typename T>
class SortedList {
public:
	//constructor
	SortedList();
	//destructor
	~SortedList();

	/**
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list is empty, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	새로운 데이터 sorted array 형식으로 추가.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add( T& data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	none.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T data);

	/**
	*	@brief	list에서 해당하는 id를 Binary Search 방법으로 찾는다.
	*	@pre	none.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값이 넘겨받은 item의 내용으로 변경된다.
	*	@param	data	교체하고자 하는 id와 레코드를 가진 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(T& data);
	
	//추가
	int GetByBinarySearch(T& data);


	/**
	*	@brief	list에서 해당하는 kind number를 가진 item을 찾아서 display한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 type(kind)가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	result - 찾은 아이템의 index 저장할 배열, kind - 찾고자하는 kind int상수, num - result 배열의 크기를 나타내는 int 변수
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int SearchByKind(int* result, int kind, int& num);

	

	

private:
	T* m_Array;  ///list array
	int m_CurPointer;           ///iterator pointer
	int m_Length;               ///number of element current list


};





//constructor
template<typename T>
SortedList<T>::SortedList() {
	m_Array = new T[LISTMAXSIZE];
	m_CurPointer = NULL;
	m_Length = 0;
}
//destructor
template<typename T>
SortedList<T>::~SortedList() {
	delete[] m_Array;
}

//Clear List
template<typename T>
void SortedList<T>::MakeEmpty() {
	m_Length = 0; // <- 현재 list 길이를 0으로 바꿈.
}

//return list  size
template<typename T>
int SortedList<T>::GetLength() {
	return m_Length;
}

//check list is full
template<typename T>
bool SortedList<T>::IsFull() {
	if (m_Length >= LISTMAXSIZE) return true;
	else return false;
}

//check list is empty
template<typename T>
bool SortedList<T>::IsEmpty() {
	if (m_Length == 0) return true;
	else return false;
}



//Reset m_CurPointer
template<typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}

// move list iterator to the next item in list and get that item.
template<typename T>
int SortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;			//pointer 증가(다음아이템으로 pointer 이동)
	if (m_CurPointer == m_Length) return -1;		//pointer가 list 끝에 도달하면 -1 리턴
	data = m_Array[m_CurPointer];	//data에 pass by reference로 데이터 넘겨줌

	return m_CurPointer;    // pointer 리턴
}

//리스트에 아이템을 정렬된 방식으로 추가
//정상적으로 작동하면 1을 리턴, 그렇지 않으면 0을 리턴
template<typename T>
int SortedList<T>::Add(T& data) {

	
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
	T curItem;
	ResetList();
	iPos = GetNextItem(curItem);  // 끝에 도달하면 -1을 리턴
	
	while (iPos > -1 && !found)
	{
		switch (curItem.CompareID(data))
		{
		case EQUAL:			//동일한 ID 발견
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

template<typename T>
int SortedList<T>::GetByBinarySearch(T& data)
{
	int first = 0;
	int last = m_Length - 1;
	bool found = false;
	while (first <= last && !found)
	{
		int mid = (first + last) / 2;
		if (data < m_Array[mid]) {
			last = mid - 1;
		}
		else if (data > m_Array[mid]) {
			first = mid + 1;
		}
		else {
			data = m_Array[mid];
			found = true;
			return 1;
		}
	}
	return 0;
}

//정렬된 리스트에서 아이템 삭제
template<typename T>
int SortedList<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)
		{
			for (int j = i; j < m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;
			return 1;
		}
	}
	return 0;
}

//Binary Search를 통해 찾고자하는 ID 검색 후 Replace.
template<typename T>
int SortedList<T>::Replace(T& data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)
		{
			m_Array[i] = data;
			return 1;
		}
	}
	return 0;
}




//1. 입력된 데이터와 일치하는 kind를 가진 Item 검색
//2. 그 Item들의 index를 result 배열에 저장
//3. result배열의 크기를 나타내는 변수 num에 currentIndex 입력
//4. 종료
template<typename T>
int SortedList<T>::SearchByKind(int* result, int kind, int& num) {
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


#endif // !SortedList_H
