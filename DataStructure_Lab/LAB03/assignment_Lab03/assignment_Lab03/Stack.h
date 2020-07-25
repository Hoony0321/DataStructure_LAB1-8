#ifndef STACK_H
#define STACK_H


template<typename T>
class Stack {

private:
	T* m_Stack;
	int m_CurPointer;
	int m_Top;
public:
	Stack();
	~Stack();

	/**
	*	@brief	Determines whether the stack is full.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (stack is full)
	*/
	bool IsFull() const;

	/**
	*	@brief	Determines whether the stack is empty.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (stack is empty)
	*/
	bool IsEmpty() const;

	/**
	*	@brief	Adds newItem to the top of the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is full), FullStack exception is thrown; otherwise, newItem is at the top of the stack.
	*/
	int Push(T item);

	/**
	*	@brief	Removes top item from the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
	int Pop(T& item);

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void DisplayStack();

	/**
	*	@brief	Reset m_CurPointer.
	*	@pre	none.
	*	@post	m_CurPointer가 m_iFront 값으로 초기화된다.
	*/
	void ResetPointer();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& item);

	int ReplaceItem(T& item);
};

template<typename T>
Stack<T>::Stack() {
	m_CurPointer = NULL;
	m_Top = -1;
	m_Stack = new T[STACKMAXSIZE];
}

template<typename T>
Stack<T>::~Stack() {
	delete[] m_Stack;
}

template<typename T>
bool Stack<T>::IsFull() const{
	if (m_Top == STACKMAXSIZE - 1) return true;
	else return false;
}

template<typename T>
bool Stack<T>::IsEmpty() const {
	if (m_Top == -1) return true;
	else return false;
}

template<typename T>
int Stack<T>::Push(T item) {
	if (IsFull()) return -1;

	m_Top++;
	m_Stack[m_Top] = item;
	return m_Top;
}

template<typename T>
int Stack<T>::Pop(T& item) {
	if (IsEmpty()) return -1;

	item = m_Stack[m_Top];
	m_Top--;
	return m_Top;
}


template<typename T>
void Stack<T>::DisplayStack() {
	if (IsEmpty()) return;

	int Point = m_Top;
	cout << "\t";
	while (Point >= 0) {
		cout << m_Stack[Point] << " - ";
		Point--;
	}
	cout << endl;
}

template<typename T>
void Stack<T>::ResetPointer() {
	m_CurPointer = -1;
}

template<typename T>
int Stack<T>::GetNextItem(T& item) {
	if (IsEmpty) return -1;

	m_CurPointer++;
	item = m_Stack[m_CurPointer];

	if (m_CurPointer == STACKMAXSIZE - 1) {
		m_CurPointer = -1;
		return 0;
	}

	return m_CurPointer;
}

template<typename T>
int Stack<T>::ReplaceItem(T& item) {
	for (int i = m_Top; i >= 0; i--) {
		if (m_Stack[i] == item) {
			m_Stack[i] = item;
			return 1;
		}
	}
	return 0;
}
#endif // !STACK_H


