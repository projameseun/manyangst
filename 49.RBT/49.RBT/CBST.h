#pragma once
#include <assert.h>

enum class NODE_POS
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
	FBSTNode* NodePosition[(int)NODE_POS::START];		//�θ� �ڽĵ��� �����ϴ� ���޸�
	NODE_COLOR NodeColor;



public:
	bool IsRoot()
	{
		if (nullptr == NodePosition[(int)NODE_POS::PARENT])
		{

			return true;
		}
		return false;
	}


	bool IsLeftChild()
	{
		if (NodePosition[(int)NODE_POS::PARENT]->NodePosition[(int)NODE_POS::LCHILD] == this)
		{
			return true;
		}
		return false;
	}

	bool IsRightChild()
	{
		if (NodePosition[(int)NODE_POS::PARENT]->NodePosition[(int)NODE_POS::RCHILD] == this)
		{
			return true;
		}
		return false;
	}


	//�������
	bool IsLeafNode()
	{
		if (NodePosition[(int)NODE_POS::LCHILD] == nullptr && NodePosition[(int)NODE_POS::RCHILD] == nullptr)
		{
			return true;
		}

		return false;
	}
	bool IsFullNode()	//�ڽ��� �ٰ��� ����
	{
		if (NodePosition[(int)NODE_POS::LCHILD] && NodePosition[(int)NODE_POS::RCHILD])
		{
			return true;
		}

		return false;
	}

	int  Getpairfirst()
	{
		return pair.first;
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
	//Default ������
	FBSTNode() :
		pair(),
		NodePosition{},
		NodeColor{}
	{
		int a = 0;
	}

	//�ʱ�ȭ ������
	FBSTNode(const FPair<T1, T2>& _pair, FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(_pair),
		NodePosition{ _pParent, _pLChild, _pRChild },
		NodeColor(NODE_COLOR::Default)
	{

		int a = 0;
	}
	//Nil��� ������
	FBSTNode(FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(make_mypair(0, 0)),
		NodePosition{ _pParent, _pLChild, _pRChild },
		NodeColor(NODE_COLOR::Default)
	{
		int a = 0;
	}

};


//BST
template <typename T1, typename T2>
class CBST
{
private:
	FBSTNode<T1, T2>*	m_pRoot;		//root
	FBSTNode<T1, T2>*	m_pNil;
	int					m_iCount;		//�����Ͱ���



public:
	CBST() :
		m_pRoot(nullptr),
		m_iCount(0)
	{




	}

public:
	bool insert(const FPair<T1, T2>& _pair);
	FBSTNode<T1, T2>* GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetInOrderPredecessor(FBSTNode<T1, T2>* _pNode);


	FBSTNode<T1, T2>* GetParent(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetGrandParent(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetUncle(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetSibling(FBSTNode<T1, T2>* _pNode);
	
	NODE_POS ChangeNodePos(FBSTNode<T1, T2>* _pNode, NODE_POS _pos);

	class iterator;
public:
	iterator begin();
	iterator end();
	iterator GetNilNode();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);
	iterator insert(const iterator& _iter, const FPair<T1, T2>& _pair);

private:
	FBSTNode<T1, T2>* CASE(FBSTNode<T1, T2>*_pNewNode);
	FBSTNode<T1, T2>* CASEONE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);
	FBSTNode<T1, T2>* CASETWO(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);
	FBSTNode<T1, T2>* CASETHREE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _role);

	FBSTNode<T1, T2>* Rotation(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos, int _iNumber);

private:
	FBSTNode<T1, T2>* DeleteNode(FBSTNode<T1, T2>* _pDelNode);

public:
	class iterator
	{
	private:
		CBST<T1, T2>* m_pBST;		//bst��ü�� �˰��ձ� 
		FBSTNode<T1, T2>* m_pNode;	///Ư�� ��带 �˱� 

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
			//���������ڸ� ã�´�
			//m_pBST->GetInorderSuccessor(m_pNode);
			m_pNode = m_pBST->GetInOrderPredecessor(m_pNode);
			return *this;
		}


	public:
		iterator() :
			m_pBST(nullptr),
			m_pNode(nullptr)
		{

		}
		iterator(CBST<T1, T2>* m_pBST, FBSTNode<T1, T2>* _m_pNode) :
			m_pBST(m_pBST),
			m_pNode(_m_pNode)
		{

		}

		

		friend class CBST<T1, T2>;
	};

};

template<typename T1, typename T2>
bool CBST<T1, T2>::insert(const FPair<T1, T2>& _pair)
{
	FBSTNode<T1, T2>* pNewNode = new FBSTNode < T1, T2>(_pair, nullptr, nullptr, nullptr);


	//insert�� �⺻������ redĮ�� �־��ش�
	NODE_COLOR nodeColor = pNewNode->GetRedColor();


	//rootnode
	if (nullptr == m_pRoot)
	{
		//NillNode Init
		FBSTNode<T1, T2>* pNewNillNode = new FBSTNode < T1, T2>(nullptr, nullptr, nullptr);
		m_pNil = pNewNillNode;
		m_pNil->NodeColor = m_pNil->GetBlackColor();

		nodeColor = pNewNode->GetBlackColor();
		pNewNode->NodeColor = nodeColor;
		m_pRoot = pNewNode;

		m_pRoot->NodePosition[(int)NODE_POS::PARENT] = m_pNil;

		m_pRoot->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
		m_pRoot->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;

	}
	else 
	{
		//2��°�� �ö� root ��� �ȿ� pair.first���� �񱳸� �ؾߵɰŴ� 
		//root���� �����ؼ� leaf��尡 �ɶ����� ���ϸ鼭 �������� �ɰ��̴� �ᱹ �ݺ��� ���...
		
		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_POS nodeType = NODE_POS::START;

		//root ���� new�� Ŀ�� ���࿡ ���������� ��� �������ٰ�
		//new�� �̵̹���մ� �����Ͱ� �������� ��ؾߵǳ�?
		//map������쿡�� �ߺ��� ������� �ʴ´� �׷��� �׻� find�Լ��� ����ؼ� �̹� ������ key���� ����ó���� ���� ����ߵȴ�.
		// �ٵ� multmap�� ������ϰ� ���ο���� ���� ��� �߰��ȴ� �ٵ� ���࿡ �̷������� ��������� ����Ž��Ʈ���� ȿ���� ��������.

		while (true)
		{


			//������
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_POS::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_POS::LCHILD;
			}

			//����
			else
			{
				return false;
			}

			//�����
			if (pNode->NodePosition[(int)nodeType]->IsLeafNode())
			{

				pNode->NodePosition[(int)nodeType] = pNewNode;
				//pNode->NodeColor[(int)nodeColor] = pNewNode;
				pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNode;
				pNewNode->NodeColor = nodeColor;

				break;

			}

			else
			{
				pNode = pNode->NodePosition[(int)nodeType];

			}



		}

		if (pNewNode->IsLeafNode())
		{
			pNewNode->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
			pNewNode->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;
		}


		//RBT ���� ����
	//1.���� red �Ǵ� black�̿��� �Ѵ�.
	//2. root���� black�̿��� �ȴ�.
	//3. ��� �������(NIL)���� ���̴�.
	//4. ���尡 ���������� �Ͼ�� ����. 
	//5. � ���κ��� ������ �Ǿ� �׿� ���� ���� ������忡 ���� �ϴ°�� ��� ��ο��� �ڱ��ڽ��� �����ϰ� ���� ���� �׻󰰴�.


	

		//RED �ΰ��� 4���Ӽ����� 
		if (pNewNode->NodePosition[(int)NODE_POS::PARENT]->NodeColor == nodeColor)
		{
			CASE(pNewNode);
		}

	}
	
		//��� root���� �ٽ� black���� �������ش�.
		if (m_pRoot->NodeColor != NODE_COLOR::BLACK)
		{
			m_pRoot->NodeColor = NODE_COLOR::BLACK;
		}

	++m_iCount;
	return true;
}

