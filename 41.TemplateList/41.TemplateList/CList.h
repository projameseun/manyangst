#pragma once

template <class T>
struct tFNode
{
	T				tData;
	tFNode<T>*		pPrevNode;
	tFNode<T>*		pNextNode;

public:
	tFNode() :
		tData(),
		pNextNode(nullptr),
		pPrevNode(nullptr)
	{

	}

	tFNode(const T& _data, tFNode<T>* _pPrev, tFNode<T>* _pNext) :
		tData(_data),
		pPrevNode(_pPrev),
		pNextNode(_pNext)
	{
		
	}

};


template <class T>
class CList
{
private:
	//������ʿ�
	tFNode<T>*		m_pHeadNode;
	tFNode<T>*		m_pTailNode;
	//��������ʿ�
	int				m_iCount;

public:
	CList();
	~CList();

public:
	void PushBack(const T& _data);
	void PushFront(const T& _data);

};

template<class T>
 CList<T>::CList():
	 m_pHeadNode(nullptr),
	 m_pTailNode(nullptr),
	 m_iCount(0)
{

}

 template<class T>
  CList<T>::~CList()
 {
 }


  template<class T>
  void CList<T>::PushBack(const T& _data)
{
	//�Էµ� �����͸� ������ ��带 �����Ҵ�
	  tFNode<T>* pNewNode = new tFNode<T>(_data,nullptr,nullptr);
	 // FNode* pNode = new FNode;

	  //����
	  //pNode->pNextNode = nullptr;
	  //pNode->data = _data;

	  //�����͸� �߰��ؾ߰���..
	  //ó������ �ƴ���
	  if (nullptr == m_pHeadNode)
	  {
		  m_pHeadNode = pNewNode;
		  m_pTailNode = pNewNode;
	  }
	  else//�����Ͱ� �̹� �ִٴ°� 
	  {
		  //���� ���� ���������(tail)�� �����ϰ� �ִ� ����
		  //���� ������ ��尡 ���� ����Ű��
		  m_pTailNode->pNextNode = pNewNode;
		  pNewNode->pPrevNode = m_pTailNode;

		
		  //list�� ������ ����� �ּҰ��� ���� �Էµ� ���� ����
		  m_pTailNode = pNewNode;
	  }
	  
	  m_iCount;


}

  template<class T>
   void CList<T>::PushFront(const T& _data)
  {
	 
	   tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);
	

	

		//�����͸� �߰��ؾ߰���..
		//ó������ �ƴ���
	   if (nullptr == m_pHeadNode)
	   {
		   m_pHeadNode = pNewNode;
		   m_pTailNode = pNewNode;
	   }
	   else//�����Ͱ� �̹� �ִٴ°� 
	   {
		   //���� ���� ���������(tail)�� �����ϰ� �ִ� ����
		   //���� ������ ��尡 ���� ����Ű��
		   m_pHeadNode->pPrevNode = pNewNode;
		   pNewNode->pNextNode = m_pHeadNode;


		   //list�� ������ ����� �ּҰ��� ���� �Էµ� ���� ����
		   m_pHeadNode = pNewNode;
	   }

	   m_iCount;
  }




////�����ͻ���
//
//void DestroyList(FLinkedList* _pList);
//
////����Ʈ������ �տ��߰�
//
//void PushFront(FLinkedList* _pList, int _data);


//#include "FLinkedList.h"
//#include <iostream>


////��͹��
//void Destroy(FNode* _pNode)
//{
//	if (nullptr == _pNode)
//	{
//		return;
//	}
//
//	Destroy(_pNode->pNextNode);
//	free(_pNode);
//}
//
//void DestroyList(FLinkedList* _pList)
//{
//
//	//Destroy(_pList->pHeadNode);
//
//	FNode* pDelNode = _pList->pHeadNode;
//
//	while (pDelNode)
//	{
//		FNode* pNext = pDelNode->pNextNode;
//		delete pDelNode;	//C++���
//		//free(pDelNode);	//C���
//		pDelNode = pNext;
//	}
//}
//
//void PushFront(FLinkedList* _pList, int _data)
//{
//	//FNode* pNode = (FNode*)malloc(sizeof(FNode));
//
//	FNode* pNode = new FNode;
//
//	pNode->iData = _data;
//	pNode->pNextNode = _pList->pHeadNode;
//
//	//�ش������� ����
//	_pList->pHeadNode = pNode;
//
//	++_pList->iCount;
//
//
//}

