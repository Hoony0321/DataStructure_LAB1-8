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
		case 4:		//search by id.
			SearchById_SequenS();
			break;
		case 5:	//search by binary search.
			SearchByID_BinaryS();
			break;
		case 6:		//search by name.
			SearchByName();
			break;
		case 7:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 8:		// make empty list.
			m_MusicList.MakeEmpty();
			break;
		case 9:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 10:		// save list data into a file.
			WriteDataToFile();
			break;
		case 11:
			AddPlayItem();
			break;
		case 12:
			DeletePlayItem();
			break;
		case 13:
			PrintAllPlayItem();
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
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by Binary Search" << endl;
	cout << "\t   6 : Search item by name" << endl;
	cout << "\t   7 : Print all on screen" << endl;
	cout << "\t   8 : Make empty list" << endl;
	cout << "\t   9 : Get from file" << endl;
	cout << "\t   10 : Put to file " << endl;
	cout << "\t   11 : Add play item" << endl;
	cout << "\t   12 : Delete play item" << endl;
	cout << "\t   13 : Print play item on screen" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> m_Command;
	cout << endl;
}

int Application::AddItem()
{
	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if (m_MusicList.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_MusicList.Add(item);

	return 1;
}

void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
	m_MusicList.ResetList();
	int length = m_MusicList.GetLength();
	int curIndex = m_MusicList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_MusicList.GetNextItem(data);
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
		m_MusicList.Add(data);
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
	m_MusicList.ResetList();

	// list의 모든 데이터를 파일에 쓰기
	int length = m_MusicList.GetLength();
	int curIndex = m_MusicList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_MusicList.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

int Application::SearchById_SequenS()
{
	ItemType item;
	item.SetIdFromKB(); //id입력받는다.

	if (m_MusicList.Get(item)) //0이 아니면(찾으면)
	{
		cout << "<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //해당 item을 출력한다.
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 리턴
	}
	cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	//실패(0)을 리턴
}

int Application::SearchByName()
{
	ItemType item;
	item.SetNameFromKB(); //name을 입력받는다.

	if (SearchAllItmeByName(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}

int Application::SearchAllItmeByName(ItemType & inData)
{
	ItemType tmp;
	int result = 0;

	m_MusicList.ResetList();//iterator 초기화
	while (m_MusicList.GetNextItem(tmp) != -1) //리스트의 마지막까지 반복
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

int Application::DeleteItem()
{
	int pre = m_MusicList.GetLength();//이전 item개수를 받아온다.
	ItemType item;
	item.SetIdFromKB();

	m_MusicList.Delete(item);

	if (pre > m_MusicList.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
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

	m_MusicList.Replace(item); //해당 item의 id와 일치하는 것을 찾아 바꾼다.
	//this->DisplayAllItem();
	return 0;
}

int Application::SearchByID_BinaryS()
{
	ItemType item;

	item.SetIdFromKB();	//id를 입력받는다
	if (m_MusicList.GetByBinarySearch(item))	//이진탐색에 성공했다면
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 반환
}

void Application::AddPlayItem()
{
	PlayItemType item;
	ItemType tmpItem;

	item.SetRecordFromKB();
	tmpItem.SetId(item.GetId());
	if (!m_MusicList.Get(tmpItem)) {
		cout << "<============I NOT FOUND ITEM !==========>" << endl;
		return;
	}
	m_PlayList.EnQueue(item);
	cout << item;
	return;
}

void Application::DeletePlayItem()
{
	PlayItemType item;
	m_PlayList.DeQueue(item);
	return;
}

void Application::PrintAllPlayItem()
{
	m_PlayList.PlayInsertOrder();
}
