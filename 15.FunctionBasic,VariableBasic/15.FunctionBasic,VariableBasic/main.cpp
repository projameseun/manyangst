#include <iostream>
#include <Windows.h>
#include <conio.h>

/*
	�Լ�(Function) : ����ڰ� ���ϴ� �ڵ带 ��Ƽ� ����� ����� �ټ� �ִ� ���� ���Ѵ�.
	������ �ݺ��Ǵ� �ڵ尡 �ִٸ� �װ��� �Լ��� ���� �ʿ��� ���� �� �Լ��� �ҷ��� �ش��ڵ尡 �۵� �ɼ� �ְ� ����� �� �� �ִ�.
	���� ��Ģ������ �Լ��ε� ����� �ִ� �̿� ���� �Լ��� ���� ����� ���� �Ҽ� �ִ�.

	�Լ�����
	
	��ȯŸ��(�ڷ���) �Լ���(���� �Ǵ� �Ű� ������� �θ���)
	{

	}�ڵ��

	
	��ȯŸ��: �Լ��� ������ �����ϰ� ����� ��ȯ���ټ� �ִ� �ڷ����� �����Ѵ�(void,int,float��)
	
	���ڴ� �������� �ְ� �������� �ִ�
	���ڴ� �� �Լ��� �ҷ��� ȣ���Ҷ� �� �Լ��� �Ѱ��ְ��� �ϴ� ���� �ִٸ� ������ ���� ����ϰ� ���ش�.
	void��ȯŸ���� ��ȯ �� ���� ���ٴ� ���̴�.

*/

int gNum = 0;

void IntPrint(int iPrint)
{
	
	std::cout << "��� : " << iPrint << std::endl;
}

void GVIntPrint(int iPrint)
{
	
	std::cout << "������� : " << iPrint << std::endl;
}

int Add(int a , int b)
{
	gNum = 100;
	int iNum = 0;

	iNum = 100;
	return a + b;
}

int Minus(int a, int b)
{
	gNum += 100;
	int iNumber = 0;
	return a - b;
}

void Position(short x, short y)
{
	COORD _pos = { x,y };
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _pos);
	 
}


void Print(); //�Լ��Ǽ���


int main()
{

	int iNumber = 0;
	IntPrint(10);

	iNumber = Add(10, 30);

	IntPrint(iNumber);

	iNumber = 0;

	iNumber = Minus(100, 50);
	
	Position(10, 10);

	IntPrint(iNumber);

	/*
		���׿�����
		���� ? A : B
		������ ���̸� A ������ �����̸� B�� ��ȯ�Ѵ�
	*/

	int iResult = 0;
	
	int a = 100, b = 235;

	iResult = (a < b) ? a : b;

	IntPrint(iResult);

	GVIntPrint(gNum);

	/*
		��������:�ڵ��{}�ȿ��� ����� ������ ���Ѵ�.
		�Լ��� ���γ� �Լ��� ���ڵ��� ���������� ���Ѵ�.
		���������� ���ÿ����� �����Ѵ�.
		���������� �Լ��ȿ����� ������ �����ϸ�, �Լ��� ����� �Ҹ�ȴ�(�޸𸮿��� �����ȴ�)

		��������:Main�ڵ�� �ܺο��� �����ϴ� ������ ���Ѵ�.
		���������� ����� �������� �Ʒ��� ��� �Լ����� �� ������ ������ ������ �����ϴ�.
		���������� ���α׷��� ���� �ɶ� �Ҵ�ǰ� �ʱ�ȭ�� ���ϸ� �ڵ����� 0���� �ʱ�ȭ �Ѵ�.
		���������� ���α׷��� ���� �� ���� �޸𸮿��� ��� �����ϴٰ� ���α׷��� ���� �� �� �޸𸮿��� �����ȴ�.
		���������� data���� �����Ѵ�.
		
	
	*/

	gNum++;
	gNum++;
	gNum++;

	GVIntPrint(gNum);
	

	return 0;
}

void Print() //�Լ�������
{

}