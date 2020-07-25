#include "pch.h"
#include "ContainerType.h"

ContainerType::ContainerType()
{
	id = -1;
	position = "";
}

ContainerType::~ContainerType()
{
}

int ContainerType::GetId() const
{
	return id;
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
	cout << photoList << endl;
}

void ContainerType::DisplayAllsItem()
{
	cout << sItemList << endl;
}

void ContainerType::DisplayAllDetailsItem(SortedList<ItemType>& ref)
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
