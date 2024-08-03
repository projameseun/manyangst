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
	//헤드노드필요
	tFNode<T>*		m_pHeadNode;
	tFNode<T>*		m_pTailNode;
	//꼬리노드필요
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
	//입력된 데이터를 저장할 노드를 동적할당
	  tFNode<T>* pNewNode = new tFNode<T>(_data,nullptr,nullptr);
	 // FNode* pNode = new FNode;

	  //삽입
	  //pNode->pNextNode = nullptr;
	  //pNode->data = _data;

	  //데이터를 추가해야겠지..
	  //처음인지 아닌지
	  if (nullptr == m_pHeadNode)
	  {
		  m_pHeadNode = pNewNode;
		  m_pTailNode = pNewNode;
	  }
	  else//데이터가 이미 있다는거 
	  {
		  //현재 가장 마지막노드(tail)을 저장하고 있는 노드와
		  //새로 생성된 노드가 서로 가리키됨
		  m_pTailNode->pNextNode = pNewNode;
		  pNewNode->pPrevNode = m_pTailNode;

		
		  //list가 마지막 노드의 주소값을 새로 입력된 노드로 갱신
		  m_pTailNode = pNewNode;
	  }
	  
	  m_iCount;


}

  template<class T>
   void CList<T>::PushFront(const T& _data)
  {
	 
	   tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);
	

	

		//데이터를 추가해야겠지..
		//처음인지 아닌지
	   if (nullptr == m_pHeadNode)
	   {
		   m_pHeadNode = pNewNode;
		   m_pTailNode = pNewNode;
	   }
	   else//데이터가 이미 있다는거 
	   {
		   //현재 가장 마지막노드(tail)을 저장하고 있는 노드와
		   //새로 생성된 노드가 서로 가리키됨
		   m_pHeadNode->pPrevNode = pNewNode;
		   pNewNode->pNextNode = m_pHeadNode;


		   //list가 마지막 노드의 주소값을 새로 입력된 노드로 갱신
		   m_pHeadNode = pNewNode;
	   }

	   m_iCount;
  }




////데이터삭제
//
//void DestroyList(FLinkedList* _pList);
//
////리스트데이터 앞에추가
//
//void PushFront(FLinkedList* _pList, int _data);


//#include "FLinkedList.h"
//#include <iostream>


////재귀방식
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
//		delete pDelNode;	//C++방식
//		//free(pDelNode);	//C방식
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
//	//해당포인터 갱신
//	_pList->pHeadNode = pNode;
//
//	++_pList->iCount;
//
//
//}

