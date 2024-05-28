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

	//C언어의 입출력방식
	printf("안녕하세요%d\n", 10);
	printf("실수 출력%f 정수 출력%d\n", 3.14f,100);

	float fNum = 3.14f;

	printf("Num =%d ", iNum);
	printf("fNum =%.2f ", fNum);

	system("cls");

	//C언의 입력방식

	scanf_s("%d", &iNum);
	
	printf("iNum = %d\n", iNum);

	scanf_s("%f", &fNum);

	printf("iNum = %f\n", fNum);

	
	

	return 0;
}