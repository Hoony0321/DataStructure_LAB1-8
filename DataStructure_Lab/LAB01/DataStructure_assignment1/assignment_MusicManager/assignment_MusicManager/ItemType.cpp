#include "ItemType.h"


string ItemType::GetSong() const {
	return m_song;
}

string ItemType::GetComposer() const {
	return m_composer;
}

string ItemType::GetMusician() const {
	return m_musician;
}

int ItemType::GetGenre() const {
	return m_genre;
}

int ItemType::GetNum() const {
	return m_number;
}

void ItemType::SetSong(string inSong) {
	m_song = inSong;
}

void ItemType::SetComposer(string inComposer) {
	m_composer = inComposer;
}

void ItemType::SetMusician(string inMusician) {
	m_musician = inMusician;
}

void ItemType::SetGenre(int inGenre) {
	m_genre = inGenre;
}

void ItemType::SetNumber(int inNum) {
	m_number = inNum;
}

void ItemType::SetRecord(string inSong, string inComposer, int inGenre, int inNum, string inMusician) {
	SetSong(inSong);
	SetMusician(inMusician);
	SetComposer(inComposer);
	SetGenre(inGenre);
	SetNumber(inNum);
}

void ItemType::DisplayNumOnScreen() {

	cout << "\tNumber   : " << m_number << endl;
}

void ItemType::DisplaySongOnScreen() {
	cout << "\tSong    : " << m_song << endl;
}

void ItemType::DisplayComposerOnScreen() {
	cout << "\tComposer    : " << m_composer << endl;
}

void ItemType::DisplayMusicianOnScreen() {
	cout << "\tMusician    : " << m_musician << endl;
}

void ItemType::DisplayGenreOnScreen() {
	//genre에 따른 노래 장르 표시.
	if (m_genre == 1) {
		cout << "\tGenre    : "<< "가요" << endl;
	}
	else if (m_genre == 2) {
		cout << "\tGenre    : " << "연주곡" << endl;
	}
	else {
		cout << "\tGenre    : " << "Unkown" << endl;
	}
	
}

void ItemType::DisplayRecordOnScreen() {
	DisplaySongOnScreen();
	DisplayComposerOnScreen();
	DisplayMusicianOnScreen();
	DisplayGenreOnScreen();
	DisplayNumOnScreen();
	cout << endl;
}

void ItemType::SetSongFromKB() {
	cout << "\tSong : ";
	cin >> m_song;
}

void ItemType::SetComposerFromKB() {
	cout << "\tComposer : ";
	cin >> m_composer;
}

void ItemType::SetMusicianFromKB() {
	cout << "\tMusician : ";
	cin >> m_musician;
}

void ItemType::SetGenreFromKB() {
	cout << "\tGenre : ";
	cin >> m_genre;
}

void ItemType::SetNumFromKB() {
	cout << "\tNumber : ";
	cin >> m_number;
}

void ItemType::SetRecordFromKB() {
	SetSongFromKB();
	SetComposerFromKB();
	SetMusicianFromKB();
	SetGenreFromKB();
	SetNumFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_song;
	fin >> m_composer;
	fin >> m_musician;
	fin >> m_genre;
	fin >> m_number;

	return 1;
}

int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_song << " ";
	fout << m_composer << " ";
	fout << m_musician << " ";
	fout << m_genre << " ";
	fout << m_number << " ";
	fout << endl;

	return 1;
}

bool ItemType::operator==(const ItemType& A) {
	if (m_number == A.GetNum())
		return true;
	return false;
}
void ItemType::operator=(const ItemType& _item) {
	m_number = _item.GetNum();
	m_song = _item.GetSong();
	m_composer = _item.GetComposer();
	m_musician = _item.GetMusician();
	m_genre = _item.GetGenre();
}

RelationType ItemType::CompareByID(const ItemType& data) {
	if (m_number > data.GetNum()) return GREATER;
	else if (m_number == data.GetNum()) return EQUAL;
	else return LESS;
}

