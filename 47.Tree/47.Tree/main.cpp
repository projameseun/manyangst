#include <iostream>
#include <vector>


class ComplateBianryTree
{
private:
	std::vector<int> m_tree;	//트리

public:
	//노드삽입
	void NodeInsert(int _data)
	{
		m_tree.push_back(_data);
	}

	//부모
	int GetParent(const int _pIdx)
	{
		if (_pIdx == 0)
		{
			return -1;
		}
		else
		{
			return (_pIdx - 1) / 2;
		}
	}

	int GetLeft(const int _idx) 
	{
		int leftidx = 2 * _idx + 1;
		return leftidx < m_tree.size() ? leftidx : -1;
	}

	int GetRight(const int _idx)
	{
		int rightidx = 2 * _idx + 2;

		return rightidx < m_tree.size() ? rightidx : -1;
	}

	void TreePrint()
	{
		for (int i = 0; i < m_tree.size() ; ++i)
		{
			std::cout << "노드 인덱스 : " << i << ", 값 : " << m_tree[i];

			int pIdx = GetParent(i);

			if (pIdx != -1)
			{
				std::cout << ", 부모 값 : " << m_tree[pIdx];
			}
			else
			{
				std::cout << " , 부모 값 : 없음(루트노드)";
			}

			int leftidx = GetLeft(i);

			if (leftidx != -1)
			{

				std::cout << " , 왼쪽 자식 값 : " << m_tree[leftidx];
			}
			else
			{
				std::cout << " , 왼쪽 자식 값 : 없음";
			}

			int rightidx = GetRight(i);

			if (rightidx != -1)
			{

				std::cout << " , 오른쪽 자식 값 : " << m_tree[rightidx];
			}
			else
			{
				std::cout << " , 오른쪽 자식 값 : 없음";
			}

			std::cout << std::endl;
		}
	}

	int GetSize() const
	{
		return m_tree.size();
	}

	
};

int main()
{
	/*
		===트리===
		1.노드들의 집합
		각 노드는 값(data)와 다른노드들을 가리키는 레퍼런스로 구성된다.  

		2.간선(edge)
		노드와 노드를 연결하는 선 구현관점에서는 레퍼런스를 의미한다. (node ==> data,ref,ref,ref...)를 갖고있다.

		3.최상위 노드를 root 노드라고 한다.
		
		A가 B를 가르키고 있을때 A를 B의 부모노드,
		B를 A의 자식노드라고 부른다.
		자식의 자식이 또 나올수도 있다.

		같은 부모를 가지는 노드들 형제노드(sibling) 라고 부른다.

		부모노드를 따라 루트노드까지 올라가며 만나는 모든 노드는 조상노드 

		자녀노드를 따라 내려가며 만날수 있는 모든 노드를 자손 노드라고 부른다.

		내부노드: 자녀노드를 가지는 노드(branch node ,inner node)
		
		외부노드: 자녀가 없는노드 (leaf node) 라고 많이부르고 한국말로는 단말 노드라고 한다.

		노드의 레벨 : 노드와 루트노드 사이의 경로에서 간선의 수

		대표적인게 : winodw폴더 트리구조이다.

		===트리의 특징==
		1.루트노드는 하나만존재
		2.사이클이 존재 하지않음
		3.자녀노드는 하나의 부모만 존재한다.

		이런 트리중에 자식을2개로 제한 한걸 이진트리(Binary Tree) 라고 부른다.
		최대가 2개 이기 때문에 자식이 있을수도 있고 없을수도 있고 한개만 있을수도 있다.

		부모노드가 없는 노드는 root노드가 된다.
		가장 아래 밑단에 있는 노드는 자식이 없는 노드일것이다. leaf노드는 자식이 존재하지 않는다.

		완전이진트리특징
		root노드로 시작해서 자식을 항상 2개로 채워나가는 트리를 말한다
		마지막 레벨은 왼쪽부터 빠짐없이 노드가 채워져 있는 트리를 말한다.
		또한 이런특징을 갖고 있는 트리는 일반적으로 배열로 구현을 하게된다.

		규칙 --> 왼쪽 자식 2 * 인덱스 +1 // 오른쪽자식 2 * 인덱스 +2

		=====================
		우리가 진짜해야되는거... 이진탐색트리...
		BST(Binary Search Tree)

		이진탐색트리 특징
		★★★★★1.데이터가 정렬되어 있어야 된다(순서대로)★★★★★
		2.해결해야 되는 데이터크기를 절반으로 줄여가면서 탐색하는 방식이다.
		3. 모든 노드의 왼쪽 서브트리 해당 노드의 값보다 작은 값들만 가지고
		   모든 노드의 오른쪽 서브트리는 해당 노드의 값보다 큰값들만 가져야 된다.

		   
		  
		  포화 이진트리 - 모든 레벨이 노드로 꽉차 있는 트리이다. 자식이 무조건 2개 
		  완전 이진트리 - 모든 레벨이 노드로 차있고, 마지막 레벨(leaf노드)에서는 노드가 왼쪽 부터 채워지는 이진트리를 말한다.
		
		

	
	*/

	ComplateBianryTree tree;

	tree.NodeInsert(200);
	tree.NodeInsert(100);
	tree.NodeInsert(300);
	tree.NodeInsert(50);
	tree.NodeInsert(75);
	tree.NodeInsert(250);
	tree.NodeInsert(500);
	tree.NodeInsert(25);

	/*for (int i = 0; i < 100; ++i)
	{
		tree.NodeInsert(i);
	}*/

	tree.TreePrint();


	

	return 0;
}