template<typename T1, typename T2>
 typename FBSTNode<T1, T2>* CBST<T1, T2>::CASE(FBSTNode<T1, T2>* _pNewNode)
{

	std::cout << "Case �߻�!" << std::endl;

	
	if (_pNewNode == nullptr) return nullptr;


	NODE_POS CheckPosition = NODE_POS::START;
	NODE_POS CheckPosition2 = NODE_POS::START;

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewNodeGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);


	//NewNode�� NewNode�� �θ��� ���� ���� ���ؼ� ����������� ã�Ƴ���

/*	if (pNewNode->pair.first == pNewNodeParent->NodePosition[(int)nodeType]->Getpairfirst())
	{
		std::cout << "New�ڽ� �θ��� ������ ����" << std::endl;
		CheckPosition = NODE_ROLE::LCHILD;


	}
	else
	{
		CheckPosition = NODE_ROLE::RCHILD;
	}*/


	if (pNewNodeParent == nullptr || pNewNodeGradParent == nullptr)
	{
		return _pNewNode;
	}


	//�ܹ������� ���������� üũ���ִ� �Լ��� �����.

	CheckPosition = ChangeNodePos(_pNewNode, CheckPosition);
	CheckPosition2 = ChangeNodePos(pNewNodeParent, CheckPosition2);

	if (CheckPosition == NODE_POS::START || CheckPosition2 == NODE_POS::START)
	{
		return _pNewNode;
	}



	//CASE 1 
	//�θ�,������ ������ black���� �����Ѵ� �׸��� �Ҿƹ����� ����� �����ϰ� 
	//�Ҿƹ������� �ݵ�� üũ�� �Ѵ�.
	if (pNewNodeParent->NodeColor == NODE_COLOR::RED && pNewUncle->NodeColor == NODE_COLOR::RED)
	{
		 CASEONE(_pNewNode, CheckPosition);

		if (m_pRoot->NodeColor != NODE_COLOR::BLACK)
		{
			m_pRoot->NodeColor = NODE_COLOR::BLACK;
		}
		//�Ҿƹ������� �ٽ� Ȯ���Ѵ�.
		return CASE(pNewNodeGradParent);
		
	}

	//CASE 2
	//�������̰� ������ ���̶�� �߻��Ѵ�.
	//�׷��ٸ� �ش� �θ��� �������� ȸ���� �ؼ� CASE3������ ����� �ش�.
	else if (CheckPosition != CheckPosition2 && pNewUncle->NodeColor == NODE_COLOR::BLACK && _pNewNode->NodeColor == NODE_COLOR::RED && pNewNodeParent->NodeColor == NODE_COLOR::RED)
	{
		CASETWO(_pNewNode, CheckPosition);

		//ȸ��
		_pNewNode = Rotation(_pNewNode, CheckPosition2, 2);

		return CASE(_pNewNode);
	}
	

	//�ڽİ� �θ� �ܹ����̰� ������ ���϶� 3�����̽� �߻�
	// �θ�� �Ҿƹ����� ���� �������� �Ҿƹ��� �������� ȸ���� �Ѵ�.
	//CASE 3
	else if (CheckPosition == CheckPosition2 && pNewUncle->NodeColor == NODE_COLOR::BLACK)
	{
		
		//�θ�� �Ҿƹ��� ���� ����
		CASETHREE(_pNewNode,CheckPosition);

	

		if (CheckPosition2 != NODE_POS::LCHILD)
		{
			CheckPosition2 = NODE_POS::LCHILD;
		}

		else
		{
			CheckPosition2 = NODE_POS::RCHILD;

		}


		 _pNewNode = Rotation(_pNewNode, CheckPosition2, 3);
		
		
	}
	

	


	return _pNewNode;
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASEONE(FBSTNode<T1, T2>* _pNewNode,NODE_POS _pos)
{
	//���� �θ� ����Ȯ��

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);

	pNewNodeParent->NodeColor = NODE_COLOR::BLACK;
	pNewUncle->NodeColor = NODE_COLOR::BLACK;
	pNewGradParent->NodeColor = NODE_COLOR::RED;
	
	

	return pNewGradParent;
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASETWO(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos)
{


	return _pNewNode;
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASETHREE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos)
{

	NODE_COLOR tempColor = NODE_COLOR::Default;

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewGradParent = GetGrandParent(_pNewNode);

	//ȸ��
	//1.�θ�� �Ҿƹ��� ���� ���� 
	tempColor = pNewNodeParent->NodeColor;
	pNewNodeParent->NodeColor = pNewGradParent->NodeColor;
	pNewGradParent->NodeColor = tempColor;

	

	//2.�Ҿƹ��� �������� ȸ��


	return _pNewNode;
}

