#include <iostream>
#include "CArray.h"
#include <vector>
#define TEST 10

using namespace std;


//함수 템플릿
template<typename T>
T	Add(T a, T b)
{
	return a + b;
}

template<class T>
void OutPut(T a)
{
	std::cout << a << std::endl;
}


class Player
{
public:
	int iHP;
	int iMP;

public:
	void Attack()
	{
	std:cout << "Attack!! " << std::endl;
	}
};

int main()
{
	/*
		오버로딩을 통해서 여러 자료형에 사칙연산 기능을 만들수 있는데
		만약에 이걸 하나의 함수를 통해서 그 자료형을 그 상황에 맞게 변경해줄수 있다면 좀더 효율적이고 기능적일 것이다.
		이래서 나오게 된게 템플릿이다.
		
		클래스 템플릿에 정의는 헤더파일에 만들어져야 된다.
		이유는 컴파일러가 템플릿을 인스턴스화를 제대로 처리하기 위해서 필요한 코드가 템플릿 정의와 선언 모두 포함된 헤더파일이 있어야 된다.
		템플릿은 컴파일 시점이아닌 인스턴스화 시점에 컴파일 됩니다. 

		템플릿 인스턴스화..
		템플릿을 구체적인 타입으로 변환하는 과정을 말한다.

		인스턴스
		class에 소속된 개별적인 개체를 말한다.
		ex) Player클래스를 정의하고 py를 객체를 생성하게 되면 py라는 객체는 Player라는 클래스의 인스턴스가 된다.
		
		
		
	
	*/

	int a = Add<int>(10, 10);

	float f = Add<float>(3.f, 3.f);

	double d = Add<double>(3.14, 567.1);

	OutPut<int>(a);
	OutPut<float>(d);
	OutPut<double>(d);


	std::cout << "Hellow" << std::endl;


	//cout << "Hellow " << endl;

	//Player py, py2, py3;

	CArray<float> arr;

	arr.push_back(10.35);
	arr.push_back(2.55);
	arr.push_back(11.545);

	arr.OutPut();
	

	std::cout << std::endl;
	CArray<int> arrint;

	
	arrint.push_back(10);
	arrint.push_back(20);
	arrint.push_back(30);

	int test = 300;

	arrint.Delete(1);


	arrint[1] = test;

	arrint.OutPut();


	
	


	
	return 0;
}