#include <iostream>

int main()
{
	/*
		배열:같은 자료형의 변수 여러개를 한번에 선언 할수 있게 해주는 기능이다.
		배열은 메모리가 연속적으로 잡혀 있다.

		변수 타입 배열명[갯수] 갯수는 상수만 가능하다.
		의 형태로 구성

		배열을 쓰는 이유
		연속적 메모리를 만들때 똑같은 데이터를 그룹으로 묶어서 표현 할때 배열 문법을 사용한다.
	*/

	int iStudent[100];
	//위처럼 만들게 되면 학생 100명을 저장할수 있는 메모리가 생긴것이다.
	//각 요소에 접근하기 위해서 사용하는것이 인덱스이다.
	//인덱스는 0 에서 부터 시작한다.

	//배열 초기화 
	
	int iNum[10] = {}; //모두 0 으로 초기화 한다.
	//int iNum[10] = { 0, };
	//int iNum[10] = { 0,0,0,0,0,0,0,0,0,0,0, };

	int iNum2[] = { 100,200,59,29,20,50,102 }; 

	int iAraay[10] = { 1,2,3 }; //0,1,2번 인덱스에 1,2,3값이 들어가게되고 나머지는 0으로 초기화 한다.

	iAraay[0] = 10;
	iAraay[8] = 199;

	std::cout << "iArray[0] =" << iAraay[0] << "  iArray[7] =" << iAraay[8];
	std::cout << std::endl;

	//배열의 원소갯수 = sizeof(배열명) / sizeof(자료형)
	size_t iSize = 0;

	iSize = sizeof(iAraay) / sizeof(int); //배열의갯수를 구한거다

	for (int i = 0; i < iSize; ++i)
	{
		iAraay[i] = i + 1;
	}

	for (int i = 0; i < iSize; ++i)
	{
		std::cout << "iArray[";
		std::cout << i << "] " << iAraay[i] << std::endl;
	}

	//다음시간에 로또게임, 빙고게임 ...
	

	return 0;
}