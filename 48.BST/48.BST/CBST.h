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
	
	//레퍼런스경로
	//FBSTNode*			pParent;			//부모 노드
	//FBSTNode*			pLeftChild;			//왼쪽 자식노드
	//FBSTNode*			pRightChild;		//오른쪽 자식노드
	//enum class를 사용해서 배열로 관리
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
