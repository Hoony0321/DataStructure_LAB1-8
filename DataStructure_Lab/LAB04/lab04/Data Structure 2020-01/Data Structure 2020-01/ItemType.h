#pragma once
class ItemType
{
private:
	int m_id;		///prodcut id
	int m_storageId;  //storageId
	int m_containerId; // container id
	
	string m_name;  ///product name
	int m_kind;     ///product type - only 1 or 2.
	int m_date;     ///product date
	int m_amount;   ///product amount

public:
	ItemType();
	~ItemType();

	int GetId() const;
	int GetContainerID() const;
	string GetName() const;
	int GetKind() const;
	int GetDate() const;
	int GetAmount() const;
	int GetStorageId() const;
	

	void SetId(int _id);
	void SetKind(int _kind);
	void SetDate(int _date);
	void SetName(string _name);
	void SetAmount(int _num);
	void SetContainerID(int _cID);
	void SetStorageId(int _sID);
	void SetRecord(int _id, int _kind, int _date, string _name, int _num, int _cID, int sID);

	void SetIdFromKB();
	void SetKindFromKB();
	void SetDateFromKB();
	void SetNameFromKB();
	void SetAmountFromKB();
	void SetContainerIDFromKB();
	void SetStorageIdFromKB();
	void SetRecordFromKB();

	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);

	bool operator==(const ItemType& _item) {
		if (m_id == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const ItemType& _item) {
		if (m_id > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const ItemType& _item) {
		if (m_id < _item.GetId())
			return true;
		return false;
	}
	void operator=(const ItemType& _item) {
		m_id = _item.GetId();
		m_kind = _item.GetKind();
		m_date = _item.GetDate();
		m_name = _item.GetName();
		m_amount = _item.GetAmount();
		m_containerId = _item.GetContainerID();
		m_storageId = _item.GetStorageId();
	}
	friend ostream& operator<<(ostream& os, const ItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tName   : " << _item.GetName() << endl;
		os << "\tKind   : " << _item.GetKind() << endl;
		os << "\tDate   : " << _item.GetDate() << endl;
		os << "\tAmount   : " << _item.GetAmount() << endl;
		os << "\tStorage ID  : " << _item.GetStorageId() << endl;
		os << "\tContainer ID  : " << _item.GetContainerID() << endl;
		return os;
	}
};

