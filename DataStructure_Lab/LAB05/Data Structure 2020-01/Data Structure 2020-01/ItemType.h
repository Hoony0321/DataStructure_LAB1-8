#pragma once
class ItemType
{
private:
	int m_id;		///prodcut id
	int m_storageId;  //storageId
	int m_containerId; // container id
	int m_date;     ///product date
	int m_amount;   ///product amount
	int m_numofsearch; ///number of search the product

	string m_photo; ///product photo image
	string m_name;  ///product name
	string m_kind;     ///product type

public:
	//-------constructor-------//
	ItemType();
	//-------default-constructor-------//
	~ItemType();

	//------- Get Function -------//
	/*
	*	@pre	product id is set.
	*	@post	none.
	*	@return product id.
	*/
	int GetId() const;

	/**
	*	@pre	product container id is set.
	*	@post	none.
	*	@return product container id.
	*/
	int GetContainerID() const;

	/*
	*	@pre	product name is set.
	*	@post	none.
	*	@return product name.
	*/
	string GetName() const;

	/**
	*	@pre	product type is set. 
	*	@post	none.
	*	@return product type.
	*/
	string GetKind() const;

	/**
	*	@pre	product photo is set.
	*	@post	none.
	*	@return product photo.
	*/
	string GetPhoto() const;


	/**
	*	@pre	product date is set.
	*	@post	none.
	*	@return product date.
	*/
	int GetDate() const;

	/**
	*	@pre	product amount is set.
	*	@post	none.
	*	@return product amount.
	*/
	int GetAmount() const;

	/**
	*	@pre	product storage  id is set.
	*	@post	none.
	*	@return product storage id.
	*/
	int GetStorageId() const;

	/**
	*	@pre	product numofsearch is set.
	*	@post	none.
	*	@return product numofsearch id.
	*/
	int GetNumOfSearch() const;
	


	//------- Set Function -------//

	/**
	*	@brief	Set product id.
	*	@pre	none.
	*	@post	product id is set.
	*	@param	inId	product id.
	*/
	void SetId(int _id);

	/**
	*	@brief	Set product type.
	*	@pre	none.
	*	@post	product type is set.
	*	@param	inType	product type.
	*/
	void SetKind(string _kind);

	/**
	*	@brief	Set product photo.
	*	@pre	none.
	*	@post	product photo is set.
	*	@param	inType	product photo.
	*/
	void SetPhoto(string _photo);

	/**
	*	@brief	Set product date.
	*	@pre	none.
	*	@post	product date is set.
	*	@param	inDate	product date.
	*/
	void SetDate(int _date);

	/**
	*	@brief	Set product name.
	*	@pre	none.
	*	@post	product name is set.
	*	@param	inName	product name.
	*/
	void SetName(string _name);

	/**
	*	@brief	Set product amount.
	*	@pre	none.
	*	@post	product id is amount.
	*	@param	inAmount	product amount.
	*/
	void SetAmount(int _num);

	/**
	*	@brief	Set product container id.
	*	@pre	none.
	*	@post	product container id is set.
	*	@param	inId	product container id.
	*/
	void SetContainerID(int _cID);

	/**
	*	@brief	Set product storage id.
	*	@pre	none.
	*	@post	product storage id is set.
	*	@param	inId	product storage id.
	*/
	void SetStorageId(int _sID);

	/**
	*	@brief	Set product record.
	*	@pre	none.
	*	@post	product record is set.
	*	@param	product record.
	*/
	void SetRecord(int _id, string _kind, int _date, string _name, int _num, int _cID, int sID,string _photo);
	
	/**
	*	@brief	Set number of search the product.
	*	@pre	none.
	*	@post	numofsearch is set.
	*	@param	numofsearch.
	*/
	void SetNumOfSearch(int _search);




	//------- Set From Keyboard Function -------//

	/**
	*	@brief	Set product id from keyboard.
	*	@pre	none.
	*	@post	product id is set.
	*/
	void SetIdFromKB();

	/**
	*	@brief	Set product kind from keyboard.
	*	@pre	none.
	*	@post	product kind is set.
	*/
	void SetKindFromKB();

	/**
	*	@brief	Set product photo from keyboard.
	*	@pre	none.
	*	@post	product photo is set.
	*/
	void SetPhotoFromKB();

	/**
	*	@brief	Set product date from keyboard.
	*	@pre	none.
	*	@post	product date is set.
	*/
	void SetDateFromKB();

	/**
	*	@brief	Set product id from keyboard.
	*	@pre	none.
	*	@post	product id is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set product amount from keyboard.
	*	@pre	none.
	*	@post	product amount is set.
	*/
	void SetAmountFromKB();

	/**
	*	@brief	Set product container id from keyboard.
	*	@pre	none.
	*	@post	product container id is set.
	*/
	void SetContainerIDFromKB();

	/**
	*	@brief	Set product storage id from keyboard.
	*	@pre	none.
	*	@post	product storage id is set.
	*/
	void SetStorageIdFromKB();

	/**
	*	@brief	Set product record from keyboard.
	*	@pre	none.
	*	@post	product record is set.
	*/
	void SetRecordFromKB();

	//------- Set From Keyboard Function -------//

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
	bool operator==(const ItemType& _item);

	/*
	*	@brief	item id�� ���մϴ�.
	*	@pre	item id is set.
	*	@post	���� item id�� ũ�� ture,�׷��� ������ false
	*	@param	ItemType ����
	*/
	bool operator>(const ItemType& _item);

	/*
	*	@brief	item id�� ���մϴ�.
	*	@pre	item id is set.
	*	@post	���� item id�� ������ ture,�׷��� ������ false
	*	@param	ItemType ����
	*/
	bool operator<(const ItemType& _item);

	/*
	*	@brief	item ������ �����մϴ�.
	*	@pre	item record is set.
	*	@post	item ����Լ��� �� ������ ���Ե˴ϴ�.
	*	@param	ItemType ����
	*/
	void operator=(const ItemType& _item);

	// ostream<< �����ε�
	friend ostream& operator<<(ostream& os, const ItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tNAME   : " << _item.GetName() << endl;
		os << "\tKIND   : " << _item.GetKind() << endl;
		os << "\tDATE   : " << _item.GetDate() << endl;
		os << "\tAMOUNT   : " << _item.GetAmount() << endl;
		os << "\tPHOTO   : " << _item.GetPhoto() << endl;
		os << "\tSTORAGE ID  : " << _item.GetStorageId() << endl;
		os << "\tCONTAINER ID  : " << _item.GetContainerID() << endl;
		os << "\t�˻� Ƚ��  : " << _item.GetNumOfSearch() << endl;
		return os;
	}
};

