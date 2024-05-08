#include <iostream>

int main()
{
	/*
		형변환(TypeCasting)
		형 변환은 자료형을 변환시키는것이다.
		5가지의 종류가 있다
		c-style cast
	*/

	//c-style cast

	int a = 0;
	float b = 5.f;

	a = (float)3.222f; //명시적 형변환 (사용자가 직접데이터 타입변경하는것)

	a = static_cast<float>(2.3f);

	a = a + 5.555f; //암시적 형변환(자동으로 형변환)

	//암시적 형변환은 Data의 손실이 발생할수 있기때문에 문제가 될수 있다.
	//크기가 큰대서 작은거로 대입을 하게 되면 데이터의 손실이 올수있다. 그래서 확실할때 만 사용하는 것이 좋다.

	
	
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	//타입캐스트 연산자 
	//static_cast,const_cast,dynamic_cast,reinterpreat_cast

	//static_cast
	int iNumber = 0;

	char cNumer = 0;

	float fNumber = 0.f;

	iNumber = 100;

	cNumer = static_cast<char>(iNumber);  //int -> char

	fNumber= static_cast<float>(cNumer);  //char ->float

	std::cout << cNumer << std::endl;

	std::cout << fNumber << std::endl;
	
	//const_cast
	//상수성을 변경할때 사용한다 포인터나 참조(레펀런스)를 통해서 사용함

	const volatile int conValue = 100;
	const volatile int* ptr = &conValue;
	
	int* ptr2 = const_cast<int*>(ptr);
	
	*ptr2 = 50;

	
	std::cout << conValue << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << *ptr2<< std::endl;

	//dynamci_cast
	//클래스에서 상속관계로 되어있을때 스캐팅이 가능하다 타입검사를 하지 않기 때문에 위험하다.
	//이럴때 안전하게 사용하기위해서 dynamic_cast이다.
	//변환을 실패하면 nullptr을 반환한다 .. 이걸 알려면 나중에 상속,업캐스팅,다운캐스팅을 이해해 하셔야 알수 있음

	//reinterpreat_cast
	//서로 다른 포인터 또는 레퍼런스를 변환하는데 사용한다
	
	
	


	


	return 0;
}