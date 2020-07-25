#pragma once


class SimpleItemType {
private:
	int m_containerId;
	int m_id;
	string m_name;
	int m_type;
public:
	SimpleItemType() {
		m_containerId = 0;
		m_id = 0;
		m_type = 0;
		m_name = "";
	};
	~SimpleItemType() {};

	int GetId() const {
		return m_id;
	}

	int GetContainerId() const {
		return m_containerId;
	}

	string GetName() const {
		return m_name;
	}

	int GetType() const {
		return m_type;
	}

	void SetId(int Inid) {
		m_id = Inid;
	}

	void SetContainerId(int Inid) {
		m_containerId = Inid;
	}

	void SetName(string inname) {
		m_name = inname;
	}

	void SetType(int intype) {
		m_type = intype;
	}

	void SetIdFromKB() {
		cout << "\tINPUT ID : ";
		cin >> m_id;
	}

	void SetContainerIdFromKB() {
		cout << "\tINPUT CONTAINER_ID : ";
		cin >> m_containerId;
	}

	void SetNameFromKB() {
		cout << "\tINPUT NAME : ";
		cin >> m_name;
	}

	void SetTypeFromKB() {
		cout << "\tINPUT TYPE : ";
		cin >> m_type;
	}

	void DisplayContainerId() {
		cout << "\tCONTAINER_ID : " << m_containerId << endl;
	}

	void DisplayId() {
		cout << "\tID : " << m_id << endl;
	}

	void DisplayName() {
		cout << "\tNAME : " << m_name << endl;
	}

	void DisplayType() {
		cout << "\tTYPE : " << m_type << endl;
	}

	void DisplayRecord() {
		DisplayId();
		DisplayName();
		DisplayType();
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

	void operator=(const ItemType& other) {
		m_id = other.GetId();
		m_containerId = other.GetContainerId();
		m_name = other.GetName();
		m_type = other.GetType();
	}

	void operator=(SimpleItemType& other) {
		m_id = other.GetId();
		m_containerId = other.GetContainerId();
		m_name = other.GetName();
		m_type = other.GetType();
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

};