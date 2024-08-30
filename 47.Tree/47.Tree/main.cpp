#include <iostream>
#include <vector>


class ComplateBianryTree
{
private:
	std::vector<int> m_tree;	//Ʈ��

public:
	//������
	void NodeInsert(int _data)
	{
		m_tree.push_back(_data);
	}

	//�θ�
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
			std::cout << "��� �ε��� : " << i << ", �� : " << m_tree[i];

			int pIdx = GetParent(i);

			if (pIdx != -1)
			{
				std::cout << ", �θ� �� : " << m_tree[pIdx];
			}
			else
			{
				std::cout << " , �θ� �� : ����(��Ʈ���)";
			}

			int leftidx = GetLeft(i);

			if (leftidx != -1)
			{

				std::cout << " , ���� �ڽ� �� : " << m_tree[leftidx];
			}
			else
			{
				std::cout << " , ���� �ڽ� �� : ����";
			}

			int rightidx = GetRight(i);

			if (rightidx != -1)
			{

				std::cout << " , ������ �ڽ� �� : " << m_tree[rightidx];
			}
			else
			{
				std::cout << " , ������ �ڽ� �� : ����";
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
		===Ʈ��===
		1.������ ����
		�� ���� ��(data)�� �ٸ������� ����Ű�� ���۷����� �����ȴ�.  

		2.����(edge)
		���� ��带 �����ϴ� �� �������������� ���۷����� �ǹ��Ѵ�. (node ==> data,ref,ref,ref...)�� �����ִ�.

		3.�ֻ��� ��带 root ����� �Ѵ�.
		
		A�� B�� ����Ű�� ������ A�� B�� �θ���,
		B�� A�� �ڽĳ���� �θ���.
		�ڽ��� �ڽ��� �� ���ü��� �ִ�.

		���� �θ� ������ ���� �������(sibling) ��� �θ���.

		�θ��带 ���� ��Ʈ������ �ö󰡸� ������ ��� ���� ������ 

		�ڳ��带 ���� �������� ������ �ִ� ��� ��带 �ڼ� ����� �θ���.

		���γ��: �ڳ��带 ������ ���(branch node ,inner node)
		
		�ܺγ��: �ڳడ ���³�� (leaf node) ��� ���̺θ��� �ѱ����δ� �ܸ� ����� �Ѵ�.

		����� ���� : ���� ��Ʈ��� ������ ��ο��� ������ ��

		��ǥ���ΰ� : winodw���� Ʈ�������̴�.

		===Ʈ���� Ư¡==
		1.��Ʈ���� �ϳ�������
		2.����Ŭ�� ���� ��������
		3.�ڳ���� �ϳ��� �θ� �����Ѵ�.

		�̷� Ʈ���߿� �ڽ���2���� ���� �Ѱ� ����Ʈ��(Binary Tree) ��� �θ���.
		�ִ밡 2�� �̱� ������ �ڽ��� �������� �ְ� �������� �ְ� �Ѱ��� �������� �ִ�.

		�θ��尡 ���� ���� root��尡 �ȴ�.
		���� �Ʒ� �شܿ� �ִ� ���� �ڽ��� ���� ����ϰ��̴�. leaf���� �ڽ��� �������� �ʴ´�.

		��������Ʈ��Ư¡
		root���� �����ؼ� �ڽ��� �׻� 2���� ä�������� Ʈ���� ���Ѵ�
		������ ������ ���ʺ��� �������� ��尡 ä���� �ִ� Ʈ���� ���Ѵ�.
		���� �̷�Ư¡�� ���� �ִ� Ʈ���� �Ϲ������� �迭�� ������ �ϰԵȴ�.

		��Ģ --> ���� �ڽ� 2 * �ε��� +1 // �������ڽ� 2 * �ε��� +2

		=====================
		�츮�� ��¥�ؾߵǴ°�... ����Ž��Ʈ��...
		BST(Binary Search Tree)

		����Ž��Ʈ�� Ư¡
		�ڡڡڡڡ�1.�����Ͱ� ���ĵǾ� �־�� �ȴ�(�������)�ڡڡڡڡ�
		2.�ذ��ؾ� �Ǵ� ������ũ�⸦ �������� �ٿ����鼭 Ž���ϴ� ����̴�.
		3. ��� ����� ���� ����Ʈ�� �ش� ����� ������ ���� ���鸸 ������
		   ��� ����� ������ ����Ʈ���� �ش� ����� ������ ū���鸸 ������ �ȴ�.

		   
		  
		  ��ȭ ����Ʈ�� - ��� ������ ���� ���� �ִ� Ʈ���̴�. �ڽ��� ������ 2�� 
		  ���� ����Ʈ�� - ��� ������ ���� ���ְ�, ������ ����(leaf���)������ ��尡 ���� ���� ä������ ����Ʈ���� ���Ѵ�.
		
		

	
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