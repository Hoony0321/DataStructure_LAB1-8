#pragma once
class ContainerType
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

	void AddsItem(SimpleItemType& _item);
	void DeletesItem(SimpleItemType& _item);
	void UpdatesItem(SimpleItemType& _item);

	void AddPhoto(string photo);
	void DeletePhoto(string photo);

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
		os << "Container ID : " << _item.id << endl;
		os << "Position		: " << _item.position << endl;
		os << "ItemList		: " << endl;
		os << _item.sItemList << endl;
		return os;
	}
};

