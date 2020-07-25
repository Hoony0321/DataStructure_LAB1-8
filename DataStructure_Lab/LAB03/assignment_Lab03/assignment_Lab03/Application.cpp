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
		case 1:		//��� ������ �޾� masterList& container�� �߰�
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


//��� ������ �Է¹޾� masterList & containerList�� �߰���
int Application::AddItem_AllInfo()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if (MasterList.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;
	item.SetRecordFromKB();

	//MasterList�� �߰�
	MasterList.Add(item);
	
	//�ӽ� �����̳� ����
	ContainerType container;
	SimpleItemType tdata;
	tdata = item;
	container.AddItem(tdata);
	//return 0 -> ������ �����̳� ����. -> ���� �����̳ʿ� �����۸� �Է��ϸ� ��.
	if (ContainerList.Add(container) == 0) {

		ContainerList.GetByBinarySearch(container);
		container.AddItem(tdata);
		ContainerList.Replace(container);
	}
	


	return 1;
}


//ContainerID�� ���� ������ �Է¹޾� templist�� ����
int Application::AddItem_NoContainerID()
{
	ItemType item;

	item.SetRecordFromKB_NoContainerID();
	//tempList�� ����
	if (TempList.Enqueue(item)) {
		return 1;
	}
	cout << "TempList is Full." << endl;
	return 0;
	
}

//�߰�
int Application::TempListToConatinerList() {
	ItemType item;
	if (TempList.Dequeue(item) == 0) {
		cout << "\tTempList is empty." << endl;
		return 0;
	}
	cout << "\tNULL container id is -1." << endl;
	item.DisplayRecord();
	item.SetContainerIdFromKB();

	//MasterList�� �߰�
	MasterList.Add(item);

	//�ӽ� �����̳� ����
	ContainerType container;
	SimpleItemType tdata;
	tdata = item;
	container.AddItem(tdata);

	//return 0 -> ������ �����̳� ����
	//���� �����̳ʿ� �����۸� �Է��ϸ� ��.
	if (ContainerList.Add(container) == 0) {
		//id�� ���� ã�� �����̳� ������Ʈ
		ContainerList.GetByBinarySearch(container);
		//�� �� ������Ʈ
		container.AddItem(tdata);
		ContainerList.Replace(container);
	}
	
	return 1;
}

//container_id�� container ã�� ���
int Application::SearchContainerByID() {
	ContainerType container;
	container.SetIdFromKB();

	if (ContainerList.GetByBinarySearch(container))	//����Ž���� �����ߴٸ�
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		container.DisplayAllInfo();
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ

}

//Add Container
int Application::AddContainer() {
	ContainerType tContainer;
	tContainer.SetIdFromKB();
	tContainer.SetLocFromKB();

	if (ContainerList.Add(tContainer) == 0) {
		cout << "\t������ �����̳ʰ� �̹� �����մϴ�." << endl;
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



//�̸��� �Է¹��� item���� ����Ʈ���� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchByName()
{
	ItemType item;
	item.SetNameFromKB(); //name�� �Է¹޴´�.

	if (SearchAllItmeByName(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

//�̸����� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchAllItmeByName(ItemType& inData)
{
	ItemType tmp;
	int result = 0;

	MasterList.ResetList();//iterator �ʱ�ȭ
	while (MasterList.GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecord();
			result = 1;	//����(1)
		}
	}
	if (result)	//�߰��� ���
		cout << "<====================================>" << endl;
	else	//�߰� ���ϴ� ���
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

//�̸����� �ش� �����̳� ������ �������� ã�´�.
int Application::SearchByNameInContainer() {
	SimpleItemType tdata;
	ContainerType container;
	
	tdata.SetContainerIdFromKB();
	tdata.SetNameFromKB();
	container.SetId(tdata.GetContainerId());
	if (ContainerList.GetByBinarySearch(container) == 0) {
		cout << "\t �ش� id�� �����̳ʰ� �������� �ʽ��ϴ�." << endl;
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
		cout << "\t �ش� id�� �����̳ʰ� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	return container.FindByUsage(tdata);
}

//id�� item�� ã�Ƽ� �����Ѵ�.
int Application::DeleteItem()
{
	int pre = MasterList.GetLength();//���� item������ �޾ƿ´�.
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
	if (pre > MasterList.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << "<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

//�ش� id�� item�� �����Ѵ�.
int Application::ReplaceItem()
{
	ItemType item;
	ItemType tItem;
	item.SetRecordFromKB(); //Ű����κ��� ������ �Է¹���
	tItem.SetId(item.GetId());
	MasterList.GetByBinarySearch(tItem);


	//�ش� item�� id�� ��ġ�ϴ� ���� ã�� �ٲ۴�.
	if (MasterList.Replace(item)) {
		SimpleItemType SimpleItem;
		ContainerType container;

		//���� �����̳ʿ��� ����
		SimpleItem = tItem;
		container.SetId(tItem.GetContainerId());
		ContainerList.GetByBinarySearch(container);
		container.DeleteItem(SimpleItem);
		ContainerList.Replace(container);

		//����� �����̳ʿ� �߰�
		SimpleItem = item;
		container.SetId(item.GetContainerId());
		ContainerList.GetByBinarySearch(container);
		container.AddItem(SimpleItem);
		if (ContainerList.Add(container) == 0) {
			ContainerList.GetByBinarySearch(container);
			container.AddItem(SimpleItem);
			ContainerList.Replace(container);
		}

		//container id�� ���� �ȵŵ� ������. �׳� ���� �����̳ʿ��� �����Ǿ��ٰ� ����� ������ ������ �ٽ� �����Ǵ� ��.
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

	// list�� ��� �����͸� ȭ�鿡 ���
	MasterList.ResetList();
	int length = MasterList.GetLength();
	int curIndex = MasterList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecord();
		curIndex = MasterList.GetNextItem(data);
	}
}

//�߰�
void Application::DisplayAllContainer() {
	ContainerType data;
	cout << "\n\tCurrent list" << endl;
	// list�� ��� �����͸� ȭ�鿡 ���
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

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
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


// Open a file as a write mode, and write all data into the file,
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

//ã���� �ϴ� ID�� ����Ž�� ����� ���� ã�´�.
int Application::SearchByID_BinaryS()
{
	ItemType item;

	item.SetIdFromKB();	//id�� �Է¹޴´�
	if (MasterList.GetByBinarySearch(item))	//����Ž���� �����ߴٸ�
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecord();
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ

}

//�Էµ� kind�� ������ kind�� ���� �������� ã�´�.
int Application::SearchByKind() {
	int result[LISTMAXSIZE];  // ã�� ������ index�� ������ �迭
	int arraySize;   //����� �������� ���� -> �˻��� result �迭�� ũ��
	ItemType item;
	cout << endl;
	item.SetTypeFromKB();
	if (MasterList.SearchByKind(result, item.GetType(),arraySize)) {
		cout << "<============I FOUND ITEM !==========>" << endl;

		for (int i = 0; i < arraySize; i++) {
			//����� ������ ������ŭ�� ã�� (i < arraySize)
			MasterList.ResetList();
			for (int j = 0; j < result[i] + 1; j++) {
				MasterList.GetNextItem(item);      //����� index�� m_CuPointer �̵�
			}
			item.DisplayRecord();   //item ����� data display
		}

		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���� ��
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ
}
