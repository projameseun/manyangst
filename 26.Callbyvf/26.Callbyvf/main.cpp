#include <iostream>

//call by value
//void swap(int a, int b)
//{
//	int iTemp = 0;
//
//	iTemp = a;
//	a = b;
//	b = iTemp;
//}

//call by Address
void swap(int* a, int* b)
{

	std::cout << "a = " << &a << std::endl;
	std::cout << "b = " << &b << std::endl;
	int iTemp = 0;

	iTemp = *a;
	*a = *b;
	*b = iTemp;
}

void swap(int& a, int& b)
{
	std::cout << "a = " << &a << std::endl;
	std::cout << "b = " << &b << std::endl;
	int iTemp = 0;

	iTemp = a;
	a = b;
	b = iTemp;
}

int main()
{
	/*
		Call by Value Call by Reference
		
		Call by Value는 값을 인자로 전달하는 함수의 호출방식
		값이 복사되어서 전달되기때문에 함수 내에서 값을 변경을해도 원본값이 변경이 되지 않는다.

		Call by Reference 는 주소 값을 인자로 전달하는 함수의 호출방식
		함수가 인자로 전달되는 값이 변수의 주소이므로, 함수 내에서 변수의 값을 변경하면 해당 주소에 저장된 값이 변경이 된다.



	*/

	int iNum = 100;
	int iNum2 = 200;

	
	std::cout << "iNum = " << &iNum << std::endl;
	std::cout << "iNum2 = " << &iNum2 << std::endl;

	/*std::cout << "<======변경전 ======>" << std::endl;
	std::cout << "iNum = " << iNum << std::endl;
	std::cout << "iNum2 = " << iNum2 << std::endl;*/

	swap(iNum, iNum2);	//callbyvalue
	//swap(&iNum, &iNum2); //callbyaddress
	//swap(iNum, iNum2);	//callbyreference
	//std::cout << "<======변경후 ======>" << std::endl;
	//std::cout << "iNum = " << iNum << std::endl;
	//std::cout << "iNum2 = " << iNum2 << std::endl;


	
	
	/*
		레퍼런스 와 포인터는 둘다 c++에서 사용되지만 비슷하면서 둘은 차이가 있어...
		레퍼런스
		1.선언시 반드시 초기화가 되어야 한다.
		2.초기화 한후 다른 변수를 가르킬수가 없다.
		3.레퍼런스를 통해서 원본변수에 접근해서 변경할수 있다. 포인터와 달리 주소 연산자를 사용할 필요가 없다.
		4.레퍼런스는 NULL값을 가질수가 없다 항상 유효한 변수를 가르켜야 된다는 말이다.

		포인터는 NULL,nullptr을 가질수 있는데 이는 포인터가 어떤 유효한 변수를 가리키지 않는다는것을 의미한다.
		
	*/


	/*int a = 100;
	int b = 200;
	int c = 300;


	int& ref = a;
	
	ref = b; 
	
	std::cout << "&a : " << &a << std::endl;
	std::cout << "&b : " << &b << std::endl;
	std::cout << "&ref :" << &ref << std::endl;

	b = 1000;

	std::cout << "a :" << a << std::endl;
	std::cout << "b : "<< b << std::endl;
	std::cout << "ref : " << ref << std::endl;*/

	


	return 0;
}