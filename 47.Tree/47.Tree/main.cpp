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
	int GetParent(int _pIdx)
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

	int GetLeft(int _idx)
	{
		int leftidx = 2 * _idx + 1;
		return leftidx;
	}

	int GetRight(int _idx)
	{
		int rightidx = 2 * _idx + 2;
		return rightidx;
	}

	void TreePrint()
	{
		for (int i = 0; i < m_tree.size(); ++i)
		{
			std::cout << m_tree[i] << std::endl;
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
		
		

	
	*/

	ComplateBianryTree tree;

	for (int i = 0; i < 100; ++i)
	{
		tree.NodeInsert(i);
	}

	tree.TreePrint();

	for (int i = 0; i < tree.GetSize(); ++i)
	{
		int ileft = tree.GetLeft(i);
		int iright = tree.GetRight(i);

		std::cout << "Node : " << i << "Left : ";
		
		if (ileft != -1)
		{
			std::cout << ileft;
		}
		std::cout << "Right : ";
		if (iright != -1)
		{
			std::cout << iright;
		}

		std::cout << std::endl;
	}
	

	return 0;
}