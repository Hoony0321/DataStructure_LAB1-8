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
			DisplayAllItem();
			break;
		case 5:		// make empty list.
			MasterList.MakeEmpty();
			break;
			//---File System---
		case 6:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 7:		// save list data into a file.
			WriteDataToFile();
			break;
			//---TempList----
		case 8:
			Add_tempItem();
			break;
		case 9:
			DequeueFromtItemList();
			break;
		case 10:
			PrinttItemList();
			break;
			//---Container Setting---
		case 11:
			SetContainerPosition();
			break;
		case 12:
			AddPhoto();
			break;
		case 13:
			DeletePhoto();
			break;
			//---StorageList---
		case 14:
			DisplayAllStorage();
			break;
		case 15:
			DisplayAllContainer();
			break;
		case 16:
			DisplayAllDetailsContainer();
			break;
		case 17:
			DisplayAllContainer2();
			break;
		case 18:
			DisplayPhotoList();
			break;
			//---Search Function---
		case 19:
			SearchByID_BinaryS();
			break;
		case 20:
			SearchByUsage();
			break;
		case 21:
			SearchByYear();
			break;
		case 22:
			FindItem();
			break;
		case 23:
			FindItemDetail();
			break;
			//---Additional Function---
		case 24:
			RecommandItem_ThrowAway();
			break;
		case 25:
			RecommandContainer();
			break;
		case 26:
			Display_MostSearch();
			break;
		case 27:
			Display_SearchList();
			break;
		case 28:
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
	cout << "\t   4 : Print all on screen" << endl;
	cout << "\t   5 : Make empty list" << endl;
	cout << "\t-------File System----- " << endl;
	cout << "\t   6 : Get from file" << endl;
	cout << "\t   7 : Put to file " << endl;
	cout << "\t-------TempList------- " << endl;
	cout << "\t   8 : AddtItem" << endl;
	cout << "\t   9 : DequeueFromtItemList" << endl;
	cout << "\t   10 : PrinttItemList" << endl;
	cout << "\t-------Container Setting--------" << endl;
	cout << "\t   11 : Set Container Position" << endl;
	cout << "\t   12 : AddPhoto" << endl;
	cout << "\t   13 : DeletePhoto" << endl;
	cout << "\t-------StorageList------" << endl;
	cout << "\t   14 : DisplayAllStorage" << endl;
	cout << "\t   15 : DisplayAllContainer" << endl; 
	cout << "\t   16 : DisplayAllDetailsContainer" << endl;
	cout << "\t   17 : Display All Container version 2" << endl;
	cout << "\t   18 : Display Photo list" << endl;
	cout << "\t-------Search Function------" << endl;
	cout << "\t   19 : Search item By ID" << endl;
	cout << "\t   20 : Search Item By Usage" << endl;
	cout << "\t   21 : Search Item By Purchase Year" << endl;
	cout << "\t   22 : Find Item Simple" << endl;
	cout << "\t   23 : Find Item Detail" << endl;
	cout << "\t-------Additional Function------" << endl;
	cout << "\t   24 : Recommand item to throw away" << endl;
	cout << "\t   25 : Recommand container to store" << endl;
	cout << "\t   26 : ���ã�� ��ǰ ����Ʈ ���" << endl;
	cout << "\t   27 : �˻� ��� ���" << endl;
	cout << "\t   28 : �� �˻� ������� ���ư���" << endl;
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
	if (MasterList.Get(item) == 1) {
		cout << endl;
		cout << "<=======������ ID�� �������� �����մϴ�.=======>" << endl;
		return 0;
	}
	MasterList.Add(item);

	//�ӽ� ���� ����

	StorageType tempStorageType;
	tempStorageType.SetId(item.GetStorageId());

	ContainerType tmpContainer;
	tmpContainer.SetId(item.GetContainerID());

	SimpleItemType tmpsItem;
	tmpsItem.SetId(item.GetId());
	tmpsItem.SetName(item.GetName());

	//StorageList�� �����̳� �߰� & �����̳ʿ� ������ �߰�
	
	//������ Storage�ִ� �� �˻�
	if (StorageList.GetByBinarySearch(tempStorageType) == 1) { //Storage �����Ҷ�
		//������ Container�ִ� �� Ȯ��
		if ((tempStorageType.GetContainer(tmpContainer)) == 1) { // ����
			tmpContainer.AddsItem(tmpsItem);
			tempStorageType.UpdateContainer(tmpContainer);
			StorageList.Replace(tempStorageType);

		}
		else { //������ Container ���� x
			tmpContainer.AddsItem(tmpsItem);
			tempStorageType.AddContainer(tmpContainer);
			StorageList.Replace(tempStorageType);
		}

	}
	else { //Storage �������� ������
		tmpContainer.AddsItem(tmpsItem);
		tempStorageType.AddContainer(tmpContainer);
		StorageList.Add(tempStorageType);

	}
	
	
	
	
	return 1;
}


