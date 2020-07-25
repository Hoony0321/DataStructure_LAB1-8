#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include<iostream>
#include<string>
#include<fstream>

#include "ItemType.h"

using namespace std;

#define MAXSIZE 15

//Array class
class ArrayList {
public:
	//constructor
	ArrayList();
	//destructor
	~ArrayList();

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
	*	@brief	새로운 데이터 sorted array 형식으로 추가.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(ItemType data);

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
	int GetNextItem(ItemType& data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	none.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(ItemType data);

	/**
	*	@brief	list에서 해당하는 id를 Binary Search 방법으로 찾는다.
	*	@pre	none.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값이 넘겨받은 item의 내용으로 변경된다.
	*	@param	data	교체하고자 하는 id와 레코드를 가진 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(ItemType data);
	
	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Retrieve_SeqS(ItemType& data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Retrieve_BinaryS(ItemType& data);

	/**
	*	@brief	list에서 해당하는 kind number를 가진 item을 찾아서 display한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 type(kind)가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	result - 찾은 아이템의 index 저장할 배열, kind - 찾고자하는 kind int상수, num - result 배열의 크기를 나타내는 int 변수
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int SearchByKind(int* result, int kind, int& num);

	

	

private:
	ItemType m_Array[MAXSIZE];  ///list array
	int m_CurPointer;           ///iterator pointer
	int m_Length;               ///number of element current list


};


#endif // !ARRAYLIST_H
