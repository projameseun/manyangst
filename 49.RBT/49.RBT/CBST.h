#pragma once
#include <assert.h>

enum class NODE_ROLE
{
	PARENT,
	LCHILD,
	RCHILD,
	START,
};

enum class NODE_COLOR
{
	RED,
	BLACK,
	Default,
};

template<typename T1, typename T2>
struct FPair 
{
	T1		first;		//Ű��
	T1		second;		//���
};


//make pair ����
template<typename T1, typename T2>
FPair<T1, T2> make_mypair(const T1& _first, const T2& _second)
{
	return FPair<T1, T2>{_first, _second};
}

template<typename T1, typename T2>
struct FBSTNode
{
	FPair<T1, T2>		pair;					//data	map������ pair�� �Ҹ���.

	//������尡 �ֱ⶧���� �迭�� ���� �����ϸ� ���� 
	FBSTNode* NodePosition[(int)NODE_ROLE::START];		//�θ� �ڽĵ��� �����ϴ� ���޸�
	NODE_COLOR NodeColor;
	


public:
	bool IsRoot()
	{
		if (nullptr == NodePosition[(int)NODE_ROLE::PARENT])
		{
			
			return true;
		}
		return false;
	}

	bool IsLeftChild()
	{
		if (NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::LCHILD] == this)
		{
			return true;
		}
		return false;
	}

	bool IsRightChild()
	{
		if (NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::RCHILD] == this)
		{
			return true;
		}
		return false;
	}


	//�������
	bool IsLeafNode()
	{
		if (NodePosition[(int)NODE_ROLE::LCHILD] == nullptr && NodePosition[(int)NODE_ROLE::RCHILD] == nullptr)
		{
			return true;
		}

		return false;
	}
	bool IsFullNode()	//�ڽ��� �ٰ��� ����
	{
		if (NodePosition[(int)NODE_ROLE::LCHILD] && NodePosition[(int)NODE_ROLE::RCHILD])
		{
			return true;
		}

		return false;
	}

	NODE_COLOR GetRedColor()
	{
		return NODE_COLOR::RED;
	}

	NODE_COLOR GetBlackColor()
	{
		return NODE_COLOR::BLACK;
	}

	

public:
	FBSTNode():
		pair(),
		NodePosition{},
		NodeColor{}
	{

	}

	FBSTNode(const FPair<T1, T2>& _pair, FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(_pair),
		NodePosition{ _pParent, _pLChild, _pRChild },
		NodeColor(NODE_COLOR::Default)
	{

	}

};


//BST
template <typename T1, typename T2>
class CBST 
{
private:
	FBSTNode<T1,T2>*	m_pRoot;		//root
	int					m_iCount;		//�����Ͱ���



public:
	CBST() :
		m_pRoot(nullptr),
		m_iCount(0)
	{

	}

public:
	bool insert(const FPair<T1,T2>& _pair);
	FBSTNode<T1, T2>* GetInOrderSuccessor(FBSTNode<T1,T2>* _pNode);
	FBSTNode<T1, T2>* GetInOrderPredecessor(FBSTNode<T1, T2>* _pNode);

	
	FBSTNode<T1, T2>* GetParent(FBSTNode<T1, T2>* _pNode);


	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);

private:
	FBSTNode<T1, T2>* DeleteNode(FBSTNode<T1, T2>* _pDelNode);

public:
	class iterator
	{
	private:
		CBST<T1, T2>*		m_pBST;		//bst��ü�� �˰��ձ� 
		FBSTNode<T1, T2>*	m_pNode;	///Ư�� ��带 �˱� 

			//���ͷ����� �񱳿�����
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
			//end iteartor üũ
			assert(m_pNode);

			return m_pNode->pair;
		}

		const FPair<T1, T2>* operator->()
		{
			//end iteartor üũ
			assert(m_pNode);

			return &m_pNode->pair;
		}

		//++ ������ȸ 
		iterator& operator ++()
		{
			//�����ļ��ڸ� ã�´�
			//m_pBST->GetInorderSuccessor(m_pNode);
			m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
			return *this;
		}

		//++ ������ȸ 
		iterator& operator --()
		{
			//�����ļ��ڸ� ã�´�
			//m_pBST->GetInorderSuccessor(m_pNode);
			m_pNode = m_pBST->GetInOrderPredecessor(m_pNode);
			return *this;
		}


	public:
		iterator() :
			m_pNode(nullptr),
			m_pBST(nullptr)
		{

		}
		iterator(CBST<T1, T2>* m_pBST, FBSTNode<T1, T2>* _m_pNode) :
			m_pBST(m_pBST),
			m_pNode(_m_pNode)
		{

		}
		
		friend class CBST<T1,T2>;
	};

};

