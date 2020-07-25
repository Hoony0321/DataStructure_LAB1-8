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
	*	@brief  �����̳ʿ� ����ִ� ������ ������ ��ȯ�մϴ�.
	*	@pre	none.
	*	@post	none.
	*	@return numofItems.
	*/
	int GetNumOfItems();

	/*
	*	@brief  �����̳� Position�� ��ȯ�մϴ�.
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
	*	@brief	���ο� item �߰�.
	*	@pre	itemList should be initialized.
	*	@post	added the new item into the item list.
	*	@param	data	 ItemType.
	*/
	void AddsItem(SimpleItemType& _item);

	//-------DELETE FUNCTION-------//
	/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	none.
	*	@post	item list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� ItemType��.
	*/
	void DeletesItem(SimpleItemType& _item);

	//-------UPDATE FUNCTION-------//
	/**
	*	@brief	item�� ã�Ƽ� �ش� item ������ �ٲߴϴ�.
	*	@pre	�μ��� �ִ� item id�� item list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	item list ������ ã�� item�� �ش� data ������ ������Ʈ �ȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� SimpleItemType��. 
	*/
	void UpdatesItem(SimpleItemType& _item);

	//-------PHOTO FUNCTION-------//
	/**
	*	@brief	���ο� photo �߰�.
	*	@pre	photoList should be initialized.
	*	@post	added the new photo into the list.
	*	@param	data	 string.
	*/
	void AddPhoto(string photo);

	//-------DELETE FUNCTION-------//
	/**
	*	@brief	��ġ�ϴ� photo�� ã�Ƽ� �ش� photo�� �����Ѵ�.
	*	@pre	none.
	*	@post	photo list ���� �ش� photo�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� photo �̸�.
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
	*	@brief	Item id�� �̿��Ͽ� Master list���� �������� ã�� �� detail ���� ���
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllDetailsItem(DoublySortedLinkedList<ItemType>& ref);

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
	*	@brief	container id�� ���մϴ�.
	*	@pre	container id is set.
	*	@post	���� Storage id�� ���� �� ture,�׷��� ������ false
	*	@param	containerType ����
	*/
	bool operator==(const ContainerType& _item);

	/*
	*	@brief	container id�� ���մϴ�.
	*	@pre	container id is set.
	*	@post	���� container id�� ũ�� ture,�׷��� ������ false
	*	@param	containerType ����
	*/
	bool operator>(const ContainerType& _item);

	/*
	*	@brief	container id�� ���մϴ�.
	*	@pre	container id is set.
	*	@post	���� container id�� ������ ture,�׷��� ������ false
	*	@param	containerType ����
	*/
	bool operator<(const ContainerType& _item);

	/*
	*	@brief	container ������ �����մϴ�.
	*	@pre	container record is set.
	*	@post	container ����Լ��� �� ������ ���Ե˴ϴ�.
	*	@param	containerType ����
	*/
	void operator=(const ContainerType& _item);

	// ostream<< �����ε�
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

