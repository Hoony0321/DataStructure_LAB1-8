#include "pch.h"
#include "SimpleItemType.h"

//------- default-constructor -------//
SimpleItemType::SimpleItemType()
{
	id = -1;
	name = "";
}

//-------destructor -------//
SimpleItemType::~SimpleItemType()
{
}

//------- Get Function -------//
int SimpleItemType::GetId() const
{
	return id;
}

string SimpleItemType::GetName() const
{
	return name;
}

//------- Set Function -------//
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

//------- Set From Keyboard Function -------//
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

//------- File System Function -------//
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

//------- Operator Function -------//
bool SimpleItemType::operator==(const SimpleItemType& _item) {
	if (id == _item.GetId())
		return true;
	return false;
}

bool SimpleItemType::operator>(const SimpleItemType& _item) {
	if (id > _item.GetId())
		return true;
	return false;
}

bool SimpleItemType::operator<(const SimpleItemType& _item) {
	if (id < _item.GetId())
		return true;
	return false;
}

void SimpleItemType::operator=(const SimpleItemType& _item) {
	id = _item.GetId();
	name = _item.GetName();
}