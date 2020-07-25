#pragma once
class SimpleItemType
{
private:
	int id;
	string name;

public:
	//default-constructor
	SimpleItemType();
	//destructor
	~SimpleItemType();

	//------- Get Function -------//

	/**
	*	@pre	product id is set.
	*	@post	none.
	*	@return product id.
	*/
	int GetId() const;

	/**
	*	@pre	product name is set.
	*	@post	none.
	*	@return product name.
	*/
	string GetName() const;

	//------- Set Function -------//

	/**
	*	@brief	Set product id.
	*	@pre	none.
	*	@post	product id is set.
	*	@param	inId	product id.
	*/
	void SetId(int _id);

	/**
	*	@brief	Set product name.
	*	@pre	none.
	*	@post	product name is set.
	*	@param	inName	product name.
	*/
	void SetName(string _name);

	/*
	*	@brief	Set product record.
	*	@pre	none.
	*	@post	product record is set.
	*	@param	product record.
	*/
	void SetRecord(int _id, string _name);

	//------- Set From Keyboard Function -------//

	/**
	*	@brief	Set product id.
	*	@pre	none.
	*	@post	product id is set.
	*	@param	inId	product id.
	*/
	void SetIdFromKB();

	/**
	*	@brief	Set product name.
	*	@pre	none.
	*	@post	product name is set.
	*	@param	inId	product id.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set product record.
	*	@pre	none.
	*	@post	product record is set.
	*	@param	inId	product record.
	*/
	void SetRecordFromKB();

	//------- File System Function -------//

	/**
	*	@brief	파일로부터 데이터를 읽어옵니다.
	*	@pre	ifstream is open.
	*	@post	Item record is set.
	*	@param	ifstream 변수
	*/
	int ReadDataFromFile(ifstream& fin);

	/*
	*	@brief	파일에 데이터를 씁니다.
	*	@pre	ofstream is open.
	*	@post	file에 데이터 정보가 저장됩니다.
	*	@param	ofstream 변수
	*/
	int WriteDataToFile(ofstream& fout);


	//------- Operator Function -------//

	/*
	*	@brief	item id를 비교합니다.
	*	@pre	item id is set.
	*	@post	만약 item id가 같을 시 ture,그렇지 않으면 false
	*	@param	ItemType 변수
	*/
	bool operator==(const SimpleItemType& _item);

	/*
	*	@brief	item id를 비교합니다.
	*	@pre	item id is set.
	*	@post	만약 item id가 크면 ture,그렇지 않으면 false
	*	@param	ItemType 변수
	*/
	bool operator>(const SimpleItemType& _item);

	/*
	*	@brief	item id를 비교합니다.
	*	@pre	item id is set.
	*	@post	만약 item id가 작으면 ture,그렇지 않으면 false
	*	@param	ItemType 변수
	*/
	bool operator<(const SimpleItemType& _item);

	/*
	*	@brief	item 정보를 대입합니다.
	*	@pre	item record is set.
	*	@post	item 멤버함수에 각 정보가 대입됩니다.
	*	@param	ItemType 변수
	*/
	void operator=(const SimpleItemType& _item);

	// ostream<< 오버로딩
	friend ostream& operator<<(ostream& os, const SimpleItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tName   : " << _item.GetName() << endl;
		return os;
	}

};

