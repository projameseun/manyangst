#include <iostream>

//�����ε�����
//void Func()
//{
//	std::cout << "Fun ȣ��" << std::endl;
//}
//
//void Func(int a,int b)
//{
//	std::cout << "Fun2 ȣ��" << std::endl;
//}
//
//int Func(float a, float b)
//{
//	std::cout << "Fun3 ȣ��" << std::endl;
//	return 0;
//}
//
//void Func(float a, int b)
//{
//	std::cout << "Fun4 ȣ��" << std::endl;
//}
//
//void Func(int a)
//{
//	std::cout << "Fun5 ȣ��" << std::endl;
//}
//
//

void Func(int a)
{
	std::cout << "int ȣ��" << std::endl;
}

void Func(int* a)
{
	std::cout << "int* ȣ��" << std::endl;
}

void Func(std::nullptr_t ptr)
{
	std::cout << "nullptr ȣ�� " << std::endl;

	
}




int main()
{
	/*
		NULL,nullptr ���̿� ��� ������...

		Ÿ��:nullptr�� c++11���� ���Ե� Ư���� Ű�����̴� 
		�̿����� NULL�� C���� ���Ǵ� ��ũ�η�, ���� 0���� �򰡵Ǵ� ǥ�����Դϴ�.
		���� nullptr�� �������� ���� ���� ��Ÿ���� ������ ǥ���̸�, Ÿ�������� ������ �ִ�.

		nullptr�� Ÿ���� ��ü�� �ʱ�ȭ�Ҷ� �ش� ������ Ÿ���� �����Ϸ��� ���� ��Ȯ�ϰ� �����Ǳ� ������ 
		Ÿ���� �������� ���� �˴ϴ�.

		NULL�� ��ũ���̰� 0���� ���ǵǾ� �ֽ��ϴ�
		NULL�� ���� 0���� �ؼ��ɼ� �ִ�
		NULL�� ����Ͽ� �����͸� �ʱ�ȭ�Ҷ� Ÿ�� ����ġ�� ���� ������
		�߻����� ������ �־ Ÿ���� �������� ������� �ʴ´�.

		std::nullptr_t
		nullptr�� Ÿ���̴�. �������� �������ֱ����� ���ԵǾ���.
		std::nullptr_t Ÿ���Ǻ����� nullptr�� ������ �־� 
		�Լ��� �����ε��� ����� �ȴ�. ���� ���ø������� ����̵ȴ�.

		
	*/
	int a = 0;
	int* ptr = nullptr;

	
	Func(ptr);
	Func(NULL);
	Func(nullptr);


	int iNum = 0;
	
	 a = NULL;

	Func(0);
	Func((int*)0);

	system("cls");

	//NULL�� ��ȣ�ϴ�.
	std::cout << "NULL,nullptr �� " << std::endl;

	int* ptr1 = NULL;
	int* ptr2 = nullptr;

	if (ptr1 == NULL)
	{
		std::cout << "NULL == NULL" << std::endl;
	}
	if (ptr2 == NULL)
	{
		std::cout << "nullptr == NULL" << std::endl;
	}
	if (ptr1 == nullptr)
	{
		std::cout << "NULL == nullptr" << std::endl;
	}
	if (ptr2 == nullptr)
	{
		std::cout << "nullptr == nullptr" << std::endl;
	}
	if (ptr1 == ptr2)
	{
		std::cout << "NULL== nullptr" << std::endl;
	}

	//���� ����� �ϰԵǸ� �������� �ȴ�.
	//NULL�� 0�̱⵵ ������ nullptr�� �� ������ true�� ���´ٴ� ����� �˼� �ְ�
	//NULL�� ��Ȳ������ ��ȣ�ϰ� �����ȴ�.
	//����� intŸ���̶� �񱳸� �ϰ� �� ����� ������0���� null�� ����Ű�� ��ȣ�� ��Ȳ�� ���´�.
	//�׷��� �����͸� ����Ҷ� �ʱ�ȭ�� �Ҷ��� NULL�� �ƴ� nullptr�� ����ϴ� ���� �´�.
	//�׸��� nullptr�� ����ϰ� �Ǹ� ����ڰ� �̰Ŵ� �����͸� �ʱ�ȭ �Ѱ��̶�� �ٷξ˼��־ �������� ����.
	

	return 0;
}