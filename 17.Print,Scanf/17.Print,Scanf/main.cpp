#include <iostream>



void  IntPrint(const int _Num) 
{
	std::cout << "iNum:" << _Num << std::endl;

	
}

int main()
{
	

	//c++
	std::cout << "Hellow Word\n";

	int iNum = 0;

	//std::cin >> iNum;
	IntPrint(iNum);

	//C����� ����¹��
	printf("�ȳ��ϼ���%d\n", 10);
	printf("�Ǽ� ���%f ���� ���%d\n", 3.14f,100);

	float fNum = 3.14f;

	printf("Num =%d ", iNum);
	printf("fNum =%.2f ", fNum);

	system("cls");

	//C���� �Է¹��

	scanf_s("%d", &iNum);
	
	printf("iNum = %d\n", iNum);

	scanf_s("%f", &fNum);

	printf("iNum = %f\n", fNum);

	
	

	return 0;
}