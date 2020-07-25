#include "pch.h"
#include "PlayItemType.h"


PlayItemType::PlayItemType()
{
	id = -1;
	numPlay = 0;
	inTime = -1;
}


PlayItemType::~PlayItemType()
{
}

int PlayItemType::GetId() const
{
	return id;
}

int PlayItemType::GetNumPlay() const
{
	return numPlay;
}

int PlayItemType::GetInTime() const
{
	return inTime;
}

void PlayItemType::SetId(int _id)
{
	id = _id;
}

void PlayItemType::SetNumPlay(int _numPlay)
{
	numPlay = _numPlay;
}

void PlayItemType::SetInTime(int _inTime)
{
	inTime = _inTime;
}

void PlayItemType::SetRecord(int _id, int _numPlay, int _inTime)
{
	SetId(_id);
	SetNumPlay(_numPlay);
	SetInTime(_inTime);
}

void PlayItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> id;
}

void PlayItemType::SetNumPlayFromKB()
{
	cout << "\tPlay Num : ";
	cin >> numPlay;
}

void PlayItemType::SetInTimeFromKB()
{
	cout << "\tIn Time : ";
	cin >> inTime;
}

void PlayItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNumPlayFromKB();
	SetInTimeFromKB();
}

int PlayItemType::ReadDataFromFile(ifstream & fin)
{
	fin >> id;
	fin >> numPlay;
	fin >> inTime;

	return 1;
}

int PlayItemType::WriteDataToFile(ofstream & fout)
{
	fout << id << " ";
	fout << numPlay << " ";
	fout << inTime;
	fout << endl;

	return 1;
}