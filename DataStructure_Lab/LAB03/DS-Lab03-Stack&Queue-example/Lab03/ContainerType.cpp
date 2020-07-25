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
	cout << endl;
}

void ContainerType::DisplayAllItem() {
	itemList.ResetList();
	SimpleItemType data;
	while (itemList.GetNextItem(data) != -1) {
		data.DisplayRecord();
	}
}
void ContainerType::DisplayAllPhoto() {
	string inData;
	photoList.ResetList();
	while (photoList.GetNextItem(inData) != -1) {
		cout << "Photo : " << inData << endl;
	}
}

int ContainerType::FindById(SimpleItemType& data) {
	if (itemList.Get(data)) return 1;
	else return 0;
}
void ContainerType::FindByName() {
	//나중에
}
void ContainerType::FindByUsage() {
	//나중에
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