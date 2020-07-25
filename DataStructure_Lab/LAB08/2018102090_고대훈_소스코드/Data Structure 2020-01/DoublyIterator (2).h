#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	����Ʈ ������.
	*/
	DoublyIterator(const DoublySortedLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList�� ģ�� Ŭ����.

	/*
	*	@brief	���� ����Ű�� node�� Null���� Ȯ���մϴ�.
	*	@pre	m_pCurPointer is set.
	*	@post	none.
	*	@return	m_pCurPointer�� Null�̸� false, �׷��� ������ true�� return
	*/
	bool NotNull();

	/*
	*	@brief	���� node�� Null���� Ȯ���մϴ�.
	*	@pre	m_pCurPointer is set.
	*	@post	none.
	*	@return	m_pCurPointer->Next�� Null�̸� false, �׷��� ������ true�� return
	*/
	bool NextNotNull();

	/*
	*	@pre	m_List is set.
	*	@post	none.
	*	@return	m_List ù��° ��带 return
	*/
	T First();

	/*
	*	@pre	m_pCurPointer is set.
	*	@post	none.
	*	@return	m_pCurPointer�� next node�� �ٲߴϴ�.
	*/
	T Next();

	/*
	*	@pre	m_pCurPointer is set.
	*	@post	none.
	*	@return	���� ����Ű�� �ִ� ��带 return.
	*/
	DoublyNodeType<T> GetCurrentNode();

private:
	const DoublySortedLinkedList<T>& m_List;   //DoublySortedLinkedList
	DoublyNodeType<T>* m_pCurPointer;          //Pointer
};

template <typename T>
bool DoublyIterator<T> ::NotNull()
{
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

template <typename T>
bool DoublyIterator<T> ::NextNotNull()
{
	if (m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}

template <typename T>
T DoublyIterator<T> ::First()
{
	return m_List.m_pFirst->data;
}

template <typename T>
T DoublyIterator<T> ::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

template <typename T>
DoublyNodeType<T> DoublyIterator<T> ::GetCurrentNode()
{
	return *m_pCurPointer;
}

#endif _DOUBLYITERATOR_H
