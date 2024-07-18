#include "FLinkedList.h"
#include <iostream>

void InitList(FLinkedList* _pList)
{

	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(FLinkedList* _pList, int _data)
{
	//1.노드 생성
	FNode* pNode = (FNode*)malloc(sizeof(FNode));

	//2.삽입
	pNode->iData = _data;
	pNode->pNextNode = nullptr;	//노드 입장에서는 다음노드는 마지막 노드이다.

	//추가 데이터가 처음인지 아닌지
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		//해당노드는 첫번째 주소를 알고 있다.
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
		free(pNode); // 노드 메모리 해제
		pNode = pNext;
	}

	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushFront(FLinkedList* _pList, int _data)
{
	// 새로운 노드 생성
	FNode* pNode = (FNode*)malloc(sizeof(FNode));
	pNode->iData = _data;

	// 기존 헤드 노드가 있는지 확인
	if (_pList->pHeadNode != nullptr) 
	{
		pNode->pNextNode = _pList->pHeadNode;
	}
	else
	{
		pNode->pNextNode = nullptr;
	}

	// 새로운 노드를 헤드 노드로 설정
	_pList->pHeadNode = pNode;

	// 리스트 크기 증가
	++_pList->iCount;
}

