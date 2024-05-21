#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>


//구조체..
typedef int MyInt;
typedef float MyFloat;


//typedef란?
//c언어에서 자료형을 새롭게 이름을 붙일때 쓰는 키워드다.
//구조체라는게 있는데 구조체를 편하게 사용하기 위해서이다.


//키보드
enum class Key
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13,
	ESC = 27,
};

//비동기방식키보드

enum class KeyWASD
{
	W = 87,
	A = 65,
	S = 83,
	D = 68,
	ESC = 27,
};



//UP키 아스키코드 값 = 72;
//DOWN키 아스키 코드 값 = 80;
//LEFT키 아스키 코드 값 = 75;
//RIGHT키 아스키 코드 값 = 77;
//출처: https://dev-with-precious-dreams.tistory.com/7 [더 가치있는 나를 위해. Almost there "dev":티스토리]


void gotoxy(int x, int y)
{
	COORD _pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _pos);

	
	
}


void Clear()
{
	system("cls");
}

void Pause()
{
	system("pause");
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
	
	//for (int i = 0; i < 10; ++i)
	//{
	//	std::cout << i << std::endl;

	//	std::cout << i << std::endl;
	//	std::cout << i << std::endl;

	//	std::cout << i << std::endl;
	//	std::cout << i << std::endl;
	//	Sleep(100);
	//}

	
	//gotoxy(50, 5);
	//std::cout << "로그인 중입니다....";
	//Sleep(1000);

	////Sleep함수와 gotoxy를 이용하여 역동적인걸 만들어보자.
	//for (int i = 0; i < 5; ++i)
	//{
	//	system("cls");

	//	gotoxy(50, 7);
	//
	//	if (i == 0)
	//	{
	//		std::cout << "■□□□□";
	//	}
	//	else if (i == 1)
	//	{
	//		std::cout << "■■□□□";
	//	}
	//	else if (i == 2)
	//	{
	//		std::cout << "■■■□□";
	//	}
	//	else if (i == 3)
	//	{
	//		std::cout << "■■■■□";
	//	}
	//	else if (i == 4)
	//	{
	//		std::cout << "■■■■■";
	//	}

	//	Sleep(1000);


	//}

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

	//키보드를 움직이다....
	
	
	Clear();

	int iStart = 1;

	int iXpos = 1;
	int iYpos = 1;

	gotoxy(iXpos, iYpos);
	
	while (iStart)
	{
		//_kbhit()함수는 키가 눌렀느지 체크를 해준다 만약에 키를 눌르지 않으면 0이 들어가게 되고
		//키를 만약에 눌렀을 경우 0이외의 값을 리턴한다.
		
		//if (_kbhit())
		//{
		//	char c = _getch();	//키보드로 하나의 키를 입력받는 함수이다. 아스키코드값을 반환한다.


		//	switch (c)
		//	{
		//	case (int)Key::UP:
		//		std::cout << "UP 키를 입력하였습니다" << std::endl;
		//		break;
		//	case (int)Key::DOWN:
		//		std::cout << "DOWN 키를 입력하였습니다" << std::endl;
		//		break;
		//	case (int)Key::LEFT:
		//		std::cout << "LEFT 키를 입력하였습니다" << std::endl;
		//		break;
		//	case (int)Key::RIGHT:
		//		std::cout << "RIGTH 키를 입력하였습니다" << std::endl;
		//		break;
		//	case (int)Key::ENTER:
		//		std::cout << "ENTER 키를 입력하였습니다" << std::endl;
		//		break;
		//	case (int)Key::ESC:
		//	{
		//		std::cout << "ESC 키를 입력하였습니다" << std::endl;
		//		std::cout << "게임종료" << std::endl;
		//		iStart = 0;
		//	}
		//		
		//		
		//		break;
		//
		//	}
		//	
		//	Sleep(500);
		//	
		//}


		if (GetAsyncKeyState((int)KeyWASD::W) & 0x8000)
		{
			iYpos--;
		}
		else if (GetAsyncKeyState((int)KeyWASD::S) & 0x8000)
		{
			iYpos++;
		}
		else if (GetAsyncKeyState((int)KeyWASD::D) & 0x8000)
		{
			iXpos++;

		}
		else if (GetAsyncKeyState((int)KeyWASD::A) & 0x8000)
		{
			iXpos--;
		}
		else if (GetAsyncKeyState((int)KeyWASD::ESC) & 0x8000)
		{
			iStart = 0;//종료 
			std::cout << std::endl;
			
			break;
		}
		
		Clear();

		gotoxy(iXpos, iYpos);

		std::cout << "★";
		
	}
	
	Clear();
	std::cout << "수고 하셨습니다 Enter를 누르면 게임이 종료 됩니다" << std::endl;
	Pause();


	return 0;
}