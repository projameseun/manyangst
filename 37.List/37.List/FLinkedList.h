#pragma once

struct FNode
{
	int iData;
	FNode* pNextNode;

};



struct FLinkedList
{
	//������ʿ�
	FNode* pHeadNode;
	//��������ʿ�

	int iCount;
	

};

//�ʱ�ȭ ����������Ʈ
void InitList(FLinkedList* _pList);

//������ �߰�

void PushBack(FLinkedList* _pList, int _data);

//�����ͻ���

void DestroyList(FLinkedList* _pList);

//����Ʈ������ �տ��߰�

void PushFront(FLinkedList* _pList, int _data);