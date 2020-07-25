#pragma once
class ItemType
{
private:
	int id;				///< item ID.
	string name;		///< item name.
	string singer;		///< item singer.
	int genre;			///< item genre.

public:
	ItemType();
	~ItemType();

	int GetId() const;
	string GetName() const;
	string GetSinger() const;
	int GetGenre() const;

	void SetId(int _id);
	void SetName(string _name);
	void SetSinger(string _singer);
	void SetGenre(int _genre);
	void SetRecord(int _id, string _name, string _singer, int _genre);

	void SetIdFromKB();
	void SetNameFromKB();
	void SetSingerFromKB();
	void SetGenreFromKB();
	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);

	void DisplayIdOnScreen();
	void DisplayNameOnScreen();
	void DisplaySingerOnScreen();
	void DisplayGenreOnScreen();
	void DisplayRecordOnScreen();

	bool operator==(const ItemType& _item) {
		if (id == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const ItemType& _item) {
		if (id > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const ItemType& _item) {
		if (id < _item.GetId())
			return true;
		return false;
	}
	void operator=(const ItemType& _item) {
		id = _item.GetId();
		name = _item.GetName();
		singer = _item.GetSinger();
		genre = _item.GetGenre();
	}
	friend ostream& operator<<(ostream& os, const ItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tName   : " << _item.GetName() << endl;
		os << "\tSinger   : " << _item.GetSinger() << endl;
		os << "\tGenre   : " << _item.GetGenre() << endl;
		return os;
	}
};

