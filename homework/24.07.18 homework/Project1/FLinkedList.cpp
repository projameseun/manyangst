#include "FLinkedList.h"
#include <iostream>

void InitList(FLinkedList* _pList)
{

	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(FLinkedList* _pList, int _data)
{
	//1.��� ����
	FNode* pNode = (FNode*)malloc(sizeof(FNode));

	//2.����
	pNode->iData = _data;
	pNode->pNextNode = nullptr;	//��� ���忡���� �������� ������ ����̴�.

	//�߰� �����Ͱ� ó������ �ƴ���
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		//�ش���� ù��° �ּҸ� �˰� �ִ�.
		FNode* pTempNode = _pList->pHeadNode;
		while (pTempNode->pNextNode)
		{
			/*	if (pTempNode->pNextNode == nullptr)
				{
					break;
				}*/

			pTempNode = pTempNode->pNextNode;
		}

		pTempNode->pNextNode = pNode;

	}

	++_pList->iCount;

}

void DestroyList(FLinkedList* _pList)
{
	FNode* pNode = _pList->pHeadNode;

	while (pNode != nullptr) 
	{
		FNode* pNext = pNode->pNextNode;
		free(pNode); // ��� �޸� ����
		pNode = pNext;
	}

	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushFront(FLinkedList* _pList, int _data)
{
	// ���ο� ��� ����
	FNode* pNode = (FNode*)malloc(sizeof(FNode));
	pNode->iData = _data;

	// ���� ��� ��尡 �ִ��� Ȯ��
	if (_pList->pHeadNode != nullptr) 
	{
		pNode->pNextNode = _pList->pHeadNode;
	}
	else
	{
		pNode->pNextNode = nullptr;
	}

	// ���ο� ��带 ��� ���� ����
	_pList->pHeadNode = pNode;

	// ����Ʈ ũ�� ����
	++_pList->iCount;
}

