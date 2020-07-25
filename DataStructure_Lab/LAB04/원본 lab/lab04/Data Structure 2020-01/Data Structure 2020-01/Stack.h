#pragma once
template <typename T>
class Stack
{
private:
	int m_iTop;			///< Number of elements.
	int m_nMaxStack;	///< max size of the stack.
	T* m_pItems;		///< Pointer for a stack.

public:
	Stack();
	Stack(int max);
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
	*	@brief	Returns a copy of top item on the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
	int Top(T& item);

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void Print();
};

// Allocate dynamic array whose size is MAXSTACK.
template<typename T>
inline Stack<T>::Stack()
{
	m_nMaxStack = MAXSTACK;
	m_pItems = new T[m_nMaxStack];
	m_iTop = -1;
}

// Allocate dynamic array whose size is max.
template<typename T>
inline Stack<T>::Stack(int max)
{
	m_nMaxStack = max;
	m_pItems = new T[m_nMaxStack];
	m_iTop = -1;
}

// Destruct the object. Free the array dynamically allocated.
template<typename T>
inline Stack<T>::~Stack()
{
	delete[] m_pItems;
}

// Determines whether the stack is full.
template<typename T>
inline bool Stack<T>::IsFull() const
{
	if (m_iTop >= m_nMaxStack - 1)
		return true;
	else
		return false;
}

// Determines whether the stack is empty.
template<typename T>
inline bool Stack<T>::IsEmpty() const
{
	if (m_iTop <= -1)
		return true;
	else
		return false;
}

// Adds newItem to the top of the stack.
template<typename T>
inline int Stack<T>::Push(T item)
{
	if (IsFull())
		return -1;
	else
	{
		m_iTop++;
		m_pItems[m_iTop] = item;
		return m_iTop;
	}
}

// Removes top item from the stack.
template<typename T>
inline int Stack<T>::Pop(T& item)
{
	if (IsEmpty())
		return -1;
	else
	{
		item = m_pItems[m_iTop--];
		return m_iTop;
	}
}

// Gets top item from the stack.
template<typename T>
inline int Stack<T>::Top(T& item)
{
	if (IsEmpty())
		return -1;
	else
	{
		item = m_pItems[m_iTop];
		return m_iTop;
	}
}

// Print all the items in the stack on screen
template<typename T>
inline void Stack<T>::Print()
{
	cout << "Stack: ";
	// Stack 내의 모든 element 출력.
	for (int i = m_iTop; i >= 0; i--)
	{
		cout << m_pItems[i] << " - ";
	}
	cout << endl;
}
