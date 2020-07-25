#include "pch.h"
#include "Application.h"
#include "time.h"


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
			//---MasterList--
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		//delete
			DeleteItem();
			break;
		case 3:		//replace
			ReplaceItem();
			break;
		case 4:		// display all the records in list on screen.
			Display_InOrder();
			break;
		case 5:		// display all the records in list on screen.
			Display_PreOrder();
			break;
		case 6:		// display all the records in list on screen.
			Display_PostOrder();
			break;
		case 7:		// make empty list.
			MasterList.MakeEmpty();
			break;
			//---File System---
		case 8:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 9:		// save list data into a file.
			WriteDataToFile();
			break;
			//---TempList----
		case 10:
			Add_tempItem();
			break;
		case 11:
			DequeueFromtItemList();
			break;
		case 12:
			PrinttItemList();
			break;
			//---Container Setting---
		case 13:
			SetContainerPosition();
			break;
		case 14:
			AddPhoto();
			break;
		case 15:
			DeletePhoto();
			break;
			//---StorageList---
		case 16:
			DisplayAllStorage();
			break;
		case 17:
			DisplayAllContainer();
			break;
		case 18:
			DisplayAllDetailsContainer();
			break;
		case 19:
			DisplayAllContainer2();
			break;
		case 20:
			DisplayPhotoList();
			break;
			//---Search Function---
		case 21:
			SearchByID_BinaryS();
			break;
		case 22:
			SearchByUsage();
			break;
		case 23:
			SearchByYear();
			break;
		case 24:
			FindItem();
			break;
		case 25:
			FindItemDetail();
			break;
			//---Additional Function---
		case 26:
			RecommandItem_ThrowAway();
			break;
		case 27:
			RecommandContainer();
			break;
		case 28:
			Display_MostSearch();
			break;
		case 29:
			Display_SearchList();
			break;
		case 30:
			ReturnPreviousSearch();
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
	cout << "\t   3 : Modify item Info" << endl;
	cout << "\t   4 : Print all on screen by InOrder" << endl;
	cout << "\t   5 : Print all on screen by PreOrder" << endl;
	cout << "\t   6 : Print all on screen by PostOrder" << endl;
	cout << "\t   7 : Make empty list" << endl;
	cout << "\t-------File System----- " << endl;
	cout << "\t   8 : Get from file" << endl;
	cout << "\t   9 : Put to file " << endl;
	cout << "\t-------TempList------- " << endl;
	cout << "\t   10 : AddtItem" << endl;
	cout << "\t   11: DequeueFromtItemList" << endl;
	cout << "\t   12 : PrinttItemList" << endl;
	cout << "\t-------Container Setting--------" << endl;
	cout << "\t   13 : Set Container Position" << endl;
	cout << "\t   14 : AddPhoto" << endl;
	cout << "\t   15 : DeletePhoto" << endl;
	cout << "\t-------StorageList------" << endl;
	cout << "\t   16 : DisplayAllStorage" << endl;
	cout << "\t   17 : DisplayAllContainer" << endl; 
	cout << "\t   18 : DisplayAllDetailsContainer" << endl;
	cout << "\t   19 : Display All Container version 2" << endl;
	cout << "\t   20 : Display Photo list" << endl;
	cout << "\t-------Search Function------" << endl;
	cout << "\t   21 : Search item By ID" << endl;
	cout << "\t   22 : Search Item By Usage" << endl;
	cout << "\t   23 : Search Item By Purchase Year" << endl;
	cout << "\t   24 : Find Item Simple" << endl;
	cout << "\t   25 : Find Item Detail" << endl;
	cout << "\t-------Additional Function------" << endl;
	cout << "\t   26 : Recommand item to throw away" << endl;
	cout << "\t   27 : Recommand container to store" << endl;
	cout << "\t   28 : 즐겨찾는 물품 리스트 출력" << endl;
	cout << "\t   29 : 검색 기록 출력" << endl;
	cout << "\t   30 : 전 검색 기록으로 돌아가기" << endl;
	cout << "\t---------------------- " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> m_Command;
	cout << endl;
}