int Application::AddItem(ItemType& item)
{
	//���� ó��
	if (MasterList.Get(item) == 1) {
		//������ ID�� ���� ������ ����. 
		return 0;
	}
	MasterList.Add(item);

	//�ӽ� ���� ����

	StorageType tempStorageType;
	tempStorageType.SetId(item.GetStorageId());

	ContainerType tmpContainer;
	tmpContainer.SetId(item.GetContainerID());

	SimpleItemType tmpsItem;
	tmpsItem.SetId(item.GetId());
	tmpsItem.SetName(item.GetName());

	//StorageList�� �����̳� �߰� & �����̳ʿ� ������ �߰�

	//������ Storage�ִ� �� �˻�
	if (StorageList.GetByBinarySearch(tempStorageType) == 1) { //Storage �����Ҷ�
		//������ Container�ִ� �� Ȯ��
		if ((tempStorageType.GetContainer(tmpContainer)) == 1) { // ����
			tmpContainer.AddsItem(tmpsItem);
			tempStorageType.UpdateContainer(tmpContainer);
			StorageList.Replace(tempStorageType);

		}
		else { //������ Container ���� x
			tmpContainer.AddsItem(tmpsItem);
			tempStorageType.AddContainer(tmpContainer);
			StorageList.Replace(tempStorageType);
		}

	}
	else { //Storage �������� ������
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

	DoublyIterator<ItemType> itor(MasterList);
	// list�� ��� �����͸� ȭ�鿡 ���
	data = itor.Next();
	while (itor.NextNotNull()) {
		cout << data << endl;
		data = itor.Next();
	}

	/*int length = MasterList.GetLength();
	int curIndex = MasterList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		cout << data;
		curIndex = MasterList.GetNextItem(data);
	}*/
}

int Application::OpenInFile(char * fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}

int Application::OpenOutFile(char * fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}

int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		AddItem(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	//DisplayAllItem();

	return 1;
}

int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;

	

	// list�� ��� �����͸� ���Ͽ� ����
	DoublyIterator<ItemType> itor(MasterList);

	data = itor.Next();
	while (itor.NextNotNull()) {
		data.WriteDataToFile(m_OutFile);
		data = itor.Next();
	}



	m_OutFile.close();	// file close

	return 1;
}

int Application::SearchById_SequenS()
{
	ItemType item;
	item.SetIdFromKB(); //id�Է¹޴´�.

	if (MasterList.Get(item)) //0�� �ƴϸ�(ã����)
	{
		cout << "<============ Item FOUND !==========>" << endl;
		cout << item;
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ����
	}
	cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	//����(0)�� ����
}

