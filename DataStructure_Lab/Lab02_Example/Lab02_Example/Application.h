#ifndef APPLICATION_H
#define APPLICATION_H

#include<iostream>
#include<fstream>
#include<string>

#include "ArrayList.h"

using namespace std;

#define FILENAMESIZE 1024

class Application {
public:
	Application();
	~Application();

	void Run();
	int GetCommand();
	int AddItem();
	void DisplayAllItem();
	int OpenInFile(char* fileName);
	int OpenOutFile(char* fileName);
	int ReadDataFromFile();
	int WriteDataToFile();

private:
	ifstream m_InFile;
	ofstream m_OutFile;
	ArrayList m_List;
	int m_Command;

};


#endif // !APPLICATION_H
