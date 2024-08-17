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
	//생성자 ,소멸자
	Test() :
		m_iNum(0)
	{

	}

	//복사생성자..
	Test(const Test& _other) :
		m_iNum(_other.m_iNum)
	{

	}
};



int main()
{
	//전위
	//_CONSTEXPR20_CONTAINER _Vector_iterator& operator++() noexcept {
	//	_Mybase::operator++();
	//	return *this;
	//}

	//후위
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
	////비교 itator가 알고있는 주소와, vector가 알고 있는 주소가 달라진경우(공간을 확장하고 주소가 달라질경우)
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

	CArray<int>::iterator myIter = myVec.begin();  // begin에서 시작

	std::cout << *myIter << std::endl; // 100이 맞는지 확인

	++myIter; // 200으로 올림
	std::cout << *myIter << std::endl;//맞는지 확인
	--myIter; // 100으로 낮춤
	std::cout << *myIter << std::endl; // 맞는지 확인
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
	////복사생성자
	//Test t2 = t1;

	//Test t3(t2);
	
	
	

	return 0;
}