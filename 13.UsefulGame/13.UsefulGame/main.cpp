#include <iostream>
#include <stdlib.h>
#include <Windows.h>


//구조체..
typedef int MyInt;
typedef float MyFloat;


//typedef란?
//c언어에서 자료형을 새롭게 이름을 붙일때 쓰는 키워드다.
//구조체라는게 있는데 구조체를 편하게 사용하기 위해서이다.


void gotoxy(int x, int y)
{
	COORD _pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _pos);
	
}

typedef struct _Student
{
	int iAge;
	char sName[25]; 
	int iScore;
}Student;


int main()
{
	int iNumber = 0;

	iNumber += 100;

	std::cout << iNumber << std::endl;
	std::cout << iNumber << std::endl;
	std::cout << iNumber << std::endl;
	std::cout << iNumber << std::endl;

	system("cls");

	/*
		sleep 함수..
		1._sleep(1000) 초단위가 아니라 1000분의 1초 단위이다. 그러므로 1초가 된다. //#include <stdlib.h>
		2.Sleep(1000) Windows.h

		
	*/
	
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << std::endl;

		std::cout << i << std::endl;
		std::cout << i << std::endl;

		std::cout << i << std::endl;
		std::cout << i << std::endl;
		Sleep(100);
	}

	
	gotoxy(50, 5);
	std::cout << "로그인 중입니다....";
	Sleep(1000);

	//Sleep함수와 gotoxy를 이용하여 역동적인걸 만들어보자.
	for (int i = 0; i < 5; ++i)
	{
		system("cls");

		gotoxy(50, 7);
	
		if (i == 0)
		{
			std::cout << "■□□□□";
		}
		else if (i == 1)
		{
			std::cout << "■■□□□";
		}
		else if (i == 2)
		{
			std::cout << "■■■□□";
		}
		else if (i == 3)
		{
			std::cout << "■■■■□";
		}
		else if (i == 4)
		{
			std::cout << "■■■■■";
		}

		Sleep(1000);


	}

	//콘솔에서 색깔표현하는거 
	//첫번째 인자는 핸들을 꼭 얻어야되서 GetstdHandle(STD_OUTPUT_HANDLE)를 꼭 넣어주기
	//두번째 인자는 색깔을 넣어준다. (이색은 삼원색이랑 같은원리다)
	//FOREGROUND_INTENSITY 밝은색을 의미한다.


	////레드 
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	//std::cout << "색깔 확인해 볼까요?" << std::endl;

	////레드 
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//std::cout << "색깔 확인해 볼까요?" << std::endl;

	////블루 
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	//std::cout << "색깔 확인해 볼까요?" << std::endl;

	////그린
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	//std::cout << "색깔 확인해 볼까요?" << std::endl;

	////엘로우
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	//std::cout << "색깔 확인해 볼까요?" << std::endl;

	////흰색
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	//std::cout << "색깔 확인해 볼까요?" << std::endl;

	



	return 0;
}