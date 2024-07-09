#include <iostream>

struct Student
{
	std::string stName;
	int iScore;


public:
	void PrintInfo(Student* st,int size)
	{
		for (int i = 0; i < size; ++i)
		{
			std::cout << "이름 : " << st[i].stName << "점수 : " << st[i].iScore << std::endl;
		}
	}
};



int main()
{
	/*
		동적할당(Dynamic Allocaton)은 메모리를 런타임에서 결정나고
		동적으로 할당,해제 하는것을 말합니다. 또한 프로그램 실행중에
		메모리를 할당하고 해제 할 수 있어서 더 유연한 메모리 관리를 가능하게 한다.

		c - malloc(),calloc() ,relloc() 과 같은 함수를 사용해서 할당하고
		free()로 해제한다.

		c++ new할당하고
		delete해제 한다.

		동적할당은 주로 배열,구조체,객체(클래스)등의 데이터구조를 다룰때 유용하게 사용한다.

		동적할당을 하고 메모리를 해제를 하지 않게되면 메모리 누스(memory leak)가 생기는데 이를 꼭 방지해줘야 된다.
		메모리를 할당하게 되면 무조건 메모리를 해제 해줘야 된다.
		만약에 메모리를 해제 해주지 않게 된다면 누수가 발생하여 시스템의 메모리 사용량이 계속 증가하게 되고,
		결국 시스템 성능저하를 시킬수 있게 된다.


	*/


	/*
		malloc()
		표준 라이브러리 <stdlib.h> 헤더파일에 정의되어 있다.
		malloc함수는 힙(heap)영역에 메모리 블록을 할당하고, 해당 메모리 블록의 포인터를 반환 합니다.

		단계
		1.요청된 메모리 크기에 대한 공간을 할당하기 위해서 운영체제에게 요청을 보냅니다.
		2.운영체제는 사용 가능한 힙 영역에서 요청된 메모리 크기에 해당하는 블록을 찾아 할당합니다.
		3.할당된 메모리의 블록의 주소를 반환하고, 해당 주소를 사용하여 동적으로 할당된 메모리에 접근 할수 있게 된다.

		malloc함수에서는 사용가능한 힙여역에 충분한 메모리가 없는경우malloc()함수는 nullptr을 반환하게 된다.
		이는 결국 메모리 할당을 실패하는 경우를 말한다.

		메모리릭을 체크하는 함수
		_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	*/

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int* ptr = (int*)malloc(sizeof(int));
	//float* fPtr = (float*)malloc(sizeof(float));
	//if (ptr == NULL)
	//{
	//	//메모리 할당 실패
	//	std::cout << "Faill" << std::endl;
	//}
	//else
	//{
	//	std::cout << "Success" << std::endl;
	//	//메모리 할당 성공
	//}



	*ptr = 200;

	std::cout << "Ptr : " << *(ptr) << std::endl;

	//강제형변환
	*((int*)ptr) = 3.f;

	std::cout << "Ptr : " << *(ptr) << std::endl;

	//메모리 해제

	if (NULL != ptr)
	{
		free(ptr);
	}

	{
		int* ptr = new int;

		*ptr = 300;

		std::cout << "Ptr : " << *(ptr) << std::endl;

		if (nullptr != ptr)
		{
			delete ptr;
		}
	}


	//동적할당을 통한 간단한 예시

	int iNum = 0;

	std::cout << "학생수를 입력해주세요 : ";
	std::cin >> iNum;

	//할당
	Student* st = new Student[iNum];

	if (iNum < 0 || iNum <= 10)
	{
		//학생정보 
		for (int i = 0; i < iNum; ++i)
		{
			std::cout << (i + 1) << "학생 이름 입력 ";
			std::cin >> st[i].stName;
			std::cout << (i + 1) << "점수 입력";
			std::cin >> st[i].iScore;
		}

		float fAvg = 0.f;
		int iTotal = 0;
		for (int i = 0; i < iNum; ++i)
		{
			iTotal += st[i].iScore;
		}

		fAvg = iTotal / iNum;

		std::cout << "평균 점수 :" << fAvg <<std::endl;

		std::cout << "학생 정보 " << std::endl;
		
		st->PrintInfo(st, iNum);
		
	}


	if (st != nullptr)
	{
		delete[] st;

	}
 
	return 0;
}