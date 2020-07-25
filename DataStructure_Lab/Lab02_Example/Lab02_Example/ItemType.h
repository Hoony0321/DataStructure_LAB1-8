#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

enum RelationType {LESS, GREATER, EQUAL};

class ItemType {
public:
	ItemType();
	~ItemType();

	//return domain
	int GetId();
	string GetName();
	string GetAddress();

	//set record
	void SetId(int inid);
	void SetName(string inName);
	void SetAddress(string inAddress);
	void SetRecord(int inid, string inName, string inAddress);

	//display record
	void DisplayIdOnScreen();
	void DisplayNameOnScreen();
	void DisplayAddressOnScreen();
	void DisplayRecordOnScreen();

	//set domain from keyboard
	void SetIdFromKB();
	void SetNameFromKB();
	void SetAddressFromKB();
	void SetRecordFromKB();

	//using file system
	int ReadDataFromFIle(ifstream& fin);
	int WriteDataToFile(ofstream& fout);

	//later
	RelationType CompareByID(const ItemType& data);

	//operator
	void operator=(ItemType other);



private:
	int m_id;
	string m_sName;
	string m_sAddress;

};

#endif // !ITEMTYPE_H

