#include <iostream>
#include <stdlib.h>
#include <Windows.h>


//����ü..
typedef int MyInt;
typedef float MyFloat;


//typedef��?
//c���� �ڷ����� ���Ӱ� �̸��� ���϶� ���� Ű�����.
//����ü��°� �ִµ� ����ü�� ���ϰ� ����ϱ� ���ؼ��̴�.


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
		sleep �Լ�..
		1._sleep(1000) �ʴ����� �ƴ϶� 1000���� 1�� �����̴�. �׷��Ƿ� 1�ʰ� �ȴ�. //#include <stdlib.h>
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
	std::cout << "�α��� ���Դϴ�....";
	Sleep(1000);

	//Sleep�Լ��� gotoxy�� �̿��Ͽ� �������ΰ� ������.
	for (int i = 0; i < 5; ++i)
	{
		system("cls");

		gotoxy(50, 7);
	
		if (i == 0)
		{
			std::cout << "������";
		}
		else if (i == 1)
		{
			std::cout << "������";
		}
		else if (i == 2)
		{
			std::cout << "������";
		}
		else if (i == 3)
		{
			std::cout << "������";
		}
		else if (i == 4)
		{
			std::cout << "������";
		}

		Sleep(1000);


	}

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

	



	return 0;
}