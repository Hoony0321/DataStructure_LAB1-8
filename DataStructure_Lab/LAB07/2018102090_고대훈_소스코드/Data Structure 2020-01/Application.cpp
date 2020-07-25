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
	cout << "\t   28 : ���ã�� ��ǰ ����Ʈ ���" << endl;
	cout << "\t   29 : �˻� ��� ���" << endl;
	cout << "\t   30 : �� �˻� ������� ���ư���" << endl;
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
	bool found = false;
	MasterList.RetrieveItem(item, found);
	if (found == true) {
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
	item.SetIdFromKB(); //id�Է¹޴´�.
	bool found = false;
	MasterList.RetrieveItem(item,found);
	if (found = true) //0�� �ƴϸ�(ã����)
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

	bool found = false;
	MasterList.RetrieveItem(item,found); //item detail ���� ���
	if (found == false) {
		cout << "\t �ش� ID�� ���� �������� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	

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

	MasterList.DeleteItem(item);
	
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
	bool found = false;
	ItemType item;
	item.SetRecordFromKB(); //Ű����κ��� ������ �Է¹���

	ItemType origin;
	origin.SetId(item.GetId());
	MasterList.RetrieveItem(origin, found);
	if (found = false) { //�ش� item�� id�� ��ġ�ϴ� ���� �����´�. ��������� �񱳸� ����
		cout << "�ش� ID�� ���� �������� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	MasterList.ReplaceItem(item); //�ش� item�� id�� ��ġ�ϴ� ���� ã�� �ٲ۴�.

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

	bool found = false;
	MasterList.RetrieveItem(item, found);
	if (found == true)	//����Ž���� �����ߴٸ�
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

	bool found = false;
	MasterList.RetrieveItem(tmpItem, found);
	if (found == true) {
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

	// list�� ��� �����͸� ȭ�鿡 ���
	MasterList.ResetQueue();
	cout << "<============I �ĺ� List !==========>" << endl;
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
		cout << "\t�ĺ� �������� �������� �ʽ��ϴ�." << endl;
		return;
	}
	ItemType tmpItem;
	int _id;
	cout << "�ڼ��� ������ ���� ���� ���� ID : ";
	cin >> _id;
	tmpItem.SetId(_id);
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);
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



	MasterList.ResetQueue();
	cout << "<============I �ĺ� List !==========>" << endl;
	while (MasterList.GetNextItem(data) != 0) {
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
	bool found = false;
	MasterList.RetrieveItem(tmpItem, found);
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
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);

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

	MasterList.ResetQueue();
	cout << "<============I Recommand item to throw away I==========>" << endl;
	while (MasterList.GetNextItem(data) != 0) {
		//3�� �̻� �˻�Ƚ�� 0�� ������ Ž��
		if (data.GetNumOfSearch() == 0 && CompareTime(data.GetDate()) > 365 * 3) {
			if (!found) found = true;
			cout << data << endl;
		}
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

	MasterList.ResetQueue();
	while (MasterList.GetNextItem(data)) {
		if (MaxSearchTime < data.GetNumOfSearch()) {
			MaxSearchTime = data.GetNumOfSearch();   //MaxSearchTime ����
		}
	}

	MasterList.ResetQueue();
	cout << "<============I Most Search ItemList I==========>" << endl;
	while (MasterList.GetNextItem(data) != 0) {
		//���� ���� �˻�Ƚ�� - 1 �̻� -> ���ã�� ��ǰ
		if (data.GetNumOfSearch() >= MaxSearchTime -1) {   
			cout << data << endl;
		}
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
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);
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
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);
	cout << tmpItem << endl;

	//�˻�Ƚ�� �߰� �� �˻� ����Ʈ�� �߰�
	UpdateSearchList(tmpItem);

}

//item�� �˻�Ƚ�� ���� & Search List�� �߰�
void Application::UpdateSearchList(ItemType item) {
	//�˻� Ƚ�� ����
	item.SetNumOfSearch(item.GetNumOfSearch() + 1);
	MasterList.ReplaceItem(item);

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
	bool found = false;
	MasterList.RetrieveItem(tmpItem,found);
	cout << "<============I Previous Search I==========>" << endl;
	cout << tmpItem << endl;
}

