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
	*	@brief	���ο� ������ sorted array �������� �߰�.
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
	int Replace(T& data);
	
	//�߰�
	int GetByBinarySearch(T& data);


	/**
	*	@brief	list���� �ش��ϴ� kind number�� ���� item�� ã�Ƽ� display�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� type(kind)�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	result - ã�� �������� index ������ �迭, kind - ã�����ϴ� kind int���, num - result �迭�� ũ�⸦ ��Ÿ���� int ����
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
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
	m_Length = 0; // <- ���� list ���̸� 0���� �ٲ�.
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
	m_CurPointer++;			//pointer ����(�������������� pointer �̵�)
	if (m_CurPointer == m_Length) return -1;		//pointer�� list ���� �����ϸ� -1 ����
	data = m_Array[m_CurPointer];	//data�� pass by reference�� ������ �Ѱ���

	return m_CurPointer;    // pointer ����
}

//����Ʈ�� �������� ���ĵ� ������� �߰�
//���������� �۵��ϸ� 1�� ����, �׷��� ������ 0�� ����
template<typename T>
int SortedList<T>::Add(T& data) {

	
	if (IsFull()) return 0; // list�� �� ���� return 0
	if (IsEmpty()) {
		m_Array[0] = data;  // list�� ��������� �˻��� �ʿ���� �ٷ� ù��° index�� �Է�.
		m_Length += 1;
		return 1;
	}
	// �� �׸��� ���� ��ġ iPos�� �˻�.
	/*
	*	1. ���� �����ϸ� ����. (����Ʈ ���� ������ �Է�)
	*	2. ������ ID�� ���� �������� ������ ����(return 0)
	*	3. �Է� data id���� ū data�� �߰��ϸ� ����. (���� ��ġ ã��)
	*/
	int iPos = 0;
	bool found = false;
	T curItem;
	ResetList();
	iPos = GetNextItem(curItem);  // ���� �����ϸ� -1�� ����
	
	while (iPos > -1 && !found)
	{
		switch (curItem.CompareID(data))
		{
		case EQUAL:			//������ ID �߰�
			return 0;
		case GREATER:		//ū ID �߰�. search �ߴ�
			found = true;
			break;
		case LESS:			//���� ID �߰�. ��� ����.
			iPos = GetNextItem(curItem);
			break;
		}
	}

	//���� �����ϸ� iPos==-1. �̰�� �� �ڿ� �߰�
	if (iPos == -1) {
		// �ε��� length�� �߰�, length++, 1����
		m_Array[m_Length++] = data;
		return 1;
	}

	// iPost<length�̸� iPos���� length-1 ������ ��� �׸��� �ڷ� �� ĭ�� �̵�
	for (int i = m_Length; i > iPos; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	// iPos�� �߰�
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

//���ĵ� ����Ʈ���� ������ ����
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

//Binary Search�� ���� ã�����ϴ� ID �˻� �� Replace.
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




//1. �Էµ� �����Ϳ� ��ġ�ϴ� kind�� ���� Item �˻�
//2. �� Item���� index�� result �迭�� ����
//3. result�迭�� ũ�⸦ ��Ÿ���� ���� num�� currentIndex �Է�
//4. ����
template<typename T>
int SortedList<T>::SearchByKind(int* result, int kind, int& num) {
	int currentIndex = 0; //result �迭 index - 0���� ���� �����Ͽ� result �迭 0������ �������� ������ index�� �����.
	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i].GetType() == kind) {
			result[currentIndex] = i;     // ���� kind �������� �߰��ϸ� �ش� index(i)�� result �迭�� �Է�.
			currentIndex++;
		}
	}
	num = currentIndex; // ���� result �迭�� ����� index ��.
	if (currentIndex == 0) return 0; // currentIndex�� 0�̸� ������ kind�� ���� ������ ���� x return 0
	else return 1; // ���������� �Լ� �����. return 1
}


#endif // !SortedList_H
