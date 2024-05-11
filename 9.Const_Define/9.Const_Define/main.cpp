#include <iostream>

#define MAXHP 10000




int main()
{
	//변수(variable)란 데이터(data)를 저장하기 위해 이름을 할당받은 메모리 공간을 의미합니다.
	//	즉, 변수란 데이터(data)를 저장할 수 있는 메모리 공간을 의미한다.
				//컴파일 과정 ///      
	//전처리 - > 컴파일 -> 빌드 - > 링킹 -> 실행파일 

	//define은 메모리에 할당 되지 않는다.(디버깅 안된다 오류났을시 난리난다)
	//const는 메모리에 할당 된다.

	//const(상수)
	//enum class
	
	int iDamage = 0;
	iDamage = 100;

	int iBOSSHP = 0;

	iBOSSHP -= iDamage;

	std::cout << 50000 << std::endl;

	double dNumber = 0;

	dNumber = 1.7444;

	const int conValue = 0;

	
	
	


	return 0;
}