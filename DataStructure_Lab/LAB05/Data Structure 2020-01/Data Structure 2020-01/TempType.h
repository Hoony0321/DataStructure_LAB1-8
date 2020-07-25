#pragma once
class TempType
{
private:
	int numOfItems;
	CircularQueue<ItemType> tItemList;

public:
	//-------default-constructor-------//
	TempType();

	//-------destructor-------//
	~TempType();

	//-------Empty function-------//
	/**
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list is empty, otherwise return false.
	*/
	bool IsEmpty();

	//-------Add function-------//
	/**
	*	@brief	tItemList에 아이템 추가.
	*	@pre	tItemList should be initialized.
	*	@post	added the new item into the tItemList.
	*	@param	data	ItemType.
	*/
	void AddtItem(ItemType _tItem);

	//-------Dequeue function-------//
	/**
	*	@brief	tItemList에서 아이템을 Dequeue로 뺍니다.
	*	@pre	tItemList should be initialized & tItemList is not empty.
	*	@post	dequeue the item in the tItemList.
	*	@param	data    ItemType.
	*/
	void DequeueFromtItemList(ItemType& item);

	//-------Display function-------//
	/**
	*	@brief	Display item record in the tempList on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void PrinttItemList();

};