template<typename T1, typename T2>
typename  FBSTNode<T1, T2>* CBST<T1, T2>::Rotation(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos, int _iCase)
{

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewNodeGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);
	//FBSTNode<T1, T2>* pNewSibling = GetSibling(_pNewNode);

	//�Ҿƹ����� �Ҿƹ��� ����
	FBSTNode<T1, T2>* pNewGGParent = GetParent(pNewNodeGradParent);

	NODE_POS CheckPosition = NODE_POS::START;

	//���� �־��� ��忡�� ©���� ���ο� ��忡 �ڽ��� ������ ���
	FBSTNode<T1, T2>* pNewChildNode = nullptr;
	
	
	if (pNewNodeParent == nullptr || pNewNodeGradParent == nullptr || pNewGGParent == nullptr)
	{
		return _pNewNode;
	}

	
	if (_iCase == 2)
	{

		//ȸ���� �θ�������� ���������� ���� �������� ������ ������� �ȴ�.
		
		
		//�θ��� �ڽ��� ����
		if (_pos == NODE_POS::LCHILD)
		{
			pNewChildNode = _pNewNode->NodePosition[(int)NODE_POS::LCHILD];

			_pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeGradParent;
			_pNewNode->NodePosition[(int)NODE_POS::LCHILD] = pNewNodeParent;
			
			pNewNodeGradParent->NodePosition[(int)::NODE_POS::LCHILD] = _pNewNode;
			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = _pNewNode;

			pNewNodeParent->NodePosition[(int)::NODE_POS::RCHILD] = pNewChildNode;
			pNewChildNode->NodePosition[(int)::NODE_POS::PARENT] = pNewNodeParent;
		
			
			
	


			
		}
		//�θ��� �ڽ��� ������
		else if(_pos == NODE_POS::RCHILD)
		{
			pNewChildNode = _pNewNode->NodePosition[(int)NODE_POS::RCHILD];

			_pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeGradParent;
			_pNewNode->NodePosition[(int)NODE_POS::RCHILD] = pNewNodeParent;

			pNewNodeGradParent->NodePosition[(int)::NODE_POS::RCHILD] = _pNewNode;
			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = _pNewNode;

			pNewNodeParent->NodePosition[(int)::NODE_POS::LCHILD] = pNewChildNode;
			pNewChildNode->NodePosition[(int)::NODE_POS::PARENT] = pNewNodeParent;
		}

		return pNewNodeParent;
		

	}

	//�Ҿƹ��� �������� ȸ���� �Ѵ�
	else if (_iCase == 3)
	{

		

		if (pNewNodeGradParent == m_pRoot)
		{
			m_pRoot = pNewNodeParent;
		}


		if (_pos == NODE_POS::LCHILD)
		{
		
			pNewChildNode = pNewNodeParent->NodePosition[(int)NODE_POS::LCHILD];
			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = pNewGGParent;
			

			CheckPosition = ChangeNodePos(pNewNodeGradParent, CheckPosition);
			
			pNewGGParent->NodePosition[(int)CheckPosition] = pNewNodeParent;
			
			pNewNodeParent->NodePosition[(int)NODE_POS::LCHILD] = pNewNodeGradParent;

			
			pNewNodeGradParent->NodePosition[(int)NODE_POS::PARENT] = pNewNodeParent;

			pNewNodeGradParent->NodePosition[(int)NODE_POS::RCHILD] = pNewChildNode;
			pNewChildNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeGradParent;


		}
		else if (_pos == NODE_POS::RCHILD)
		{
		
			pNewChildNode = pNewNodeParent->NodePosition[(int)NODE_POS::RCHILD];

			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = pNewGGParent;


			CheckPosition = ChangeNodePos(pNewNodeGradParent, CheckPosition);

			pNewGGParent->NodePosition[(int)CheckPosition] = pNewNodeParent;

			pNewNodeParent->NodePosition[(int)NODE_POS::RCHILD] = pNewNodeGradParent;


			pNewNodeGradParent->NodePosition[(int)NODE_POS::PARENT] = pNewNodeParent;

			pNewNodeGradParent->NodePosition[(int)NODE_POS::LCHILD] = pNewChildNode;
			pNewChildNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeGradParent;


		}

		
		return _pNewNode = pNewNodeGradParent;
		
	}
	

	
}



