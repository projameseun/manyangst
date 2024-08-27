#pragma once
#include <assert.h>


template<typename T>
struct tFNode
{
	T			tData;
	tFNode<T>*	pPrevNode;
	tFNode<T>*	pNextNode;

	tFNode() :
		tData(),
		pPrevNode(nullptr),
		pNextNode(nullptr)
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
	tFNode<T>*		m_pHeadNode;
	tFNode<T>*		m_pTailNode;
	int				m_iCount;

public:
	CList();
	~CList();

public:
	void push_back(const T& _data);
	int size() const
	{
		return m_iCount;
	}
	void push_front(const T& _data);

public:
	class iterator;

	iterator begin();
	iterator end();
	iterator earse(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);

public:
	class iterator
	{
	private:
		CList<T>*		m_pList;
		tFNode<T>*		m_pNode;
		bool			m_Valid;
	public:
		iterator() :
			m_pList(nullptr),
			m_pNode(nullptr),
			m_Valid(false)
		{

		}
		iterator(CList<T>* _pList, tFNode<T>* _pNode) :
			m_pList(_pList),
			m_pNode(_pNode),
			m_Valid(false)

		{
			
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_Valid = true;
			}

		}
		~iterator()
		{

		}

		//oper
	public:
		T& operator *()
		{
			return m_pNode->tData;
		}

		bool operator == (const iterator& _otheriter)
		{
			if (m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
			{
				return true;
			}

			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		iterator& operator ++()
		{
			if (nullptr == m_pNode || !m_Valid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNextNode;

			return *this;
		}
		iterator& operator ++(int)
		{
			iterator copyiter = (*this);

			++(*this);

			return copyiter;
		}
		iterator& operator --()
		{
			if (nullptr == m_pNode || !m_Valid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrevNode;

			return *this;
		}
		iterator& operator --(int)
		{
			iterator copyiter = (*this);

			--(*this);

			return copyiter;
		}

		friend class CList;
		
	};
	
};

template<class T>
 CList<T>::CList() :
	 m_pHeadNode(nullptr),
	 m_pTailNode(nullptr),
	 m_iCount(0)
{
	 
}

template<class T>
 CList<T>::~CList()
{
	 tFNode<T>* pDelNode = m_pHeadNode;

	 while (pDelNode)
	 {
		 tFNode<T>* pNext= pDelNode->pNextNode;
		 delete(pDelNode);
		 pDelNode = pNext;
	 }
}

 template<class T>
  void CList<T>::push_back(const T& _data)
 {
	  tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);

	  //처음인지 아닌지
	  if (nullptr == m_pHeadNode)
	  {
		  m_pHeadNode = pNewNode;
		  m_pTailNode = pNewNode;
	  }
	  else
	  {

		  m_pTailNode->pNextNode = pNewNode;
		  pNewNode->pPrevNode = m_pTailNode;

		  m_pTailNode = pNewNode;
	  }

	  ++m_iCount;
	  
 }


  template<class T>
  void CList<T>::push_front(const T& _data)
  {
	  tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, m_pHeadNode);

	  //처음인지 아닌지
	  if (nullptr == m_pHeadNode)
	  {
		  m_pHeadNode = pNewNode;
		  m_pTailNode = pNewNode;
	  }
	  else
	  {

		  m_pHeadNode->pPrevNode = pNewNode;
		 

		  m_pHeadNode = pNewNode;
	  }

	  ++m_iCount;

  }

  template<class T>
  inline typename CList<T>::iterator CList<T>::begin()
  {
	  return iterator(this,m_pHeadNode);
  }

  template<class T>
  inline typename CList<T>::iterator CList<T>::end()
  {
	  return iterator(this,nullptr);
  }

  template<class T>
  typename CList<T>::iterator CList<T>::earse(iterator& _iter)
  {
	  if (_iter.m_pList != this || !_iter.m_Valid || _iter.m_pNode == nullptr)
	  {
		  assert(nullptr);
	  }

	  //삭제할노드
	  tFNode<T>* pDelNode = _iter.m_pNode;

	  //이전 노드 다음노드 저장
	  tFNode<T>* tPrevNode = _iter.m_pNode->pPrevNode;
	  tFNode<T>* tNextNode = _iter.m_pNode->pNextNode;

	  //헤드인지
	  if (m_pHeadNode == pDelNode)
	  {
		  m_pHeadNode = tNextNode;
	  }
	  else
	  {
		  tPrevNode->pNextNode = tNextNode;
	  }

	  if (m_pTailNode == pDelNode)
	  {
		  m_pTailNode = tPrevNode;
	  }
	  else
	  {
		  tNextNode->pPrevNode = tPrevNode;
	  }


	  
	  --m_iCount;


	  return iterator(this,tNextNode);
  }

  template<class T>
  typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
  {
	  if (end() == _iter)
	  {
		  assert(nullptr);
	  }

	  tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);

	  if (_iter.m_pNode == m_pHeadNode)
	  {
		  _iter.m_pNode->pPrevNode = pNewNode;
		  pNewNode->pNextNode = _iter.m_pNode;

		  m_pHeadNode = pNewNode;
	  }
	  else
	  {
		  _iter.m_pNode->pPrevNode->pNextNode = pNewNode;
		  pNewNode->pPrevNode = _iter.m_pNode->pPrevNode;

		  _iter.m_pNode->pPrevNode = pNewNode;
		  pNewNode->pNextNode = _iter.m_pNode;
	  }

	  ++m_iCount;

	  return iterator(this,pNewNode);
  }
