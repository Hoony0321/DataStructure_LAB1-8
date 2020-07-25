#include "pch.h"
#include "Application.h"

//constructor
Application::Application() {
	m_Command = 0;
}

//destructor
Application::~Application(){}


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		//모든 정보를 받아 masterList& container에 추가
			AddItem_AllInfo();
			break;
		case 2:
			AddItem_NoContainerID();
			break;
		case 3:
			TempListToConatinerList();
			break;
		case 4:		//delete
			DeleteItem();
			break;
		case 5:		//replace
			ReplaceItem();
			break;
		case 6:	//search by binary search.
			SearchByID_BinaryS();
			break;
		case 7:		//search by name.
			SearchByName();
			break;
		case 8:		// display all the records in list on screen.
			SearchContainerByID();
			break;
		case 9:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 10:		// make empty list.
			MasterList.MakeEmpty();
			ContainerList.MakeEmpty();
			break;
		case 11:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 12:		// save list data into a file.
			WriteDataToFile();
			break;
		case 13:		// search by kind
			SearchByKind();
			break;
		case 14:		// search by kind
			AddContainer();
			break;
		case 15:
			AddPhoto();
			break;
		case 16:
			SetContainerLocation();
			break;
		case 17:
			SearchByNameInContainer();
			break;
		case 18:
			SearchByUsageInContainer();
			break;
		case 19:
			DisplayAllContainer();
			break;
		case 0:
			cout << "Exit program..." << endl;
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item_AllInfo" << endl;
	cout << "\t   2 : Add item_NoContainerID" << endl;
	cout << "\t   3 : Temp_To_Container" << endl;
	cout << "\t   4 : Delete item" << endl;
	cout << "\t   5 : Replace item" << endl;
	cout << "\t   6 : Search item by Binary Search" << endl;
	cout << "\t   7 : Search item by name" << endl;
	cout << "\t   8 : Search container by ID" << endl;
	cout << "\t   9 : Print all item on screen" << endl;
	cout << "\t   10 : Make empty list" << endl;
	cout << "\t   11 : Get from file" << endl;
	cout << "\t   12 : Put to file " << endl;
	cout << "\t   13 : Search item by kind " << endl;
	cout << "\t   14 : Add contaienr " << endl;
	cout << "\t   15 : Add Photo Image " << endl;
	cout << "\t   16 : Set container location " << endl;
	cout << "\t   17 : Search item by Name In container" << endl;
	cout << "\t   18 : Search item by Usage In container" << endl;
	cout << "\t   19 : Print all container on screen" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


