#pragma once


class SimpleItemType {
private:
	int m_containerId;
	int m_id;
public:
	SimpleItemType() {
		m_containerId = 0;
		m_id = 0;
	};
	~SimpleItemType() {};

	int GetId() const {
		return m_id;
	}

	int GetContainerId() const {
		return m_containerId;
	}

	void SetId(int Inid) {
		m_id = Inid;
	}

	void SetContainerId(int Inid) {
		m_containerId = Inid;
	}

	void SetIdFromKB() {
		cout << "\tINPUT ID : ";
		cin >> m_id;
	}

	void SetContainerIdFromKB() {
		cout << "\tINPUT CONTAINER_ID : ";
		cin >> m_containerId;
	}

	void DisplayContainerId() {
		cout << "\tCONTAINER_ID : " << m_containerId << endl;
	}

	void DisplayId() {
		cout << "\tID : " << m_id << endl;
	}

	void DisplayRecord() {
		DisplayId();
		DisplayContainerId();
		cout << endl;
	}

	RelationType CompareID(SimpleItemType& data) {
		if (m_id > data.GetId()) return GREATER;
		else if (m_id == data.GetId()) return EQUAL;
		else return LESS;
	}


	bool operator==(SimpleItemType& other) {
		if (this->m_id == other.GetId()) return true;
		else return false;
	}

	void operator=(SimpleItemType& other) {
		m_id = other.m_id;
		m_containerId = other.m_containerId;
	}

	bool operator>(SimpleItemType& _item) {
		if (m_id > _item.GetId())
			return true;
		return false;
	}
	bool operator<(SimpleItemType& _item) {
		if (m_id < _item.GetId())
			return true;
		return false;
	}

	friend ostream& operator<<(ostream& os, const SimpleItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tContainerID   : " << _item.GetContainerId() << endl;
		return os;
	}
};