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