template<typename T1, typename T2>
 bool CBST<T1, T2>::insert(const FPair<T1, T2>& _pair)
{
	 FBSTNode<T1, T2>* pNewNode = new FBSTNode < T1, T2>(_pair,nullptr,nullptr,nullptr);

	//insert�� �⺻������ redĮ�� �־��ش�
	 NODE_COLOR nodeColor = pNewNode->GetRedColor();
	

	//rootnode
	if (nullptr == m_pRoot)
	{
		nodeColor = pNewNode->GetBlackColor();
		pNewNode->NodeColor = nodeColor;
		m_pRoot = pNewNode;
		
	}
	else
	{
		//2��°�� �ö� root ��� �ȿ� pair.first���� �񱳸� �ؾߵɰŴ� 
		//root���� �����ؼ� leaf��尡 �ɶ����� ���ϸ鼭 �������� �ɰ��̴� �ᱹ �ݺ��� ���...

		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_ROLE nodeType = NODE_ROLE::START;

		//root ���� new�� Ŀ�� ���࿡ ���������� ��� �������ٰ�
		//new�� �̵̹���մ� �����Ͱ� �������� ��ؾߵǳ�?
		//map������쿡�� �ߺ��� ������� �ʴ´� �׷��� �׻� find�Լ��� ����ؼ� �̹� ������ key���� ����ó���� ���� ����ߵȴ�.
		// �ٵ� multmap�� ������ϰ� ���ο���� ���� ��� �߰��ȴ� �ٵ� ���࿡ �̷������� ��������� ����Ž��Ʈ���� ȿ���� ��������.

		while (true)
		{


			//������
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_ROLE::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_ROLE::LCHILD;
			}
			
				//����
			else
			{
				return false;
			}
			
			//�����
			if (nullptr == pNode->NodePosition[(int)nodeType])
			{

				pNode->NodePosition[(int)nodeType] = pNewNode;
				//pNode->NodeColor[(int)nodeColor] = pNewNode;
				pNewNode->NodePosition[(int)NODE_ROLE::PARENT] = pNode;
				pNewNode->NodeColor = nodeColor;
				
				break;

			}
			
			else
			{
				pNode = pNode->NodePosition[(int)nodeType];
			
			}

		

		}
		
		//case�� ���� �ش��� �ȴٸ� Rot
		// red�� �ι��������� �Ͼ��
		//�ڰ����� �Լ��� �ߵ���Ų�� 
		
	}

	++m_iCount;
	return true;
}

