#pragma once



class ContainerType {
private:
	UnsortedList<SimpleItemType> itemList;
	UnsortedList<string> photoList;
	int m_containerID;
	string m_location;

public:
	ContainerType();
	~ContainerType();

	int GetId() const;
	void SetId(int inid);

	void SetIdFromKB();
	void SetLocFromKB();


	void AddItem(SimpleItemType& item);
	void DeleteItem(SimpleItemType& item);
	int UpdateItem(SimpleItemType& item);
	int AddPhoto(string& inData);
	int DeletePhoto(string& inData);
	int UpdatePhoto(string& inData);
	
	void DisplayContainerInfo();
	void DisplayAllItem();
	void DisplayAllInfo();
	void DisplayAllPhoto();
	int FindByName(SimpleItemType& data);
	int FindByUsage(SimpleItemType& data);

	int FindById(SimpleItemType& data);

	//--------Compare Function--------
	RelationType CompareID(ContainerType& data);

	bool operator>(ContainerType& _item) {
		if (m_containerID > _item.GetId())
			return true;
		return false;
	}
	bool operator<(ContainerType& _item) {
		if (m_containerID < _item.GetId())
			return true;
		return false;
	}

	bool operator==(ContainerType& data);

	void operator=(ContainerType& data);
};


