#include <iostream>
#include <vector>
#include <list>
#include "CArray.h"

class Test
{
public:
	int m_iNum;

public:
	Test& operator = (const Test& _other)
	{
		m_iNum = _other.m_iNum;

		return *this;
	}

public:
	//������ ,�Ҹ���
	Test() :
		m_iNum(0)
	{

	}

	//���������..
	Test(const Test& _other) :
		m_iNum(_other.m_iNum)
	{

	}
};



int main()
{
	//����
	//_CONSTEXPR20_CONTAINER _Vector_iterator& operator++() noexcept {
	//	_Mybase::operator++();
	//	return *this;
	//}

	//����
	//_CONSTEXPR20_CONTAINER _Vector_iterator operator++(int) noexcept {
	//	_Vector_iterator _Tmp = *this;
	//	_Mybase::operator++();
	//	return _Tmp;
	//}

	//std::vector<int> vecInt;

	//vecInt.push_back(10);
	//vecInt.push_back(20);
	//vecInt.push_back(30);

	//std::vector<int>::iterator vecIter = vecInt.begin();

	//int iData = *(++vecIter);

	//int iData = *(vecIter++);
	
	
	
	


	//std::cout << (*vecIter) << std::endl;

	//vecIter = vecInt.end();

	////*vecIter;
	//
	////�� itator�� �˰��ִ� �ּҿ�, vector�� �˰� �ִ� �ּҰ� �޶������(������ Ȯ���ϰ� �ּҰ� �޶������)
	//for (int i = 0; i < 10; ++i)
	//{
	//	vecInt.push_back(i);
	//}

	//std::cout << *vecIter << std::endl;
	
	

	/*CArray<int> myVec;

	myVec.push_back(100);
	myVec.push_back(200);
	myVec.push_back(300);

	CArray<int>::iterator myIter = myVec.begin();

	std::cout << *myIter << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		myVec.push_back(i);
	}

	myIter = myVec.end();*/

	
	//CArray<int> myVec;

	//myVec.push_back(10);
	//myVec.push_back(20);
	//myVec.push_back(30);

	//CArray<int>::iterator myIter = myVec.begin();

	//

	//for (int i = 0; i < 10; ++i)
	//{
	//	myVec.push_back(i);
	//}

	//std::cout << *myIter << std::endl;
	

	


	CArray<int> myVec;

	myVec.push_back(100);
	myVec.push_back(200);
	myVec.push_back(300);

	CArray<int>::iterator myIter = myVec.begin();  // begin���� ����

	std::cout << *myIter << std::endl; // 100�� �´��� Ȯ��

	++myIter; // 200���� �ø�
	std::cout << *myIter << std::endl;//�´��� Ȯ��
	--myIter; // 100���� ����
	std::cout << *myIter << std::endl; // �´��� Ȯ��
	myIter++; //200
	std::cout << *myIter << std::endl;
	myIter--; // 100
	std::cout << *myIter << std::endl;
	

	/*++myIter;
	++myIter;
	++myIter;*/

	//myIter++;

	//int iData = *(myIter++);
	//

	//Test t1;

	//t1.m_iNum = 100;

	//
	////���������
	//Test t2 = t1;

	//Test t3(t2);
	
	
	

	return 0;
}