//���� �ļ���
template<typename T1, typename T2>
FBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pSuccesor = nullptr;

	//1.������ �ڽ��� �ִ� ��� ������ �ڽ����ΰ���, ���� �ڽ��� ������ ���� ������ 
	if (_pNode->NodePosition[(int)NODE_POS::RCHILD] != m_pNil)
	{
		pSuccesor = _pNode->NodePosition[(int)NODE_POS::RCHILD];

		while (pSuccesor->NodePosition[(int)NODE_POS::LCHILD] != m_pNil)
		{
			pSuccesor = pSuccesor->NodePosition[(int)NODE_POS::LCHILD];
		}
	}

	//2.������ �ڽ��� ������ �θ�� ���� ���� �ڽ� �϶� ���� ���� �ö� 
	//�׶� �θ� �ļ��� 
	else
	{
		pSuccesor = _pNode;


		while (pSuccesor != m_pNil)	//true�� �����ʴ����� ���ѷ����������մ°� �����ϱ� ���ؼ�
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
	if (_pNode->NodePosition[(int)NODE_POS::LCHILD] != m_pNil)
	{
		pPredecessor = _pNode->NodePosition[(int)NODE_POS::LCHILD];

		while (pPredecessor->NodePosition[(int)NODE_POS::RCHILD] != m_pNil)
		{
			pPredecessor = pPredecessor->NodePosition[(int)NODE_POS::RCHILD];
		}
	}

	//2.���� �ڽ��� ������ �θ�� ���� ������ �ڽ� �϶� ���� ���� �ö� 
	//�׶� �θ� ������ 
	else
	{
		pPredecessor = _pNode;

		while (pPredecessor != m_pNil)
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
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::GetParent(FBSTNode<T1, T2>* _pNode)
{
	return _pNode->NodePosition[(int)NODE_POS::PARENT];
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::GetGrandParent(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pNodeParent = _pNode->NodePosition[(int)NODE_POS::PARENT];
	return pNodeParent->NodePosition[(int)NODE_POS::PARENT];
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::GetUncle(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pNodeParent = _pNode->NodePosition[(int)NODE_POS::PARENT];
	FBSTNode<T1, T2>* pNodeGrandParent = pNodeParent->NodePosition[(int)NODE_POS::PARENT];
	NODE_POS UnclePos = NODE_POS::START;

	if (pNodeParent == nullptr)
	{
		return nullptr;
	}

	if (pNodeGrandParent == nullptr)
	{
		return nullptr;
	}
	if (pNodeParent->IsLeftChild())
	{
		UnclePos = NODE_POS::RCHILD;
	}
	else
	{
		UnclePos = NODE_POS::LCHILD;
	}



	
	return pNodeGrandParent->NodePosition[(int)UnclePos];
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::GetSibling(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pNodeParent = _pNode->NodePosition[(int)NODE_POS::PARENT];

	FBSTNode<T1, T2>* pNodeSibling = nullptr;
	if (pNodeParent == nullptr)
	{
		return nullptr;
	}

	//�����ڽ�
	if (_pNode->IsLeftChild())
	{
		
		pNodeParent->NodePosition[(int)NODE_POS::RCHILD];
		return pNodeSibling;
	}
	//�������ڽ�
	if(_pNode->IsRightChild())
	{
		pNodeSibling = pNodeParent->NodePosition[(int)NODE_POS::LCHILD];
		return pNodeSibling;
	}
	


	
}



template<typename T1, typename T2>
typename NODE_POS CBST<T1, T2>::ChangeNodePos(FBSTNode<T1, T2>* _pNode, NODE_POS _pos)
{

	//�ܹ������� ����������
	if (_pNode->IsLeftChild())
	{
		
		_pos = NODE_POS::LCHILD;
	}

	else if (_pNode->IsRightChild())
	{
		
		_pos = NODE_POS::RCHILD;
	}
	else
	{
		
		std::cout << "�ٸ���" << std::endl;
	}



	return _pos;
}



//��ȯŸ���� ���� Ÿ�� �̳�Ŭ������ typename ������ߵ�
template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	//���̳ʸ� Ž�� ����Ʈ�������� ������ȸ�� �����߿��ϰ� �װ��� ù��°�� �� ���̴�.
	FBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->NodePosition[(int)NODE_POS::LCHILD] != m_pNil)
	{
		pNode = pNode->NodePosition[(int)NODE_POS::LCHILD];
		
		
	}
	return iterator(this,pNode);

}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename  CBST<T1, T2>::iterator CBST<T1, T2>::GetNilNode()
{
	FBSTNode<T1, T2>* pNode = m_pNil;
	return iterator(this , pNode);
}

template<typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{



	FBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_POS nodeType = NODE_POS::START;


	while (true)
	{
		//������
		if (pNode->pair.first < _find)
		{
			nodeType = NODE_POS::RCHILD;

		}
		//����
		else if (pNode->pair.first > _find)
		{
			nodeType = NODE_POS::LCHILD;
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

	FBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);

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




	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::insert(const iterator& _iter, const FPair<T1, T2>& _pair)
{


	FBSTNode<T1, T2>* pNewNode = new FBSTNode < T1, T2>(_pair, nullptr, nullptr, nullptr);


	//insert�� �⺻������ redĮ�� �־��ش�
	NODE_COLOR nodeColor = pNewNode->GetRedColor();


	//rootnode
	if (nullptr == m_pRoot)
	{
		//NillNode Init
		FBSTNode<T1, T2>* pNewNillNode = new FBSTNode < T1, T2>(nullptr, nullptr, nullptr);
		m_pNil = pNewNillNode;
		m_pNil->NodeColor = m_pNil->GetBlackColor();

		nodeColor = pNewNode->GetBlackColor();
		pNewNode->NodeColor = nodeColor;
		m_pRoot = pNewNode;

		m_pRoot->NodePosition[(int)NODE_POS::PARENT] = m_pNil;

		m_pRoot->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
		m_pRoot->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;

	}
	else
	{
		//2��°�� �ö� root ��� �ȿ� pair.first���� �񱳸� �ؾߵɰŴ� 
		//root���� �����ؼ� leaf��尡 �ɶ����� ���ϸ鼭 �������� �ɰ��̴� �ᱹ �ݺ��� ���...

		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_POS nodeType = NODE_POS::START;

		//root ���� new�� Ŀ�� ���࿡ ���������� ��� �������ٰ�
		//new�� �̵̹���մ� �����Ͱ� �������� ��ؾߵǳ�?
		//map������쿡�� �ߺ��� ������� �ʴ´� �׷��� �׻� find�Լ��� ����ؼ� �̹� ������ key���� ����ó���� ���� ����ߵȴ�.
		// �ٵ� multmap�� ������ϰ� ���ο���� ���� ��� �߰��ȴ� �ٵ� ���࿡ �̷������� ��������� ����Ž��Ʈ���� ȿ���� ��������.

		while (true)
		{


			//������
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_POS::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_POS::LCHILD;
			}

			//����
			else
			{
				return  iterator(nullptr, nullptr);
			}

			//�����
			if (pNode->NodePosition[(int)nodeType]->IsLeafNode())
			{

				pNode->NodePosition[(int)nodeType] = pNewNode;
				//pNode->NodeColor[(int)nodeColor] = pNewNode;
				pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNode;
				pNewNode->NodeColor = nodeColor;

				break;

			}

			else
			{
				pNode = pNode->NodePosition[(int)nodeType];

			}



		}

		if (pNewNode->IsLeafNode())
		{
			pNewNode->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
			pNewNode->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;
		}

	


		return iterator(this,pNewNode);
	}
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
				_pDelNode->NodePosition[(int)NODE_POS::PARENT]->ArrNode[(int)NODE_POS::LCHILD] = nullptr;
			}
			else
			{
				_pDelNode->NodePosition[(int)NODE_POS::PARENT]->ArrNode[(int)NODE_POS::RCHILD] = nullptr;
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

		NODE_POS nodetype = NODE_POS::LCHILD;
		if (_pDelNode->NodePosition[(int)NODE_POS::RCHILD])
		{
			nodetype = NODE_POS::RCHILD;
		}

		//������ ��尡 ��Ʈ���
		if (_pDelNode == m_pRoot)
		{
			//���� �ڽ����� �����U �ڽ����� �˾ƾߵ� 
			m_pRoot = _pDelNode->NodePosition[(int)nodetype];
			_pDelNode->NodePosition[(int)nodetype]->ArrNode[(int)NODE_POS::PARENT] = nullptr;
		}
		else
		{
			//������ ����� �θ�� ������ ����� �ڽ��� ����
			if (_pDelNode->IsLeftChild())
			{
				_pDelNode->NodePosition[(int)NODE_POS::PARENT]->ArrNode[(int)NODE_POS::LCHILD] = _pDelNode->NodePosition[(int)nodetype];
			}
			else
			{
				_pDelNode->NodePosition[(int)NODE_POS::PARENT]->ArrNode[(int)NODE_POS::RCHILD] = _pDelNode->NodePosition[(int)nodetype];
			}

			_pDelNode->NodePosition[(int)nodetype]->ArrNode[(int)NODE_POS::PARENT] = _pDelNode->NodePosition[(int)NODE_POS::PARENT];


		}

		--m_iCount;

		delete _pDelNode;
	}

	//--m_iCount;

	return pSuccessor;
}

