#include <iostream>
#include <windows.h>
#include <conio.h>

int ixpos = 0;
int iypos = 0;

void gotoxy(int _x, int _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Resetpos()
{
	ixpos = 50;
	iypos = 2;
}

int main()
{
	//자판기게임
	//while 사용
	//골드 존재
	// 골드가 0이 되면 게임 자동 종료
	// 음료수 메뉴랑 나가기 만들기

	int iGold = 10000;
	int iSelect = 0;
	int iDrink = 0;


	system("cls");
	Resetpos();
	gotoxy(ixpos, iypos);
	std::cout << "<====자판기게임입니다=====>";
	iypos++;
	gotoxy(ixpos, iypos);
	std::cout << "1.시작하기";
	iypos++;
	gotoxy(ixpos, iypos);
	std::cout << "2.나가기";
	iypos++;
	gotoxy(ixpos, iypos);
	std::cin >> iSelect;
	

	while (true)
	{
	
		if (iSelect == 1)
		{
			system("cls");
			std::cout << "골드: " <<iGold << std::endl;
			
			Resetpos();
			gotoxy(ixpos, iypos);
			iypos++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			std::cout << "<========메뉴를 선택해주세요========>";
			gotoxy(ixpos, iypos);
			iypos++; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			std::cout << "1. 사이다: 1200G"; 
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "2. 코카콜라 : 1200G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "3. 펩시: 1000G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "4. 펩시 제로 라임맛: 1200G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "5. 환타: 1000G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "6. 레쓰비: 500G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "7. 나가기";
			gotoxy(ixpos, iypos);
			std::cin >> iDrink;

			if (iDrink == 1)
			{
				iGold -= 1200;
			}

			else if (iDrink == 2)
			{
				iGold -= 1200;
			}

			else if (iDrink == 3)
			{
				iGold -= 1000;
			}

			else if (iDrink == 4)
			{
				iGold -= 1200;
			}

			else if (iDrink == 5)
			{
				iGold -= 1000;
			}
			else if (iDrink == 6)
			{
				iGold -= 500;
			}

			if (iGold <= 400)
			{
				system("cls");
				gotoxy(ixpos, iypos);
				iypos++;
				std::cout << "골드가 부족합니다";
				gotoxy(ixpos, iypos);
				iypos++;

				Sleep(900);
				break;
			}

			if (iDrink == 7)
			{
				break;
			}
		}
		
		else
		{
			break;
		}
	}
	system("cls");

	std::cout << "고생하셨습니다" << std::endl;

	return 0;
}