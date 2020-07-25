#pragma once
class Application
{
private:
	ifstream					m_InFile;		///< input file descriptor.
	ofstream					m_OutFile;		///< output file descriptor.
	int							m_Command;		///< current command number.

	SortedList<ItemType>		m_MusicList;	///< music list.
	CircularQueue<PlayItemType>	m_PlayList;		///< play list.

public:
	/**
	*	constructor.
	*/
	Application();

	/**
	*	destructor.
	*/
	~Application();

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
	*/
	void GetCommand();

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

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchById_SequenS();

	/**
	*	@brief	리스트에서 해당 이름을 가진 item을 찾아 출력한다.
	*	@pre	없음.
	*	@post	찾은 item이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchByName();

	/**
	*	@brief	리스트에서 해당 이름을 가진 item을 찾아 반환한다.
	*	@pre	인자로 받는 ItemType에 이름이 입력되어 있어야 한다.
	*	@post	찾은 item이 인자로 들어온다.
	*	@param	inData	이름이 입력되 있는 ItemType값.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchAllItmeByName(ItemType &inData);

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 제거한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 해당 item을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DeleteItem();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾아 변경한다.
	*	@pre	입력하는 id가 리스트에 존재해야 한다.
	*	@post	리스트에 item이 변경된다.
	*/
	int ReplaceItem();

	/**
	*	@brief	리스트에서 해당 id를 가진 item을 이진탐색을 이용해 찾는다.
	*	@pre	없음.
	*	@post	찾은 item이 화면에 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchByID_BinaryS();

	void AddPlayItem();
	void DeletePlayItem();
	void PrintAllPlayItem();
};