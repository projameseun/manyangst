#include <iostream>
#include <vector>
#include <list>
#include "CArray.h"
int main()
{

	
	/*
		c++에서 컨테이너란 데이터를 저장하고 관리하는데 사용되는 클래스 템플릿 이다.	
		표준 라이브러리(STL-Standard Template Libaray)에 포함되어 있고
		이는 다양한 유형의 데이터를 효율적으로 관리 할 수 있는 다양한 컨테이너들이 제공된다.
		컨테이너는 데이터를 저장하고 관리하는데 사용되는 객체

		반복자(iterator)
		반복자는 컨테이너의 요소들에 순차적으로 접근하기 위해 사용되는 객체이다.
		이너클래스라고 부른다. 반복자는 포인터와 아주 유사한 동작을 하며, 다양한 컨테이너와 함께 동작될수 있다.

		1.시퀀스컨테이너(Sequdence Containers)
		시퀀스 컨테이너는 데이터요소를 순차적으로 저장한다.

		vector,list,array등이 있다.

		vcector====
		push_back() 백터의 끝 추가
		resize() 백터 크기조절
		reserve() 지정된 용량 미리 할당
		capacity() 최대크기 반환
		earse() 삭제 

		begin() 컨테이너의 첫번째 요소를 가리키는 이터레이터 반환
		end() 컨테이너 마지막 요소다음을 가리키는 반복자 반환 

		list======
		push_front() 앞에추가
		push_back() 뒤에추가
		pop_front() 앞에 제거
		pop_back() 뒤 삭제
		insert() 지정된 위치 요소 삽입

		2.연관컨테이너(Associate Containers)
		연관 컨테이너는 키를 사용하여 데이터를 저장하여 , 주로 정렬된 상태로 유지된다.
		
		set,map,multmap 등

		3.어댑터 컨테이너(Adapter Containers)
		어댑터 컨테이너는 다른 컨테이너를 기반으로 특정 기능을 제공하는 컨테이너다.
		어댑터 컨테이너는 내부적으로 시퀀스 컨테이너를 사용하여 제한된 인터페이스를 통해 특정 동작을 수행한다.

		주로 stack LIFO(Last In,Frist Out) ,queue FIFO(First In,First Out) 
		
		stack====
		push() 스택의 상단에 요소추가
		pop() 스택의 상단에 요소제거
		top() 스택의 상단요소 반환
		empty() 스택이 비어 있는지 확인
		size() 사이즈 반환

		queue===
		push() 큐의 뒤에 요소를 추가
		pop() 큐의 앞에 요소를 제거
		front() 큐의 앞 요소를 반환
		back() 큐의 뒤 요소를 반환
		empty() 큐가 비어 있는지 여부 확인
		size() 사이즈반환
	

		

	
	*/


	std::vector <int> vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);

	//vecInt[0] = 500;

	//int iNumber = vecInt.at(1);

//	vecInt.data();	//최초 시작주소
	//vecInt.capacity(); // 현재 최대값.

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

	//std::vector<int>::iterator iter = vecInt.begin();	// 컨테이너의 첫번째 주소를 가리키는 이터레이터 반환

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

		//리스트는 iterator를 제공한다 
		std::list<int>::iterator iter = listInt.begin();	//첫번재 주소를 가리킨다.

		//포인터가아니고 opterator
		int iNum = *iter;
		++iter;	//다음 인덱스를 가리킴
		++iter;	//다음 인덱스를 가리킴
		iNum = *iter;


		std::list<int>::iterator iter2;
	int a = 0;

	}

	{
		//++ ,-- ,!= , == , * , *= 
		
	}
	



	return 0;
}