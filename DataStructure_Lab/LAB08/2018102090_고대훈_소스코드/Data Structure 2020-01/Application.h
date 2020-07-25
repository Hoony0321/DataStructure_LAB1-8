#pragma once


class Application : public Base
{
private:
	ifstream					m_InFile;		///< input file descriptor.
	ofstream					m_OutFile;		///< output file descriptor.
	int							m_Command;		///< current command number.
	SortedList<StorageType> StorageList;
	SortedList<ContainerType> ContainerList;
	TempType TempList;
	Stack<SimpleItemType> SearchList;


public:
	/**
	*	constructor.
	*/
	Application();

	/**
	*	destructor.
	*/
	~Application();


	void Test();


	///=============== Application System ===============///
	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*/
	void GetCommand();




	///=============== MasteList ===============///
	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem(ItemType& item);

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� item�� �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteItem();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� item�� ����ȴ�.
	*/
	int ReplaceItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchById_SequenS();

	/**
	*	@brief	����Ʈ���� �ش� id�� ���� item�� ����Ž���� �̿��� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ȭ�鿡 ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByID_BinaryS();




	///=============== File System ===============///
	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	


	///=============== TempType ===============///
	/**
	*	@brief	Add new record into list. (��, Storage ID, Container ID �Է� �� ��.)
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*/
 	void Add_tempItem();

	/**
	*	@brief	TempList���� ������ �ϳ��� dequeue �������� ���ϴ�.
	*	@pre	list should be initialized. at least one item in the list.
	*	@post	first item is dequeue.
	*/
	void DequeueFromtItemList();

	/**
	*	@brief	Display TempList's item on screen
	*	@pre	list should be initialized.
	*	@post	none.
	*/
	void PrinttItemList();





	///====== Container ======///

	/**
	*	@brief	Add new photo into list.
	*	@pre	photo list should be initialized.
	*	@post	new photo is added into the list.
	*/
	void AddPhoto();

	/**
	*	@brief	��ġ�ϴ� photo�� ã�Ƽ� �ش� photo�� �����Ѵ�.
	*	@pre	none.
	*	@post	list ���� �ش� photo�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� photo �̸��� �Էµ� string��.
	*/
	void DeletePhoto();

	/**
	*	@brief	Set container position.
	*	@pre	none.
	*	@post	container position id is set.
	*	@param	inId	container position.
	*/
	void SetContainerPosition();

	/**
	*	@brief	Display photolist info on screen.
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
	void DisplayAllDetailsItem();






	///====== Storage ======///

	/**
	*	@brief	Display all storage info on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllStorage();

	/**
	*	@brief	Display all storage info on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllContainer();

	/**
	*	@brief	Display all item's detail info on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllDetailsContainer();

	/**
	*	@brief	Display photo list on screen. �̶� Storage - Container �ܰ踦 ��ħ.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayPhotoList();

	/**
	*	@brief	Display container info on screen. �̶� Storage - Container �ܰ踦 ��ħ.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllContainer2();





	///====== Additional Function ======///
	
	/**
	*	@brief	����Ʈ���� �ش� usage�� ���� item�� ã�´�.
	*   @pre    none.
	*   @post   none.
	*	@detail	ã�� item�� ȭ�鿡 ��µȴ�.
	*/
	void SearchByUsage();



	/**
	*	@brief	����Ʈ���� ������ �ش��ϴ� Date�� ���� item�� ã�´�.
	*   @pre    none.
	*   @post   none.
	*	@detail	ã�� item�� ȭ�鿡 ��µȴ�.
	*/
	//�ԷµǴ� �⵵�� ���� �ĺ� �������� ����Ѵ�.
	//���� 2���� �Էµȴ�. ex) 2018, 2020 
	//��, �ԷµǴ� ���ڴ� 4�ڸ������Ѵ�.
	void SearchByYear();

	/**
	*	@brief	����Ʈ���� Storage - container �ܰ踦 ���� item�� ã�´�.
	*   @pre    none.
	*   @post   none.
	*	@detail	ã�� item�� ȭ�鿡 ��µȴ�.
	*/
	void FindItem();

	/**
	*	@brief	item�� date ������ ���� �ð� ������ ��.
	*   @pre    none.
	*   @post   none.
	*	@detail	item�� date ������ ���� �ð� ���̸� ����մϴ�.
	*/
	int CompareTime(int date);

	//CompareTime() �Լ��� numofsearch �̿�
	/**
	*	@brief	������ ��õ�ϴ� ��ǰ ����Ʈ ���
	*   @pre    none.
	*   @post   none.
	*	@detail	item�� ���� �ð����� ���� 3�� �̻��̰� �˻�Ƚ�� 0�� �������� ����մϴ�.
	*/
	void RecommandItem_ThrowAway();

	/**
	*	@brief	item ���� container�� ��õ�մϴ�.
	*   @pre    none.
	*   @post   none.
	*	@detail	���� ���� ���� item�� ���� container�� ã�� ����մϴ�.
	*/
	void RecommandContainer();

	/**
	*	@brief	���ã�� item ����Ʈ�� ����մϴ�.
	*   @pre    none.
	*   @post   none.
	*	@detail	���� ���� �˻�Ƚ���� ���� item�� �� ���� 1 ���� �˻�Ƚ���� ���� �������� ����մϴ�.
	*/
	void Display_MostSearch();

	/**
	*	@brief	�˻� ����� ����մϴ�.
	*   @pre    none.
	*   @post   none.
	*	@detail SearchList�� ����� �˻� ��ϵ��� ����մϴ�.	
	*/
	void Display_SearchList();

	/**
	*	@brief	��� item�� Storage - Container layer ���� �����ְ� �ڼ��� ������ ���� ���� �������� ã���ϴ�.
	*   @pre    none.
	*   @post   none.
	*	@detail	�ڼ��� ���� ���� ID ������ ���� Masterlist���� �ڼ��� ������ ������ ����մϴ�.
	*/
	void FindItemDetail();

	/**
	*	@brief	�˻� ����� Update�մϴ�.
	*   @post   �˻��� item�� �˻�Ƚ�� �����ϰ� �˻���Ͽ� �߰��մϴ�.
	*	@detail �� �˻� Ȱ������ �� �Լ��� ���� �� item �˻�Ƚ���� ������Ű�� �˻���Ͽ� �߰��մϴ�.
	*/
	void UpdateSearchList(ItemType item);

	/**
	*	@brief	�� �˻� ����� ������ ����մϴ�.
	*   @pre    none.
	*   @post   SearchList���� �˻� ����� pop�� ��, ����մϴ�.
	*/
	void ReturnPreviousSearch();


	/*
	*	@brief	MaxHeap�� MinHeap �� �� �ϳ��� �����ϴ� �Լ�.
	*	@pre	none.
	*	@post	none.
	*/
	void WhatHeap();
	
};