int Application::DeleteItem()
{
	int pre = MasterList.GetLength();//���� item������ �޾ƿ´�.
	ItemType item;
	item.SetIdFromKB();
	MasterList.Get(item); //item detail ���� ���
	

	//�ӽ� ���� ����
	StorageType tmpStorage;
	tmpStorage.SetId(item.GetStorageId());

	ContainerType tmpContainer;
	tmpContainer.SetId(item.GetContainerID());

	SimpleItemType tmpsItem;
	tmpsItem.SetId(item.GetId());

	//Storage ����ȭ & �����̳� ����ȭ
	
	if (StorageList.GetByBinarySearch(tmpStorage) == 1) { //���� �Ҷ�
		if (tmpStorage.GetContainer(tmpContainer) == 1) { //���� �Ҷ�
			if (tmpContainer.GetsItem(tmpsItem) == 1) { //���� �Ҷ�
				//�����̳ʿ��� ������ ����
				tmpContainer.DeletesItem(tmpsItem);
				//Storage���� �����̳� ������Ʈ
				tmpStorage.UpdateContainer(tmpContainer);
				//StorageList�� Storage ���� ������Ʈ
				StorageList.Replace(tmpStorage);
				
			}
			else { //������
				cout << "�ش� ID �� ���� Item�� �����ϴ�. " << endl;
				cout << "<========DELETE FAIL !=======>" << endl;
				return 0;
			}
		}
		else { //������
			cout << "�ش� ID �� ���� Container�� �����ϴ�. " << endl;
			cout << "<========DELETE FAIL !=======>" << endl;
			return 0;
		}
	}
	else { // ������
		cout << "�ش� ID �� ���� Storage�� �����ϴ�. " << endl;
		cout << "<========DELETE FAIL !=======>" << endl;
		return 0;
	}

	MasterList.Delete(item);
	
	if (pre > MasterList.GetLength()) //���� item�������� ���� item������ �������� ���ż���
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
	item.SetRecordFromKB(); //Ű����κ��� ������ �Է¹���

	ItemType origin;
	origin.SetId(item.GetId());
	if (MasterList.Get(origin) != 1) { //�ش� item�� id�� ��ġ�ϴ� ���� �����´�. ��������� �񱳸� ����
		cout << "�ش� ID�� ���� �������� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	MasterList.Replace(item); //�ش� item�� id�� ��ġ�ϴ� ���� ã�� �ٲ۴�.

	//Storage & Container �ӽ� ���� ����
	StorageType tmpStorage;
	ContainerType tmpContainer;
	SimpleItemType tmpsItem;

	//���� ���� ����
	tmpStorage.SetId(origin.GetStorageId());
	tmpContainer.SetId(origin.GetContainerID());
	tmpsItem.SetId(origin.GetId());

	StorageList.GetByBinarySearch(tmpStorage);
	tmpStorage.GetContainer(tmpContainer);
	tmpContainer.DeletesItem(tmpsItem);
	tmpStorage.UpdateContainer(tmpContainer);
	StorageList.Replace(tmpStorage);

	//Storage & Container �ӽ� ���� ����
	StorageType tmpStorage2;
	ContainerType tmpContainer2;
	SimpleItemType tmpsItem2;

	//���� �� ���� �߰�
	tmpStorage2.SetId(item.GetStorageId());
	tmpContainer2.SetId(item.GetContainerID());
	tmpsItem2.SetId(item.GetId());
	tmpsItem2.SetName(item.GetName());

	//������ Storage�ִ� �� �˻�
	if (StorageList.GetByBinarySearch(tmpStorage2) == 1) { //Storage �����Ҷ�
		//������ Container�ִ� �� Ȯ��
		if ((tmpStorage2.GetContainer(tmpContainer2)) == 1) { // ����
			tmpContainer2.AddsItem(tmpsItem2);
			tmpStorage2.UpdateContainer(tmpContainer2);
			StorageList.Replace(tmpStorage2);

		}
		else { //������ Container ���� x
			tmpContainer2.AddsItem(tmpsItem2);
			tmpStorage2.AddContainer(tmpContainer2);
			StorageList.Replace(tmpStorage2);
		}

	}
	else { //Storage �������� ������
		tmpContainer2.AddsItem(tmpsItem2);
		tmpStorage2.AddContainer(tmpContainer2);
		StorageList.Add(tmpStorage2);

	}



	return 0;
}

int Application::SearchByID_BinaryS()
{
	ItemType item;

	item.SetIdFromKB();	//id�� �Է¹޴´�
	if (MasterList.Get(item))	//����Ž���� �����ߴٸ�
	{
		//�˻� Ƚ�� �߰� �� �˻� ����Ʈ�� �߰�
		UpdateSearchList(item);

		cout << "<============I FOUND ITEM !==========>" << endl;
		cout << item;
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ
}

void Application::Add_tempItem()
{
	ItemType tmpItem;
	tmpItem.SetIdFromKB();
	if (MasterList.Get(tmpItem) == 1) {
		cout << endl;
		cout << "<=======������ ID�� �������� �����մϴ�.=======>" << endl;
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
		cout << "�ش��ϴ� Stroage ID�� �������� �ʽ��ϴ�. " << endl;
		cout << "\t<======FAIL!!!======>" << endl;
	}
	if (tmpStorage.GetContainer(tmpContainer) == 0) {
		cout << "�ش��ϴ� Container ID�� �������� �ʽ��ϴ�. " << endl;
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
		cout << "�ش��ϴ� Stroage ID�� �������� �ʽ��ϴ�. " << endl;
		cout << "\t<======FAIL!!!======>" << endl;
	}
	if (tmpStorage.GetContainer(tmpContainer) == 0) {
		cout << "�ش��ϴ� Container ID�� �������� �ʽ��ϴ�. " << endl;
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
		cout << "�ش� Storage ID �� �������� �ʽ��ϴ�." << endl;
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
		cout << "�ش� Storage ID �� �������� �ʽ��ϴ�." << endl;
		return;
	}
	cout << endl;
	cout << "\t******** Storage ********" << endl;
	tmpStorage.DisplayAllDetailsContainer();
}

//Container Position ����
void Application::SetContainerPosition() {
	StorageType tmpStorage;
	ContainerType tmpContainer;
	tmpStorage.SetIdFromKB();
	tmpContainer.SetIdFromKB();

	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "�ش� Storage ID�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	if (tmpStorage.GetContainer(tmpContainer) == 0) {
		cout << "�ش� Container ID�� �������� �ʽ��ϴ�." << endl;
		return;
	}

	tmpContainer.SetPositionFromKB();
	tmpStorage.UpdateContainer(tmpContainer);
	StorageList.Replace(tmpStorage);
}

//�뵵�� ���� ������ ���
void Application::SearchByUsage() {

	bool check = false;
	ItemType data;
	ItemType item;

	item.SetKindFromKB();

	StorageType tmpStorage;
	ContainerType tmpContainer;

	DoublyIterator<ItemType> itor(MasterList);
	// list�� ��� �����͸� ȭ�鿡 ���
	data = itor.Next();
	cout << "<============I �ĺ� List !==========>" << endl;
	while (itor.NextNotNull()) {
		if (data.GetKind() == item.GetKind()) {
			if (!check) check = true;
			cout << "======ITEM======" << endl;
			cout << data.GetId() << endl;
			cout << data.GetName() << endl;
			cout << endl;
		}
		data = itor.Next();

	}
	if (!check) {
		cout << "\t�ĺ� �������� �������� �ʽ��ϴ�." << endl;
		return;
	}
	ItemType tmpItem;
	int _id;
	cout << "�ڼ��� ������ ���� ���� ���� ID : ";
	cin >> _id;
	tmpItem.SetId(_id);
	MasterList.Get(tmpItem);
	cout << tmpItem << endl;

	//�˻���� & �˻� Ƚ�� ������Ʈ
	UpdateSearchList(tmpItem);

}

//�� ���� ���� ������ ������ ���
void Application::SearchByYear() {
	int FromYear;
	int ToYear;
	//From�� ���� To�� ����X
	cout << "\tINPUT From Year(include) and  To Year(exclude)" << endl;
	cout << "\t From : ";
	cin >> FromYear;
	cout << "\t To : ";
	cin >> ToYear;

	bool check = false;
	ItemType data;
	ItemType item;


	DoublyIterator<ItemType> itor(MasterList);

	data = itor.Next();
	cout << "<============I �ĺ� List !==========>" << endl;
	while (itor.NextNotNull()) {
		int tmpData = data.GetDate();
		string tmpData2 = to_string(tmpData);
		//������ Date�� 20181020 �̷� ���� ��� �տ� 4���� �����Ͽ� ���
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
		data = itor.Next();
	}
	if (!check) {
		cout << "\t�ĺ� �������� �������� �ʽ��ϴ�." << endl;
		return;
	}
	ItemType tmpItem;
	int _id;
	cout << "�ڼ��� ������ ���� ���� ���� ID : ";
	cin >> _id;
	tmpItem.SetId(_id);
	MasterList.Get(tmpItem);
	cout << tmpItem << endl;

	//�˻���� & �˻� Ƚ�� ������Ʈ
	UpdateSearchList(tmpItem);

}

//item ã��
void Application::FindItem() {
	StorageType tmpStorage;
	ContainerType tmpContainer;
	ItemType tmpItem;
	//Storage ID ����
	cout << "<============I Select Storage ID I==========>" << endl;
	tmpStorage.SetIdFromKB();

	cout << "<============I Display Container ID I==========>" << endl;
	StorageList.GetByBinarySearch(tmpStorage);
	tmpStorage.DisplayAllContainerID();
	
	//Container ID ����
	cout << "<============I Select Container ID I==========>" << endl;
	tmpContainer.SetIdFromKB();
	
	cout << "<============I Display Item Name I==========>" << endl;
	tmpStorage.GetContainer(tmpContainer);
	tmpContainer.DisplayAllsItemName();

	//Item ����
	cout << "<============I Select Item I==========>" << endl;
	tmpItem.SetIdFromKB();
	MasterList.Get(tmpItem);

	cout << tmpItem << endl;

	//�˻���� & �˻� Ƚ�� ������Ʈ
	UpdateSearchList(tmpItem);


}

//Storage - container�� �����ؼ� �ش� container�� Photolist ���
void Application::DisplayPhotoList() {
	StorageType tmpStorage;
	ContainerType tmpContainer;
	//Storage ID ����
	cout << "<============I Select Storage ID I==========>" << endl;
	tmpStorage.SetIdFromKB();

	cout << "<============I Display Container ID I==========>" << endl;
	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "�ش� ID�� ���� Storage�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	tmpStorage.DisplayAllContainerID();

	//Container ID ����
	cout << "<============I Select Container ID I==========>" << endl;
	tmpContainer.SetIdFromKB();

	cout << "<============I Display Photo List I==========>" << endl;
	tmpStorage.GetContainer(tmpContainer);
	tmpContainer.DisplayAllPhoto();


}

//Storage Id�� ���� storage �ȿ� ����ִ� container �������� Ȯ��
void Application::DisplayAllContainer2() {
	StorageType tmpStorage;
	tmpStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(tmpStorage) == 0) {
		cout << "�ش� Storage ID �� �������� �ʽ��ϴ�." << endl;
		return;
	}
	cout << "\t******** Storage ********" << endl;
	cout << "\tStorage ID : " << tmpStorage.GetId() << endl;
	cout << "\t===== Container =====" << endl;
	tmpStorage.DisplayAllContainer2();
}

