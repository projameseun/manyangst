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
			std::cout << "�̸� : " << st[i].stName << "���� : " << st[i].iScore << std::endl;
		}
	}
};



int main()
{
	/*
		�����Ҵ�(Dynamic Allocaton)�� �޸𸮸� ��Ÿ�ӿ��� ��������
		�������� �Ҵ�,���� �ϴ°��� ���մϴ�. ���� ���α׷� �����߿�
		�޸𸮸� �Ҵ��ϰ� ���� �� �� �־ �� ������ �޸� ������ �����ϰ� �Ѵ�.

		c - malloc(),calloc() ,relloc() �� ���� �Լ��� ����ؼ� �Ҵ��ϰ�
		free()�� �����Ѵ�.

		c++ new�Ҵ��ϰ�
		delete���� �Ѵ�.

		�����Ҵ��� �ַ� �迭,����ü,��ü(Ŭ����)���� �����ͱ����� �ٷ궧 �����ϰ� ����Ѵ�.

		�����Ҵ��� �ϰ� �޸𸮸� ������ ���� �ʰԵǸ� �޸� ����(memory leak)�� ����µ� �̸� �� ��������� �ȴ�.
		�޸𸮸� �Ҵ��ϰ� �Ǹ� ������ �޸𸮸� ���� ����� �ȴ�.
		���࿡ �޸𸮸� ���� ������ �ʰ� �ȴٸ� ������ �߻��Ͽ� �ý����� �޸� ��뷮�� ��� �����ϰ� �ǰ�,
		�ᱹ �ý��� �������ϸ� ��ų�� �ְ� �ȴ�.


	*/


	/*
		malloc()
		ǥ�� ���̺귯�� <stdlib.h> ������Ͽ� ���ǵǾ� �ִ�.
		malloc�Լ��� ��(heap)������ �޸� ����� �Ҵ��ϰ�, �ش� �޸� ����� �����͸� ��ȯ �մϴ�.

		�ܰ�
		1.��û�� �޸� ũ�⿡ ���� ������ �Ҵ��ϱ� ���ؼ� �ü������ ��û�� �����ϴ�.
		2.�ü���� ��� ������ �� �������� ��û�� �޸� ũ�⿡ �ش��ϴ� ����� ã�� �Ҵ��մϴ�.
		3.�Ҵ�� �޸��� ����� �ּҸ� ��ȯ�ϰ�, �ش� �ּҸ� ����Ͽ� �������� �Ҵ�� �޸𸮿� ���� �Ҽ� �ְ� �ȴ�.

		malloc�Լ������� ��밡���� �������� ����� �޸𸮰� ���°��malloc()�Լ��� nullptr�� ��ȯ�ϰ� �ȴ�.
		�̴� �ᱹ �޸� �Ҵ��� �����ϴ� ��츦 ���Ѵ�.

		�޸𸮸��� üũ�ϴ� �Լ�
		_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	*/

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int* ptr = (int*)malloc(sizeof(int));
	//float* fPtr = (float*)malloc(sizeof(float));
	//if (ptr == NULL)
	//{
	//	//�޸� �Ҵ� ����
	//	std::cout << "Faill" << std::endl;
	//}
	//else
	//{
	//	std::cout << "Success" << std::endl;
	//	//�޸� �Ҵ� ����
	//}



	*ptr = 200;

	std::cout << "Ptr : " << *(ptr) << std::endl;

	//��������ȯ
	*((int*)ptr) = 3.f;

	std::cout << "Ptr : " << *(ptr) << std::endl;

	//�޸� ����

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


	//�����Ҵ��� ���� ������ ����

	int iNum = 0;

	std::cout << "�л����� �Է����ּ��� : ";
	std::cin >> iNum;

	//�Ҵ�
	Student* st = new Student[iNum];

	if (iNum < 0 || iNum <= 10)
	{
		//�л����� 
		for (int i = 0; i < iNum; ++i)
		{
			std::cout << (i + 1) << "�л� �̸� �Է� ";
			std::cin >> st[i].stName;
			std::cout << (i + 1) << "���� �Է�";
			std::cin >> st[i].iScore;
		}

		float fAvg = 0.f;
		int iTotal = 0;
		for (int i = 0; i < iNum; ++i)
		{
			iTotal += st[i].iScore;
		}

		fAvg = iTotal / iNum;

		std::cout << "��� ���� :" << fAvg <<std::endl;

		std::cout << "�л� ���� " << std::endl;
		
		st->PrintInfo(st, iNum);
		
	}


	if (st != nullptr)
	{
		delete[] st;

	}
 
	return 0;
}