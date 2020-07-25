#include "pch.h"
#include "SimpleItemType.h"

SimpleItemType::SimpleItemType()
{
	id = -1;
	name = "";
}

SimpleItemType::~SimpleItemType()
{
}

int SimpleItemType::GetId() const
{
	return id;
}

string SimpleItemType::GetName() const
{
	return name;
}

void SimpleItemType::SetId(int _id)
{
	id = _id;
}

void SimpleItemType::SetName(string _name)
{
	name = _name;
}

void SimpleItemType::SetRecord(int _id, string _name)
{
	SetId(_id);
	SetName(_name);
}

void SimpleItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> id;
}

void SimpleItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> name;
}

void SimpleItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
}

int SimpleItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> id;
	fin >> name;

	return 1;
}

int SimpleItemType::WriteDataToFile(ofstream& fout)
{
	fout << id << " ";
	fout << name << endl;

	return 1;
}
