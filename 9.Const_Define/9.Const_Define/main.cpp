#include <iostream>

#define MAXHP 10000
#define ASPITO 1.6655



int main()
{
	//����(variable)�� ������(data)�� �����ϱ� ���� �̸��� �Ҵ���� �޸� ������ �ǹ��մϴ�.
	//	��, ������ ������(data)�� ������ �� �ִ� �޸� ������ �ǹ��Ѵ�.
				//������ ���� ///      
	//��ó�� - > ������ -> ���� - > ��ŷ -> �������� 

	//define�� �޸𸮿� �Ҵ� ���� �ʴ´�.(����� �ȵȴ� ���������� ��������)
	//const�� �޸𸮿� �Ҵ� �ȴ�.

	//const(���)
	//enum class
	
	int iDamage = 0;
	iDamage = 100;

	int iBOSSHP = 0;

	iBOSSHP -= iDamage;

	std::cout << 50000 << std::endl;

	double dNumber = 0;

	dNumber = 1.7444;

	

	//1. const ��ġ�� �� �տ� ������ ������ ������ ����Ű�� ���� ���Ͽ� ���ȭ�� ��Ű�� ��� �̴�.

	int iNum = 100;

	const  int* ptr= &iNum;
	
	//*ptr = 200; ���� ������ �ȵȴ�

	iNum = 300;

	//2. const ��ġ�� type�� ���� �̸� ���̿� �����鼭 ������ ���� ��ü�� ���ȭ ��Ű�� ��� �̴�.

	int iNum2 = 1100;

	int* const ptr2 = &iNum2; //ptr2�ּҸ� ���ȭ 

	//ptr2 = &iNum;
	
	const int* const ptr3 = &iNum; //���� �ּҸ� ��� ���ȭ 



	
	


	return 0;
}