#pragma once
class ContainerType : public Base
{
private:
	int								id;
	string							position;
	UnsortedList<SimpleItemType>	sItemList;
	UnsortedList<string>			photoList;

public:
	//-------DEFAULT-CONSTRUCTOR-------//
	ContainerType();

	//-------DESTRUCTOR-------//
	~ContainerType();

	//-------GET FUNCTION-------//
	/*
	*	@pre	container id is set.
	*	@post	none.
	*	@return container id.
	*/
	int GetId() const;

	/*
	*	@brief  컨테이너에 들어있는 아이템 개수를 반환합니다.
	*	@pre	none.
	*	@post	none.
	*	@return numofItems.
	*/
	int GetNumOfItems();

	/*
	*	@brief  컨테이너 Position를 반환합니다.
	*	@pre	none.
	*	@post	none.
	*	@return container position.
	*/
	string GetPosition() const;


	//-------SET FUNCTION-------//
	/**
	*	@brief	Set container id.
	*	@pre	none.
	*	@post	container id is set.
	*	@param	inId	container id.
	*/
	void SetId(int _id);

	/**
	*	@brief	Set container position.
	*	@pre	none.
	*	@post	container position is set.
	*	@param	inId	container position.
	*/
	void SetPosition(string _name);

	//-------SET FROM KEYBOARD FUNCTION-------//
	/**
	*	@brief	Set container id from keyboard.
	*	@pre	none.
	*	@post	container id is set.
	*/
	void SetIdFromKB();

	/**
	*	@brief	Set container position from keyboard.
	*	@pre	none.
	*	@post	container position is set.
	*/
	void SetPositionFromKB();

	/**
	*	@brief	Set container record from keyboard.
	*	@pre	none.
	*	@post	container record is set.
	*/
	void SetRecordFromKB();

	//-------SEARCH FUNCTION-------//

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int GetsItem(SimpleItemType& _item);


	//-------ADD FUNCTION-------//
	/**
	*	@brief	새로운 item 추가.
	*	@pre	itemList should be initialized.
	*	@post	added the new item into the item list.
	*	@param	data	 ItemType.
	*/
	void AddsItem(SimpleItemType& _item);

	//-------DELETE FUNCTION-------//
	/**
	*	@brief	id가 일치하는 item를 찾아서 해당 item을 제거한다.
	*	@pre	none.
	*	@post	item list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값.
	*/
	void DeletesItem(SimpleItemType& _item);

	//-------UPDATE FUNCTION-------//
	/**
	*	@brief	item을 찾아서 해당 item 정보를 바꿉니다.
	*	@pre	인수에 있는 item id가 item list 내에 존재하는 값이어야 한다.
	*	@post	item list 내에서 찾은 item에 해당 data 정보가 업데이트 된다.
	*	@param	data	찾고자 하는 id가 입력된 SimpleItemType값. 
	*/
	void UpdatesItem(SimpleItemType& _item);

	//-------PHOTO FUNCTION-------//
	/**
	*	@brief	새로운 photo 추가.
	*	@pre	photoList should be initialized.
	*	@post	added the new photo into the list.
	*	@param	data	 string.
	*/
	void AddPhoto(string photo);

	//-------DELETE FUNCTION-------//
	/**
	*	@brief	일치하는 photo를 찾아서 해당 photo를 제거한다.
	*	@pre	none.
	*	@post	photo list 내에 해당 photo가 제거된다.
	*	@param	data	제거하고자 하는 photo 이름.
	*/
	void DeletePhoto(string photo);

	//-------DISPLAY FUNCTION-------//
	/**
	*	@brief	Display container info on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayContainerInfo();

	/**
	*	@brief	Display photo list info on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllPhoto();

	/**
	*	@brief	Display itemlist info on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllsItem();

	/**
	*	@brief	Item id를 이용하여 Master list에서 아이템을 찾은 뒤 detail 정보 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllDetailsItem(CHeapBase<ItemType>* ref);

	/**
	*	@brief	Display item's name on screen
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllsItemName();

	/**
	*	@brief  Display	container all record on screen
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayDetailInfo();

	//-------OPERATOR FUNCTION-------//
	/*
	*	@brief	container id를 비교합니다.
	*	@pre	container id is set.
	*	@post	만약 Storage id가 같을 시 ture,그렇지 않으면 false
	*	@param	containerType 변수
	*/
	bool operator==(const ContainerType& _item);

	/*
	*	@brief	container id를 비교합니다.
	*	@pre	container id is set.
	*	@post	만약 container id가 크면 ture,그렇지 않으면 false
	*	@param	containerType 변수
	*/
	bool operator>(const ContainerType& _item);

	/*
	*	@brief	container id를 비교합니다.
	*	@pre	container id is set.
	*	@post	만약 container id가 작으면 ture,그렇지 않으면 false
	*	@param	containerType 변수
	*/
	bool operator<(const ContainerType& _item);

	/*
	*	@brief	container 정보를 대입합니다.
	*	@pre	container record is set.
	*	@post	container 멤버함수에 각 정보가 대입됩니다.
	*	@param	containerType 변수
	*/
	void operator=(const ContainerType& _item);

	// ostream<< 오버로딩
	friend ostream& operator<<(ostream& os, ContainerType& _item) {
		os << "\tContainer ID : " << _item.id << endl;
		os << "\tPosition  : " << _item.position << endl;
		os << "\t===== PhotoList ====" << endl;
		_item.DisplayAllPhoto();
		os << "\t===== ItemList ====" << endl;
		os << _item.sItemList;
		return os;
	}


};

