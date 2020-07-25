#pragma once
class StorageType
{
private:
	int								id;				///< storage id.
	int								currentNum;		///< current container number.
	int								maxNum;			///< max container number.
	SingleLinkedList<ContainerType>	ContainerList;	///< container list.

public:
	StorageType();
	StorageType(int maxnum);
	~StorageType();

	int GetId() const;
	int GetCurrentNum() const;
	int GetMaxNum() const;

	bool isFull();

	void GetContainer(ContainerType& _con);
	void AddContainer(ContainerType& _item);
	void DeleteContainer(ContainerType& _item);
	void UpdateContainer(ContainerType& _item);

	void DisplayAllContainer();
	void DisplayAllDetailsContainer(SortedList<ItemType>& ref);

	bool operator==(const StorageType& _item) {
		if (id == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const StorageType& _item) {
		if (id > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const StorageType& _item) {
		if (id < _item.GetId())
			return true;
		return false;
	}
	void operator=(StorageType& _item) {
		id = _item.GetId();
		currentNum = _item.GetCurrentNum();
		maxNum = _item.GetMaxNum();
		ContainerList = _item.ContainerList;
	}
};

