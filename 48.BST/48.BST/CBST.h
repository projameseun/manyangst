#pragma once
#include <assert.h>

enum class NODE_TYPE
{
	PARENT,
	LCHILD,
	RCHILD,
	START,
	
};


template<typename T1, typename T2>
struct FPair
{
	T1	first;		//key
	T2	second;		//value

};

namespace MySTD
{
	template<typename T1, typename T2>
	FPair<T1, T2> make_pair(const T1& _first, const T2& _second)
	{
		return FPair<T1, T2>{_first, _second};
	}
}



template<typename T1,typename T2>
struct FBSTNode
{
	FPair<T1, T2>		pair;
	
	//레퍼런스경로
	//FBSTNode*			pParent;			//부모 노드
	//FBSTNode*			pLeftChild;			//왼쪽 자식노드
	//FBSTNode*			pRightChild;		//오른쪽 자식노드
	//enum class를 사용해서 배열로 관리
	FBSTNode* ArrNode[(int)NODE_TYPE::START];

public:
	bool IsRoot()
	{
		if (nullptr == ArrNode[(int)NODE_TYPE::PARENT])
		{
			return true;
		}
		return false;
	}

	bool IsLeftChild()
	{
		if (ArrNode[(int)NODE_TYPE::PARENT]->ArrNode[(int)NODE_TYPE::LCHILD] == this)
		{
			return true;
		}
		return false;
	}

	

public:
	FBSTNode() :
		pair(nullptr),
		ArrNode{}
	{

	}
	FBSTNode(const FPair<T1,T2>& _pair, FBSTNode* _pParent, FBSTNode* _pLeftChild, FBSTNode* _pRightChild):
		pair(_pair),
		ArrNode{_pParent,_pLeftChild,_pRightChild}
	{

	}

};

template <class T1, class T2>
class CBST
{
private:
	FBSTNode<T1, T2>*			m_pRoot;
	int							m_iCount;		



public:
	CBST() :
		m_pRoot(nullptr),
		m_iCount(0)
	{

	}
	



public:
	bool insert(const FPair<T1, T2>& _pair);
	FBSTNode<T1, T2>* GetInorderSuccesor(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetInorderPredecessor(FBSTNode<T1, T2>* _pNode);

	FBSTNode<T1, T2>* GetParent(FBSTNode<T1, T2>* _pNode);

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T1& _rfind);

	//iterator
public:
	class iterator
	{
	private:
		CBST<T1, T2>*		m_pBST;		//bst본체를 알기위해서
		FBSTNode<T1, T2>*	m_pNode;	//특정노드를 알기위해서

	public:
		iterator() :
			m_pBST(nullptr),
			m_pNode(nullptr)
		{

		}
		iterator(CBST<T1, T2>* _pBST, FBSTNode<T1,T2>* _pNode) :
			m_pBST(_pBST),
			m_pNode(_pNode)
		{

		}


		//opeator
	public:
		bool operator == (const iterator& _other)
		{
			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
			{
				return true;
			}
			return false;
		}

		bool operator != (const iterator& _other)
		{
			return !(*this == _other);
		}
		

		const FPair<T1, T2>& operator*()
		{
			assert(m_pNode);

			return m_pNode->pair;
		}

		const FPair<T1, T2>* operator->()
		{
			assert(m_pNode);
			
			return &m_pNode->pair;
		}

		iterator& operator++()
		{
			m_pNode = m_pBST->GetInorderSuccesor(m_pNode);

			return *this;
		}
		
	};

};

