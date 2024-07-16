#pragma once

struct FNode
{
	int iData;
	FNode* pNextNode;

};



struct FLinkedList
{
	//헤드노드필요
	FNode* pHeadNode;
	//꼬리노드필요

	int iCount;
	

};

//초기화 연결형리스트
void InitList(FLinkedList* _pList);

//데이터 추가

void PushBack(FLinkedList* _pList, int _data);

//데이터삭제

void DestroyList(FLinkedList* _pList);

//리스트데이터 앞에추가

void PushFront(FLinkedList* _pList, int _data);