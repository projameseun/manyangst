#include <iostream>

void Clear()
{
	system("cls");
}

void Pause()
{
	system("pause");
}

int main()
{

	//system("mode con:cols=150 lines=30");
	/*
		반복문(loop):프로그램 내에서 똑같은 명령을 일정 횟수만큼 반복하여 수행하도록 제어하는 명령문이다.
		단순하게 얘기하면 동일한 코드를 반복해서 동작 시킬때 활용하는 기능이다.

		for문
		for(초기값; 조건식; 증가값)
		{

			코드블럭;
		}의 형태로 구성된다.

		1.초기값은 for문이 시작될 때 1번만 실행이 된다.
		2.조건식은 매번 반복을 할 때 마다 체크하게 되고 조건식이 true일때 코드블럭 안의 코드가 동작이 되고 false가 되면 for문을 빠져 나오게 된다.
		3.증가값은 코드가 1번 실행 되면 증가값이 동작 되고 그 이 후에 조건이 체크된다.

		for문 실행순서
		초기값 -> 조건식 -> 코드실행 -> 증가값 -> 조건식 -> 코드실행 -> 증가값 -> 조건식 -> 코드실행 ...false일때 for문 종료 

		반복문 공통
		break를 사용하게 되면 반복문을 빠져나오게 된다.
		continue를 사용하면 반복문의 시작점으로 돌아오게 된다.
	
	*/

	int iNumber = 1;
	int iTotal = 0;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << std::endl;
	}

	//시작 조건을 생략할때
	for(; iNumber <= 10;++iNumber)
	{
		iTotal += iNumber;
	}
	
	std::cout << "iTotal = " << iTotal << std::endl;

	iNumber = 0;
	//for문을 무한루프를 만드는 방법
	for (; ; )
	{
		iNumber++;
		
		if (iNumber == 100)
		{
			break;
		}
		

		std::cout << "iNumber = " <<iNumber<< std::endl;
	}

	
	//for문을 이용하여 구구단2단
	for (int i = 1; i < 10; ++i)
	{
		std::cout << "2 * " << i << " = " << i * 2 << std::endl;
	}
	
	Clear();

	//구구단 5단을 만들어보세요 
	for (int i = 1; i < 10; ++i)
	{
		std::cout << "5 * " << i << " = " << i * 5 << std::endl;
	}

	Clear();

	//이중 for문
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << " i " << i << " j :" << j << std::endl;
		}
	}

	Clear();

	for (int i = 0; i < 10; ++i)
	{
		if (i == 8)
			continue;

		for (int j = 0; j < 10; ++j)
		{
			std::cout << " i " << i << "  j :" << j << std::endl;
		}
	}

	Clear();
	
	//구구단 2~9 단까지 만들어보세요
	for (int i = 2; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			if (j == 1)
			{
				std::cout << i << "단: " << std::endl;
				//std::cout << i << " * " << j << " = " << i * j << "\t  ";
				
			}
			std::cout << i << " * " << j << " = " << i * j << std::endl;
			
		}

		//std::cout << std::endl;									
	}


	return 0;
}