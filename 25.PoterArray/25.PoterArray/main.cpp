#include <iostream>

void Func(int* a)
{
	*a = 2000;
}

void Func(int a)
{
	a = 2000;
}

int main()
{
	int iNum = 0;
	int* pNum = nullptr;

	pNum = &iNum;

	//��������ũ��
	//�÷��� ȯ�濡 ���� �ٸ���
	std::cout << sizeof(pNum) << std::endl;

	//�������� ����
	//�����ʹ� ������ ���� 2������ �����Ѵ�
	//���࿡ ������ ������ +1�� �ϰԵǸ� �޸��ּҰ� 1000���� ��� �����Ҷ�
	//1001�� �Ǵ°� �ƴ϶� �� �ش� �ڷ��� ��ŭ ��������.
	//������� int�� int�� 4byte�̴ϱ� 1004�� �Ǵ°��̴�.


	pNum += 1;
	//pNum = pNum + 1;

	/*
		������ �迭
		�迭���� �����ʹ� �迭���� �ش� �迭�� �����ϴ� ù��° �޸��ּ��̴�.
		�׷��� ������ �����ͺ����� �迭�� ���� �޸� �ּҸ� �����ϰ� �ε����� �����Ҽ� �ִ�.
		���⼭ ���ϴ� index�� ������ �����ϸ� ����.

		�迭��Ư¡
		1.���������� �޸𸮰� ���������.
		2.�迭���� �����ʹ� �迭���� �ش� �迭�� ù��° �ּ��̴�.
	
	*/

	int iArr[100] = {};

	std::cout << iArr << std::endl;

	for (int i = 0; i < 100; ++i)
	{
		iArr[i] = i + 1;
	}

	std::cout << *(iArr+1) << std::endl;

	*(iArr+ 0) = 30;	//iArr[0] = 30;
	*(iArr + 3) = 500;	//iArr[3] = 500;

	
	system("cls");

	pNum = iArr;
	
	int iSize = 0;

	iSize = sizeof(iArr) / sizeof(int);

	/*for (int i = 0; i < iSize; ++i)
	{
		std::cout << iArr[i] << std::endl;
	}*/

	//for (int i = 0; i < iSize; ++i)
	//{
	//	std::cout << *(pNum + i) << std::endl;
	//}

	*(pNum + 5) = 10000;

	for (int i = 0; i < iSize; ++i)
	{
		std::cout << iArr[i] << std::endl;
	}
	

	int a = 200;

	int b = 200;

	Func(&a);
	Func(b);

	std::cout << a << std::endl;

	std::cout << b << std::endl;
	

	return 0;
}