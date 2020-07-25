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


//���� �Լ���
int Application::AddItem(ItemType& item)
{

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

	// list�� ��� �����͸� ȭ�鿡 ���
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
		MasterList.Add(data);
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

	// list �����͸� �ʱ�ȭ
	MasterList.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
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
	MasterList.GetByBinarySearch(item); //item detail ���� ���
	

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
	if (MasterList.GetByBinarySearch(item))	//����Ž���� �����ߴٸ�
	{
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
		cout << "\t===== Container =====" << endl;
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

