#include "ArrayList.h"

//constructor
ArrayList::ArrayList() {
	m_CurPointer = NULL;
	m_Length = 0;
}
//destructor
ArrayList::~ArrayList(){}

//Clear List
void ArrayList::MakeEmpty() {
	m_Length = 0; // <- ���� list ���̸� 0���� �ٲ�.
}

//return list  size
int ArrayList::GetLength() {
	return m_Length;
}

//check list is full
bool ArrayList::IsFull() {
	if (m_Length >= MAXSIZE) return true;
	else return false;
}

//check list is empty
bool ArrayList::IsEmpty() {
	if (m_Length == 0) return true;
	else return false;
}

// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data) {
	m_CurPointer++;			//pointer ����(�������������� pointer �̵�)
	if (m_CurPointer == m_Length) return -1;		//pointer�� list ���� �����ϸ� -1 ����
	data = m_Array[m_CurPointer];	//data�� pass by reference�� ������ �Ѱ���

	return m_CurPointer;    // pointer ����
}

//Reset m_CurPointer
void ArrayList::ResetList() {
	m_CurPointer = -1;
}

//����Ʈ�� �������� ���ĵ� ������� �߰�
//���������� �۵��ϸ� 1�� ����, �׷��� ������ 0�� ����
int ArrayList::Add(ItemType data) {
	if (IsFull()) return 0; // list�� �� ���� return 0
	if (IsEmpty()) {
		m_Array[0] = data;  // list�� ��������� �˻��� �ʿ���� �ٷ� ù��° index�� �Է�.
		m_Length += 1;
		return 1;
	}
	// �� �׸��� ���� ��ġ iPos�� �˻�.
	/*
	*	1. ���� �����ϸ� ����. (����Ʈ ���� ������ �Է�)
	*	2. ������ ID�� ���� �������� ������ ����(return 0)
	*	3. �Է� data id���� ū data�� �߰��ϸ� ����. (���� ��ġ ã��)
	*/
	int iPos = 0;
	bool found = false;
	ItemType curItem;
	ResetList();
	iPos = GetNextItem(curItem);  // ���� �����ϸ� -1�� ����
	while (iPos > -1 && !found)
	{
		switch (curItem.CompareID(data))
		{
		case EQUAL:			//������ ID �߰�
			cout << " %%% same item exist in the list %%%\n";
			return 0;
		case GREATER:		//ū ID �߰�. search �ߴ�
			found = true;
			break;
		case LESS:			//���� ID �߰�. ��� ����.
			iPos = GetNextItem(curItem);
			break;
		}
	}

	//���� �����ϸ� iPos==-1. �̰�� �� �ڿ� �߰�
	if (iPos == -1) {
		// �ε��� length�� �߰�, length++, 1����
		m_Array[m_Length++] = data;
		return 1;
	}

	// iPost<length�̸� iPos���� length-1 ������ ��� �׸��� �ڷ� �� ĭ�� �̵�
	for (int i = m_Length; i > iPos; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	// iPos�� �߰�
	m_Array[iPos] = data;

	m_Length++;
	return 1;
}

//���ĵ� ����Ʈ�� �̿��Ͽ� ���������� ������ �˻��ؼ� ã��.
int ArrayList::Retrieve_SeqS(ItemType& data) {
	
	ItemType CurItem;

	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while (m_CurPointer < m_Length)	//ó������ ������
	{
		switch (CurItem.CompareID(data))	//�Է� �����۰� ���� �������� ��
		{
		case EQUAL:	//��ġ�ϸ�
			data = CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� Primary key�� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return 0;	//����(0)�� ����
			break;
		default:	//���� �������� Primary key�� �� ������
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
			break;
		}
	}
	return 0; //���н�0
}

//���ĵ� ����Ʈ���� ������ ����
int ArrayList::Delete(ItemType data) {
	if (Retrieve_BinaryS(data))	//Primary key�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//Primary key��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//Binary Search�� ���� ã�����ϴ� ID �˻� �� Replace.
int ArrayList::Replace(ItemType data)
{
	ItemType tmp(data);	//�Է¹��� item�� ���


	if (Retrieve_BinaryS(data))	//��ġ�ϴ� �������� ã�� ���
	{
		m_Array[m_CurPointer] = tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//Primary key�� ��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}


//���ĵ� ����Ʈ���� �����˻��� ���� �������� ã��.
int ArrayList::Retrieve_BinaryS(ItemType& data)
{
	int First = 0;  //ã���� �ϴ� ������ ù ��ġ.
	int Last = m_Length -1;		//ã���� �ϴ� ������ ������ ��ġ.
	int midPoint = 0;		//ù ��ġ�� ������ ��ġ�� �߰�.(�ݳ���)
	bool Found = false;     //ã�Ҵ� �� �� ã�Ҵ� �� Ȯ�� �뵵 bool
	bool MoreToSearch = true;      //��� Search�� �����ؾ��ϴ� �� Ȯ�� �뵵 bool

	while (MoreToSearch && !Found)  //�� ã�Ұ� ��� Search�ؾ��Ѵٸ� ����
	{
		midPoint = (First + Last) / 2;
		switch (m_Array[midPoint].CompareID(data))//ID ��
		{
		case LESS:      //midPoint �����ʿ� ã���� �ϴ� ID ���� ����.
			First = midPoint + 1;
			break;
		case EQUAL:    //ã���� �ϴ� ID ã��. Found = true -> while�� ���� (�̹����� �׳� return���� �Լ� �����Ŵ)
			Found = true;
			data = m_Array[midPoint];
			m_CurPointer = midPoint;
			return 1;
		case GREATER:    //midPoint ���ʿ� ã���� �ϴ� ID ���� ����.
			Last = midPoint - 1;
			break;
		}
		if (First > Last) { MoreToSearch = false; }     //First�� Last���� Ŀ���� �� �˻��� �ʿ� x -> �� �˻���.
	}
	return 0;
}


//1. �Էµ� �����Ϳ� ��ġ�ϴ� kind�� ���� Item �˻�
//2. �� Item���� index�� result �迭�� ����
//3. result�迭�� ũ�⸦ ��Ÿ���� ���� num�� currentIndex �Է�
//4. ����
int ArrayList::SearchByKind(int* result, int kind, int& num) {
	int currentIndex = 0; //result �迭 index - 0���� ���� �����Ͽ� result �迭 0������ �������� ������ index�� �����.
	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i].GetType() == kind) {
			result[currentIndex] = i;     // ���� kind �������� �߰��ϸ� �ش� index(i)�� result �迭�� �Է�.
			currentIndex++;
		}
	}
	num = currentIndex; // ���� result �迭�� ����� index ��.
	if (currentIndex == 0) return 0; // currentIndex�� 0�̸� ������ kind�� ���� ������ ���� x return 0
	else return 1; // ���������� �Լ� �����. return 1
}