int Application::AddItem()
{
	bool found = false;
	ItemType item;

	item.SetRecordFromKB();
	MasterList.RetrieveItem(item, found);
	if (found == true) {
		cout << endl;
		cout << "<=======동일한 ID의 아이템이 존재합니다.=======>" << endl;
		return 0;
	}
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


int Application::AddItem(ItemType& item)
{
	//에러 처리
	bool found = false;
	MasterList.RetrieveItem(item, found);
	if (found == true) {
		//동일한 ID를 가진 아이템 있음. 
		return 0;
	}
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

void Application::Display_InOrder() {
	MasterList.PrintInOrder(cout);
}

void Application::Display_PreOrder() {
	MasterList.PrintPreOrder(cout);
}

void Application::Display_PostOrder() {
	MasterList.PrintPostOrder(cout);
}

void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	
	MasterList.PrintTree(cout);
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
		AddItem(data);
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

	

	// list의 모든 데이터를 파일에 쓰기


	MasterList.ResetQueue();
	while (MasterList.GetNextItem(data) != 0) {
		data.WriteDataToFile(m_OutFile);
	}



	m_OutFile.close();	// file close

	return 1;
}

int Application::SearchById_SequenS()
{
	ItemType item;
	item.SetIdFromKB(); //id입력받는다.
	bool found = false;
	MasterList.RetrieveItem(item,found);
	if (found = true) //0이 아니면(찾으면)
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

	bool found = false;
	MasterList.RetrieveItem(item,found); //item detail 정보 백업
	if (found == false) {
		cout << "\t 해당 ID를 가진 아이템은 존재하지 않습니다." << endl;
		return 0;
	}
	

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

	MasterList.DeleteItem(item);
	
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
	bool found = false;
	ItemType item;
	item.SetRecordFromKB(); //키보드로부터 정보를 입력받음

	ItemType origin;
	origin.SetId(item.GetId());
	MasterList.RetrieveItem(origin, found);
	if (found = false) { //해당 item의 id와 일치하는 것을 가져온다. 이전내용과 비교를 위해
		cout << "해당 ID를 가진 아이템은 존재하지 않습니다." << endl;
		return 0;
	}
	MasterList.ReplaceItem(item); //해당 item의 id와 일치하는 것을 찾아 바꾼다.

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

	bool found = false;
	MasterList.RetrieveItem(item, found);
	if (found == true)	//이진탐색에 성공했다면
	{
		//검색 횟수 추가 및 검색 리스트에 추가
		UpdateSearchList(item);

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

	bool found = false;
	MasterList.RetrieveItem(tmpItem, found);
	if (found == true) {
		cout << endl;
		cout << "<=======동일한 ID의 아이템이 존재합니다.=======>" << endl;
		return;
	}
	tmpItem.SetKindFromKB();
	tmpItem.SetDateFromKB();
	tmpItem.SetNameFromKB();
	tmpItem.SetAmountFromKB();
	tmpItem.SetPhotoFromKB();
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

//Container Position 설정
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

//용도를 통해 아이템 출력
void Application::SearchByUsage() {
	bool check = false;
	ItemType data;
	ItemType item;

	item.SetKindFromKB();

	StorageType tmpStorage;
	ContainerType tmpContainer;

	// list의 모든 데이터를 화면에 출력
	MasterList.ResetQueue();
	cout << "<============I 후보 List !==========>" << endl;
	while (MasterList.GetNextItem(data) != 0) {
		if (data.GetKind() == item.GetKind()) {
			if (!check) check = true;
			cout << "======ITEM======" << endl;
			cout << data.GetId() << endl;
			cout << data.GetName() << endl;
			cout << endl;
		}
	}
	if (!check) {
		cout << "\t후보 아이템이 존재하지 않습니다." << endl;
		return;
	}
	ItemType tmpItem;
	int _id;
	cout << "자세한 정보를 보고 싶은 물건 ID : ";
	cin >> _id;
	tmpItem.SetId(_id);
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);
	cout << tmpItem << endl;

	//검색기록 & 검색 횟수 업데이트
	UpdateSearchList(tmpItem);

}

//두 개의 연도 사이의 아이템 출력
void Application::SearchByYear() {
	int FromYear;
	int ToYear;
	//From은 포함 To는 포함X
	cout << "\tINPUT From Year(include) and  To Year(exclude)" << endl;
	cout << "\t From : ";
	cin >> FromYear;
	cout << "\t To : ";
	cin >> ToYear;

	bool check = false;
	ItemType data;



	MasterList.ResetQueue();
	cout << "<============I 후보 List !==========>" << endl;
	while (MasterList.GetNextItem(data) != 0) {
		int tmpData = data.GetDate();
		string tmpData2 = to_string(tmpData);
		//물건의 Date가 20181020 이런 식일 경우 앞에 4개만 추출하여 사용
		if (tmpData2.size() >= 4) {
			tmpData = int(tmpData2[0] - '0') * 1000 + int(tmpData2[1] - '0') * 100 + int(tmpData2[2] - '0') * 10 + int(tmpData2[3] - '0');
		}
		if (FromYear <= tmpData && tmpData < ToYear) {
			if (!check) check = true;
			cout << "======ITEM======" << endl;
			cout << data.GetId() << endl;
			cout << data.GetName() << endl;
			cout << endl;
		}
	}
	if (!check) {
		cout << "\t후보 아이템이 존재하지 않습니다." << endl;
		return;
	}
	ItemType tmpItem;
	int _id;
	cout << "자세한 정보를 보고 싶은 물건 ID : ";
	cin >> _id;
	tmpItem.SetId(_id);
	bool found = false;
	MasterList.RetrieveItem(tmpItem, found);
	cout << tmpItem << endl;

	//검색기록 & 검색 횟수 업데이트
	UpdateSearchList(tmpItem);

}

//item 찾기
void Application::FindItem() {
	StorageType tmpStorage;
	ContainerType tmpContainer;
	ItemType tmpItem;
	//Storage ID 선택
	cout << "<============I Select Storage ID I==========>" << endl;
	tmpStorage.SetIdFromKB();

	cout << "<============I Display Container ID I==========>" << endl;
	StorageList.GetByBinarySearch(tmpStorage);
	tmpStorage.DisplayAllContainerID();
	
	//Container ID 선택
	cout << "<============I Select Container ID I==========>" << endl;
	tmpContainer.SetIdFromKB();
	
	cout << "<============I Display Item Name I==========>" << endl;
	tmpStorage.GetContainer(tmpContainer);
	tmpContainer.DisplayAllsItemName();

	//Item 선택
	cout << "<============I Select Item I==========>" << endl;
	tmpItem.SetIdFromKB();
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);

	cout << tmpItem << endl;

	//검색기록 & 검색 횟수 업데이트
	UpdateSearchList(tmpItem);


}

//Storage - container를 선택해서 해당 container의 Photolist 출력
void Application::DisplayPhotoList() {
	StorageType tmpStorage;
	ContainerType tmpContainer;
	//Storage ID 선택
	cout << "<============I Select Storage ID I==========>" << endl;
	tmpStorage.SetIdFromKB();

	cout << "<============I Display Container ID I==========>" << endl;
	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "해당 ID를 가진 Storage가 존재하지 않습니다." << endl;
		return;
	}
	tmpStorage.DisplayAllContainerID();

	//Container ID 선택
	cout << "<============I Select Container ID I==========>" << endl;
	tmpContainer.SetIdFromKB();

	cout << "<============I Display Photo List I==========>" << endl;
	tmpStorage.GetContainer(tmpContainer);
	tmpContainer.DisplayAllPhoto();


}

