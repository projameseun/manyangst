#include <iostream>
#include <vector>
#include <list>
#include "CArray.h"
int main()
{

	
	/*
		c++���� �����̳ʶ� �����͸� �����ϰ� �����ϴµ� ���Ǵ� Ŭ���� ���ø� �̴�.	
		ǥ�� ���̺귯��(STL-Standard Template Libaray)�� ���ԵǾ� �ְ�
		�̴� �پ��� ������ �����͸� ȿ�������� ���� �� �� �ִ� �پ��� �����̳ʵ��� �����ȴ�.
		�����̳ʴ� �����͸� �����ϰ� �����ϴµ� ���Ǵ� ��ü

		�ݺ���(iterator)
		�ݺ��ڴ� �����̳��� ��ҵ鿡 ���������� �����ϱ� ���� ���Ǵ� ��ü�̴�.
		�̳�Ŭ������� �θ���. �ݺ��ڴ� �����Ϳ� ���� ������ ������ �ϸ�, �پ��� �����̳ʿ� �Բ� ���۵ɼ� �ִ�.

		1.�����������̳�(Sequdence Containers)
		������ �����̳ʴ� �����Ϳ�Ҹ� ���������� �����Ѵ�.

		vector,list,array���� �ִ�.

		vcector====
		push_back() ������ �� �߰�
		resize() ���� ũ������
		reserve() ������ �뷮 �̸� �Ҵ�
		capacity() �ִ�ũ�� ��ȯ
		earse() ���� 

		begin() �����̳��� ù��° ��Ҹ� ����Ű�� ���ͷ����� ��ȯ
		end() �����̳� ������ ��Ҵ����� ����Ű�� �ݺ��� ��ȯ 

		list======
		push_front() �տ��߰�
		push_back() �ڿ��߰�
		pop_front() �տ� ����
		pop_back() �� ����
		insert() ������ ��ġ ��� ����

		2.���������̳�(Associate Containers)
		���� �����̳ʴ� Ű�� ����Ͽ� �����͸� �����Ͽ� , �ַ� ���ĵ� ���·� �����ȴ�.
		
		set,map,multmap ��

		3.����� �����̳�(Adapter Containers)
		����� �����̳ʴ� �ٸ� �����̳ʸ� ������� Ư�� ����� �����ϴ� �����̳ʴ�.
		����� �����̳ʴ� ���������� ������ �����̳ʸ� ����Ͽ� ���ѵ� �������̽��� ���� Ư�� ������ �����Ѵ�.

		�ַ� stack LIFO(Last In,Frist Out) ,queue FIFO(First In,First Out) 
		
		stack====
		push() ������ ��ܿ� ����߰�
		pop() ������ ��ܿ� �������
		top() ������ ��ܿ�� ��ȯ
		empty() ������ ��� �ִ��� Ȯ��
		size() ������ ��ȯ

		queue===
		push() ť�� �ڿ� ��Ҹ� �߰�
		pop() ť�� �տ� ��Ҹ� ����
		front() ť�� �� ��Ҹ� ��ȯ
		back() ť�� �� ��Ҹ� ��ȯ
		empty() ť�� ��� �ִ��� ���� Ȯ��
		size() �������ȯ
	

		

	
	*/


	std::vector <int> vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);

	//vecInt[0] = 500;

	//int iNumber = vecInt.at(1);

//	vecInt.data();	//���� �����ּ�
	//vecInt.capacity(); // ���� �ִ밪.

	//if (!vecInt.empty())
	//{
	//	std::cout << "The first character is " << vecInt.front() << std::endl;
	//}

	//if (!vecInt.empty())
	//{
	//	std::cout << "The last character is " << vecInt.back() << std::endl;
	//}

	//for (int i = 0; i < vecInt.size(); ++i)
	//{
	//	std::cout << i + 1 << "Character : " << vecInt[i] << std::endl;
	//}
	
	{
		std::vector<int> vecInt(5, 100);

		for (int i = 0; i < vecInt.size(); ++i)
		{
			std::cout << i + 1 << "Character : " << vecInt[i] << std::endl;
		}

	}

	system("cls");

	//std::vector<int>::iterator iter = vecInt.begin();	// �����̳��� ù��° �ּҸ� ����Ű�� ���ͷ����� ��ȯ

	//iter = vecInt.insert(iter, 200);
	//iter = vecInt.insert(iter,5, 500);
	//
	//for (vecInt.begin(); iter != vecInt.end(); ++iter)
	//{
	//	std::cout << *iter << std::endl;
	//}
	

	{

		std::list<int> listInt;

		listInt.push_back(10);
		listInt.push_back(20);
		listInt.push_back(30);
		listInt.push_back(40);
		listInt.push_back(50);

		listInt.push_front(100);

		//����Ʈ�� iterator�� �����Ѵ� 
		std::list<int>::iterator iter = listInt.begin();	//ù���� �ּҸ� ����Ų��.

		//�����Ͱ��ƴϰ� opterator
		int iNum = *iter;
		++iter;	//���� �ε����� ����Ŵ
		++iter;	//���� �ε����� ����Ŵ
		iNum = *iter;


		std::list<int>::iterator iter2;
	int a = 0;

	}

	{
		//++ ,-- ,!= , == , * , *= 
		
	}
	



	return 0;
}