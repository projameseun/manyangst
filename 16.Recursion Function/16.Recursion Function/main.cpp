#include <iostream>

/*
	재귀(Ruecursion)함수란
	함수 안에서 자기 자신의 함수를 호출하는 방식
	디버그 할때 호출 스택에 더블클릭을 하게되면 다른쪽도 볼수 있음
	
	함수안에서 자기 함수를 계속불러오면(재귀함수) 스택의 한계치를 도달하게 되는데
	이를 스택 오버 플로우라고 한다.
*/


int FactorialFor(int _Count)
{
	int iValue = 1;

	for (int i = 0; i < _Count - 1; ++i)
	{
		//iValue = iValue * (i + 2);
		iValue *= (i + 2);
	}

	//이건 재귀함수 맞는데 심각한 문제가 생긴다 스택에 계속 메모리가ㅐ 쌓여서 스택오버 플로우가 생긴다.
	//FactorialFor(4);

	return iValue;
}

//팩토리얼 재귀함수
int Factorial_Re(int _Count)
{
	if (_Count == 1)
	{
		return 1;
	}

	return _Count * Factorial_Re(_Count - 1);
}


int main()
{
	//팩토리얼 for문
	
	int FacNum = 5;
	int iValue = 1;

	for (int i = 0; i < FacNum - 1; ++i)
	{
		//iValue = iValue * (i + 2);
		iValue *= (i + 2);
	}


	std::cout << "FactorialForMun :" << iValue << std::endl;

	//팩토리얼 for문 함수
	
	iValue = FactorialFor(5);

	std::cout << "FactorialForMunFunction : " << iValue << std::endl;

	//팩토리얼 재귀함수
	
	iValue = Factorial_Re(5);

	std::cout << "Factorial_ReFunction : " << iValue << std::endl;


	//피보나치해야됨
	
	//꼬리재귀 설명잘한거 https ://bozeury.tistory.com/entry/%EA%BC%AC%EB%A6%AC-%EC%9E%AC%EA%B7%80-%EC%B5%9C%EC%A0%81%ED%99%94Tail-Recursion

	return 0;
}