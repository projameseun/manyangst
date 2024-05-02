#include <iostream>

/*
	namespace란
	이름 공간 이라고 부른다. std는 namepace안에 구현되어 있다.
	네임스페이스는 변수 이름 또는 함수이름과 같이 명칭을 사용하는 공간으로 소속을 나타낸다.
	
	c++은 같은경우에는 이름이 같으면 구분이 불가능하다.
	그렇기 때문에 이름이 중복되서 충돌 되는 상황을 최대한 막아주어야 한다.
	namespcae는 이름이 충돌 될 경우 대비하여 소속을 지정해주는 기능으로 만들어져 있다.

	::범위지정연산자 -> 전역에 접근이 가능하다.
	
	출력
	cout(Console OutPut)
	cout은 std namespcae안에 만들어져 있는 기능이다.
	std::를 붙여서 사용해야 된다.
	
	한줄의 끝은 ;세미콜론으로 한다.
	컴퓨터는 ;이 없으면 끝난지를 모르기 때문에 계속 머물러 있다.

	======제어문자종류==================
	\n 한줄 개행을 해준다.
	\a 경고문자
	\b back space
	\f 새페이지로
	\0 공백문자(문자열의 끝을 알린다 ) NULL..
	\r 현재 행의 처음으로 간다
	\t 탭만큼 이동
	\' 작은따옴표를 사용할때
	\" 큰따옴표를 사용할때
	\를 출력할려면 \\로 해야된다.

	======제어문자종류==================

	==========서식문자================
	c언에서 사용되는 서식문자
	printf(),scanf()와 같은 함수에서 사용하고 출력 또는 입력할때 데이터의 형식을 지정한다.
	%기호로 시작을 한다.

	%d 부호있는 10진수
	%f 10진형 부동소수점(기본적으로 소수점 이하 6자리까지 출력 나머지는 0으로출력
	%c 단일문자
	%s 문자열
	%o 8진수
	%x 16진수
	%u 부호없는 정수
	%% %기호를 출력
	==========서식문자================

	입력
	cin(Console Input)
	c언에서는 scanf를 사용한다
	c언에서는 입력을 사용할때  &를 붙이게 되는데 
	c++은 붙일 필요가 없다 내부에서 &를 사용하기 때문이다.

	cin은 공백 입력시 공백이전까지의 값만 결과로 받아들인다.
	ex)hellow word라고 입력하면 hellow만 입력이 된다.
	이러한 끊킴을 없애기 위해서 
	getline()함수를 사용한다
	getline()함수는 개행문자(\n)를 구분자로 사용하여서 한 줄 전체를 결과로 받아들인다.
	따라서 한 줄 전체를 읽을수 있다. 공백을 포함한 문잘열으 처리 할때 유용하다.

	getline()은 각기 다른 라이브러리에 2가지가 존재한다
	istream 라이브러리에 속한 cin.getline()
	string 라이브러리에 속한 getline()

	

*/

namespace Bard
{
	int iHP = 5000;
	int iMP = 12333;
	char cSkill[25] = "";

	void Info()
	{
		std::cout << "저의 직업은 바드입니다." << std::endl;
		std::cout << "HP:" << iHP <<"  " << "iMP:" << iMP << std::endl;
	}

	void cout(char* cSkill)
	{
		std::cout  << cSkill <<"를 발동시켰습니다" << std::endl;

	}
}



int main()
{
	int iNumber = 0;
	float fNumber = 0.f;

	//c++에서 출력하는 방법
	std::cout << "test" << std::endl;



	//c언어에서 출력하는 방법
	printf("%d\n", 10);
	printf("%f\n", 13454555.f);
	printf("%s\n", "안녕하시오");

	//입력..
	
	std::cin >> iNumber;

	std::cout << "iNumber ==> " << iNumber << std::endl;

	std::cin.ignore(256, '\n'); 

	char cName[25] = "";



	//std::cin >> cName;

	
	std::cin.getline(cName, 25);


	std::cout << "cName ==> " << cName << std::endl;

	//std::cin.ignore(256, '\n');
	

	std::cout << "<=================>" << std::endl;


	char cSkill[25] = "";
	
	Bard::Info();
	std::cout << "스킬을 입력해주세요:" << std::endl;
	std::cin >> cSkill;
	Bard::cout(cSkill);


	return 0;
}