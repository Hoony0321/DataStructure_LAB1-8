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
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 제거한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 해당 item을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DeleteItem();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 변경한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 item이 변경된다.
	*/
	int ReplaceItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchById_SequenS();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 이진탐색을 이용해 찾는다.
	*	@pre	없음.
	*	@post	찾은 item이 화면에 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
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
	*	@brief	Add new record into list. (단, Storage ID, Container ID 입력 안 됨.)
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*/
 	void Add_tempItem();

	/**
	*	@brief	TempList에서 아이템 하나를 dequeue 형식으로 뺍니다.
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
	*	@brief	일치하는 photo을 찾아서 해당 photo을 제거한다.
	*	@pre	none.
	*	@post	list 내에 해당 photo이 제거된다.
	*	@param	data	제거하고자 하는 photo 이름이 입력된 string값.
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
	*	@brief	Item id를 이용하여 Master list에서 아이템을 찾은 뒤 detail 정보 출력
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
	*	@brief	Display photo list on screen. 이때 Storage - Container 단계를 거침.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayPhotoList();

	/**
	*	@brief	Display container info on screen. 이때 Storage - Container 단계를 거침.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllContainer2();





	///====== Additional Function ======///
	
	/**
	*	@brief	리스트에서 해당 usage를 가진 item을 찾는다.
	*   @pre    none.
	*   @post   none.
	*	@detail	찾은 item이 화면에 출력된다.
	*/
	void SearchByUsage();



	/**
	*	@brief	리스트에서 범위에 해당하는 Date를 가진 item을 찾는다.
	*   @pre    none.
	*   @post   none.
	*	@detail	찾은 item이 화면에 출력된다.
	*/
	//입력되는 년도를 통해 후보 아이템을 출력한다.
	//숫자 2개가 입력된다. ex) 2018, 2020 
	//단, 입력되는 숫자는 4자리여야한다.
	void SearchByYear();

	/**
	*	@brief	리스트에서 Storage - container 단계를 거쳐 item을 찾는다.
	*   @pre    none.
	*   @post   none.
	*	@detail	찾은 item이 화면에 출력된다.
	*/
	void FindItem();

	/**
	*	@brief	item의 date 정보와 현재 시간 정보를 비교.
	*   @pre    none.
	*   @post   none.
	*	@detail	item의 date 정보와 현재 시간 차이를 출력합니다.
	*/
	int CompareTime(int date);

	//CompareTime() 함수랑 numofsearch 이용
	/**
	*	@brief	버리기 추천하는 물품 리스트 출력
	*   @pre    none.
	*   @post   none.
	*	@detail	item이 현재 시각으로 부터 3년 이상이고 검색횟수 0인 아이템을 출력합니다.
	*/
	void RecommandItem_ThrowAway();

	/**
	*	@brief	item 넣을 container를 추천합니다.
	*   @pre    none.
	*   @post   none.
	*	@detail	현재 가장 적은 item을 가진 container를 찾아 출력합니다.
	*/
	void RecommandContainer();

	/**
	*	@brief	즐겨찾는 item 리스트를 출력합니다.
	*   @pre    none.
	*   @post   none.
	*	@detail	가장 높은 검색횟수를 가진 item과 그 보다 1 적은 검색횟수를 가진 아이템을 출력합니다.
	*/
	void Display_MostSearch();

	/**
	*	@brief	검색 기록을 출력합니다.
	*   @pre    none.
	*   @post   none.
	*	@detail SearchList에 저장된 검색 기록들을 출력합니다.	
	*/
	void Display_SearchList();

	/**
	*	@brief	모든 item을 Storage - Container layer 별로 보여주고 자세한 정보를 보고 싶은 아이템을 찾습니다.
	*   @pre    none.
	*   @post   none.
	*	@detail	자세히 보고 싶은 ID 정보를 통해 Masterlist에서 자세한 정보를 가져와 출력합니다.
	*/
	void FindItemDetail();

	/**
	*	@brief	검색 기록을 Update합니다.
	*   @post   검색한 item의 검색횟수 증가하고 검색기록에 추가합니다.
	*	@detail 매 검색 활동마다 이 함수를 통해 각 item 검색횟수를 증가시키고 검색기록에 추가합니다.
	*/
	void UpdateSearchList(ItemType item);

	/**
	*	@brief	전 검색 기록을 가져와 출력합니다.
	*   @pre    none.
	*   @post   SearchList에서 검색 기록을 pop한 뒤, 출력합니다.
	*/
	void ReturnPreviousSearch();


	/*
	*	@brief	MaxHeap와 MinHeap 둘 중 하나를 선택하는 함수.
	*	@pre	none.
	*	@post	none.
	*/
	void WhatHeap();
	
};