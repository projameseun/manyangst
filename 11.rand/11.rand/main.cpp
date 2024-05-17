#include <iostream>
#include <time.h>

int main()
{
	/*
		난수(무작위의수)
		컴퓨터는 랜덤이라는 수를 만들수 없다.
		랜덤이란 무작위의 수를 나오게 하는건데 이 무작위의 수를 무의식적으로 선택 할 수 없기 때문에 컴퓨터는 랜덤(무의식의수)을 절대 만들수 없다.
		그러므로, 컴퓨터는 마치 랜덤처럼 보이는 정해진 입력 값을 나타내고 있는거다.
		컴퓨터가 만들어 낸 랜덤은 여러 계산을 통해서 사람들이 볼때 마치 임의의값인 랜덤처럼 보이게 하는거다.

		rand()
		무작위의 랜덤테이블이란 것이 존재하고 이를 리턴하는거다.
		rand()함수는 내부에 RAND_MAX #define으로 정의가 되어 있꼬 이 숫자는 16진수로 되어 있는데, 10진수로 바꾸게 되면 32,767으로 되어 있다.
		결국 rand()함수는 표현할수 있는 return값은 0 ~ 32,767값이 나오는 거다.
		rand함수는 프로그램이 실행될때 값이 딱 정해지기 때문에 프로그램을 여러번 실행을 해도 동일한 값이 나오게 된다.
	
	*/


	int iNumber = 0;

	iNumber = rand();

	/*std::cout << "1.rand : " << rand() << std::endl;
	std::cout << "2.rand : " << rand() << std::endl;
	std::cout << "3.rand : " << rand() << std::endl;
	std::cout << "4.rand : " << rand() << std::endl;
	std::cout << "5.rand : " << rand() << std::endl;*/

	/*
		rand함수로만은 표현을 할수 없기 때문에 나오게 된다. srand(시드값) 함수이다.
		srand(seed값) 
		srand는 rand함수에 사용될 수를 초기화 한다.이 초기화를 매개변수로 받는 seed값을 이용해서 사용한다.
		아래에는 srand 때문에 초기화 되지만 seed값이 동일하면 결국 똑같은 수가 반복되기 때문에 우리가 원하는 랜덤이아니다.
		
	
	*/
	
	
	/*srand(1000);
	std::cout << "rand :" << rand() << std::endl;
	srand(500);
	std::cout << "rand :" << rand() << std::endl;
	srand(1233);
	std::cout << "rand :" << rand() << std::endl;
	srand(110);
	std::cout << "rand :" << rand() << std::endl;*/

	/*
		seed값이 계속 변할수 있다면 rand()함수에 계속 다른값을 출력할수 잇을것이다.
		그래서 나오게 된게 time시간 함수이다.
		time함수
		UTC(1972년 1월 1일 0 분 0초 부터 시행된 국제 표준시)이 시간을 정수값으로 변환해주는 함수가 time함수이다.
		결론:seed값안에 time이라는 시간함수를 넣어준다.
	*/
	
	//srand((unsigned int)time(NULL));
	srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "rand :" << rand() << std::endl;
	std::cout << "rand :" << rand() << std::endl;
	std::cout << "rand :" << rand() << std::endl;
	std::cout << "rand :" << rand() << std::endl;
	std::cout << "rand :" << rand() << std::endl;

	//우리가 정해진 범위의 숫자안에서 랜덤을 가져온다.
	//이때 사용하는 연산자 모듈러스(나머지)이다.
	//ex) rand() % 5; === > 어떤 숫자가 와도 0 ~  4까지만 출력이된다.
	//rand() % 10; === > 어떤 숫자가 와도 0 ~  9까지만 출력이된다.
	//규칙은 n-1까지 출력이된다.


	//0~2까지출력


	iNumber = rand() % 3;

	std::cout << iNumber << std::endl;

	//0~99

	iNumber = rand() % 100;

	/*iNumber = 1 % 10;
	iNumber = 2 % 10;
	iNumber = 3 % 10;
	iNumber = 4 % 10;
	iNumber = 5 % 10;
	iNumber = 6 % 10;
	iNumber = 7 % 10;
	iNumber = 8 % 10;
	iNumber = 9 % 10;
	iNumber = 10 % 10;

	iNumber = 11 % 10;
	iNumber = 12 % 10;
	iNumber = 13 % 10;
	iNumber = 14 % 10;
	iNumber = 15 % 10;
	iNumber = 16 % 10;
	iNumber = 17 % 10;
	iNumber = 18 % 10;
	iNumber = 19 % 10;
	iNumber = 20 % 10;*/

	//1~100까지만 출력해보세요

	iNumber = rand() % 100 +1;

	//100~ 199 
	iNumber = rand() % 100 + 100;

	float fRand = rand() % 10000 / 100.f; 
	//std::cout << "Rand :" << fRand << std::endl;


	
	//최소공격력 최대 공격력
	//500 ~ 1000
	int iMin = 500;
	int iMax = 1000;

	//강화프로그램
	if (fRand < 1.f)
	{
		std::cout << "에스더 획득" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	else if (fRand < 30.f)
	{
		std::cout << "유물 획득" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	else if (fRand < 60.f)
	{
		std::cout << "희귀 획득" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	else if (fRand < 80.f)
	{
		std::cout << "일반 획득" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	else
	{
		std::cout << "아이템 없음" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	int a = 0;



	return 0;
}