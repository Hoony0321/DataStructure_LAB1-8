#ifndef QUEUE_H
#define QUEUE_H



template<typename T>
class Queue {
private:
	T* m_Queue;
	int m_Front;
	int m_Rear;
	int m_CurPointer;

public:
	
	Queue();
	~Queue();

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
	void ResetPoint();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	int EnQueue(T item);

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	int DeQueue(T& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void DisplayQueue();

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
Queue<T>::Queue() {
	m_Queue = new T[QUEUEMAXSIZE];
	m_Front = QUEUEMAXSIZE - 1;
	m_Rear = QUEUEMAXSIZE - 1;
	m_CurPointer = NULL;
}

template<typename T>
Queue<T>::~Queue() {
	delete[] m_Queue;
}

template<typename T>
bool Queue<T>::IsFull() {
	if (m_Front - m_Rear == 1 || m_Rear - m_Front == QUEUEMAXSIZE - 1) return true;
	else return false;
}

template<typename T>
bool Queue<T>::IsEmpty() {
	if (m_Front == m_Rear) return true;
	else return false;
}

template<typename T>
void Queue<T>::ResetQueue() {
	m_Front = QUEUEMAXSIZE - 1;
	m_Rear = QUEUEMAXSIZE - 1;
	delete[] m_Queue;
	m_Queue = new T[QUEUEMAXSIZE];
}

template<typename T>
void Queue<T>::ResetPoint() {
	m_CurPointer = m_Front;
}

template<typename T>
int Queue<T>::EnQueue(T item) {
	if (IsFull()) {
		return 0;
	}
	m_Rear = (m_Rear + 1) % QUEUEMAXSIZE;
	m_Queue[m_Rear] = item;
	return 1;
}

template<typename T>
int Queue<T>::DeQueue(T& item) {
	if (IsEmpty()) {
		cout << "\t Queue is Empty." << endl;
		return 0;
	}
	m_Front = (m_Front + 1) % QUEUEMAXSIZE;
	item = m_Queue[m_Front];
	return 1;
}

template<typename T>
void Queue<T>::DisplayQueue() {
	if (IsEmpty()) return;
	int Pointer = m_Front;
	cout << "\t";
	while (Pointer != m_Rear) {
		Pointer = (Pointer + 1) % QUEUEMAXSIZE;
		cout << m_Queue[Pointer] << " - ";
	}
	cout << endl;
}

template<typename T>
int Queue<T>::GetNextItem(T& item) {
	if (IsEmpty) return -1;
	m_CurPointer = (m_CurPointer + 1) % QUEUEMAXSIZE;
	item = m_Queue[m_CurPointer];
	if (m_CurPointer == m_Rear) {
		ResetPoint();
		return 0;
	}
	return 1;
	

}
#endif // !QUEUE_H