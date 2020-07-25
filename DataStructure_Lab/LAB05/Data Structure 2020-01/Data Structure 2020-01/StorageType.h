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
	*	@brief  ���� Storage�� �ִ� container ������ ����մϴ�.
	*	@pre    .
	*	@post	none.
	*	@return return currentNum.
	*/
	int GetCurrentNum() const;

	/*
	*	@brief  Storage�� �ִ� container ������ ����մϴ�.
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
	*	@brief	Ž���� ���� ���� id�� ���� container�� ã���ϴ�.
	*	@pre	����.
	*	@post	�Ѱܹ��� container�� id�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� containerType��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int GetContainer(ContainerType& _con);

	//-------Add Function-------//
	/**
	*	@brief	���ο� ContainerType �߰�.
	*	@pre	container list should be initialized.
	*	@post	added the new container into the container list.
	*	@param	data	new containerType.
	*/
	void AddContainer(ContainerType& _item);

	//-------Delete Function-------//
	/**
	*	@brief	id�� ��ġ�ϴ� container�� ã�Ƽ� �ش� container�� �����Ѵ�.
	*	@pre	none.
	*	@post	container list ���� �ش� container�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� containerType��.
	*/
	void DeleteContainer(ContainerType& _item);

	//-------Update Function-------//
	/**
	*	@brief	container�� ã�Ƽ� �ش� container�� �ٲߴϴ�.
	*	@pre	�μ� container�� �ִ� id�� container list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	container list ������ ã�� container�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� containerType��. �߰��� containerType�� ���ϵȴ�.
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
	*	@brief	Container �ȿ� �ִ� �������� id�� ���� MasterList���� item�� ã�ƿ� Detail�� item ������ ����մϴ�.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllDetailsContainer();

	//-------Operator Function-------//

	/*
	*	@brief	Storage id�� ���մϴ�.
	*	@pre	Storage id is set.
	*	@post	���� Storage id�� ���� �� ture,�׷��� ������ false
	*	@param	StorageType ����
	*/
	bool operator==(const StorageType& _item);


	/*
	*	@brief	Storage id�� ���մϴ�.
	*	@pre	Storage id is set.
	*	@post	���� Storage id�� ũ�� ture,�׷��� ������ false
	*	@param	StorageType ����
	*/
	bool operator>(const StorageType& _item);


	/*
	*	@brief	Storage id�� ���մϴ�.
	*	@pre	Storage id is set.
	*	@post	���� item id�� ������ ture,�׷��� ������ false
	*	@param	StorageType ����
	*/
	bool operator<(const StorageType& _item);

	/*
	*	@brief	Storage ������ �����մϴ�.
	*	@pre	Storage record is set.
	*	@post	Storage ����Լ��� �� ������ ���Ե˴ϴ�.
	*	@param	StorageType ����
	*/
	void operator=(StorageType& _item);
};