template<class T1, class T2>
 bool CBST<T1, T2>::insert(const FPair<T1, T2>& _pair)
{
	/* FBSTNode<T1, T2>* pNewNode = new FBSTNode<T1, T2>();

	 pNewNode->pair = _pair;
	 pNewNode->pParent = nullptr;
	 pNewNode->pLeftChild = nullptr;
	 pNewNode->pRightChild = nullptr;*/

	 FBSTNode<T1, T2>* pNewNode = new FBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

	 //맨처음
	 if (nullptr == m_pRoot)
	 {
		 m_pRoot = pNewNode;
	 }
	 else
	 {
		 //2번째로 들어올때는 root노드안에서 pair.first에서 비교를 해야 될거다.
		 //root에서 시작해서 leaf노드가 나올때까지 비교하면서 내려가면 된다. 비교하면서 계속 반복을 하기 때문에 반복문을 사용해야 된다.

		 FBSTNode<T1, T2>* pNode = m_pRoot;
		 NODE_TYPE nodeType = NODE_TYPE::START;

#pragma region FIRTST

		 //while (true)
		 //{
			// //오른쪽
			// if (pNode->pair.first < pNewNode->pair.first)
			// {
			//	 //여기야
			//	 if (nullptr == pNode->pRightChild)
			//	 {
			//		 pNode->pRightChild = pNewNode;
			//		 pNewNode->pParent = pNode;
			//	 }

			//	 //node를 다시 갱신
			//	 else
			//	 {
			//		 pNode = pNode->pRightChild;
			//	 }
			// }
			// //왼쪽
			// else if (pNode->pair.first > pNewNode->pair.first)
			// {
			//	 //여기야
			//	 if (nullptr == pNode->pLeftChild)
			//	 {
			//		 pNode->pLeftChild = pNewNode;
			//		 pNewNode->pParent = pNode;
			//	 }

			//	 //node를 다시 갱신
			//	 else
			//	 {
			//		 pNode = pNode->pLeftChild;
			//	 }
			// }
			// //같다 
			// else
			// {
			//	 return false;
			// }

		 //}

#pragma endregion

		 while (true)
		 {
			 //오른쪽
			 if (pNode->pair.first < pNewNode->pair.first)
			 {
				 nodeType = NODE_TYPE::RCHILD;
				 //여기야
			
			 }
			 //왼쪽
			 else if (pNode->pair.first > pNewNode->pair.first)
			 {
				 
				 nodeType = NODE_TYPE::LCHILD;
			 }
			 //같다 
			 else
			 {
				 return false;
			 }

			 //넣어주는곳
			 if (nullptr == pNode->ArrNode[(int)nodeType])
			 {
				 pNode->ArrNode[(int)nodeType] = pNewNode;
				 pNewNode->ArrNode[(int)NODE_TYPE::PARENT] = pNode;
				 break;
			 }
			 else
			 {
				 pNode = pNode->ArrNode[(int)nodeType];
			 }

		 }

		
	 }




	 m_iCount;
	return true;
}

//후속자
template<class T1, class T2>
inline FBSTNode<T1, T2>* CBST<T1, T2>::GetInorderSuccesor(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pSuccesor = nullptr;

	//1.오른쪽 자식이 있는경우에 오른쪽 자식으로가서, 왼쪽 자식이 없을때 까지 내려감
	if (_pNode->ArrNode[(int)NODE_TYPE::RCHILD] != nullptr)
	{
		pSuccesor = _pNode->ArrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccesor->ArrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccesor = pSuccesor->ArrNode[(int)NODE_TYPE::LCHILD];
		}

	}

	//2.오른쪽 자식이 없으면 부모로 부터 왼쪽 자식일때까지 위로 올라간다.
	//그때 부모가 후속자 
	else
	{
		pSuccesor = _pNode;

		while (pSuccesor != nullptr)
		{
			if (pSuccesor->IsRoot())
			{
				return nullptr;
			}
			else
			{
				//현재노드가 현재노드부모의 왼쪽 자식이랑 같을경우  현재노드 부모가 후속자 
				if (pSuccesor->IsLeftChild())
				{
					pSuccesor = GetParent(pSuccesor);
					break;
				}
				else
				{
					pSuccesor = GetParent(pSuccesor);
				}
			}

		}
	}
	

	return pSuccesor;
}

template<class T1, class T2>
inline FBSTNode<T1, T2>* CBST<T1, T2>::GetInorderPredecessor(FBSTNode<T1, T2>* _pNode)
{
	return nullptr;
}

template<class T1, class T2>
inline FBSTNode<T1, T2>* CBST<T1, T2>::GetParent(FBSTNode<T1, T2>* _pNode)
{
	return _pNode->ArrNode[(int)NODE_TYPE::PARENT];
}


template<class T1, class T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	FBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->ArrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->ArrNode[(int)NODE_TYPE::LCHILD];
	}

	return iterator(this,pNode);
}

template<class T1, class T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this,nullptr);
}

template<class T1, class T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _rfind)
{
	FBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE nodeType = NODE_TYPE::START;

	while (pNode != nullptr)
	{
		//왼쪽
		if (pNode->pair.first > _rfind)
		{
			nodeType = NODE_TYPE::LCHILD;
		}
		else if (pNode->pair.first < _rfind)
		{
			nodeType = NODE_TYPE::RCHILD;
		}
		else
		{
			break;
		}

		if (nullptr == pNode->ArrNode[(int)nodeType])
		{
			pNode = nullptr;
			break;
		}
		else
		{
			pNode = pNode->ArrNode[(int)nodeType];
		}

		
	}
	
	return iterator(this,pNode);
}
