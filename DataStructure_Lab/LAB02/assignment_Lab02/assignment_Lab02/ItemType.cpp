#include "ItemType.h"

//constructor
ItemType::ItemType() {
	m_id = NULL;
	m_name = "";
	m_type = NULL;
	m_date = NULL;
	m_amount = NULL;
}
//destructor
ItemType::~ItemType(){}

//--------Get Function--------
int ItemType::GetId() {
	return m_id;
}
string ItemType::GetName() {
	return m_name;
}
int ItemType::GetType() {
	return m_type;
}
int ItemType::GetDate() {
	return m_date;
}
int ItemType::GetAmount() {
	return m_amount;
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

void ItemType::SetRecord(int inid, string inname, int intype, int indate, int inamount) {
	SetId(inid);
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

void ItemType::DisplayRecord() {
	DisplayId();
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

void ItemType::SetRecordFromKB() {
	SetIdFromKB();
	SetNameFromKB();
	SetTypeFromKB();
	SetDateFromKB();
	SetAmountFromKB();
}

//--------File System Function--------
void ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_id;
	fin >> m_name;
	fin >> m_type;
	fin >> m_date;
	fin >> m_amount;
}

//끝에 " "로 공백을 만들어야함. 나중에 fin할때 공백으로 구분해서 data 입력 받을 수 있음.
void ItemType::WriteDataToFile(ofstream& fout) {
	fout << endl;
	fout << m_id << " ";
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
