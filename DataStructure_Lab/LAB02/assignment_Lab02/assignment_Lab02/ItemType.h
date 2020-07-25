#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//RelationType - primary key(ID) 비교 타입
enum RelationType{LESS,EQUAL,GREATER};

//ITEMTYPE 클래스 
class ItemType {

public:
	//constructor
	ItemType();
	//destructor
	~ItemType();

	//--------Get Function--------

	/**
	*	@pre	product id is set.
	*	@post	none.
	*	@return product id.
	*/
	int GetId();

	/**
	*	@pre	product name is set.
	*	@post	none.
	*	@return product name.
	*/
	string GetName();

	/**
	*	@pre	product type is set. only 1 or 2.
	*	@post	none.
	*	@return product type.
	*/
	int GetType();

	/**
	*	@pre	product date is set.
	*	@post	none.
	*	@return product date.
	*/
	int GetDate();

	/**
	*	@pre	product amount is set.
	*	@post	none.
	*	@return product amount.
	*/
	int GetAmount();

	//---------Set Function-----------

	/**
	*	@brief	Set product id.
	*	@pre	none.
	*	@post	product id is set.
	*	@param	inId	product id.
	*/
	void SetId(int Inid);

	/**
	*	@brief	Set product name.
	*	@pre	none.
	*	@post	product name is set.
	*	@param	inName	product name.
	*/
	void SetName(string InName);

	/**
	*	@brief	Set product type.
	*	@pre	none.
	*	@post	product type is set.
	*	@param	inType	product type.
	*/
	void SetType(int InType);

	/**
	*	@brief	Set product date.
	*	@pre	none.
	*	@post	product date is set.
	*	@param	inDate	product date.
	*/
	void SetDate(int InDate);

	/**
	*	@brief	Set product amount.
	*	@pre	none.
	*	@post	product id is amount.
	*	@param	inAmount	product amount.
	*/
	void SetAmount(int InAmount);

	/**
	*	@brief	Set product record.
	*	@pre	none.
	*	@post	product record is set.
	*	@param	product record.
	*/
	void SetRecord(int Inid, string InName, int InType, int InDate, int InAmount);

	//--------Display Function--------

	/**
	*	@brief	Display product id on screen.
	*	@pre	product id is set.
	*	@post	product id is on screen.
	*/
	void DisplayId();

	/**
	*	@brief	Display product name on screen.
	*	@pre	product name is set.
	*	@post	product name is on screen.
	*/
	void DisplayName();

	/**
	*	@brief	Display product type on screen.
	*	@pre	product type is set.
	*	@post	product type is on screen.
	*/
	void DisplayType();

	/**
		*	@brief	Display product date on screen.
		*	@pre	product date is set.
		*	@post	product date is on screen.
		*/
	void DisplayDate();

	/**
	*	@brief	Display product amount on screen.
	*	@pre	product amount is set.
	*	@post	product amount is on screen.
	*/
	void DisplayAmount();

	/**
	*	@brief	Display product record on screen.
	*	@pre	product record is set.
	*	@post	product record is on screen.
	*/
	void DisplayRecord();

	//--------Set from keyboard Function--------

	/**
	*	@brief	Set product id from keyboard.
	*	@pre	none.
	*	@post	product id is set.
	*/
	void SetIdFromKB();

	/**
	*	@brief	Set product id from keyboard.
	*	@pre	none.
	*	@post	product id is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set product type from keyboard.
	*	@pre	none.
	*	@post	product type is set.
	*/
	void SetTypeFromKB();

	/**
	*	@brief	Set product date from keyboard.
	*	@pre	none.
	*	@post	product date is set.
	*/
	void SetDateFromKB();

	/**
	*	@brief	Set product amount from keyboard.
	*	@pre	none.
	*	@post	product amount is set.
	*/
	void SetAmountFromKB();

	/**
	*	@brief	Set product record from keyboard.
	*	@pre	none.
	*	@post	product record is set.
	*/
	void SetRecordFromKB();

	//--------File system Function--------

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	prodcut record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void ReadDataFromFile(ifstream& fin);

	/**
*	@brief	Write a record into file.
*	@pre	the target file is opened. And the list should be initialized.
*	@post	the target file is included the new student record.
*	@param	fout	file descriptor.
*	@return	return 1 if this function works well, otherwise 0.
*/
	void WriteDataToFile(ofstream& fout);


	//--------Compare Function--------
	RelationType CompareID(ItemType& data);


private:
	int m_id;		///prodcut id
	string m_name;  ///product name
	int m_type;     ///product type - only 1 or 2.
	int m_date;     ///product date
	int m_amount;   ///product amount


};

#endif // !ITEMTYPE_H