//Storage Id를 통해 storage 안에 들어있는 container 정보들을 확인
void Application::DisplayAllContainer2() {
	StorageType tmpStorage;
	tmpStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "해당 Storage ID 는 존재하지 않습니다." << endl;
		return;
	}
	cout << "\t******** Storage ********" << endl;
	cout << "\tStorage ID : " << tmpStorage.GetId() << endl;
	cout << "\t===== Container =====" << endl;
	tmpStorage.DisplayAllContainer2();
}

//item date와 현재 시간 차이 출력
int Application::CompareTime(int date) {
	time_t timer;
	struct tm t;
	string date_string = to_string(date);
	if (date_string.size() != 8) {
		return 0;
	}
	timer = time(NULL); // 현재 시각을 초 단위로 얻기
	localtime_s(&t, &timer); // 초 단위의 시간을 분리하여 구조체에 넣기

	int diff_year, diff_month, diff_day;

	diff_year = (t.tm_year +1900) - stoi(date_string.substr(0,4));  //Year 차이 계산
	diff_month = (t.tm_mon + 1) - stoi(date_string.substr(4,2));    //Month 차이 계산
	diff_day = t.tm_mday - stoi(date_string.substr(6, 2));          //Day 차이 계산

	//날짜 차이 출력
	return diff_year * 365 + diff_month * 30 + diff_day;  //Day로 환산해서 리턴
}

