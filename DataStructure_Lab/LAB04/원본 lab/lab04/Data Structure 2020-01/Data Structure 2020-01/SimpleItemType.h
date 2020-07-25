#pragma once
class SimpleItemType
{
private:
	int id;
	string name;

public:
	SimpleItemType();
	~SimpleItemType();

	int GetId() const;
	string GetName() const;

	void SetId(int _id);
	void SetName(string _name);
	void SetRecord(int _id, string _name);

	void SetIdFromKB();
	void SetNameFromKB();
	void SetRecordFromKB();

	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);

	bool operator==(const SimpleItemType& _item) {
		if (id == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const SimpleItemType& _item) {
		if (id > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const SimpleItemType& _item) {
		if (id < _item.GetId())
			return true;
		return false;
	}
	void operator=(const SimpleItemType& _item) {
		id = _item.GetId();
		name = _item.GetName();
	}
	friend ostream& operator<<(ostream& os, const SimpleItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tName   : " << _item.GetName() << endl;
		return os;
	}

};

