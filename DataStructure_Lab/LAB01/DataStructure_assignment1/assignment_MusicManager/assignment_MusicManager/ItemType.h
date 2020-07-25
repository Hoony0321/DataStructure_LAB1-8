#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

enum RelationType {LESS,EQUAL,GREATER};

/**
*	item information class.
*/
class ItemType {

public:

	/**
	*	default constructor.
	*/
	ItemType() {
		m_song = "";
		m_composer = "";
		m_musician = "";
		m_genre = 0;
		m_number = -1;
	}

	/**
	*	destructor.
	*/
	~ItemType() {}

	/**
	*	@brief	Get Song name.
	*	@pre	Song name is set.
	*	@post	none.
	*	@return	Song name.
	*/
	string GetSong() const;

	// @brief  : Get Composer name.
	// @pre    : Composer name is set
	// @post   : none.
	// @return : Composer name.
	string GetComposer() const;

	// @brief  : Get Musician name.
	// @pre    : Musician name is set
	// @post   : none.
	// @return : Musician name.
	string GetMusician() const;

	// @brief  : Get Genre.
	// @pre    : Genre is set
	// @post   : none.
	// @return : Genre.
	int GetGenre() const;

	// @brief  : Get Music Number. This number is primary key
	// @pre    : Music Number is set
	// @post   : none.
	// @return : Music Number.
	int GetNum() const;

	/**
	*	@brief	Set song name.
	*	@pre	none.
	*	@post	Song name is set.
	*	@parameter :Song name. string value.
	*/
	void SetSong(string inSong);

	// @brief  : Set composer name.
	// @pre    : none.
	// @post   : composer name is set.
	// @parameter : composer name. string value.
	void SetComposer(string inComposer);

	// @brief  : Set Musician name.
	// @pre    : none.
	// @post   : Musician name is set.
	// @parameter : Musician name. string value.
	void SetMusician(string inMusician);

	// @brief  : Set genre.
	// @pre    : none.
	// @post   : genre is set.
	// @parameter : Just 1 or 2 (1 : genre = ∞°ø‰ , 2 : genre = ø¨¡÷∞Ó)
	void SetGenre(int inGenre);

	// @brief  : Set music number.
	// @pre    : none.
	// @post   : music number is set.
	// @parameter : music number. int value.
	void SetNumber(int inNum);

	/**
	*	@brief	Set Music record.
	*	@pre	none.
	*	@post   Music record is set.
	*	@param	inSong	Song name. string value.
	*	@param	inComposer	Composer name. string value.
	*	@param	inGenre	Just 1 or 2 (1 : genre = ∞°ø‰ , 2 : genre = ø¨¡÷∞Ó)
	*	@param	inNum	music number. int value.
	*	@param	inMusician	Musician name. string value.
	*/
	void SetRecord(string inSong, string inComposer, int inGenre, int inNum, string inMusician);

	/**
	*	@brief	Display music number on screen.
	*	@pre	music number is set.
	*	@post	music number is on screen.
	*/
	void DisplayNumOnScreen();

	/**
	*	@brief	Display music number on screen.
	*	@pre	music number is set.
	*	@post	music number is on screen.
	*/
	void DisplaySongOnScreen();

	/**
	*	@brief	Display composer name on screen.
	*	@pre	composer name is set.
	*	@post	composer name is on screen.
	*/
	void DisplayComposerOnScreen();

	/**
	*	@brief	Display musician name on screen.
	*	@pre	musician name is set.
	*	@post	musician name is on screen.
	*/
	void DisplayMusicianOnScreen();

	/**
	*	@brief	Display genre on screen.
	*	@pre	genre is set.
	*	@post	genre is on screen.
	*/
	void DisplayGenreOnScreen();

	/**
	*	@brief	Display music record on screen.
	*	@pre	music record is set.
	*	@post	music record is on screen.
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief	Set music number from keyboard.
	*	@pre	int value.
	*	@post	music number is set.
	*/
	void SetNumFromKB();

	/**
	*	@brief	Set song name from keyboard.
	*	@pre	string value.
	*	@post	song name is set.
	*/
	void SetSongFromKB();

	/**
	*	@brief	Set composer name from keyboard.
	*	@pre	string value.
	*	@post	composer name is set.
	*/
	void SetComposerFromKB();

	/**
	*	@brief	Set musician name from keyboard.
	*	@pre	string value.
	*	@post	musician name is set.
	*/
	void SetMusicianFromKB();

	/**
	*	@brief	Set genre from keyboard.
	*	@pre	Just 1 or 2 ( 1 : genre = ∞°ø‰, 2 : genre = ø¨¡÷∞Ó )
	*	@post	genre is set.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Set music record from keyboard.
	*	@pre	none.
	*	@post	music record is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	music record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new music record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	@brief	Compare the primary keys(music number) of the two items.
	*	@pre	the target item has music number.
	*	@post	none.
	*	@param	ItemType value.
	*	@return	return true if this primary key is same, otherwise false.
	*/
	bool operator==(const ItemType& A);

	/**
	*	@brief	Input  member variable of the other item
	*	@pre	none.
	*	@post   The member variable of the item on the left changes to the member variable of the item on the right.
	*	@param	ItemType value.
	*	@return	none.
	*/
	void operator=(const ItemType& _item);

	RelationType CompareByID(const ItemType& data);

protected:
	string m_song;        /// song name.
	string m_composer;    /// composer name.
	string m_musician;    /// musician name.
	int m_genre;          /// music genre.
	int m_number;         /// music number.

};




#endif // !_ITEMTYPE_H