//���� �ļ���
template<typename T1, typename T2>
 FBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode)
{
		FBSTNode<T1, T2>* pSuccesor = nullptr;
	
		//1.������ �ڽ��� �ִ� ��� ������ �ڽ����ΰ���, ���� �ڽ��� ������ ���� ������ 
	 if (_pNode->NodePosition[(int)NODE_ROLE::RCHILD] != nullptr)
	 {
		 pSuccesor = _pNode->NodePosition[(int)NODE_ROLE::RCHILD];
		 
		 while (pSuccesor->NodePosition[(int)NODE_ROLE::LCHILD])
		 {
			 pSuccesor =  pSuccesor->NodePosition[(int)NODE_ROLE::LCHILD];
		 }
	 }

	 //2.������ �ڽ��� ������ �θ�� ���� ���� �ڽ� �϶� ���� ���� �ö� 
	 //�׶� �θ� �ļ��� 
	 else
	 {
		 pSuccesor = _pNode;

		 while (pSuccesor != nullptr)	//true�� �����ʴ����� ���ѷ����������մ°� �����ϱ� ���ؼ�
		 {
			 
			 if (pSuccesor->IsRoot())
			 {
				 return nullptr;
			 }
			 else
			 {
				 // ���� ��尡 �θ��� ���� �ڽ��� ��� �θ� �ļ���
				 if (pSuccesor->IsLeftChild())
				 {
					 //�θ��ļ���
					 pSuccesor = GetParent(pSuccesor);
					 break;
				 }
				 else
				 {
					 // ������ �ڽ��� ���, �θ�� ��� �ö�
					 pSuccesor = GetParent(pSuccesor);
				 }
			 }
		 }

		

		
	 }

	return pSuccesor;
}

 //���� ������
 template<typename T1, typename T2>
 inline FBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(FBSTNode<T1, T2>* _pNode)
 {
	 FBSTNode<T1, T2>* pPredecessor = nullptr;

	 //1.���� �ڽ��� �ִ� ��� ���� �ڽ����ΰ���, ������ �ڽ��� ������ ���� ������ 
	 if (_pNode->NodePosition[(int)NODE_ROLE::LCHILD] != nullptr)
	 {
		 pPredecessor = _pNode->NodePosition[(int)NODE_ROLE::LCHILD];

		 while (pPredecessor->NodePosition[(int)NODE_ROLE::RCHILD])
		 {
			 pPredecessor = pPredecessor->NodePosition[(int)NODE_ROLE::RCHILD];
		 }
	 }

	 //2.���� �ڽ��� ������ �θ�� ���� ������ �ڽ� �϶� ���� ���� �ö� 
	 //�׶� �θ� ������ 
	 else
	 {
		 pPredecessor = _pNode;

		 while (pPredecessor != nullptr)
		 {

			 if (pPredecessor->IsRoot())
			 {
				 return nullptr;
			 }
			 else
			 {
				 //�������� üũ
				 if (pPredecessor->IsRightChild())
				 {
					 //�θ�����
					 pPredecessor = GetParent(pPredecessor);
					 break;
				 }
				 else
				 {
					 pPredecessor = GetParent(pPredecessor);
				 }
			 }
		 }




	 }

	 return pPredecessor;
 }

 template<typename T1, typename T2>
 inline FBSTNode<T1, T2>* CBST<T1, T2>::GetParent(FBSTNode<T1, T2>* _pNode)
 {
	 return _pNode->NodePosition[(int)NODE_ROLE::PARENT];
 }

//��ȯŸ���� ���� Ÿ�� �̳�Ŭ������ typename ������ߵ�
template<typename T1, typename T2>
inline typename CBST<T1,T2>::iterator CBST<T1, T2>::begin()
{
	//���̳ʸ� Ž�� ����Ʈ�������� ������ȸ�� �����߿��ϰ� �װ��� ù��°�� �� ���̴�.
	FBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->NodePosition[(int)NODE_ROLE::LCHILD])
	{
		pNode = pNode->NodePosition[(int)NODE_ROLE::LCHILD];
	}
	return iterator(this,pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this,nullptr);
}

