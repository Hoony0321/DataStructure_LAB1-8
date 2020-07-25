#include "pch.h"
#include "ItemType.h"


ItemType::ItemType()
{
	id = -1;
	name = "";
	singer = "";
	genre = -1;
}


ItemType::~ItemType()
{
}

int ItemType::GetId() const
{
	return id;
}

string ItemType::GetName() const
{
	return name;
}

string ItemType::GetSinger() const
{
	return singer;
}

int ItemType::GetGenre() const
{
	return genre;
}

void ItemType::SetId(int _id)
{
	id = _id;
}

void ItemType::SetName(string _name)
{
	name = _name;
}

void ItemType::SetSinger(string _singer)
{
	singer = _singer;
}

void ItemType::SetGenre(int _genre)
{
	genre = _genre;
}

void ItemType::SetRecord(int _id, string _name, string _singer, int _genre)
{
	SetId(_id);
	SetName(_name);
	SetSinger(_singer);
	SetGenre(_genre);
}

void ItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> id;
}

void ItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> name;
}

void ItemType::SetSingerFromKB()
{
	cout << "\tSinger : ";
	cin >> singer;
}

void ItemType::SetGenreFromKB()
{
	cout << "\tGenre : ";
	cin >> genre;
}

void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetSingerFromKB();
	SetGenreFromKB();
}

int ItemType::ReadDataFromFile(ifstream & fin)
{
	fin >> id;
	fin >> name;
	fin >> singer;
	fin >> genre;

	return 1;
}

int ItemType::WriteDataToFile(ofstream & fout)
{
	fout << id << " ";
	fout << name << " ";
	fout << singer << " ";
	fout << genre;
	fout << endl;

	return 1;
}

void ItemType::DisplayIdOnScreen()
{
	cout << "\tID : " << id << endl;
}

void ItemType::DisplayNameOnScreen()
{
	cout << "\tName : " << name << endl;
}

void ItemType::DisplaySingerOnScreen()
{
	cout << "\tSinger : " << singer << endl;
}

void ItemType::DisplayGenreOnScreen()
{
	cout << "\tGenre : " << genre << endl;
}

void ItemType::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplaySingerOnScreen();
	DisplayGenreOnScreen();
}
