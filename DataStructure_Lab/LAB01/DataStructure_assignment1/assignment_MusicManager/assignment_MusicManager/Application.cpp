#include "Application.h"



void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 곡 정보를 입력 받아 리스트에 추가
			AddItem();
			break;
		case 2:		// 곡의 고유번호를 입력 받아 리스트에서 삭제
			DeleteMusic();
			break;
		case 3:		// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신			
			ReplaceMusic();
			break;
		case 4:		// 입력된 정보로 리스트에서 곡을 찾아서 화면에 출력				
			RetrieveMusic();
			break;
		case 5:		// 리스트에 저장된 모든 곡을 화면에 출력
			DisplayAllMusic();
			break;
		case 6: 		// 리스트에 입력된 모든 곡을 삭제
			MakeEmpty();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
			WriteDataToFile();
			break;
		case 9:
			RetriveMusic_Binary();
			break;
		case 0:
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
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Retrieve item" << endl;
	cout << "\t   5 : Print all on screen" << endl;
	cout << "\t   6 : Make empty list" << endl;
	cout << "\t   7 : Get from file" << endl;
	cout << "\t   8 : Put to file " << endl;
	cout << "\t   9 : Retrieve itme by binary search" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// Add new record into list.
int Application::AddItem()
{
	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if (m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// 현재 list 출력
	DisplayAllMusic();

	return 1;
}

// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;
	cout << "\t-----------------------" << endl;
	if (m_List.IsEmpty()) {
		cout << "\tList is Empty." << endl;
		return;
	}
	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
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

	// array에 정보가 들어있는 structure 저장
	while (!m_InFile.eof()) {
		// 파일에서 정보 읽어오기
		data.ReadDataFromFile(m_InFile);
		// 마지막 문자열인지 판단 후 while문 종료
		if (m_InFile.eof()) break;
		// 리스트에 해당 정보 추가
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllMusic();

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
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

int Application::RetrieveMusic() {
	ItemType selectItem;
	selectItem.SetNumFromKB();

	//음원이 있을경우
	if (m_List.Retrieve(selectItem)) {
		cout << "\t-----Search-----" << endl;
		selectItem.DisplayRecordOnScreen();
		return 1;
	}
	else {
		//음원이 없을경우
		cout << "\n\t해당 Number의 음원이 존재하지 않습니다.";
		return 0;
	}
}

int Application::RetrieveMusic_Binary() {
	ItemType selectItem;
	selectItem.SetNumFromKB();

	//음원이 있을경우
	if (m_List.Retrieve_Binary(selectItem)) {
		cout << "\t-----Search-----" << endl;
		selectItem.DisplayRecordOnScreen();
		return 1;
	}
	else {
		//음원이 없을경우
		cout << "\n\t해당 Number의 음원이 존재하지 않습니다.";
		return 0;
	}
}

int Application::RetrieveMusicByName() {
	ItemType selectItem;
	selectItem.SetSongFromKB();
	int num = m_List.GetLength();
	int *result = new int[num];
	if (m_List.RetrieveByName(selectItem,result)) {
		cout << "\t-----Search-----" << endl;
		for (int i = 0; i < result[1]; i++) {
			m_List[i].D
		}
		return 1;
	}
	else {
		//음원이 없을경우
		cout << "\n\t해당 Number의 음원이 존재하지 않습니다.";
		return 0;
	}
}

int Application::DeleteMusic() {
	ItemType selectItem;
	selectItem.SetNumFromKB();

	if (m_List.Delete(selectItem)) {
		cout << "\n\t삭제가 정상적으로 동작하였습니다.";
		return 1;
	}
	else {
		//음원이 없을경우
		cout << "\n\t해당 Number의 음원이 존재하지 않습니다.";
		return 0;
	}
}

int Application::ReplaceMusic() {
	ItemType selectItem;
	selectItem.SetRecordFromKB();

	if (m_List.Replace(selectItem)) {
		cout << "\n\t수정이 정상적으로 동작하였습니다.";
		return 1;
	}
	else {
		//음원이 없을경우
		cout << "\n\t해당 Number의 음원이 존재하지 않습니다.";
		return 0;
	}
}

void Application::MakeEmpty() {
	m_List.MakeEmpty();
}

