#include "pch.h"
#include "Application.h"


Application::Application()
{
	m_Command = 0;
}


Application::~Application()
{
}

void Application::Run()
{

	while (1)
	{
		GetCommand();

		switch (m_Command)
		{
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		//delete
			DeleteItem();
			break;
		case 3:		//replace
			ReplaceItem();
			break;
		case 4:	//search by binary search.
			SearchByID_BinaryS();
			break;
		case 5:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 6:		// make empty list.
			MasterList.MakeEmpty();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
			WriteDataToFile();
			break;
		case 9:
			Add_tempItem();
			break;
		case 10:
			DequeueFromtItemList();
			break;
		case 11:
			PrinttItemList();
			break;
		case 12:
			SetContainerPosition();
			break;
		case 13:
			AddPhoto();
			break;
		case 14:
			DeletePhoto();
			break;
		case 15:
			DisplayAllStorage();
			break;
		case 16:
			DisplayAllContainer();
			break;
		case 17:
			DisplayAllDetailsContainer();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::GetCommand()
{
	cout << endl << endl;
	cout << "\t--num--- Command ----- " << endl;
	cout << "\t-------MasterList----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Search item by Binary Search" << endl;
	cout << "\t   5 : Print all on screen" << endl;
	cout << "\t   6 : Make empty list" << endl;
	cout << "\t   7 : Get from file" << endl;
	cout << "\t   8 : Put to file " << endl;
	cout << "\t-------TempList------- " << endl;
	cout << "\t   9 : AddtItem" << endl;
	cout << "\t   10 : DequeueFromtItemList" << endl;
	cout << "\t   11 : PrinttItemList" << endl;
	cout << "\t-------Container Setting--------" << endl;
	cout << "\t   12 : Set Container Position" << endl;
	cout << "\t   13 : AddPhoto" << endl;
	cout << "\t   14 : DeletePhoto" << endl;
	cout << "\t-------StorageList------" << endl;
	cout << "\t   15 : DisplayAllStorage" << endl;
	cout << "\t   16 : DisplayAllContainer" << endl; 
	cout << "\t   17 : DisplayAllDetailsContainer" << endl;
	cout << "\t---------------------- " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> m_Command;
	cout << endl;
}

int Application::AddItem()
{

	ItemType item;

	item.SetRecordFromKB();
	MasterList.Add(item);

	//임시 변수 설정

	StorageType tempStorageType;
	tempStorageType.SetId(item.GetStorageId());

	ContainerType tmpContainer;
	tmpContainer.SetId(item.GetContainerID());

	SimpleItemType tmpsItem;
	tmpsItem.SetId(item.GetId());
	tmpsItem.SetName(item.GetName());

	//StorageList에 컨테이너 추가 & 컨테이너에 아이템 추가
	
	//동일한 Storage있는 지 검색
	if (StorageList.GetByBinarySearch(tempStorageType) == 1) { //Storage 존재할때
		//동일한 Container있는 지 확인
		if ((tempStorageType.GetContainer(tmpContainer)) == 1) { // 존재
			tmpContainer.AddsItem(tmpsItem);
			tempStorageType.UpdateContainer(tmpContainer);
			StorageList.Replace(tempStorageType);

		}
		else { //동일한 Container 존재 x
			tmpContainer.AddsItem(tmpsItem);
			tempStorageType.AddContainer(tmpContainer);
			StorageList.Replace(tempStorageType);
		}

	}
	else { //Storage 존재하지 않을때
		tmpContainer.AddsItem(tmpsItem);
		tempStorageType.AddContainer(tmpContainer);
		StorageList.Add(tempStorageType);

	}
	
	
	
	
	return 1;
}


//무슨 함수지
int Application::AddItem(ItemType& item)
{

	MasterList.Add(item);

	//임시 변수 설정

	StorageType tempStorageType;
	tempStorageType.SetId(item.GetStorageId());

	ContainerType tmpContainer;
	tmpContainer.SetId(item.GetContainerID());

	SimpleItemType tmpsItem;
	tmpsItem.SetId(item.GetId());
	tmpsItem.SetName(item.GetName());

	//StorageList에 컨테이너 추가 & 컨테이너에 아이템 추가

	//동일한 Storage있는 지 검색
	if (StorageList.GetByBinarySearch(tempStorageType) == 1) { //Storage 존재할때
		//동일한 Container있는 지 확인
		if ((tempStorageType.GetContainer(tmpContainer)) == 1) { // 존재
			tmpContainer.AddsItem(tmpsItem);
			tempStorageType.UpdateContainer(tmpContainer);
			StorageList.Replace(tempStorageType);

		}
		else { //동일한 Container 존재 x
			tmpContainer.AddsItem(tmpsItem);
			tempStorageType.AddContainer(tmpContainer);
			StorageList.Replace(tempStorageType);
		}

	}
	else { //Storage 존재하지 않을때
		tmpContainer.AddsItem(tmpsItem);
		tempStorageType.AddContainer(tmpContainer);
		StorageList.Add(tempStorageType);

	}



	return 1;
}

void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
	MasterList.ResetList();
	int length = MasterList.GetLength();
	int curIndex = MasterList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		cout << data;
		curIndex = MasterList.GetNextItem(data);
	}
}

int Application::OpenInFile(char * fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}

int Application::OpenOutFile(char * fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}

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

int Application::SearchById_SequenS()
{
	ItemType item;
	item.SetIdFromKB(); //id입력받는다.

	if (MasterList.Get(item)) //0이 아니면(찾으면)
	{
		cout << "<============ Item FOUND !==========>" << endl;
		cout << item;
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 리턴
	}
	cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	//실패(0)을 리턴
}

int Application::DeleteItem()
{
	int pre = MasterList.GetLength();//이전 item개수를 받아온다.
	ItemType item;
	item.SetIdFromKB();
	MasterList.GetByBinarySearch(item); //item detail 정보 백업
	

	//임시 변수 설정
	StorageType tmpStorage;
	tmpStorage.SetId(item.GetStorageId());

	ContainerType tmpContainer;
	tmpContainer.SetId(item.GetContainerID());

	SimpleItemType tmpsItem;
	tmpsItem.SetId(item.GetId());

	//Storage 동기화 & 컨테이너 동기화
	
	if (StorageList.GetByBinarySearch(tmpStorage) == 1) { //존재 할때
		if (tmpStorage.GetContainer(tmpContainer) == 1) { //존재 할때
			if (tmpContainer.GetsItem(tmpsItem) == 1) { //존재 할때
				//컨테이너에서 아이템 삭제
				tmpContainer.DeletesItem(tmpsItem);
				//Storage에서 컨테이너 업데이트
				tmpStorage.UpdateContainer(tmpContainer);
				//StorageList에 Storage 정보 업데이트
				StorageList.Replace(tmpStorage);
				
			}
			else { //없을때
				cout << "해당 ID 를 가진 Item은 없습니다. " << endl;
				cout << "<========DELETE FAIL !=======>" << endl;
				return 0;
			}
		}
		else { //없을때
			cout << "해당 ID 를 가진 Container는 없습니다. " << endl;
			cout << "<========DELETE FAIL !=======>" << endl;
			return 0;
		}
	}
	else { // 없을때
		cout << "해당 ID 를 가진 Storage는 없습니다. " << endl;
		cout << "<========DELETE FAIL !=======>" << endl;
		return 0;
	}

	MasterList.Delete(item);
	
	if (pre > MasterList.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout << "<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

int Application::ReplaceItem()
{
	ItemType item;
	item.SetRecordFromKB(); //키보드로부터 정보를 입력받음

	ItemType origin;
	origin.SetId(item.GetId());
	if (MasterList.Get(origin) != 1) { //해당 item의 id와 일치하는 것을 가져온다. 이전내용과 비교를 위해
		cout << "해당 ID를 가진 아이템은 존재하지 않습니다." << endl;
		return 0;
	}
	MasterList.Replace(item); //해당 item의 id와 일치하는 것을 찾아 바꾼다.

	//Storage & Container 임시 변수 설정
	StorageType tmpStorage;
	ContainerType tmpContainer;
	SimpleItemType tmpsItem;

	//기존 내용 삭제
	tmpStorage.SetId(origin.GetStorageId());
	tmpContainer.SetId(origin.GetContainerID());
	tmpsItem.SetId(origin.GetId());

	StorageList.GetByBinarySearch(tmpStorage);
	tmpStorage.GetContainer(tmpContainer);
	tmpContainer.DeletesItem(tmpsItem);
	tmpStorage.UpdateContainer(tmpContainer);
	StorageList.Replace(tmpStorage);

	//Storage & Container 임시 변수 설정
	StorageType tmpStorage2;
	ContainerType tmpContainer2;
	SimpleItemType tmpsItem2;

	//갱신 된 내용 추가
	tmpStorage2.SetId(item.GetStorageId());
	tmpContainer2.SetId(item.GetContainerID());
	tmpsItem2.SetId(item.GetId());
	tmpsItem2.SetName(item.GetName());

	//동일한 Storage있는 지 검색
	if (StorageList.GetByBinarySearch(tmpStorage2) == 1) { //Storage 존재할때
		//동일한 Container있는 지 확인
		if ((tmpStorage2.GetContainer(tmpContainer2)) == 1) { // 존재
			tmpContainer2.AddsItem(tmpsItem2);
			tmpStorage2.UpdateContainer(tmpContainer2);
			StorageList.Replace(tmpStorage2);

		}
		else { //동일한 Container 존재 x
			tmpContainer2.AddsItem(tmpsItem2);
			tmpStorage2.AddContainer(tmpContainer2);
			StorageList.Replace(tmpStorage2);
		}

	}
	else { //Storage 존재하지 않을때
		tmpContainer2.AddsItem(tmpsItem2);
		tmpStorage2.AddContainer(tmpContainer2);
		StorageList.Add(tmpStorage2);

	}



	return 0;
}

int Application::SearchByID_BinaryS()
{
	ItemType item;

	item.SetIdFromKB();	//id를 입력받는다
	if (MasterList.GetByBinarySearch(item))	//이진탐색에 성공했다면
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		cout << item;
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 반환
}

void Application::Add_tempItem()
{
	ItemType tmpItem;
	tmpItem.SetIdFromKB();
	tmpItem.SetKindFromKB();
	tmpItem.SetDateFromKB();
	tmpItem.SetNameFromKB();
	tmpItem.SetAmountFromKB();
	TempList.AddtItem(tmpItem);
}

void Application::DequeueFromtItemList()
{
	if (TempList.IsEmpty()) {
		cout << "TempList is Empty." << endl;
		return;
	}
	ItemType tmpItem;
	TempList.DequeueFromtItemList(tmpItem);
	tmpItem.SetStorageIdFromKB();
	tmpItem.SetContainerIDFromKB();
	AddItem(tmpItem);
}

void Application::PrinttItemList()
{
	if (TempList.IsEmpty()) {
		cout << "TempList is Empty." << endl;
		return;
	}
	TempList.PrinttItemList();
}

void Application::AddPhoto()
{
	StorageType tmpStorage;
	tmpStorage.SetIdFromKB();

	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();
	
	string photo;
	cout << "\tPhoto : ";
	cin >> photo;

	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "해당하는 Stroage ID가 존재하지 않습니다. " << endl;
		cout << "\t<======FAIL!!!======>" << endl;
	}
	if (tmpStorage.GetContainer(tmpContainer) == 0) {
		cout << "해당하는 Container ID가 존재하지 않습니다. " << endl;
		cout << "\t<======FAIL!!!======>" << endl;
	}
	tmpContainer.AddPhoto(photo);
	tmpStorage.UpdateContainer(tmpContainer);
	StorageList.Replace(tmpStorage);

	cout << "\t<======SUCCESS!!!======>" << endl;

}

void Application::DeletePhoto()
{
	StorageType tmpStorage;
	tmpStorage.SetIdFromKB();

	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();

	string photo;
	cout << "\tPhoto : ";
	cin >> photo;

	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "해당하는 Stroage ID가 존재하지 않습니다. " << endl;
		cout << "\t<======FAIL!!!======>" << endl;
	}
	if (tmpStorage.GetContainer(tmpContainer) == 0) {
		cout << "해당하는 Container ID가 존재하지 않습니다. " << endl;
		cout << "\t<======FAIL!!!======>" << endl;
	}
	tmpContainer.DeletePhoto(photo);
	tmpStorage.UpdateContainer(tmpContainer);
	StorageList.Replace(tmpStorage);

	cout << "\t<======SUCCESS!!!======>" << endl;
}

void Application::DisplayAllPhoto()
{
	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();

	ContainerList.Get(tmpContainer);

	tmpContainer.DisplayAllPhoto();
}

void Application::DisplayAllsItem()
{
	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();

	ContainerList.Get(tmpContainer);

	tmpContainer.DisplayAllsItem();
}

void Application::DisplayAllDetailsItem()
{
	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();

	ContainerList.Get(tmpContainer);

	tmpContainer.DisplayAllDetailsItem(MasterList);
}

void Application::DisplayAllStorage() {
	StorageType tmpStorage;
	
	StorageList.ResetList();
	while (StorageList.GetNextItem(tmpStorage) != -1) {
		cout << "\t******** Storage ********" << endl;
		cout << "\tStorage ID : " << tmpStorage.GetId() << endl;
		cout << "\t===== Container =====" << endl;
		tmpStorage.DisplayAllContainer();
	}
}

void Application::DisplayAllContainer() {
	StorageType tmpStorage;
	tmpStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "해당 Storage ID 는 존재하지 않습니다." << endl;
		return;
	}
	cout << "\t******** Storage ********" << endl;
	cout << "\tStorage ID : " << tmpStorage.GetId() << endl;
	cout << "\t===== Container =====" << endl;
	tmpStorage.DisplayAllContainer();
}

void Application::DisplayAllDetailsContainer() {
	StorageType tmpStorage;
	tmpStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "해당 Storage ID 는 존재하지 않습니다." << endl;
		return;
	}
	cout << endl;
	cout << "\t******** Storage ********" << endl;
	tmpStorage.DisplayAllDetailsContainer();
}

void Application::SetContainerPosition() {
	StorageType tmpStorage;
	ContainerType tmpContainer;
	tmpStorage.SetIdFromKB();
	tmpContainer.SetIdFromKB();

	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "해당 Storage ID는 존재하지 않습니다." << endl;
		return;
	}
	if (tmpStorage.GetContainer(tmpContainer) == 0) {
		cout << "해당 Container ID는 존재하지 않습니다." << endl;
		return;
	}

	tmpContainer.SetPositionFromKB();
	tmpStorage.UpdateContainer(tmpContainer);
	StorageList.Replace(tmpStorage);
}

