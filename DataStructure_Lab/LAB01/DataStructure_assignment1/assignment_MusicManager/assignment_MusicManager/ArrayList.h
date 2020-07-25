#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#include "ItemType.h"

#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/
class ArrayList {
public:

	/**
	*	default constructor.
	*/
	ArrayList() {
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~ArrayList(){}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
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
	*	@brief	add a new data into list.
	*	@pre	list should be initialized. and list is not full.
	*	@post	added the new record into the list.
	*	@param	data	ItemType value.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	//수정
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
	*	@brief	Check list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list is empty, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	Get data of specific item 
	*	@pre	none.
	*	@post	if music number of data is in list, get member variable of the item.
	*   @param  data ItemType variable.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Retrieve(ItemType& data);

	//추가
	int Retrieve_Binary(ItemType& data);

	//추가
	int RetrieveByName(ItemType& data, int result[]);

	/**
	*	@brief	Delete data of specific item
	*	@pre	none.
	*	@post	if music number of data is in list, delete the item.
	*   @param  data ItemType variable.
	*	@return	return 1 if this function works well, otherwise -1.
	*/
	int Delete(ItemType data);

	/**
	*	@brief	Replace data of specific item
	*	@pre	none.
	*	@post	if music number of data is in list, Replace the item.
	*   @param  data ItemType variable.
	*	@return	return 1 if this function works well, otherwise -1.
	*/
	int Replace(ItemType data);


private:
	ItemType m_Array[MAXSIZE]; /// list array
	int m_Length;              /// number of elements in list.
	int m_CurPointer;          /// iterator pointer
};




#endif // !_UNSORTEDLIST_H
