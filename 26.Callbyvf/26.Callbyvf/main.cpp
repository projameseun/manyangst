#include <iostream>

//call by value
//void swap(int a, int b)
//{
//	int iTemp = 0;
//
//	iTemp = a;
//	a = b;
//	b = iTemp;
//}

//call by Address
void swap(int* a, int* b)
{

	std::cout << "a = " << &a << std::endl;
	std::cout << "b = " << &b << std::endl;
	int iTemp = 0;

	iTemp = *a;
	*a = *b;
	*b = iTemp;
}

void swap(int& a, int& b)
{
	std::cout << "a = " << &a << std::endl;
	std::cout << "b = " << &b << std::endl;
	int iTemp = 0;

	iTemp = a;
	a = b;
	b = iTemp;
}

int main()
{
	/*
		Call by Value Call by Reference
		
		Call by Value�� ���� ���ڷ� �����ϴ� �Լ��� ȣ����
		���� ����Ǿ ���޵Ǳ⶧���� �Լ� ������ ���� �������ص� �������� ������ ���� �ʴ´�.

		Call by Reference �� �ּ� ���� ���ڷ� �����ϴ� �Լ��� ȣ����
		�Լ��� ���ڷ� ���޵Ǵ� ���� ������ �ּ��̹Ƿ�, �Լ� ������ ������ ���� �����ϸ� �ش� �ּҿ� ����� ���� ������ �ȴ�.



	*/

	int iNum = 100;
	int iNum2 = 200;

	
	std::cout << "iNum = " << &iNum << std::endl;
	std::cout << "iNum2 = " << &iNum2 << std::endl;

	/*std::cout << "<======������ ======>" << std::endl;
	std::cout << "iNum = " << iNum << std::endl;
	std::cout << "iNum2 = " << iNum2 << std::endl;*/

	swap(iNum, iNum2);	//callbyvalue
	//swap(&iNum, &iNum2); //callbyaddress
	//swap(iNum, iNum2);	//callbyreference
	//std::cout << "<======������ ======>" << std::endl;
	//std::cout << "iNum = " << iNum << std::endl;
	//std::cout << "iNum2 = " << iNum2 << std::endl;


	
	
	/*
		���۷��� �� �����ʹ� �Ѵ� c++���� �������� ����ϸ鼭 ���� ���̰� �־�...
		���۷���
		1.����� �ݵ�� �ʱ�ȭ�� �Ǿ�� �Ѵ�.
		2.�ʱ�ȭ ���� �ٸ� ������ ����ų���� ����.
		3.���۷����� ���ؼ� ���������� �����ؼ� �����Ҽ� �ִ�. �����Ϳ� �޸� �ּ� �����ڸ� ����� �ʿ䰡 ����.
		4.���۷����� NULL���� �������� ���� �׻� ��ȿ�� ������ �����Ѿ� �ȴٴ� ���̴�.

		�����ʹ� NULL,nullptr�� ������ �ִµ� �̴� �����Ͱ� � ��ȿ�� ������ ����Ű�� �ʴ´ٴ°��� �ǹ��Ѵ�.
		
	*/


	/*int a = 100;
	int b = 200;
	int c = 300;


	int& ref = a;
	
	ref = b; 
	
	std::cout << "&a : " << &a << std::endl;
	std::cout << "&b : " << &b << std::endl;
	std::cout << "&ref :" << &ref << std::endl;

	b = 1000;

	std::cout << "a :" << a << std::endl;
	std::cout << "b : "<< b << std::endl;
	std::cout << "ref : " << ref << std::endl;*/

	


	return 0;
}