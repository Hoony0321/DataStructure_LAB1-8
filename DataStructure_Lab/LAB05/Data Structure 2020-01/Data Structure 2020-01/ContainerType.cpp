#include "pch.h"
#include "ContainerType.h"

ContainerType::ContainerType()
{
	id = -1;
	position = "NULL";
}

ContainerType::~ContainerType()
{
}

int ContainerType::GetId() const
{
	return id;
}

int ContainerType::GetNumOfItems()
{
	return sItemList.GetLength();
}

string ContainerType::GetPosition() const
{
	return position;
}

void ContainerType::SetId(int _id)
{
	id = _id;
}

void ContainerType::SetPosition(string _name)
{
	position = _name;
}

void ContainerType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> id;
}

void ContainerType::SetPositionFromKB()
{
	cout << "\tPosition : ";
	cin >> position;
}

void ContainerType::SetRecordFromKB()
{
	SetIdFromKB();
	SetPositionFromKB();
}

int ContainerType::GetsItem(SimpleItemType& _item) {
	if (sItemList.Get(_item) == 1) return 1;
	else return 0;
}

void ContainerType::AddsItem(SimpleItemType& _item)
{
	sItemList.Add(_item);
}

void ContainerType::DeletesItem(SimpleItemType& _item)
{
	
	sItemList.Delete(_item);

}

void ContainerType::UpdatesItem(SimpleItemType& _item)
{
	sItemList.Replace(_item);
}

void ContainerType::AddPhoto(string photo)
{
	photoList.Add(photo);
}

void ContainerType::DeletePhoto(string photo)
{
	photoList.Delete(photo);
}

void ContainerType::DisplayAllPhoto()
{
	if (photoList.GetLength() == 0) {
		cout << "\t EMPTY " << endl;
		return;
	}
	string tmpPhoto;
	photoList.ResetList();
	while (photoList.GetNextItem(tmpPhoto) != -1) {
		cout << "\t" + tmpPhoto << endl;
	}
	
}

void ContainerType::DisplayAllsItem()
{
	cout << sItemList << endl;
}

void ContainerType::DisplayAllsItemName()
{
	SimpleItemType tmpItem;
	while (sItemList.GetNextItem(tmpItem) != -1) {
		cout << "\t"<<tmpItem.GetName() << endl;
		cout << "\t" << tmpItem.GetId() << endl;
		cout << endl;
	}
}

void ContainerType::DisplayAllDetailsItem(DoublySortedLinkedList<ItemType>& ref)
{
	SimpleItemType tmpItem;
	sItemList.ResetList();
	while(sItemList.GetNextItem(tmpItem) != -1) {
		ItemType detail;
		detail.SetId(tmpItem.GetId());
		ref.Get(detail);
		cout << detail;
	}
}

void ContainerType::DisplayContainerInfo() {
	cout << "\tContainer ID : " << id << endl;
	cout << "\tLocation : " << position << endl;
}

void ContainerType::DisplayDetailInfo() {
	SimpleItemType tmpSimpleItem;
	ItemType tmpItem;
	cout << "\tContainer ID : " << id << endl;
	cout << "\tPosition  : " << position << endl;
	cout << "\t===== PhotoList ====" << endl;
	DisplayAllPhoto();
	cout << "\t===== ItemList ====" << endl;
	while (sItemList.GetNextItem(tmpSimpleItem) != -1) {
		tmpItem.SetId(tmpSimpleItem.GetId());
		MasterList.Get(tmpItem);
		cout << tmpItem << endl;
	}
}

//-------OPERATOR FUNCTION-------//
bool ContainerType::operator==(const ContainerType& _item) {
	if (id == _item.GetId())
		return true;
	return false;
}

bool ContainerType::operator>(const ContainerType& _item) {
	if (id > _item.GetId())
		return true;
	return false;
}

bool ContainerType::operator<(const ContainerType& _item) {
	if (id < _item.GetId())
		return true;
	return false;
}

void ContainerType::operator=(const ContainerType& _item) {
	id = _item.GetId();
	position = _item.GetPosition();
	sItemList = _item.sItemList;
	photoList = _item.photoList;
}
