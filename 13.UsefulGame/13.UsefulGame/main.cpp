#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>


//����ü..
typedef int MyInt;
typedef float MyFloat;


//typedef��?
//c���� �ڷ����� ���Ӱ� �̸��� ���϶� ���� Ű�����.
//����ü��°� �ִµ� ����ü�� ���ϰ� ����ϱ� ���ؼ��̴�.


//Ű����
enum class Key
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13,
	ESC = 27,
};

//�񵿱���Ű����

enum class KeyWASD
{
	W = 87,
	A = 65,
	S = 83,
	D = 68,
	ESC = 27,
};



//UPŰ �ƽ�Ű�ڵ� �� = 72;
//DOWNŰ �ƽ�Ű �ڵ� �� = 80;
//LEFTŰ �ƽ�Ű �ڵ� �� = 75;
//RIGHTŰ �ƽ�Ű �ڵ� �� = 77;
//��ó: https://dev-with-precious-dreams.tistory.com/7 [�� ��ġ�ִ� ���� ����. Almost there "dev":Ƽ���丮]


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
		sleep �Լ�..
		1._sleep(1000) �ʴ����� �ƴ϶� 1000���� 1�� �����̴�. �׷��Ƿ� 1�ʰ� �ȴ�. //#include <stdlib.h>
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
	//std::cout << "�α��� ���Դϴ�....";
	//Sleep(1000);

	////Sleep�Լ��� gotoxy�� �̿��Ͽ� �������ΰ� ������.
	//for (int i = 0; i < 5; ++i)
	//{
	//	system("cls");

	//	gotoxy(50, 7);
	//
	//	if (i == 0)
	//	{
	//		std::cout << "������";
	//	}
	//	else if (i == 1)
	//	{
	//		std::cout << "������";
	//	}
	//	else if (i == 2)
	//	{
	//		std::cout << "������";
	//	}
	//	else if (i == 3)
	//	{
	//		std::cout << "������";
	//	}
	//	else if (i == 4)
	//	{
	//		std::cout << "������";
	//	}

	//	Sleep(1000);


	//}

	//�ֿܼ��� ����ǥ���ϴ°� 
	//ù��° ���ڴ� �ڵ��� �� ���ߵǼ� GetstdHandle(STD_OUTPUT_HANDLE)�� �� �־��ֱ�
	//�ι�° ���ڴ� ������ �־��ش�. (�̻��� ������̶� ����������)
	//FOREGROUND_INTENSITY �������� �ǹ��Ѵ�.


	////���� 
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	//std::cout << "���� Ȯ���� �����?" << std::endl;

	////���� 
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//std::cout << "���� Ȯ���� �����?" << std::endl;

	////��� 
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	//std::cout << "���� Ȯ���� �����?" << std::endl;

	////�׸�
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	//std::cout << "���� Ȯ���� �����?" << std::endl;

	////���ο�
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	//std::cout << "���� Ȯ���� �����?" << std::endl;

	////���
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	//std::cout << "���� Ȯ���� �����?" << std::endl;

	//Ű���带 �����̴�....
	
	
	Clear();

	int iStart = 1;

	int iXpos = 1;
	int iYpos = 1;

	gotoxy(iXpos, iYpos);
	
	while (iStart)
	{
		//_kbhit()�Լ��� Ű�� �������� üũ�� ���ش� ���࿡ Ű�� ������ ������ 0�� ���� �ǰ�
		//Ű�� ���࿡ ������ ��� 0�̿��� ���� �����Ѵ�.
		
		//if (_kbhit())
		//{
		//	char c = _getch();	//Ű����� �ϳ��� Ű�� �Է¹޴� �Լ��̴�. �ƽ�Ű�ڵ尪�� ��ȯ�Ѵ�.


		//	switch (c)
		//	{
		//	case (int)Key::UP:
		//		std::cout << "UP Ű�� �Է��Ͽ����ϴ�" << std::endl;
		//		break;
		//	case (int)Key::DOWN:
		//		std::cout << "DOWN Ű�� �Է��Ͽ����ϴ�" << std::endl;
		//		break;
		//	case (int)Key::LEFT:
		//		std::cout << "LEFT Ű�� �Է��Ͽ����ϴ�" << std::endl;
		//		break;
		//	case (int)Key::RIGHT:
		//		std::cout << "RIGTH Ű�� �Է��Ͽ����ϴ�" << std::endl;
		//		break;
		//	case (int)Key::ENTER:
		//		std::cout << "ENTER Ű�� �Է��Ͽ����ϴ�" << std::endl;
		//		break;
		//	case (int)Key::ESC:
		//	{
		//		std::cout << "ESC Ű�� �Է��Ͽ����ϴ�" << std::endl;
		//		std::cout << "��������" << std::endl;
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
			iStart = 0;//���� 
			std::cout << std::endl;
			
			break;
		}
		
		Clear();

		gotoxy(iXpos, iYpos);

		std::cout << "��";
		
	}
	
	Clear();
	std::cout << "���� �ϼ̽��ϴ� Enter�� ������ ������ ���� �˴ϴ�" << std::endl;
	Pause();


	return 0;
}