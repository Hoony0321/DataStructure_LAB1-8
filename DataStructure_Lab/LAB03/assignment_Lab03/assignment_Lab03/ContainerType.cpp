#include "pch.h"
#include "ContainerType.h"

ContainerType::ContainerType() {
	m_containerID = NULL;
	m_location = "";
}

ContainerType::~ContainerType(){
}

void ContainerType::AddItem(SimpleItemType& item) {
	if (itemList.IsFull()) {
		cout << "\t Container is full." << endl;
	}
	else {
		SetId(item.GetContainerId());
		itemList.Add(item);
	}
	
}
void ContainerType::DeleteItem(SimpleItemType& Item) {
	if (itemList.IsEmpty()) {
		cout << "\t Container is empty." << endl;
	}
	else {
		itemList.Delete(Item);
	}
	
}
int ContainerType::UpdateItem(SimpleItemType& Item) {
	if (itemList.Replace(Item)) return 1;
	return 0;


}
int ContainerType::AddPhoto(string& inData) {
	if (photoList.IsFull()) return 0;
	photoList.Add(inData);

}
int ContainerType::DeletePhoto(string& inData) {
	if (photoList.IsEmpty()) return 0;
	photoList.Delete(inData);
	return 1;
}
int ContainerType::UpdatePhoto(string& inData) {
	if (photoList.Replace(inData)) return 1;
	return 0;
}

void ContainerType::DisplayContainerInfo() {
	cout << "\t Container_Id : " << m_containerID << endl;
	cout << "\t Container_Location : " << m_location << endl;
}

void ContainerType::DisplayAllItem() {
	itemList.ResetList();
	SimpleItemType data;
	if (itemList.GetLength() == 0) {
		cout << "\t NOTHING " << endl;
	}
	while (itemList.GetNextItem(data) != -1) {
		data.DisplayRecord();
	}
}

void ContainerType::DisplayAllInfo() {
	cout << endl;
	cout << "\t===== CONTAINER INFO =====" << endl;
	DisplayContainerInfo();
	cout << "\t===== PHOTO LIST ======" << endl;
	DisplayAllPhoto();
	cout << "\t===== ITEM LIST ======" << endl;
	DisplayAllItem();
	cout << endl;
}
void ContainerType::DisplayAllPhoto() {
	string inData;
	photoList.ResetList();
	if (photoList.GetLength() == 0) {
		cout << "\t NOTHING " << endl;
	}
	while (photoList.GetNextItem(inData) != -1) {
		cout << "\tPhoto : " << inData << endl;
	}
}

int ContainerType::FindById(SimpleItemType& data) {
	if (itemList.Get(data)) return 1;
	else return 0;
}
int ContainerType::FindByName(SimpleItemType& data) {
	SimpleItemType item;
	int result = 0;

	itemList.ResetList();
	while (itemList.GetNextItem(item) != -1) {
		if (item.GetName().find(data.GetName()) != -1) {
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			cout << "\tCONTAINER ID : " << item.GetContainerId() << endl;
			item.DisplayRecord();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;

	
}
int ContainerType::FindByUsage(SimpleItemType& data) {
	SimpleItemType item;
	int result = 0;

	itemList.ResetList();
	while (itemList.GetNextItem(item) != -1) {
		if (item.GetType() == data.GetType()) {
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			cout << "\tCONTAINER ID : " << item.GetContainerId() << endl;
			item.DisplayRecord();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

int ContainerType::GetId() const {
	return m_containerID;
}

void ContainerType::SetId(int inid) {
	m_containerID = inid;
}

void ContainerType::SetIdFromKB() {
	cout << "\tContainerId : ";
	cin >> m_containerID;
}

void ContainerType::SetLocFromKB() {
	cout << "\tLocation : ";
	cin >> m_location;;
}


//나중에
RelationType ContainerType::CompareID(ContainerType& data) {
	if (m_containerID > data.GetId()) return GREATER;
	else if (m_containerID == data.GetId()) return EQUAL;
	else return LESS;
}

bool ContainerType::operator==(ContainerType& data) {
	if (m_containerID == data.GetId()) return true;
	else return false;
}

void ContainerType::operator=(ContainerType& data) {
	itemList = data.itemList;
	photoList = data.photoList;
	m_containerID = data.m_containerID;
	m_location = data.m_location;
}