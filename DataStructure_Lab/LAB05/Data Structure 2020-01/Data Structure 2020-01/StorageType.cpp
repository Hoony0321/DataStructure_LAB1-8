#include "pch.h"
#include "StorageType.h"


StorageType::StorageType()
{
	id = -1;
	currentNum = 0;
	maxNum = MAXCONTAINER;

}


StorageType::StorageType(int maxnum)
{
	id = -1;
	currentNum = 0;
	maxNum = maxnum;
}


StorageType::~StorageType()
{
}


int StorageType::GetId() const
{
	return id;
}


int StorageType::GetCurrentNum() const
{
	return currentNum;
}


int StorageType::GetMaxNum() const
{
	return maxNum;
}


void StorageType::SetId(int _id) {
	id = _id;
}


void StorageType::SetIdFromKB() {
	cout << "\tStorage ID : ";
	cin >> id;
}

bool StorageType::isFull()
{
	if (currentNum == maxNum)
		return true;
	return false;
}

bool StorageType::isEmpty()
{
	if (currentNum == 0)
		return true;
	return false;
}

int StorageType::GetContainer(ContainerType& _con)
{
	if (ContainerList.Get(_con) == 1) return 1;
	else return 0;
}

void StorageType::AddContainer(ContainerType& _item)
{
	if (isFull()) {
		cout << "Storage is Full." << endl;
		return;
	}
	
	ContainerList.Add(_item);
	currentNum++;
}

void StorageType::DeleteContainer(ContainerType& _item)
{
	ContainerList.Delete(_item);
}

void StorageType::UpdateContainer(ContainerType& _item)
{
	ContainerList.Replace(_item);
}

void StorageType::DisplayAllContainer()
{
	ContainerType tmpContainer;
	ContainerList.ResetList();
	ContainerList.GetNextItem(tmpContainer);
	do {
		cout << "\t===== Container =====" << endl;
		cout << tmpContainer;
	} while (ContainerList.GetNextItem(tmpContainer) != 0);
	
}

void StorageType::DisplayAllContainer2()
{
	ContainerType tmpContainer;
	ContainerList.ResetList();
	ContainerList.GetNextItem(tmpContainer);
	do {
		tmpContainer.DisplayContainerInfo();
	} while (ContainerList.GetNextItem(tmpContainer) != 0);

}



void StorageType::DisplayAllDetailsContainer()
{
	ContainerType tmpContainer;
	ContainerList.ResetList();
	ContainerList.GetNextItem(tmpContainer);
	do {
		tmpContainer.DisplayDetailInfo();
	} while (ContainerList.GetNextItem(tmpContainer) != 0);
}

void StorageType::DisplayAllContainerID() {
	ContainerType tmpContainer;
	ContainerList.ResetList();
	ContainerList.GetNextItem(tmpContainer);
	do {
		cout << "\t=====  " << tmpContainer.GetId() << "  ====="<< endl;
		cout << endl;
	} while (ContainerList.GetNextItem(tmpContainer) != 0);
}



int StorageType::GetNextContainer(ContainerType& tmpContainer) {

	return ContainerList.GetNextItem(tmpContainer);

}

void StorageType::ResetList() {
	ContainerList.ResetList();
}

void StorageType::operator=(StorageType& _item) {
	id = _item.GetId();
	currentNum = _item.GetCurrentNum();
	maxNum = _item.GetMaxNum();
	ContainerList = _item.ContainerList;
}

bool StorageType::operator<(const StorageType& _item) {
	if (id < _item.GetId())
		return true;
	return false;
}

bool StorageType::operator>(const StorageType& _item) {
	if (id > _item.GetId())
		return true;
	return false;
}

bool StorageType::operator==(const StorageType& _item) {
	if (id == _item.GetId())
		return true;
	return false;
}