//버리길 추천하는 아이템
void Application::RecommandItem_ThrowAway() {

	ItemType data;
	bool found = false;

	MasterList.ResetQueue();
	cout << "<============I Recommand item to throw away I==========>" << endl;
	while (MasterList.GetNextItem(data) != 0) {
		//3년 이상 검색횟수 0인 아이템 탐색
		if (data.GetNumOfSearch() == 0 && CompareTime(data.GetDate()) > 365 * 3) {
			if (!found) found = true;
			cout << data << endl;
		}
	}
	if (!found) {      //하나도 못 찾을 때
		cout << endl;
		cout << "<============I NOT FOUND!!!! I==========>" << endl;
	}

}


//가장 적은 item을 가진 container 탐색
void Application::RecommandContainer() {

	int Info[3];
	int Min = 100;
	int num;
	StorageType tmpStorage;
	ContainerType tmpContainer;

	StorageList.ResetList();
	while (StorageList.GetNextItem(tmpStorage) != -1) {
		tmpStorage.ResetList();
		while (tmpStorage.GetNextContainer(tmpContainer) != 0) {
			num = tmpContainer.GetNumOfItems();
			if (num < Min) {   //가장 적은 item을 가진 container 탐색
				Min = num;
				Info[0] = tmpStorage.GetId();      //Info[0]에 storage id 저장
				Info[1] = tmpContainer.GetId();    //Info[1]에 container id 저장
				Info[2] = num;                     //Info[2]에 아이템 개수 저장
			}
		}
	}
	cout << "<============I Recommand container to store I==========>" << endl;
	cout << "\tSTORAGE ID : " << Info[0] << endl;
	cout << "\tCONTAINER ID : " << Info[1] << endl;
	cout << "\t이 Container가 물건 " << Info[2] << "개로 가장 널널합니다." << endl;
}

//즐겨찾는 아이템 목록들 출력
void Application::Display_MostSearch() {

	ItemType data;
	int MaxSearchTime = 0;

	//가장 큰 검색횟수 찾기

	MasterList.ResetQueue();
	while (MasterList.GetNextItem(data)) {
		if (MaxSearchTime < data.GetNumOfSearch()) {
			MaxSearchTime = data.GetNumOfSearch();   //MaxSearchTime 갱신
		}
	}

	MasterList.ResetQueue();
	cout << "<============I Most Search ItemList I==========>" << endl;
	while (MasterList.GetNextItem(data) != 0) {
		//가장 많은 검색횟수 - 1 이상 -> 즐겨찾는 물품
		if (data.GetNumOfSearch() >= MaxSearchTime -1) {   
			cout << data << endl;
		}
	}

	

}

//SearchList 출력
void Application::Display_SearchList() {
	cout << "<============I Search List I==========>" << endl;
	SearchList.Print();
	if (SearchList.IsEmpty()) {
		cout << "\t SearchList is empty. " << endl;
		return;
	}
	ItemType tmpItem;
	int _id;
	cout << "\t 자세한 정보를 보고싶은 물건 ID : ";
	cin >> _id;
	cout << endl;
	tmpItem.SetId(_id);
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);
	cout << tmpItem << endl;

	//검색횟수 추가 및 검색 리스트에 추가
	UpdateSearchList(tmpItem);

}

//아이템의 자세한 정보 출력
void Application::FindItemDetail() {
	DisplayAllStorage();
	ItemType tmpItem;
	int _id;
	cout << "\t 자세한 정보를 보고싶은 물건 ID : ";
	cin >> _id;
	cout << endl;
	tmpItem.SetId(_id);
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);
	cout << tmpItem << endl;

	//검색횟수 추가 및 검색 리스트에 추가
	UpdateSearchList(tmpItem);

}

//item의 검색횟수 증가 & Search List에 추가
void Application::UpdateSearchList(ItemType item) {
	//검색 횟수 증가
	item.SetNumOfSearch(item.GetNumOfSearch() + 1);
	MasterList.ReplaceItem(item);

	//검색 기록에 추가
	SimpleItemType tmpSimpleItem;
	tmpSimpleItem.SetId(item.GetId());
	tmpSimpleItem.SetName(item.GetName());
	SearchList.Push(tmpSimpleItem);
}

//이전 검색 기록으로 돌아가기
void Application::ReturnPreviousSearch() {
	SimpleItemType item;
	//Pop return 값이 -1 => stack이 비어있음.
	if (SearchList.Pop(item) == -1) {
		cout << "\t 이전 검색 기록이 없습니다." << endl;
		return;
	}

	ItemType tmpItem;
	tmpItem.SetId(item.GetId());
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);
	cout << "<============I Previous Search I==========>" << endl;
	cout << tmpItem << endl;
}

