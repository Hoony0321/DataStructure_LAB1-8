#include "pch.h"
#include "ItemType.h"

//constructor
ItemType::ItemType() {
	m_id = 0;
	m_name = "";
	m_type = 0;
	m_date = 0;
	m_amount = 0;
	m_containerId = -1;
}
//destructor
ItemType::~ItemType(){}

//--------Get Function--------
int ItemType::GetId() const{
	return m_id;
}
string ItemType::GetName() const{
	return m_name;
}
int ItemType::GetType() const{
	return m_type;
}
int ItemType::GetDate() const{
	return m_date;
}
int ItemType::GetAmount() const{
	return m_amount;
}
int ItemType::GetContainerId() const {
	return m_containerId;
}

//--------Set Function--------
void ItemType::SetId(int Inid) {
	m_id = Inid;
}
void ItemType::SetName(string InName) {
	m_name = InName;
}
void ItemType::SetType(int InType) {
	m_type = InType;
}
void ItemType::SetDate(int InDate) {
	m_date = InDate;
}
void ItemType::SetAmount(int InAmount) {
	m_amount = InAmount;
}
void ItemType::SetContainerId(int Inid) {
	m_containerId = Inid;
}


void ItemType::SetRecord(int inid, string inname, int intype, int indate, int inamount, int containerId) {
	SetId(inid);
	SetContainerId(containerId);
	SetName(inname);
	SetType(intype);
	SetDate(indate);
	SetAmount(inamount);

}

//--------Display Function--------
void ItemType::DisplayId() {
	cout << "\tID : " << m_id << endl;
}
void ItemType::DisplayName() {
	cout << "\tNAME : " << m_name << endl;
}
void ItemType::DisplayType() {
	cout << "\tTYPE : " << m_type << endl;
}
void ItemType::DisplayDate() {
	cout << "\tDATE : " << m_date << endl;
}
void ItemType::DisplayAmount() {
	cout << "\tAMOUNT : " << m_amount << endl;
}
void ItemType::DisplayContainerId() {
	cout << "\tCONTAINER_ID : " << m_containerId << endl;
}

void ItemType::DisplayRecord() {
	DisplayId();
	DisplayContainerId();
	DisplayName();
	DisplayType();
	DisplayDate();
	DisplayAmount();
	cout << endl;
}

//--------Set member variable from keyboard Function--------
void ItemType::SetIdFromKB() {
	cout << "\tINPUT ID : ";
	cin >> m_id;
}
void ItemType::SetNameFromKB() {
	cout << "\tINPUT NAME : ";
	cin >> m_name;
}
void ItemType::SetTypeFromKB() {
	cout << "\tINPUT TYPE : ";
	cin >> m_type;
}
void ItemType::SetDateFromKB() {
	cout << "\tINPUT DATE : ";
	cin >> m_date;
}
void ItemType::SetAmountFromKB() {
	cout << "\tINPUT AMOUNT : ";
	cin >> m_amount;
}
void ItemType::SetContainerIdFromKB() {
	cout << "\tINPUT CONTAINER_ID : ";
	cin >> m_containerId;
}

void ItemType::SetRecordFromKB() {
	SetIdFromKB();
	SetContainerIdFromKB();
	SetNameFromKB();
	SetTypeFromKB();
	SetDateFromKB();
	SetAmountFromKB();
}

void ItemType::SetRecordFromKB_NoContainerID() {
	SetIdFromKB();
	SetNameFromKB();
	SetTypeFromKB();
	SetDateFromKB();
	SetAmountFromKB();
}

//--------File System Function--------
void ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_id;
	fin >> m_containerId;
	fin >> m_name;
	fin >> m_type;
	fin >> m_date;
	fin >> m_amount;
}

//끝에 " "로 공백을 만들어야함. 나중에 fin할때 공백으로 구분해서 data 입력 받을 수 있음.
void ItemType::WriteDataToFile(ofstream& fout) {
	fout << endl;
	fout << m_id << " ";
	fout << m_containerId << " ";
	fout << m_name << " ";
	fout << m_type << " ";
	fout << m_date << " ";
	fout << m_amount;
}

//--------Compare Function--------
//ID를 기준으로 크진 작은지 RelationType으로 return.
RelationType ItemType::CompareID(ItemType& data) {
	if (m_id > data.GetId()) return GREATER;
	else if (m_id == data.GetId()) return EQUAL;
	else return LESS;
}


bool ItemType::operator==(ItemType& other) {
	if (this->m_id == other.GetId()) return true;
	else return false;
}