#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	destructor.
	*/
	~Application()	{}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();




	int RetrieveMusic() {
		ItemType selectItem;
		selectItem.SetIdFromKB();

		if (m_List.Get(selectItem)) {
			selectItem.DisplayRecordOnScreen();
			return 1;
		}
		else {
			cout << "\n\t해당 ID의 학생이 존재하지 않습니다.";
			return 0;
		}
	}

	int DeleteMusic() {
		ItemType selectItem;
		selectItem.SetIdFromKB();

		if (m_List.Delete(selectItem)) {
			cout << "\n\t삭제가 정상적으로 동작하였습니다.";
			return 1;
		}
		else {
			cout << "\n\t해당 ID의 학생이 존재하지 않습니다.";
			return 0;
		}
	}

	int ReplaceMusic() {
		ItemType selectItem;
		selectItem.SetRecordFromKB();

		if (m_List.Replace(selectItem)) {
			cout << "\n\t수정이 정상적으로 동작하였습니다.";
			return 1;
		}
		else {
			cout << "\n\t해당 ID의 학생이 존재하지 않습니다.";
			return 0;
		}
	}
	void MakeEmpty() {
		m_List.MakeEmpty();
	}
	
private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.

	ArrayList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H