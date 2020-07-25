#pragma once
class PlayItemType
{
private:
	int id;
	int numPlay;
	int inTime;

public:
	PlayItemType();
	~PlayItemType();

	int GetId() const;
	int GetNumPlay() const;
	int GetInTime() const;

	void SetId(int _id);
	void SetNumPlay(int _numPlay);
	void SetInTime(int _inTime);
	void SetRecord(int _id, int _numPlay, int _inTime);

	void SetIdFromKB();
	void SetNumPlayFromKB();
	void SetInTimeFromKB();
	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);

	bool operator==(const PlayItemType& _item) {
		if (id == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const PlayItemType& _item) {
		if (id > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const PlayItemType& _item) {
		if (id < _item.GetId())
			return true;
		return false;
	}
	void operator=(const PlayItemType& _item) {
		id = _item.GetId();
		numPlay = _item.GetNumPlay();
		inTime = _item.GetInTime();
	}
	friend ostream& operator<<(ostream& os, const PlayItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tPlay Num   : " << _item.GetNumPlay() << endl;
		os << "\tIn Time   : " << _item.GetInTime() << endl;
		return os;
	}
};

