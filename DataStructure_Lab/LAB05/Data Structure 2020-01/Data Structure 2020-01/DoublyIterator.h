#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	디폴트 생성자.
	*/
	DoublyIterator(const DoublySortedLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList와 친구 클래스.

	/*
	*	@brief	현재 가리키는 node가 Null인지 확인합니다.
	*	@pre	m_pCurPointer is set.
	*	@post	none.
	*	@return	m_pCurPointer가 Null이면 false, 그렇지 않으면 true를 return
	*/
	bool NotNull();

	/*
	*	@brief	다음 node가 Null인지 확인합니다.
	*	@pre	m_pCurPointer is set.
	*	@post	none.
	*	@return	m_pCurPointer->Next가 Null이면 false, 그렇지 않으면 true를 return
	*/
	bool NextNotNull();

	/*
	*	@pre	m_List is set.
	*	@post	none.
	*	@return	m_List 첫번째 노드를 return
	*/
	T First();

	/*
	*	@pre	m_pCurPointer is set.
	*	@post	none.
	*	@return	m_pCurPointer를 next node로 바꿉니다.
	*/
	T Next();

	/*
	*	@pre	m_pCurPointer is set.
	*	@post	none.
	*	@return	현재 가리키고 있는 노드를 return.
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
