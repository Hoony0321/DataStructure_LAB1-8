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
	*	@brief	���ο� ������ �߰�.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(const T& inData);

	/**
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(T& data);

	/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	none.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� ItemType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T data);

	/**
	*	@brief	list���� �ش��ϴ� id�� Binary Search ������� ã�´�.
	*	@pre	none.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� �Ѱܹ��� item�� �������� ����ȴ�.
	*	@param	data	��ü�ϰ��� �ϴ� id�� ���ڵ带 ���� ItemType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Replace(const T& data);

	/*
	*	@brief	UnsortedList ������ �����մϴ�.
	*	@pre	list is set.
	*	@post	list ����Լ��� �� ������ ���Ե˴ϴ�.
	*	@param	UnsortedList ����
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

	// ostream<< �����ε�
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
