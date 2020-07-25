#include "pch.h"
#include "StorageType.h"

StorageType::StorageType()
{
}

StorageType::StorageType(int maxnum)
{
}

StorageType::~StorageType()
{
}

int StorageType::GetId() const
{
	return 0;
}

int StorageType::GetCurrentNum() const
{
	return 0;
}

int StorageType::GetMaxNum() const
{
	return 0;
}

bool StorageType::isFull()
{
	if (currentNum == maxNum)
		return true;
	return false;
}

void StorageType::GetContainer(ContainerType& _con)
{
}

void StorageType::AddContainer(ContainerType& _item)
{
}

void StorageType::DeleteContainer(ContainerType& _item)
{
}

void StorageType::UpdateContainer(ContainerType& _item)
{
}

void StorageType::DisplayAllContainer()
{
}

void StorageType::DisplayAllDetailsContainer(SortedList<ItemType>& ref)
{
}
