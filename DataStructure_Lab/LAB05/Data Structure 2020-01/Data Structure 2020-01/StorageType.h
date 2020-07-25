#pragma once
class StorageType : public Base
{
private:
	int								id;				///< storage id.
	int								currentNum;		///< current container number.
	int								maxNum;			///< max container number.
	SingleLinkedList<ContainerType>	ContainerList;	///< container list.

public:
	//-------default-constructor-------//
	StorageType();

	//-------constructor-------//
	StorageType(int maxnum);

	//-------destructor-------//
	~StorageType();

	//-------Get Function-------//
	/*
	*	@pre	Storage id is set.
	*	@post	none.
	*	@return Storage id.
	*/
	int GetId() const;

	/*
	*	@brief  현재 Storage에 있는 container 개수를 출력합니다.
	*	@pre    .
	*	@post	none.
	*	@return return currentNum.
	*/
	int GetCurrentNum() const;

	/*
	*	@brief  Storage의 최대 container 개수를 출력합니다.
	*	@pre    .
	*	@post	none.
	*	@return return Max container numberx`.
	*/
	int GetMaxNum() const;

	//-------Get Next Container Function-------//

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move container list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextContainer(ContainerType& tcontainer);

	//-------Set Function-------//

	/**
	*	@brief	Set Storage id.
	*	@pre	none.
	*	@post	Storage id is set.
	*	@param	inId	Storage id.
	*/
	void SetId(int _id);


	/**
	*	@brief	Set Storage id from keyboard.
	*	@pre	none.
	*	@post	Storage id is set.
	*/
	void SetIdFromKB();

	//-------Full&Empty Function-------//
	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool isFull();

	/**
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list is empty, otherwise return false.
	*/
	bool isEmpty();

	//-------Search Function-------//
	/**
	*	@brief	탐색을 통해 같은 id를 가진 container를 찾습니다.
	*	@pre	없음.
	*	@post	넘겨받은 container과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 containerType값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int GetContainer(ContainerType& _con);

	//-------Add Function-------//
	/**
	*	@brief	새로운 ContainerType 추가.
	*	@pre	container list should be initialized.
	*	@post	added the new container into the container list.
	*	@param	data	new containerType.
	*/
	void AddContainer(ContainerType& _item);

	//-------Delete Function-------//
	/**
	*	@brief	id가 일치하는 container를 찾아서 해당 container을 제거한다.
	*	@pre	none.
	*	@post	container list 내에 해당 container이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 containerType값.
	*/
	void DeleteContainer(ContainerType& _item);

	//-------Update Function-------//
	/**
	*	@brief	container을 찾아서 해당 container을 바꿉니다.
	*	@pre	인수 container에 있는 id가 container list 내에 존재하는 값이어야 한다.
	*	@post	container list 내에서 찾은 container에 data가 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 containerType값. 발견한 containerType이 리턴된다.
	*/
	void UpdateContainer(ContainerType& _item);

	//-------Disply Function-------//

	/**
	*	@brief	Display Id in the containerlist on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllContainerID();

	/**
	*	@brief	Display all record in the containerlist on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllContainer();

	/**
	*	@brief	Display Id and location in the containerlist on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllContainer2();

	/**
	*	@brief	Container 안에 있는 아이템의 id를 통해 MasterList에서 item을 찾아와 Detail한 item 정보를 출력합니다.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllDetailsContainer();

	//-------Operator Function-------//

	/*
	*	@brief	Storage id를 비교합니다.
	*	@pre	Storage id is set.
	*	@post	만약 Storage id가 같을 시 ture,그렇지 않으면 false
	*	@param	StorageType 변수
	*/
	bool operator==(const StorageType& _item);


	/*
	*	@brief	Storage id를 비교합니다.
	*	@pre	Storage id is set.
	*	@post	만약 Storage id가 크면 ture,그렇지 않으면 false
	*	@param	StorageType 변수
	*/
	bool operator>(const StorageType& _item);


	/*
	*	@brief	Storage id를 비교합니다.
	*	@pre	Storage id is set.
	*	@post	만약 item id가 작으면 ture,그렇지 않으면 false
	*	@param	StorageType 변수
	*/
	bool operator<(const StorageType& _item);

	/*
	*	@brief	Storage 정보를 대입합니다.
	*	@pre	Storage record is set.
	*	@post	Storage 멤버함수에 각 정보가 대입됩니다.
	*	@param	StorageType 변수
	*/
	void operator=(StorageType& _item);
};

