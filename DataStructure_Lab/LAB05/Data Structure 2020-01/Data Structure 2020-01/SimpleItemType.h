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
	*	@brief	���Ϸκ��� �����͸� �о�ɴϴ�.
	*	@pre	ifstream is open.
	*	@post	Item record is set.
	*	@param	ifstream ����
	*/
	int ReadDataFromFile(ifstream& fin);

	/*
	*	@brief	���Ͽ� �����͸� ���ϴ�.
	*	@pre	ofstream is open.
	*	@post	file�� ������ ������ ����˴ϴ�.
	*	@param	ofstream ����
	*/
	int WriteDataToFile(ofstream& fout);


	//------- Operator Function -------//

	/*
	*	@brief	item id�� ���մϴ�.
	*	@pre	item id is set.
	*	@post	���� item id�� ���� �� ture,�׷��� ������ false
	*	@param	ItemType ����
	*/
	bool operator==(const SimpleItemType& _item);

	/*
	*	@brief	item id�� ���մϴ�.
	*	@pre	item id is set.
	*	@post	���� item id�� ũ�� ture,�׷��� ������ false
	*	@param	ItemType ����
	*/
	bool operator>(const SimpleItemType& _item);

	/*
	*	@brief	item id�� ���մϴ�.
	*	@pre	item id is set.
	*	@post	���� item id�� ������ ture,�׷��� ������ false
	*	@param	ItemType ����
	*/
	bool operator<(const SimpleItemType& _item);

	/*
	*	@brief	item ������ �����մϴ�.
	*	@pre	item record is set.
	*	@post	item ����Լ��� �� ������ ���Ե˴ϴ�.
	*	@param	ItemType ����
	*/
	void operator=(const SimpleItemType& _item);

	// ostream<< �����ε�
	friend ostream& operator<<(ostream& os, const SimpleItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tName   : " << _item.GetName() << endl;
		return os;
	}

};

