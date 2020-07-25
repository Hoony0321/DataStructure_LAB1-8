#pragma once
template <typename T>
class UnsortedList
{
private:
	T* m_Array;			///< list array.
	int m_Length;		///< number of elements in list.
	int m_CurPointer;	///< iterator pointer.
	int m_MaxSize;		///< max size.

public:
	//default-constructor
	UnsortedList();

	//constructor
	UnsortedList(int MaxSize);

	//destructor
	~UnsortedList();

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
	*	@brief	새로운 데이터 추가.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(const T& inData);

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
	int Replace(const T& data);

	/*
	*	@brief	UnsortedList 정보를 대입합니다.
	*	@pre	list is set.
	*	@post	list 멤버함수에 각 정보가 대입됩니다.
	*	@param	UnsortedList 변수
	*/
	void operator=(const UnsortedList& _item) {
		delete[] m_Array;
		m_Length = _item.m_Length;
		m_CurPointer = _item.m_CurPointer;
		m_MaxSize = _item.m_MaxSize;
		m_Array = new T[m_MaxSize];
		for (int i = 0; i < m_Length; ++i) {
			m_Array[i] = _item.m_Array[i];
		}
	}

	// ostream<< 오버로딩
	friend ostream& operator<<(ostream& os, const UnsortedList& _item) {
		for (int i = 0; i < _item.m_Length; i++)
		{
			os <<_item.m_Array[i] << endl;
		}
		return os;
	}
};

template<typename T>
inline UnsortedList<T>::UnsortedList()
{
	m_MaxSize = 5;
	m_Length = 0;
	ResetList();
	m_Array = new T[m_MaxSize];
}

template<typename T>
inline UnsortedList<T>::UnsortedList(int MaxSize)
{
	m_MaxSize = MaxSize;
	m_Length = 0;
	ResetList();
	m_Array = new T[m_MaxSize];
}

template<typename T>
inline UnsortedList<T>::~UnsortedList()
{
	delete[] m_Array;
}

template<typename T>
inline void UnsortedList<T>::MakeEmpty()
{
	m_Length = 0;
}

template<typename T>
inline int UnsortedList<T>::GetLength()
{
	return m_Length;
}

template<typename T>
inline bool UnsortedList<T>::IsFull()
{
	if (m_Length > m_MaxSize - 1)
		return true;
	else
		return false;
}

template<typename T>
inline void UnsortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<typename T>
inline int UnsortedList<T>::GetNextItem(T& data)
{
	m_CurPointer++;
	if (m_CurPointer == m_Length)
		return -1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

template<typename T>
inline int UnsortedList<T>::Add(const T& inData)
{
	if (!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

	return 1;
}

template<typename T>
inline int UnsortedList<T>::Get(T& data)
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
inline int UnsortedList<T>::Delete(T data)
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
inline int UnsortedList<T>::Replace(const T& data)
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
