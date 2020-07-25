#pragma once
template <typename T>
class CircularQueue
{
private:
	int m_iFront;		///< index of one infront of the first element.
	int m_iRear;		///< index of the last element.
	int m_nMaxQueue;	///< max size of the queue.
	int m_CurPointer;	///< iterator pointer.
	T* m_pItems;		///< pointer for dynamic allocation.

public:
	CircularQueue();
	CircularQueue(int max);
	~CircularQueue();

	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Makes the queue empty.
	*	@pre	Queue has been initialized.
	*	@post	m_iFront, m_CurPointer, and m_iRear are set same value as Constructer.
	*/
	void ResetQueue();

	/**
	*	@brief	Reset m_CurPointer.
	*	@pre	none.
	*	@post	m_CurPointer가 m_iFront 값으로 초기화된다.
	*/
	void ResetCurrentPointer();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	void AddToCircularQueue(T item);

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	int DeleteFrCircularQueue(T& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void PlayInsertOrder();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& item);
};

template<typename T>
CircularQueue<T>::CircularQueue()
{
	m_nMaxQueue = MAXQUEUE;
	m_CurPointer = m_nMaxQueue - 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//멤버 변수들을 초기화시켜준다.
	m_pItems = new T[m_nMaxQueue];	//m_pItems에 크기가 maxQueue인 배열을 만든다.
}

template<typename T>
CircularQueue<T>::CircularQueue(int max)
{
	m_nMaxQueue = max;
	m_CurPointer = m_nMaxQueue - 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//멤버 변수들을 초기화시켜준다.
	m_pItems = new T[max];	//m_pItems에 크기가 max인 배열을 만든다.
}

template<typename T>
CircularQueue<T>::~CircularQueue()
{
	delete[] m_pItems;
}

template<typename T>
bool CircularQueue<T>::IsFull()
{
	if (m_iFront - m_iRear == 1 || m_iRear - m_iFront == m_nMaxQueue - 1)
		return 1;	//m_iFront가 m_iRear보다 1 앞일때는 꽉 찬것이므로 1을 리턴한다. m_iFront가 0일때는 m_iRear가 m_nMaxQueue-1과 같을때 꽉 찬것이다.
	return 0;	//꽉 차지 않았으면 0을 리턴한다.
}

template<typename T>
bool CircularQueue<T>::IsEmpty()
{
	if (m_iFront == m_iRear)
		return 1;	//m_iFront와 m_iRear가 같은 경우는 queue가 비어있는 상태이므로 1을 리턴한다.
	return 0;	//비어있지 않으면 0을 리턴한다.
}

template<typename T>
void CircularQueue<T>::ResetQueue()
{
	m_iFront = m_nMaxQueue - 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//생성자와 같은 값으로 m_iFront와 m_iRear를 변경해준다.
	delete[] m_pItems;	//동적할당했던 메모리를 해제해준다.
	m_pItems = new T[m_nMaxQueue];	//m_pItems에 크기가 maxQueue인 배열을 만든다.
}

template<typename T>
void CircularQueue<T>::ResetCurrentPointer()
{
	m_CurPointer = m_iFront;
}

template<typename T>
void CircularQueue<T>::AddToCircularQueue(T item)
{
	if (IsFull()) {
		// FullQueue().print();	//꽉 찼을땐 throw FullQueue
		T tmp;
		DeleteFrCircularQueue(tmp);
	}
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item;	//m_iRear를 1증가시켜주고 item값을 넣어준다.
}

template<typename T>
int CircularQueue<T>::DeleteFrCircularQueue(T& item)
{
	if (IsEmpty()) {
		return 0;
	}
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront];	//m_iFront를 1 증가시켜주고 삭제될 값을 item에 복사해준다.
	return 1;
}

template<typename T>
void CircularQueue<T>::PlayInsertOrder()
{
	if (IsEmpty())
		return;
	if (m_iFront > m_iRear)	//m_iFront가 m_iRear보다 클때
	{
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++)
		{
			cout << m_pItems[i] << " - ";
		}	//m_iFront 다음 항목부터 배열의 끝까지 출력한다.
		for (int i = 0; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << " - ";
		}	//배열의 처음부터 m_iRear까지 출력해준다.
	}
	else	//m_iRear가 m_iFront보다 클때
	{
		for (int i = m_iFront + 1; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << " - ";
		}	//m_iFront+1에서부터 m_iRear까지 출력
	}
	cout << endl;
}

template<typename T>
int CircularQueue<T>::GetNextItem(T& item)
{
	if (IsEmpty()) {
		return -1;
	}

	m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
	item = m_pItems[m_CurPointer];	//m_iFront에서 1 증가된 index의 m_pItem을 item에 복사해준다.
	if (m_CurPointer == m_iRear) {
		this->ResetCurrentPointer();
		return 0;
	}
	return 1;
}
