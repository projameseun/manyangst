#pragma once

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


template<typename T1,typename T2>
struct FBSTNode
{
	FPair<T1, T2>		pair;
	
	//���۷������
	//FBSTNode*			pParent;			//�θ� ���
	//FBSTNode*			pLeftChild;			//���� �ڽĳ��
	//FBSTNode*			pRightChild;		//������ �ڽĳ��
	//enum class�� ����ؼ� �迭�� ����
	FBSTNode* ArrNode[(int)NODE_TYPE::START];

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

	 //��ó��
	 if (nullptr == m_pRoot)
	 {
		 m_pRoot = pNewNode;
	 }
	 else
	 {
		 //2��°�� ���ö��� root���ȿ��� pair.first���� �񱳸� �ؾ� �ɰŴ�.
		 //root���� �����ؼ� leaf��尡 ���ö����� ���ϸ鼭 �������� �ȴ�. ���ϸ鼭 ��� �ݺ��� �ϱ� ������ �ݺ����� ����ؾ� �ȴ�.

		 FBSTNode<T1, T2>* pNode = m_pRoot;
		 NODE_TYPE nodeType = NODE_TYPE::START;

#pragma region FIRTST

		 //while (true)
		 //{
			// //������
			// if (pNode->pair.first < pNewNode->pair.first)
			// {
			//	 //�����
			//	 if (nullptr == pNode->pRightChild)
			//	 {
			//		 pNode->pRightChild = pNewNode;
			//		 pNewNode->pParent = pNode;
			//	 }

			//	 //node�� �ٽ� ����
			//	 else
			//	 {
			//		 pNode = pNode->pRightChild;
			//	 }
			// }
			// //����
			// else if (pNode->pair.first > pNewNode->pair.first)
			// {
			//	 //�����
			//	 if (nullptr == pNode->pLeftChild)
			//	 {
			//		 pNode->pLeftChild = pNewNode;
			//		 pNewNode->pParent = pNode;
			//	 }

			//	 //node�� �ٽ� ����
			//	 else
			//	 {
			//		 pNode = pNode->pLeftChild;
			//	 }
			// }
			// //���� 
			// else
			// {
			//	 return false;
			// }

		 //}

#pragma endregion

		 while (true)
		 {
			 //������
			 if (pNode->pair.first < pNewNode->pair.first)
			 {
				 nodeType = NODE_TYPE::RCHILD;
				 //�����
			
			 }
			 //����
			 else if (pNode->pair.first > pNewNode->pair.first)
			 {
				 
				 nodeType = NODE_TYPE::LCHILD;
			 }
			 //���� 
			 else
			 {
				 return false;
			 }

			 //�־��ִ°�
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
