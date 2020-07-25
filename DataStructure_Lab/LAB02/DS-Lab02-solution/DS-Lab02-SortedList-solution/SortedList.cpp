#include "SortedList.h"

// Make list empty.
void SortedList::MakeEmpty()
{
	m_Length = 0;
}

// Get a number of records in current list.
int SortedList::GetLength()
{
	return m_Length;
}

// Check capacity of list is full.
bool SortedList::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// search item by using primary key
int SortedList::Add(ItemType inData)
{
	// List�� �� ���ִ� ��� 0�� ����
	if (IsFull()) return 0;
	if (m_Length == 0) {    	// List�� ��� ������ �� �A�� �߰�, length++, 1�� ���� 
		m_Array[m_Length++] = inData;
		return 1;
	}
	// �� �׸��� ���� ��ġ iPos�� �˻�. ���� �����ϰų� ���� item�� inData���� ũ�� ����
	int iPos = 0;
	bool found = false;
	ItemType curItem;
	ResetList();
	iPos = GetNextItem(curItem);  // ���� �����ϸ� -1�� ����
	while (iPos > -1 && !found)
	{
		switch (curItem.Compare(inData))
		{
		case EQUAL:
			cout << " %%% same item exist in the list %%%\n";
			return 0;
		case GREATER:
			found = true;
			break;
		case LESS:
			iPos = GetNextItem(curItem);
			break;
		}
	}

	//���� �����ϸ� iPos==-1. �̰�� �� �ڿ� �߰�
	if (iPos == -1) {
		// �ε��� length�� �߰�, length++, 1����
		m_Array[m_Length++] = inData;
		return 1;
	}
	
	// iPost<length�̸� iPos���� length-1 ������ ��� �׸��� �ڷ� �� ĭ�� �̵�
	for (int i = m_Length; i > iPos; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	// iPos�� �߰�
	m_Array[iPos] = inData;
	
	m_Length++;
	return 1;
}

// Initialize list iterator.
void SortedList::ResetList()
{
	m_CurPointer = -1;
}



// move list iterator to the next item in list and get that item.
int SortedList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == m_Length)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}




//Primary key�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
int SortedList::Retrieve_SeqS(ItemType& data)
{
	ItemType CurItem;

	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while (m_CurPointer < m_Length)	//ó������ ������
	{
		switch (CurItem.Compare(data))	//�Է� �����۰� ���� �������� ��
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



//Primary key�� ��ġ�ϴ� item�� ã�Ƽ� ������
int SortedList::Delete(ItemType data)
{
	if (Retrieve_SeqS(data))	//Primary key�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//Primary key��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//Primary key�� ��ġ�ϴ� item�� ������ ��ü��Ŵ
int SortedList::Replace(ItemType data)
{
	ItemType tmp(data);	//�Է¹��� item�� ���

	if (Retrieve_SeqS(data))	//��ġ�ϴ� �������� ã�� ���
	{
		m_Array[m_CurPointer] = tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//Primary key�� ��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//Primary key�� ��ġ�ϴ� item�� ����Ž������ �˻��ؼ� ��ȯ�Ѵ�.
int SortedList::Retrieve_BinaryS(ItemType& data)
{
	if (m_Length == 0)	//���� �迭�� ����ٸ�
		return 0;	//����(0)�� ����
	int currentPos = m_Length / 2;	//�迭�� �߰����� ����
	while (1)
	{
		switch (m_Array[currentPos].Compare(data))
		{
		case EQUAL:	//���� �����۰� �Է� �������� Primary key�� ��ġ�Ѵٸ�
			data = m_Array[currentPos];	//data�� �߰��� ���� ����
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� Primary key�� �Է� �������� Primary key���� ũ�ٸ�
			if (currentPos == 0)	//ó�� �迭�� ������ �������
				return 0;	//����(0)�� ����
			currentPos /= 2;	//�� ������ �ε����� ���ݷ� �̵�
			break;
		case LESS:	//���� �������� Primary key�� �Է� �������� Primary key���� �۴ٸ�
			if (currentPos == m_Length - 1)	//������ �迭�� ������ ū���
				return 0;	//����(0)�� ����
			currentPos = (currentPos + m_Length) / 2;	//�� ū�� �ε����� �������� �̵�
			break;
		}
	}
	return 0;	//ȣ��� �� ���� ����(WARNING ������)
}