template<typename T1, typename T2>
 typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{



	 FBSTNode<T1, T2>* pNode = m_pRoot;
	 NODE_ROLE nodeType = NODE_ROLE::START;

	
	 while (true)
	 {
		//������
		 if (pNode->pair.first < _find)
		 {
			 nodeType = NODE_ROLE::RCHILD;

		 }
		 //����
		 else if (pNode->pair.first > _find)
		 {
			 nodeType = NODE_ROLE::LCHILD;
		 }
		 //����
		 else
		 {	
			 break;
			 
		 }

		 //ã�� ����
		 if (nullptr == pNode->NodePosition[(int)nodeType])
		 {
			 pNode = nullptr;
			 break;
			 

		 }
		 //��ã��
		 else
		 {
			 pNode = pNode->NodePosition[(int)nodeType];

		 }

	 }

	 return iterator(this, pNode);


	
}

 template<typename T1, typename T2>
 typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter)
 {

	 
	
	
	//���� �ļ���, ���� �����ڴ� �ڽ����ϳ��ų� ���°�� �ۿ� ���� 

	 assert(_iter.m_pBST == this);
	 
	 FBSTNode<T1, T2>* pSuccessor  = DeleteNode(_iter.m_pNode);

	 ////1.������ ��尡 �ܸ������ ���
	 //if (_iter.m_pNode->IsLeafNode())
	 //{
		// //�θ� ���� �Ǵ� �ڽ��� ����� �ּҸ� null�� ����� �ش�.
		// if (_iter.m_pNode->IsLeftChild())
		// {
		//	 _iter.m_pNode->ArrNode[(int)NODE_TYPE::PARENT]->ArrNode[(int)NODE_TYPE::LCHILD] = nullptr;
		// }
		// else
		// {
		//	 _iter.m_pNode->ArrNode[(int)NODE_TYPE::PARENT]->ArrNode[(int)NODE_TYPE::RCHILD] = nullptr;
		// }

		// delete _iter.m_pNode;
		// 
	 //}

	 


	 return iterator(this , pSuccessor);
 }

 template<typename T1, typename T2>
 inline FBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(FBSTNode<T1, T2>* _pDelNode)
 {

		 FBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pDelNode);

		 //1.������ ��尡 �ܸ������ ���
		if (_pDelNode->IsLeafNode())
		 {
			pSuccessor = GetInOrderSuccessor(_pDelNode);


			if (_pDelNode == m_pRoot)
			{
				m_pRoot = nullptr;
				
			}
			else
			{
				//�θ� ���� �Ǵ� �ڽ��� ����� �ּҸ� null�� ����� �ش�.
				if (_pDelNode->IsLeftChild())
				{
					_pDelNode->NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::LCHILD] = nullptr;
				}
				else
				{
					_pDelNode->NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::RCHILD] = nullptr;
				}
			}

			--m_iCount;

				delete _pDelNode;
	 
		 }
		//3.������ ��尡 2���� �ڽ��� ������� (���� ������ ,���� �ļ��ڰ� �;ߵȴ� �߿�)
		else if (_pDelNode->IsFullNode())
		{
	
			//������ �� �ڸ��� ���� �ļ����� ���� ���� ��Ų��.
			_pDelNode->pair = pSuccessor->pair;
			

			//���� �ļ��� ��带 ���� �Ѵ�.
			DeleteNode(pSuccessor);


			//������ ��尡 �����ļ��ڰ� �ȴ�.
			pSuccessor = _pDelNode;
	
		}
		//2.������ ��尡 �ڽĳ�带 �Ѱ� ������� (�ڽ��� �θ�� �������ش� )
		else
		{
			pSuccessor = GetInOrderSuccessor(_pDelNode); //�ļ��ڳ�� �̸�ã��

			NODE_ROLE nodetype = NODE_ROLE::LCHILD;
			if (_pDelNode->NodePosition[(int)NODE_ROLE::RCHILD])
			{
				nodetype = NODE_ROLE::RCHILD;
			}

			//������ ��尡 ��Ʈ���
			if (_pDelNode == m_pRoot)
			{
				//���� �ڽ����� �����U �ڽ����� �˾ƾߵ� 
				m_pRoot = _pDelNode->NodePosition[(int)nodetype];
				_pDelNode->NodePosition[(int)nodetype]->ArrNode[(int)NODE_ROLE::PARENT] = nullptr;
			}
			else
			{
				//������ ����� �θ�� ������ ����� �ڽ��� ����
				if (_pDelNode->IsLeftChild())
				{
					_pDelNode->NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::LCHILD] = _pDelNode->NodePosition[(int)nodetype];
				}
				else
				{
					_pDelNode->NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::RCHILD] = _pDelNode->NodePosition[(int)nodetype];
				}

				_pDelNode->NodePosition[(int)nodetype]->ArrNode[(int)NODE_ROLE::PARENT] = _pDelNode->NodePosition[(int)NODE_ROLE::PARENT];


			}

			--m_iCount;

			delete _pDelNode;
		}

		//--m_iCount;

		return pSuccessor;
 }