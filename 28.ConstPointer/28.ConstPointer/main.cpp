#include <iostream>

void Func(const int* ptr)
{
	int iNum = *ptr;
	
	//*ptr = 200;

	//������ ����ȯ�� ���ؼ� ���� �����Ҽ� �ִ�.
	int* pInt = (int*)ptr;
	*pInt = 10000;
}

int main()
{

	int a = 0;

	int b = 0;

	//const Pointer ����Ű�°� ���
	const int* ptr = &a;

	//*ptr = 100;

	//pointer const �ڱ��ڽ� ���
	int* const ptrConst = &b;

	*ptrConst = 300;

	//ptrConst = &a;

	//�Ѵ� ���
	const int* const pConstIntConst = nullptr;

	
	//*pConstIntConst = 500;
	//pConstIntConst = &b;
	
	//������ ���...
	//int const* ptr3 = nullptr;

	{
		int a = 0;
		
		const int* pInt = &a;

		a = 300;

		std::cout << *pInt << std::endl;
	}

	a = 100;

	Func(&a);

	std::cout << "a = " << a << std::endl;
	

	return 0;
}