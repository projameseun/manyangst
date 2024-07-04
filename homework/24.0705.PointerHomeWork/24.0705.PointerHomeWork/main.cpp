#include <iostream>

int main()
{
	//1.ptr값을 말해보시오 출력함수를 사용하여 미리알지않기 이유를 꼭말하기 

	int a = 100;
	int b = 200;
	int c = 300;
	int* ptr = nullptr;

	ptr = &a;

	*ptr = 500;
	
	ptr = &c;

	*ptr -=  b;

	
	std::cout << *ptr;
	
	
	//2. 정답을 쓰시오 출력함수를 사용하여 미리알지않기 이유를 꼭말하기 
	short sArr[10] = { 1,333,10,200,24,1010,55,532,450,100 };

	int* pI = (int*)sArr;

	int iNum = *((short*)(pI + 3));

	

	//3. 정답을 쓰시오 출력함수를 사용하여 미리알지않기 이유를 꼭말하기 
	char cArr[2] = { 2,1 };

	short* pS = (short*)cArr;

	iNum = *pS;
	
	


	return 0;
}