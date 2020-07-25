#include "pch.h"
#include "ItemType.h"


ItemType::ItemType()
{
	m_id = -1;
	m_kind = -1;
	m_date = -1;
	m_name = "";
	m_amount = -1;
	m_containerId = -1;
}


ItemType::~ItemType()
{
}

int ItemType::GetId() const
{
	return m_id;
}

int ItemType::GetKind() const
{
	return m_kind;
}

int ItemType::GetDate() const
{
	return m_date;
}

string ItemType::GetName() const
{
	return m_name;
}

int ItemType::GetAmount() const
{
	return m_amount;
}

int ItemType::GetContainerID() const
{
	return m_containerId;
}

int ItemType::GetStorageId() const
{
	return m_storageId;
}

void ItemType::SetId(int _id)
{
	m_id = _id;
}

void ItemType::SetKind(int _kind)
{
	m_kind = _kind;
}

void ItemType::SetDate(int _date)
{
	m_date = _date;
}

void ItemType::SetName(string _name)
{
	m_name = _name;
}

void ItemType::SetAmount(int _num)
{
	m_amount = _num;
}

void ItemType::SetContainerID(int _cID)
{
	m_containerId = _cID;
}

void ItemType::SetStorageId(int _cID)
{
	m_storageId = _cID;
}

void ItemType::SetRecord(int _id, int _kind, int _date, string _name, int _num, int _cID, int sID)
{
	SetId(_id);
	SetKind(_kind);
	SetDate(_date);
	SetName(_name);
	SetAmount(_num);
	SetContainerID(_cID);
	SetStorageId(sID);
}

void ItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> m_id;
}

void ItemType::SetKindFromKB()
{
	cout << "\tKind(0~2) : ";
	cin >> m_kind;
}

void ItemType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_date;
}

void ItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_name;
}

void ItemType::SetAmountFromKB()
{
	cout << "\tAmount : ";
	cin >> m_amount;
}

void ItemType::SetContainerIDFromKB()
{
	cout << "\tContainerID : ";
	cin >> m_containerId;
}

void ItemType::SetStorageIdFromKB()
{
	cout << "\tStorage ID : ";
	cin >> m_storageId;
}

void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetStorageIdFromKB();
	SetContainerIDFromKB();
	SetNameFromKB();
	SetKindFromKB();
	SetDateFromKB();
	SetAmountFromKB();
	
}

int ItemType::ReadDataFromFile(ifstream & fin)
{
	fin >> m_id;
	fin >> m_kind;
	fin >> m_date;
	fin >> m_name;
	fin >> m_amount;
	fin >> m_storageId;
	fin >> m_containerId;
	return 1;
}

int ItemType::WriteDataToFile(ofstream & fout)
{
	fout << m_id << " ";
	fout << m_kind << " ";
	fout << m_date << " ";
	fout << m_name << " ";
	fout << m_amount << " ";
	fout << m_storageId << " ";
	fout << m_containerId << endl;

	return 1;
}