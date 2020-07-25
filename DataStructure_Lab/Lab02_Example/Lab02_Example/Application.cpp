#include "Application.h"

Application::Application() {
	m_Command = -1;
}

Application::~Application(){}

void Application::Run() {
	while (1) {
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1:
			AddItem(); break;
		case 2:
			DisplayAllItem(); break;
		case 3:
			m_List.MakeEmpty(); break;
		case 4:
			ReadDataFromFile(); break;
		case 5:
			WriteDataToFile(); break;
		case 0:
			return;
		default:
			cout << "\tIlegal selection..." << endl;
			break;
		}
	}
}

int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t 1 : Add item" << endl;
	cout << "\t 2 : Print all on screen" << endl;
	cout << "\t 3 : Make empty list" << endl;
	cout << "\t 4 : Get from file" << endl;
	cout << "\t 5 : Put to file " << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

int Application::AddItem() {
	if (m_List.IsFull()) return 0;

	ItemType data;
	data.SetRecordFromKB();

	m_List.Add(data);

	DisplayAllItem();

	return 1;
}

void Application::DisplayAllItem() {
	ItemType data;
	for (int i = 0; i < m_List.GetLength(); i++) {
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
	}
	m_List.ResetList();
}

int Application::OpenInFile(char* Filename) {

	m_InFile.open(Filename);

	if (!m_InFile) return 0;
	else return 1;
}

int Application::OpenOutFile(char* Filename) {
	m_OutFile.open(Filename);

	if (!m_OutFile) return 0;
	else return 1;
}

int Application::ReadDataFromFile() {
	ItemType data;
	char filename[FILENAMESIZE];

	cout << "\tInput File name to read data : ";
	
	cin >> filename;

	if (!OpenInFile(filename)) return 0;

	while (!m_InFile.eof()) {
		data.ReadDataFromFIle(m_InFile);
		
		if (m_InFile.eof()) break;

		m_List.Add(data);
	}

	m_InFile.close();

	DisplayAllItem();

	return 1;
}

int Application::WriteDataToFile() {

	ItemType data;
	char filename[FILENAMESIZE];
	cout << "\tInput File name to Write : ";
	cin >> filename;

	if(!OpenOutFile(filename)) return 0;

	m_List.ResetList();
	for (int i = 0; i < m_List.GetLength(); i++) {
		m_List.GetNextItem(data);
		data.WriteDataToFile(m_OutFile);
	}

	m_OutFile.close();
	return 1;

}


