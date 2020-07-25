#pragma once
#ifndef _MINHEAP_H
#define _MINHEAP_H




/**
*	CMinHeap Ŭ����.
*/
template <typename T>
class CMinHeap : public CHeapBase<T>
{
public:
	/**
	*	������.
	*/
	CMinHeap();

	/**
	*	������ - �迭�� �ִ� ����.
	*/
	CMinHeap(int size);

	/**
	*	@brief	������ �Ʒ��� �������鼭 Heap ũ�⸦ ���Ͽ� �����ϴ� �����Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �����͸� ���Ͽ� �����Ѵ�.
	*	@param	iparent	�������� ������.
	*	@param	ibottom	������ ������.
	*/
	virtual void ReheapDown(int iparent, int ibottom);

	/**
	*	@brief	�Ʒ����� ���� �ö󰡸鼭 Heap ũ�⸦ ���Ͽ� �����ϴ� �����Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �����͸� ���Ͽ� �����Ѵ�.
	*	@param	iroot	ù��° ������.
	*	@param	ibottom	�ö󰡴� ������.
	*/
	virtual void ReheapUp(int iroot, int ibottom);

	/**
	*	@brief	Heap�� �����͸� �����ϴ� �����Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �����͸� �����Ѵ�.
	*	@param	item	ItemType���� ���� �� ������.
	*	@param	found	������ �����͸� ã�Ҵ��� �ƴ��� Ȯ��.
	*	@param	ibottom	�˻� ���� �迭 ��ġ.
	*/
	virtual void Delete(T item, bool& found, int iparent);

	/**
	*	@brief	Heap�� �����͸� �˻��ϴ� �����Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �����͸� �˻��Ѵ�.
	*	@param	item	ItemType���� �˻� �� ������.
	*	@param	found	�˻��� �����͸� ã�Ҵ��� �ƴ��� Ȯ��.
	*	@param	ibottom	�˻� ���� �迭 ��ġ.
	*/
	virtual void Retrieve(T& item, bool& found, int iparent);
};


// ������
template <typename T>
CMinHeap<T>::CMinHeap()
{
}


// ������ - �迭�� �ִ� ����.
template <typename T>
CMinHeap<T>::CMinHeap(int size)
{
	CHeapBase<T>::m_nMaxSize = size;
	CHeapBase<T>::m_pHeap = new T[CHeapBase<T>::m_nMaxSize];
}


// ������ �Ʒ��� �������鼭 Heap ũ�⸦ ���Ͽ� �����ϴ� �����Լ�
template <typename T>
void CMinHeap<T>::ReheapDown(int iparent, int ibottom)
{
	int minChild; // �迭�� ���� ��ġ
	int leftChild; // ���� �ڽĵ�����
	int rightChild;// ������ �ڽĵ�����

	leftChild = iparent * 2 + 1;
	rightChild = iparent * 2 + 2;

	if (leftChild <= ibottom)
	{
		if (leftChild == ibottom)
			minChild = leftChild;
		else
		{
			if (CHeapBase<T>::m_pHeap[leftChild] > CHeapBase<T>::m_pHeap[rightChild])
				minChild = rightChild;
			else
				minChild = leftChild;
		}
		if (CHeapBase<T>::m_pHeap[iparent] > CHeapBase<T>::m_pHeap[minChild])
		{
			CHeapBase<T>::Swap(iparent, minChild); // �� �������� ��ġ�� �ٲ۴�
			ReheapDown(minChild, ibottom); // �Ʒ��� ������ �ٽ� ����
		}
	}
}


// �Ʒ����� ���� �ö󰡸鼭 Heap ũ�⸦ ���Ͽ� �����ϴ� �����Լ�.
template <typename T>
void CMinHeap<T>::ReheapUp(int iroot, int ibottom)
{
	int iparent; // �θ�����
	if (ibottom > iroot)
	{
		iparent = (ibottom - 1) / 2;
		if (CHeapBase<T>::m_pHeap[iparent] > CHeapBase<T>::m_pHeap[ibottom])
		{
			CHeapBase<T>::Swap(iparent, ibottom); // �� �������� ��ġ�� �ٲ۴�
			ReheapUp(iroot, iparent); // ���� �ö� �ٽ� ����
		}
	}
}


// Heap�� �����͸� �����ϴ� �����Լ�.
template <typename T>
void CMinHeap<T>::Delete(T item, bool& found, int iparent)
{
	int leftChild; // ���� �ڽĵ�����
	int rightChild; // ������ �ڽĵ�����

	leftChild = iparent * 2 + 1;
	rightChild = iparent * 2 + 2;

	if (CHeapBase<T>::m_pHeap[iparent] == item) // �����Ϸ��� ������ �߰�
	{
		CHeapBase<T>::m_pHeap[iparent] = CHeapBase<T>::m_pHeap[CHeapBase<T>::m_iLastNode - 1];
		ReheapDown(iparent, CHeapBase<T>::m_iLastNode - 2); // ������ ����
		found = true;
	}
	if (leftChild < CHeapBase<T>::m_iLastNode && !found)
		Delete(item, found, leftChild); // �������� �˻�
	if (rightChild < CHeapBase<T>::m_iLastNode && !found)
		Delete(item, found, rightChild); // ���������� �˻�
}


// Heap�� �����͸� �˻��ϴ� �����Լ�.
template <typename T>
void CMinHeap<T>::Retrieve(T& item, bool& found, int iparent)
{
	int leftChild; // ���� �ڽĵ�����
	int rightChild; // ������ �ڽĵ�����

	leftChild = iparent * 2 + 1;
	rightChild = iparent * 2 + 2;

	if (CHeapBase<T>::m_pHeap[iparent] == item) // �˻��Ϸ��� ������ �߰�
	{
		item = CHeapBase<T>::m_pHeap[iparent];
		found = true;
	}
	if (leftChild < CHeapBase<T>::m_iLastNode && !found)
		Retrieve(item, found, leftChild); // �������� �˻�
	if (rightChild < CHeapBase<T>::m_iLastNode && !found)
		Retrieve(item, found, rightChild); // �������� �˻�
}


#endif	// _MINHEAP_H
