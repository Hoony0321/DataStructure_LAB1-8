#include "pch.h"
#include "ItemType.h"


ItemType::ItemType()
{
	id = -1;
	kind = ex1;
	date = "";
	name = "";
	num = -1;
	containerID = -1;
}


ItemType::~ItemType()
{
}

int ItemType::GetId() const
{
	return id;
}

ITEMKIND ItemType::GetKind() const
{
	return kind;
}

string ItemType::GetDate() const
{
	return date;
}

string ItemType::GetName() const
{
	return name;
}

int ItemType::GetNum() const
{
	return num;
}

int ItemType::GetContainerID() const
{
	return containerID;
}

void ItemType::SetId(int _id)
{
	id = _id;
}

void ItemType::SetKind(ITEMKIND _kind)
{
	kind = _kind;
}

void ItemType::SetDate(string _date)
{
	date = _date;
}

void ItemType::SetName(string _name)
{
	name = _name;
}

void ItemType::SetNum(int _num)
{
	num = _num;
}

void ItemType::SetContainerID(int _cID)
{
	containerID = _cID;
}

void ItemType::SetRecord(int _id, ITEMKIND _kind, string _date, string _name, int _num, int _cID)
{
	SetId(_id);
	SetKind(_kind);
	SetDate(_date);
	SetName(_name);
	SetNum(_num);
	SetContainerID(_cID);
}

void ItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> id;
}

void ItemType::SetKindFromKB()
{
	cout << "\tKind(0~2) : ";
	int tmp;
	cin >> tmp;
	kind = (ITEMKIND)tmp;
}

void ItemType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> date;
}

void ItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> name;
}

void ItemType::SetNumFromKB()
{
	cout << "\tNum : ";
	cin >> num;
}

void ItemType::SetContainerIDFromKB()
{
	cout << "\tContainerID : ";
	cin >> containerID;
}

void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetKindFromKB();
	SetDateFromKB();
	SetNameFromKB();
	SetNumFromKB();
	SetContainerIDFromKB();
}

int ItemType::ReadDataFromFile(ifstream & fin)
{
	fin >> id;
	int tmp;
	fin >> tmp;
	kind = (ITEMKIND)tmp;
	fin >> date;
	fin >> name;
	fin >> num;
	fin >> containerID;

	return 1;
}

int ItemType::WriteDataToFile(ofstream & fout)
{
	fout << id << " ";
	fout << kind << " ";
	fout << date << " ";
	fout << name << " ";
	fout << num << " ";
	fout << containerID << endl;

	return 1;
}