#pragma once
class ContainerType : public Base
{
private:
	int								id;
	string							position;
	UnsortedList<SimpleItemType>	sItemList;
	UnsortedList<string>			photoList;

public:
	ContainerType();
	~ContainerType();

	int GetId() const;
	string GetPosition() const;
	void SetId(int _id);
	void SetPosition(string _name);

	void SetIdFromKB();
	void SetPositionFromKB();
	void SetRecordFromKB();

	int GetsItem(SimpleItemType& _item);
	void AddsItem(SimpleItemType& _item);
	void DeletesItem(SimpleItemType& _item);
	void UpdatesItem(SimpleItemType& _item);

	void AddPhoto(string photo);
	void DeletePhoto(string photo);

	void DisplayContainerInfo();
	void DisplayAllPhoto();
	void DisplayAllsItem();
	void DisplayAllDetailsItem(SortedList<ItemType>& ref);


	bool operator==(const ContainerType& _item) {
		if (id == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const ContainerType& _item) {
		if (id > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const ContainerType& _item) {
		if (id < _item.GetId())
			return true;
		return false;
	}
	void operator=(const ContainerType& _item) {
		id = _item.GetId();
		position = _item.GetPosition();
		sItemList = _item.sItemList;
		photoList = _item.photoList;
	}
	friend ostream& operator<<(ostream& os, const ContainerType& _item) {
		os << "\tContainer ID : " << _item.id << endl;
		os << "\tPosition  : " << _item.position << endl;
		os << "\t===== PhotoList ====" << endl;
		os << _item.photoList << endl;
		os << "\t===== ItemList ====" << endl;
		os << _item.sItemList << endl;
		return os;
	}

	void DisplayDetailInfo() {
		SimpleItemType tmpSimpleItem;
		ItemType tmpItem;
		cout << "\tContainer ID : " << id << endl;
		cout << "\tPosition  : " << position << endl;
		cout << "\t===== PhotoList ====" << endl;
		cout << photoList << endl;
		cout << "\t===== ItemList ====" << endl;
		while (sItemList.GetNextItem(tmpSimpleItem) != -1) {
			tmpItem.SetId(tmpSimpleItem.GetId());
			MasterList.GetByBinarySearch(tmpItem);
			cout << tmpItem << endl;
		}
	}
};

