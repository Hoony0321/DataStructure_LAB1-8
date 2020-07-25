#pragma once
template <typename T>
class SortedList
{
private:
	T * m_Array;		///< list array.
	int m_Length;		///< number of elements in list.
	int m_CurPointer;	///< iterator pointer.
	int m_MaxSize;		///< max size.

public:
	//default-constructor
	SortedList();

	//destructor
	~SortedList();

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

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
	*	@brief	새로운 데이터 sorted array 형식으로 추가.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T& inData);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(T& data);

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

	/**
	*	@brief	이진 검색으로 item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int GetByBinarySearch(T& data);
};

template<typename T>
SortedList<T>::SortedList()
{
	m_MaxSize = ADDSIZE;
	m_Length = 0;
	ResetList();
	m_Array = new T[m_MaxSize];
}

template<typename T>
SortedList<T>::~SortedList()
{
	delete[] m_Array;
}

template<typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}

template<typename T>
int SortedList<T>::GetLength()
{
	return m_Length;
}

template<typename T>
bool SortedList<T>::IsFull()
{
	if (m_Length > m_MaxSize - 1)
		return true;
	else
		return false;
}

template<typename T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<typename T>
int SortedList<T>::GetNextItem(T & data)
{
	m_CurPointer++;
	if (m_CurPointer == m_Length)
		return -1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

template<typename T>
int SortedList<T>::Add(T & inData)
{
	if (IsFull()) {
		T* tmpList = new T[m_Length];
		for (int i = 0; i < m_Length; ++i) {
			tmpList[i] = m_Array[i];
		}
		delete[] m_Array;
		m_MaxSize += ADDSIZE;
		m_Array = new T[m_MaxSize];
		for (int i = 0; i < m_Length; ++i) {
			m_Array[i] = tmpList[i];
		}
		delete[] tmpList;
	}

	if (m_Length == 0)
	{
		m_Array[m_Length] = inData;
		m_Length++;
		return 1;
	}
	else
	{
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i] < inData) {
				if (i == m_Length - 1)
				{
					m_Array[m_Length] = inData;
					m_Length++;
					return 1;
				}
			}
			else if (m_Array[i] > inData) {
				for (int j = m_Length; j > i; j--)
				{
					m_Array[j] = m_Array[j - 1];
				}
				m_Array[i] = inData;
				m_Length++;
				return 1;
			}
			else {
				return -1;
			}
		}
	}
	return 0;
}

template<typename T>
int SortedList<T>::Get(T & data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)
		{
			data = m_Array[i];
			return 1;
		}
	}
	return 0;
}

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

template<typename T>
int SortedList<T>::Replace(T & data)
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

template<typename T>
int SortedList<T>::GetByBinarySearch(T & data)
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
