#include <iostream>

#define MAXHP 10000
#define ASPITO 1.6655



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

	

	//1. const 위치가 맨 앞에 있으면 포인터 변수가 가리키는 값에 대하여 상수화를 시키는 경우 이다.

	int iNum = 100;

	const  int* ptr= &iNum;
	
	//*ptr = 200; 값이 변깅이 안된다

	iNum = 300;

	//2. const 위치가 type과 변수 이름 사이에 있으면서 포인터 변수 자체를 상수화 시키는 경우 이다.

	int iNum2 = 1100;

	int* const ptr2 = &iNum2; //ptr2주소를 상수화 

	//ptr2 = &iNum;
	
	const int* const ptr3 = &iNum; //값과 주소를 모두 상수화 



	
	


	return 0;
}