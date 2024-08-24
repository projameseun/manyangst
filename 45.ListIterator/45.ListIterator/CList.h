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
	//������ʿ�
	tFNode<T>* m_pHeadNode;
	tFNode<T>* m_pTailNode;
	//��������ʿ�
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
		iterator erase(iterator& _iter);	//���� 
		iterator insert(const iterator& _iter, const T& _data);
		
		
public:
	class iterator
	{
	private:
		CList<T>*		m_pList;
		tFNode<T>*		m_pNode;	//nullptr�ΰ�� end iterator�̴�.
		bool			m_bValid;	//��ȿ
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
			//end���� ++�Ѱ��
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
			//end���� ++�Ѱ��
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
	//�Էµ� �����͸� ������ ��带 �����Ҵ�
	tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);
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
//	iterator erase(const const_iterator _Where) noexcept /* strengthened */ {
//#if _ITERATOR_DEBUG_LEVEL == 2
//		_STL_VERIFY(_Where._Getcont() == _STD addressof(_Mypair._Myval2), "list erase iterator outside range");
//#endif // _ITERATOR_DEBUG_LEVEL == 2
//		const auto _Result = _Where._Ptr->_Next;
//		_Node::_Freenode(_Getal(), _Mypair._Myval2._Unlinknode(_Where._Ptr));
//		return _Make_iter(_Result);
//	}
	if (end() == _iter)
	{
		assert(nullptr);
	}

	tFNode<T>* pNodeToErase = _iter.m_pNode;
	tFNode<T>* pNextNode = pNodeToErase->pNextNode;

	if (pNodeToErase->pPrevNode)
	{
		pNodeToErase->pPrevNode->pNextNode = pNextNode;
	}
	else
	{
		// ������ ��尡 ��� ����� ���
		m_pHeadNode = pNextNode;
	}

	// ���� ��尡 �����ϸ� �� ����� pPrevNode�� ���� ����� pPrevNode�� ����
	if (pNextNode)
	{
		pNextNode->pPrevNode = pNodeToErase->pPrevNode;
	}
	else
	{
		// ������ ��尡 ���� ����� ���
		m_pTailNode = pNodeToErase->pPrevNode;
	}


	

	return iterator(this, pNextNode);
}

template<class T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}

	//const T& _data, tFNode<T>* _pPrev, tFNode<T>* _pNext) :
	//���ο� ������
	tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);

	
	//��� ����϶�
	if (_iter.m_pNode == m_pHeadNode)
	{
		//�տ��߰�
		_iter.m_pNode->pPrevNode = pNewNode;
		pNewNode->pNextNode = _iter.m_pNode;
		
		m_pHeadNode = pNewNode;
	}
	else
	{
		//iterator�� ����Ű�� �մ� ����� �������ΰ���
		//���� ��� �ּҸ� ���� ������ ���� ����
		_iter.m_pNode->pPrevNode->pNextNode = pNewNode;
		pNewNode->pPrevNode = _iter.m_pNode->pPrevNode;

		_iter.m_pNode->pPrevNode = pNewNode;
		pNewNode->pNextNode = _iter.m_pNode;
	}

	++m_iCount;

	return iterator(this,pNewNode);
}