//모든 정보를 입력받아 masterList & containerList에 추가함
int Application::AddItem_AllInfo()
{
	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if (MasterList.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;
	item.SetRecordFromKB();

	//MasterList에 추가
	MasterList.Add(item);
	
	//임시 컨테이너 생성
	ContainerType container;
	SimpleItemType tdata;
	tdata = item;
	container.AddItem(tdata);
	//return 0 -> 동일한 컨테이너 존재. -> 기존 컨테이너에 아이템만 입력하면 됨.
	if (ContainerList.Add(container) == 0) {

		ContainerList.GetByBinarySearch(container);
		container.AddItem(tdata);
		ContainerList.Replace(container);
	}
	


	return 1;
}


//ContainerID가 없는 정보를 입력받아 templist에 저장
int Application::AddItem_NoContainerID()
{
	ItemType item;

	item.SetRecordFromKB_NoContainerID();
	//tempList에 저장
	if (TempList.Enqueue(item)) {
		return 1;
	}
	cout << "TempList is Full." << endl;
	return 0;
	
}

//추가
int Application::TempListToConatinerList() {
	ItemType item;
	if (TempList.Dequeue(item) == 0) {
		cout << "\tTempList is empty." << endl;
		return 0;
	}
	cout << "\tNULL container id is -1." << endl;
	item.DisplayRecord();
	item.SetContainerIdFromKB();

	//MasterList에 추가
	MasterList.Add(item);

	//임시 컨테이너 생성
	ContainerType container;
	SimpleItemType tdata;
	tdata = item;
	container.AddItem(tdata);

	//return 0 -> 동일한 컨테이너 존재
	//기존 컨테이너에 아이템만 입력하면 됨.
	if (ContainerList.Add(container) == 0) {
		//id를 통해 찾고 컨테이너 업데이트
		ContainerList.GetByBinarySearch(container);
		//그 후 업데이트
		container.AddItem(tdata);
		ContainerList.Replace(container);
	}
	
	return 1;
}

//container_id로 container 찾아 출력
int Application::SearchContainerByID() {
	ContainerType container;
	container.SetIdFromKB();

	if (ContainerList.GetByBinarySearch(container))	//이진탐색에 성공했다면
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		container.DisplayAllInfo();
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 반환

}

//Add Container
int Application::AddContainer() {
	ContainerType tContainer;
	tContainer.SetIdFromKB();
	tContainer.SetLocFromKB();

	if (ContainerList.Add(tContainer) == 0) {
		cout << "\t동일한 컨테이너가 이미 존재합니다." << endl;
		return 0;
	}
	cout << "\t Success!!!" << endl;
	return 1;
}

//Add ContainerLocation
int Application::SetContainerLocation() {
	ContainerType tContainer;
	tContainer.SetIdFromKB();

	if (ContainerList.GetByBinarySearch(tContainer)) {
		tContainer.SetLocFromKB();
		ContainerList.Replace(tContainer);
		cout << "\tSuceess!!!!" << endl;
		return 1;
	}
	else {
		cout << "\t the container not exist." << endl;
		return 0;
	}
}

//Add Photo
int Application::AddPhoto() {
	ContainerType tContainer;
	tContainer.SetIdFromKB();

	if (ContainerList.GetByBinarySearch(tContainer)) {
		string PhotoImage;
		cout << "\t INPUT PhotoImage : ";
		cin >> PhotoImage;
		tContainer.AddPhoto(PhotoImage);
		ContainerList.Replace(tContainer);
		cout << "\tSuccess" << endl;
		return 1;
	}
	else {
		cout << "\t the container not exist." << endl;
		return 0;
	}
	
}



//이름을 입력받은 item으로 리스트에서 item을 찾아서 출력한다.
int Application::SearchByName()
{
	ItemType item;
	item.SetNameFromKB(); //name을 입력받는다.

	if (SearchAllItmeByName(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}

//이름으로 item을 찾아서 출력한다.
int Application::SearchAllItmeByName(ItemType& inData)
{
	ItemType tmp;
	int result = 0;

	MasterList.ResetList();//iterator 초기화
	while (MasterList.GetNextItem(tmp) != -1) //리스트의 마지막까지 반복
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecord();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

//이름으로 해당 컨테이너 내에서 아이템을 찾는다.
int Application::SearchByNameInContainer() {
	SimpleItemType tdata;
	ContainerType container;
	
	tdata.SetContainerIdFromKB();
	tdata.SetNameFromKB();
	container.SetId(tdata.GetContainerId());
	if (ContainerList.GetByBinarySearch(container) == 0) {
		cout << "\t 해당 id의 컨테이너가 존재하지 않습니다." << endl;
		return 0;
	}
	return container.FindByName(tdata);


}

int Application::SearchByUsageInContainer() {
	SimpleItemType tdata;
	ContainerType container;
	
	tdata.SetContainerIdFromKB();
	tdata.SetTypeFromKB();
	container.SetId(tdata.GetContainerId());
	if (ContainerList.GetByBinarySearch(container) == 0) {
		cout << "\t 해당 id의 컨테이너가 존재하지 않습니다." << endl;
		return 0;
	}
	return container.FindByUsage(tdata);
}

//id로 item을 찾아서 제거한다.
int Application::DeleteItem()
{
	int pre = MasterList.GetLength();//이전 item개수를 받아온다.
	ItemType item;
	SimpleItemType titem;
	ContainerType container;
	item.SetIdFromKB();
	MasterList.GetByBinarySearch(item);

	titem = item;
	MasterList.Delete(item);
	
	
	container.SetId(titem.GetContainerId());
	
	ContainerList.GetByBinarySearch(container);
	container.DeleteItem(titem);
	ContainerList.Replace(container);
	if (pre > MasterList.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout << "<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

//해당 id의 item을 변경한다.
int Application::ReplaceItem()
{
	ItemType item;
	ItemType tItem;
	item.SetRecordFromKB(); //키보드로부터 정보를 입력받음
	tItem.SetId(item.GetId());
	MasterList.GetByBinarySearch(tItem);


	//해당 item의 id와 일치하는 것을 찾아 바꾼다.
	if (MasterList.Replace(item)) {
		SimpleItemType SimpleItem;
		ContainerType container;

		//기존 컨테이너에서 삭제
		SimpleItem = tItem;
		container.SetId(tItem.GetContainerId());
		ContainerList.GetByBinarySearch(container);
		container.DeleteItem(SimpleItem);
		ContainerList.Replace(container);

		//변경된 컨테이너에 추가
		SimpleItem = item;
		container.SetId(item.GetContainerId());
		ContainerList.GetByBinarySearch(container);
		container.AddItem(SimpleItem);
		if (ContainerList.Add(container) == 0) {
			ContainerList.GetByBinarySearch(container);
			container.AddItem(SimpleItem);
			ContainerList.Replace(container);
		}

		//container id가 변경 안돼도 괜찮음. 그냥 기존 컨테이너에서 삭제되었다가 변경된 정보로 아이템 다시 생성되는 것.
		cout << "<========REPLACE SUCCESS !=======>" << endl;
		return 1;
	}
	else {
		cout << "<========REPLACE FAIL !=======>" << endl;
	}

	
	return 0;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;
	cout << "\t===============" << endl;

	// list의 모든 데이터를 화면에 출력
	MasterList.ResetList();
	int length = MasterList.GetLength();
	int curIndex = MasterList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecord();
		curIndex = MasterList.GetNextItem(data);
	}
}

//추가
void Application::DisplayAllContainer() {
	ContainerType data;
	cout << "\n\tCurrent list" << endl;
	// list의 모든 데이터를 화면에 출력
	ContainerList.ResetList();
	int length = ContainerList.GetLength();
	int curIndex = ContainerList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayAllInfo();
		curIndex = ContainerList.GetNextItem(data);
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// 읽기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		MasterList.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	//DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	MasterList.ResetList();

	// list의 모든 데이터를 파일에 쓰기
	int length = MasterList.GetLength();
	int curIndex = MasterList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = MasterList.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

//찾고자 하는 ID를 이진탐색 방법을 통해 찾는다.
int Application::SearchByID_BinaryS()
{
	ItemType item;

	item.SetIdFromKB();	//id를 입력받는다
	if (MasterList.GetByBinarySearch(item))	//이진탐색에 성공했다면
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecord();
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 반환

}

//입력된 kind와 동일한 kind를 가진 아이템을 찾는다.
int Application::SearchByKind() {
	int result[LISTMAXSIZE];  // 찾은 아이템 index를 저장할 배열
	int arraySize;   //저장된 아이템의 개수 -> 검색할 result 배열의 크기
	ItemType item;
	cout << endl;
	item.SetTypeFromKB();
	if (MasterList.SearchByKind(result, item.GetType(),arraySize)) {
		cout << "<============I FOUND ITEM !==========>" << endl;

		for (int i = 0; i < arraySize; i++) {
			//저장된 아이템 개수만큼만 찾음 (i < arraySize)
			MasterList.ResetList();
			for (int j = 0; j < result[i] + 1; j++) {
				MasterList.GetNextItem(item);      //저장된 index로 m_CuPointer 이동
			}
			item.DisplayRecord();   //item 저장된 data display
		}

		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할 시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 반환
}
