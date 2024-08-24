#pragma once
#include <assert.h>

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
	tFNode<T>* m_pHeadNode;
	tFNode<T>* m_pTailNode;
	//꼬리노드필요
	int				m_iCount;

public:
	CList();
	~CList();

public:
	void PushBack(const T& _data);
	void PushFront(const T& _data);

	int size()
	{
		return m_iCount;
	}

	class iterator;
		iterator begin();
		iterator end();
		iterator erase(iterator& _iter);	//과제 
		iterator insert(const iterator& _iter, const T& _data);
		
		
public:
	class iterator
	{
	private:
		CList<T>*		m_pList;
		tFNode<T>*		m_pNode;	//nullptr인경우 end iterator이다.
		bool			m_bValid;	//유효
	public:
		iterator():
			m_pList(nullptr),
			m_pNode(nullptr),
			m_bValid(false)
		{
			
		}
		iterator(CList<T>* _pList, tFNode<T>*_pNode) :
			m_pList(_pList),
			m_pNode(_pNode),
			m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}

		}
		~iterator()
		{

		}

	public:
		//operator
		T& operator*()
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
			//end에서 ++한경우
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNextNode;

			return *this;

		}
		iterator operator ++(int)
		{
			iterator copyiter = (*this);

			++(*this);

			return copyiter;
		}

		iterator& operator --()
		{
			//end에서 ++한경우
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrevNode;

			return *this;

		}
		iterator operator --(int)
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
		tFNode<T>* pNextNode = pDelNode->pNextNode;
		delete(pDelNode);
		pDelNode = pNextNode;
	}

}


template<class T>
void CList<T>::PushBack(const T& _data)
{
	//입력된 데이터를 저장할 노드를 동적할당
	tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);
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

	++m_iCount;


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
inline typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{

	if (_iter.m_pList != this || _iter.m_pNode == nullptr || !_iter.m_bValid)
	{
		assert(nullptr);
		return end();
	}

	//삭제 할 노드 가져오기
	
	tFNode<T>* pDelNode = _iter.m_pNode;

	//이전노드와 다음노드 저장
	
	tFNode<T>* pPreveNode = _iter.m_pNode->pPreveNode;
	tFNode<T>* pNextNode = _iter.m_pNode->pNextNode;

	//삭제할 노드가 첫번째인 경우
	if (m_pHeadNode == pDelNode)
	{
		m_pHeadNode = pNextNode;
	}
	else
	{
		pPreveNode->pNextNode = pNextNode;
	}

	//삭제할 노드가 마지막인 경우
	if (m_pTailNode == pDelNode)
	{
		m_pTailNode = pPreveNode;
	}
	else
	{
		pNextNode->pPrevNode = pPreveNode;
	}

	//노드 삭제
	delete pDelNode;

	--m_iCount;

	return iterator(this, pNextNode);
#pragma region ManYang
	//만냥
	//tFNode<T>* pNodeToErase = _iter.m_pNode;
	//tFNode<T>* pNextNode = pNodeToErase->pNextNode;

	//if (pNodeToErase->pPrevNode)
	//{
	//	pNodeToErase->pPrevNode->pNextNode = pNextNode;
	//}
	//else
	//{
	//	// 삭제할 노드가 헤드 노드일 경우
	//	m_pHeadNode = pNextNode;
	//}

	//// 다음 노드가 존재하면 그 노드의 pPrevNode를 현재 노드의 pPrevNode로 설정
	//if (pNextNode)
	//{
	//	pNextNode->pPrevNode = pNodeToErase->pPrevNode;
	//}
	//else
	//{
	//	// 삭제할 노드가 테일 노드일 경우
	//	m_pTailNode = pNodeToErase->pPrevNode;
	//}

	////노드삭제 
	//delete pNodeToErase;
	//--m_iCount;
	//

	//return iterator(this, pNextNode);
#pragma endregion

	

}

template<class T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}

	//const T& _data, tFNode<T>* _pPrev, tFNode<T>* _pNext) :
	//새로운 노드생성
	tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);

	
	//헤드 노드일때
	if (_iter.m_pNode == m_pHeadNode)
	{
		//앞에추가
		_iter.m_pNode->pPrevNode = pNewNode;
		pNewNode->pNextNode = _iter.m_pNode;
		
		m_pHeadNode = pNewNode;
	}
	else
	{
		//iterator가 가리키고 잇는 노드의 이전으로가서
		//다음 노드 주소를 새로 생성한 노드로 지정
		_iter.m_pNode->pPrevNode->pNextNode = pNewNode;
		pNewNode->pPrevNode = _iter.m_pNode->pPrevNode;

		_iter.m_pNode->pPrevNode = pNewNode;
		pNewNode->pNextNode = _iter.m_pNode;
	}

	++m_iCount;

	return iterator(this,pNewNode);
}






