#include <iostream>

int main()
{
	//1.ptr���� ���غ��ÿ� ����Լ��� ����Ͽ� �̸������ʱ� ������ �����ϱ� 

	int a = 100;
	int b = 200;
	int c = 300;
	int* ptr = nullptr;

	ptr = &a;

	*ptr = 500;
	
	ptr = &c;

	*ptr -=  b;

	
	std::cout << *ptr;
	
	
	//2. ������ ���ÿ� ����Լ��� ����Ͽ� �̸������ʱ� ������ �����ϱ� 
	short sArr[10] = { 1,333,10,200,24,1010,55,532,450,100 };

	int* pI = (int*)sArr;

	int iNum = *((short*)(pI + 3));

	

	//3. ������ ���ÿ� ����Լ��� ����Ͽ� �̸������ʱ� ������ �����ϱ� 
	char cArr[2] = { 2,1 };

	short* pS = (short*)cArr;

	iNum = *pS;
	
	


	return 0;
}