//item date�� ���� �ð� ���� ���
int Application::CompareTime(int date) {
	time_t timer;
	struct tm t;
	string date_string = to_string(date);
	if (date_string.size() != 8) {
		return 0;
	}
	timer = time(NULL); // ���� �ð��� �� ������ ���
	localtime_s(&t, &timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�

	int diff_year, diff_month, diff_day;

	diff_year = (t.tm_year +1900) - stoi(date_string.substr(0,4));  //Year ���� ���
	diff_month = (t.tm_mon + 1) - stoi(date_string.substr(4,2));    //Month ���� ���
	diff_day = t.tm_mday - stoi(date_string.substr(6, 2));          //Day ���� ���

	//��¥ ���� ���
	return diff_year * 365 + diff_month * 30 + diff_day;  //Day�� ȯ���ؼ� ����
}

//������ ��õ�ϴ� ������
void Application::RecommandItem_ThrowAway() {

	ItemType data;
	bool found = false;

	DoublyIterator<ItemType> itor(MasterList);

	data = itor.Next();
	cout << "<============I Recommand item to throw away I==========>" << endl;
	while (itor.NextNotNull()) {
		//3�� �̻� �˻�Ƚ�� 0�� ������ Ž��
		if (data.GetNumOfSearch() == 0 && CompareTime(data.GetDate()) > 365 * 3) {
			if (!found) found = true;
			cout << data << endl;
		}
		data = itor.Next();
	}
	if (!found) {      //�ϳ��� �� ã�� ��
		cout << endl;
		cout << "<============I NOT FOUND!!!! I==========>" << endl;
	}

}


//���� ���� item�� ���� container Ž��
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
			if (num < Min) {   //���� ���� item�� ���� container Ž��
				Min = num;
				Info[0] = tmpStorage.GetId();      //Info[0]�� storage id ����
				Info[1] = tmpContainer.GetId();    //Info[1]�� container id ����
				Info[2] = num;                     //Info[2]�� ������ ���� ����
			}
		}
	}
	cout << "<============I Recommand container to store I==========>" << endl;
	cout << "\tSTORAGE ID : " << Info[0] << endl;
	cout << "\tCONTAINER ID : " << Info[1] << endl;
	cout << "\t�� Container�� ���� " << Info[2] << "���� ���� �γ��մϴ�." << endl;
}

