#include <iostream>
#include <Windows.h>
#include <conio.h>

/*
	함수(Function) : 사용자가 원하는 코드를 모아서 기능을 만들어 줄수 있는 것을 말한다.
	예를들어서 반복되는 코드가 있다면 그것을 함수로 만들어서 필요한 곳에 이 함수를 불러서 해당코드가 작동 될수 있게 만들어 줄 수 있다.
	또한 사칙연산을 함수로도 만들수 있다 이와 같이 함수는 많은 기능을 포함 할수 있다.

	함수문법
	
	반환타입(자료형) 함수명(인자 또는 매개 변수라고 부른다)
	{

	}코드블럭

	
	반환타입: 함수가 동작을 수행하고 결과를 반환해줄수 있는 자료형을 저장한다(void,int,float등)
	
	인자는 있을수도 있고 없을수도 있다
	인자는 이 함수를 불러다 호출할때 이 함수에 넘겨주고자 하는 값이 있다면 변수를 만들어서 사용하게 해준다.
	void반환타입은 반환 할 값이 없다는 것이다.

*/

int gNum = 0;

void IntPrint(int iPrint)
{
	
	std::cout << "출력 : " << iPrint << std::endl;
}

void GVIntPrint(int iPrint)
{
	
	std::cout << "전역출력 : " << iPrint << std::endl;
}

int Add(int a , int b)
{
	gNum = 100;
	int iNum = 0;

	iNum = 100;
	return a + b;
}

int Minus(int a, int b)
{
	gNum += 100;
	int iNumber = 0;
	return a - b;
}

void Position(short x, short y)
{
	COORD _pos = { x,y };
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _pos);
	 
}


void Print(); //함수의선언


int main()
{

	int iNumber = 0;
	IntPrint(10);

	iNumber = Add(10, 30);

	IntPrint(iNumber);

	iNumber = 0;

	iNumber = Minus(100, 50);
	
	Position(10, 10);

	IntPrint(iNumber);

	/*
		삼항연산자
		조건 ? A : B
		조건이 참이면 A 조건이 거짓이면 B를 반환한다
	*/

	int iResult = 0;
	
	int a = 100, b = 235;

	iResult = (a < b) ? a : b;

	IntPrint(iResult);

	GVIntPrint(gNum);

	/*
		지역변수:코드블럭{}안에서 선언된 변수를 말한다.
		함수의 내부나 함수의 인자들이 지역변수에 속한다.
		지역변수는 스택영역에 존재한다.
		지역변수는 함수안에서만 접근이 가능하며, 함수를 벗어나면 소멸된다(메모리에서 해제된다)

		전역변수:Main코드블럭 외부에서 선언하는 변수를 말한다.
		전역변수는 선언된 전역변수 아래의 어느 함수에서 라도 동일한 변수로 접근이 가능하다.
		전역변수는 프로그램이 시작 될때 할당되고 초기화를 안하면 자동으로 0으로 초기화 한다.
		전역변수는 프로그램이 실행 될 동안 메모리에서 계속 존재하다가 프로그램이 종료 될 때 메모리에서 해제된다.
		전역변수는 data영역 존재한다.
		
	
	*/

	gNum++;
	gNum++;
	gNum++;

	GVIntPrint(gNum);
	

	return 0;
}

void Print() //함수의정의
{

}