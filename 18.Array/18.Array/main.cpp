#include <iostream>
#include <time.h>
#include <algorithm>

bool iCompare(int a, int b)
{
	return a > b;  //오름차순
	//return a > b;  //내림차순

}

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

	float fArray[100] = { 0.f };

	std::cout << "fArray : " << sizeof(fArray) << std::endl;


	//문자열 배열
	char data[6] = { 'H','A','P','P' ,'Y' }; //문자열의끝은 NULL,0으로 표기한다 그래야 컴파일러가 이 배열에 저장된 정보는 문자열이라는것을 알수 있다.

	char data2[6] = "Happy";

	char data3[25] = "안녕하세요"; //한글은 2바이트 영어느 1바이트

	std::cout << data << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data3 << std::endl;

	system("cls");

	//로또 프로그램
	//1~45사이의 숫자중 랜던함 6개의 숫자를 가져온다.
	//값이 중복되면 안된다.
	//오름차순,내림차순 

	iSize = 0;

	int iLotto[45] = {};

	iSize = sizeof(iLotto) / sizeof(int);

	for (int i = 0; i < iSize; ++i)
	{
		iLotto[i] = i + 1;
	}

	srand(static_cast<unsigned int>(time(NULL)));
	
	int iTemp, idx1, idx2 = 0;

	//Shuffle
	for (int i = 0; i < 1000; ++i)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;

	}

	/*for (int i = 0; i < iSize; ++i)
	{
		std::cout <<" iLotto[ " << i+1 << "]  " << iLotto[i] << std::endl;
	}*/


	//STL(standard 라이브러리)

	//std::sort(iLotto, iLotto + 6);
	std::sort(iLotto, iLotto + 6, iCompare);

	//오름차순 내림차순
	
	/*for (int i = 0; i < 5; ++i)
	{
		for (int j = i + 1; j < 6; ++j)
		{
			if (iLotto[i] > iLotto[j])
			{
				iTemp = iLotto[i];
				iLotto[i] = iLotto[j];
				iLotto[j] = iTemp;
			}
		}
	}*/
	


	
	for (int i = 0; i < 6; ++i)
	{
		std::cout << iLotto[i] << std::endl;
	}

	//다음시간에 로또게임, 빙고게임 ...
	

	return 0;
}