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
	//���Ǳ����
	//while ���
	//��� ����
	// ��尡 0�� �Ǹ� ���� �ڵ� ����
	// ����� �޴��� ������ �����

	int iGold = 10000;
	int iSelect = 0;
	int iDrink = 0;


	system("cls");
	Resetpos();
	gotoxy(ixpos, iypos);
	std::cout << "<====���Ǳ�����Դϴ�=====>";
	iypos++;
	gotoxy(ixpos, iypos);
	std::cout << "1.�����ϱ�";
	iypos++;
	gotoxy(ixpos, iypos);
	std::cout << "2.������";
	iypos++;
	gotoxy(ixpos, iypos);
	std::cin >> iSelect;
	

	while (true)
	{
	
		if (iSelect == 1)
		{
			system("cls");
			std::cout << "���: " <<iGold << std::endl;
			
			Resetpos();
			gotoxy(ixpos, iypos);
			iypos++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			std::cout << "<========�޴��� �������ּ���========>";
			gotoxy(ixpos, iypos);
			iypos++; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			std::cout << "1. ���̴�: 1200G"; 
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "2. ��ī�ݶ� : 1200G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "3. ���: 1000G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "4. ��� ���� ���Ӹ�: 1200G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "5. ȯŸ: 1000G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "6. ������: 500G";
			gotoxy(ixpos, iypos);
			iypos++;
			std::cout << "7. ������";
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
				std::cout << "��尡 �����մϴ�";
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

	std::cout << "����ϼ̽��ϴ�" << std::endl;

	return 0;
}