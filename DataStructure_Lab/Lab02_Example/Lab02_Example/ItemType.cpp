#include "ItemType.h"

//constructor
ItemType::ItemType() {
	m_id = 0;
	m_sName = "";
	m_sAddress = "";
}
ItemType::~ItemType() {}

//Get Function
int ItemType::GetId() {
	return m_id;
}
string ItemType::GetName() {
	return m_sName;
}
string ItemType::GetAddress() {
	return m_sAddress;
}


//Set Function
void ItemType::SetId(int inid) {
	m_id = inid;
}
void ItemType::SetName(string inName) {
	m_sName = inName;
}
void ItemType::SetAddress(string inAddress) {
	m_sAddress = inAddress;
}
void ItemType::SetRecord(int inid, string inName, string inAddress) {
	SetId(inid);
	SetName(inName);
	SetAddress(inAddress);
}

//Display Function
void ItemType::DisplayIdOnScreen() {
	cout << "\tID : " << m_id << endl;
}
void ItemType::DisplayNameOnScreen() {
	cout << "\tNAME : " << m_sName << endl;
}
void ItemType::DisplayAddressOnScreen() {
	cout << "\tADDRESS : " << m_sAddress << endl;
}
void ItemType::DisplayRecordOnScreen() {
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayAddressOnScreen();
}

//Set Domain from keyboard
void ItemType::SetIdFromKB() {
	cout << "\tID : ";
	cin >> m_id;
}
void ItemType::SetNameFromKB() {
	cout << "\tName : ";
	cin >> m_sName;
}
void ItemType::SetAddressFromKB() {
	cout << "\tAddress : ";
	cin >> m_sAddress;
}
void ItemType::SetRecordFromKB() {
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}

//File system function
int ItemType::ReadDataFromFIle(ifstream& fin) {
	fin >> m_id;
	fin >> m_sName;
	fin >> m_sAddress;

	return 1;
}

int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_id << " ";
	fout << m_sName << " ";
	fout << m_sAddress << " ";
	fout << endl;

	return 1;
}

void ItemType::operator=(ItemType other) {
	m_id = other.GetId();
	m_sName = other.GetName();
	m_sAddress = other.GetAddress();
}