//���ã�� ������ ��ϵ� ���
void Application::Display_MostSearch() {

	ItemType data;
	int MaxSearchTime = 0;

	//���� ū �˻�Ƚ�� ã��
	DoublyIterator<ItemType> itor(MasterList);
	data = itor.Next();
	while (itor.NextNotNull()) {
		if (MaxSearchTime < data.GetNumOfSearch()) {
			MaxSearchTime = data.GetNumOfSearch();   //MaxSearchTime ����
		}
		data = itor.Next();
	}

	DoublyIterator<ItemType> itor2(MasterList);
	data = itor2.Next();
	cout << "<============I Most Search ItemList I==========>" << endl;
	while (itor2.NextNotNull()) {
		//���� ���� �˻�Ƚ�� - 1 �̻� -> ���ã�� ��ǰ
		if (data.GetNumOfSearch() >= MaxSearchTime -1) {   
			cout << data << endl;
		}
		data = itor2.Next();
	}

	

}

//SearchList ���
void Application::Display_SearchList() {
	cout << "<============I Search List I==========>" << endl;
	SearchList.Print();
	if (SearchList.IsEmpty()) {
		cout << "\t SearchList is empty. " << endl;
		return;
	}
	ItemType tmpItem;
	int _id;
	cout << "\t �ڼ��� ������ ������� ���� ID : ";
	cin >> _id;
	cout << endl;
	tmpItem.SetId(_id);
	MasterList.Get(tmpItem);
	cout << tmpItem << endl;

	//�˻�Ƚ�� �߰� �� �˻� ����Ʈ�� �߰�
	UpdateSearchList(tmpItem);

}

