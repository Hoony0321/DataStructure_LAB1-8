#include "pch.h"
#include "ItemType.h"

//------- default - constructor -------//
ItemType::ItemType()
{
	m_id = -1;
	m_date = -1;
	m_amount = -1;
	m_containerId = -1;
	m_storageId = -1;
	m_numofsearch = 0;

	m_photo = "";
	m_name = "";
	m_kind = "";
}



//------- destructor -------//
ItemType::~ItemType()
{
}



//------- Get Function -------//
int ItemType::GetId() const
{
	return m_id;
}

string ItemType::GetKind() const
{
	return m_kind;
}

string ItemType::GetPhoto() const
{
	return m_photo;
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

int ItemType::GetNumOfSearch() const {
	return m_numofsearch;
}



//------- Set Function -------//
void ItemType::SetId(int _id)
{
	m_id = _id;
}

void ItemType::SetKind(string _kind)
{
	m_kind = _kind;
}

void ItemType::SetPhoto(string _photo)
{
	m_photo = _photo;
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

void ItemType::SetRecord(int _id, string _kind, int _date, string _name, int _num, int _cID, int sID,string _photo)
{
	SetId(_id);
	SetKind(_kind);
	SetDate(_date);
	SetName(_name);
	SetAmount(_num);
	SetContainerID(_cID);
	SetStorageId(sID);
	SetPhoto(_photo);
}

void ItemType::SetNumOfSearch(int _search) {
	m_numofsearch = _search;
}



//------- Set From Keyboard Function -------//
void ItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> m_id;
}

void ItemType::SetKindFromKB()
{
	cout << "\tKIND : ";
	cin >> m_kind;
}

void ItemType::SetDateFromKB()
{
	cout << "\tDATE : ";
	int DATE;
	cin >> DATE;
	if (to_string(DATE).size() != 8) {
		cout << "잘못된 DATE를 입력하셨습니다." << endl;
		cout << "기본값으로 설정된 20200101으로 입력됩니다." << endl;
		m_date = 20200101;
		return;
	}
	m_date = DATE;
}

void ItemType::SetNameFromKB()
{
	cout << "\tNAME : ";
	cin >> m_name;
}

void ItemType::SetAmountFromKB()
{
	cout << "\tAMOUNT : ";
	cin >> m_amount;
}

void ItemType::SetContainerIDFromKB()
{
	cout << "\tCONTAINER ID : ";
	cin >> m_containerId;
}

void ItemType::SetStorageIdFromKB()
{
	cout << "\tSTORAGE ID : ";
	cin >> m_storageId;
}

void ItemType::SetPhotoFromKB() {

	cout << "\tPHOTO : ";
	cin >> m_photo;
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
	SetPhotoFromKB();
	
	
}



//------- File System Function -------//
int ItemType::ReadDataFromFile(ifstream & fin)
{
	fin >> m_id;
	fin >> m_kind;
	fin >> m_date;
	fin >> m_name;
	fin >> m_amount;
	fin >> m_storageId;
	fin >> m_containerId;
	fin >> m_photo;
	fin >> m_numofsearch;
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
	fout << m_containerId << " ";
	fout << m_photo << " ";
	fout << m_numofsearch << endl;

	return 1;
}


//------- Operator Function -------//

bool ItemType::operator==(const ItemType& _item) {
	if (m_id == _item.GetId())
		return true;
	return false;
}
bool ItemType::operator>(const ItemType& _item) {
	if (m_id > _item.GetId())
		return true;
	return false;
}
bool ItemType::operator<(const ItemType& _item) {
	if (m_id < _item.GetId())
		return true;
	return false;
}
void ItemType::operator=(const ItemType& _item) {
	m_id = _item.GetId();
	m_kind = _item.GetKind();
	m_date = _item.GetDate();
	m_name = _item.GetName();
	m_amount = _item.GetAmount();
	m_containerId = _item.GetContainerID();
	m_storageId = _item.GetStorageId();
	m_numofsearch = _item.GetNumOfSearch();
	m_photo = _item.GetPhoto();
}

