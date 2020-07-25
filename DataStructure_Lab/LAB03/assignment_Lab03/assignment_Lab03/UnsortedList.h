#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H



template<typename T>
class UnsortedList {
private:
	T* m_Array;
	int m_CurPointer;
	int m_Length;
public:

	UnsortedList();
	~UnsortedList();

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	bool IsEmpty();

	void ResetList();
	int GetNextItem(T& data);

	int Add(T& inData);
	int Get(T& data);
	int Delete(T data);
	int Replace(T& data);

	void operator=(const UnsortedList& data);
};

template<typename T>
UnsortedList<T>::UnsortedList() {
	m_Array = new T[LISTMAXSIZE];
	m_CurPointer = -1;
	m_Length = 0;
}

template<typename T>
UnsortedList<T>::~UnsortedList() {
	delete[] m_Array;
}

template<typename T>
void UnsortedList<T>::MakeEmpty() {
	m_Length = 0;
}

template<typename T>
int UnsortedList<T>::GetLength()
{
	return m_Length;
}

template<typename T>
bool UnsortedList<T>::IsFull()
{
	if (m_Length > LISTMAXSIZE - 1)
		return true;
	else
		return false;
}

template<typename T>
bool UnsortedList<T>::IsEmpty()
{
	if (m_Length == 0)
		return true;
	else
		return false;
}

template<typename T>
void UnsortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<typename T>
int UnsortedList<T>::GetNextItem(T& data)
{
	m_CurPointer++;
	if (m_CurPointer == m_Length)
		return -1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

template<typename T>
int UnsortedList<T>::Add(T& inData)
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
int UnsortedList<T>::Get(T& data)
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
int UnsortedList<T>::Delete(T data)
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
int UnsortedList<T>::Replace(T& data)
{
	for (int i = 0; i < m_Length; i++)
	{
		//operator== 추가 필요
		if (m_Array[i] == data)
		{
			m_Array[i] = data;
			return 1;
		}
	}
	return 0;
}

template<typename T>
void UnsortedList<T>::operator=(const UnsortedList& other) {
	for (int i = 0; i < other.m_Length; i++) {
		m_Array[i] = other.m_Array[i];
	}
	m_CurPointer = other.m_CurPointer;
	m_Length = other.m_Length;
}

#endif // !UNSORTEDLIST_H