//�������� �ڼ��� ���� ���
void Application::FindItemDetail() {
	DisplayAllStorage();
	ItemType tmpItem;
	int _id;
	cout << "\t �ڼ��� ������ ������� ���� ID : ";
	cin >> _id;
	cout << endl;
	tmpItem.SetId(_id);
	MasterList.Get(tmpItem);
	cout << tmpItem << endl;

	//�˻�Ƚ�� �߰� �� �˻� ����Ʈ�� �߰�
	UpdateSearchList(tmpItem);

}

//item�� �˻�Ƚ�� ���� & Search List�� �߰�
void Application::UpdateSearchList(ItemType item) {
	//�˻� Ƚ�� ����
	item.SetNumOfSearch(item.GetNumOfSearch() + 1);
	MasterList.Replace(item);

	//�˻� ��Ͽ� �߰�
	SimpleItemType tmpSimpleItem;
	tmpSimpleItem.SetId(item.GetId());
	tmpSimpleItem.SetName(item.GetName());
	SearchList.Push(tmpSimpleItem);
}

//���� �˻� ������� ���ư���
void Application::ReturnPreviousSearch() {
	SimpleItemType item;
	//Pop return ���� -1 => stack�� �������.
	if (SearchList.Pop(item) == -1) {
		cout << "\t ���� �˻� ����� �����ϴ�." << endl;
		return;
	}

	ItemType tmpItem;
	tmpItem.SetId(item.GetId());
	MasterList.Get(tmpItem);
	cout << "<============I Previous Search I==========>" << endl;
	cout << tmpItem << endl;
}

