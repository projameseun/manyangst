#include <iostream>

int main()
{
	//1.ptr값을 말해보시오 출력함수를 사용하여 미리알지않기 이유를 꼭말하기 

	int a = 100;
	int b = 200;
	int c = 300;
	int* ptr = nullptr;

	ptr = &a; // ptr이 a의 주소를 가르켰고

	*ptr = 500; // a의 값을 500으로 바꿨다.
	
	ptr = &c; // ptr이 c의 주소로 가르켰고

	*ptr -=  b; // c의 값에서 b를 뺐다

	
	std::cout << *ptr; // 300(c) - 200(b) = 100 이다
	
	
	//2. 정답을 쓰시오 출력함수를 사용하여 미리알지않기 이유를 꼭말하기 
	short sArr[10] = { 1,333,10,200,24,1010,55,532,450,100 }; // (short)2바이트로 10개의 배열을 생성함

	int* pI = (int*)sArr; // short를 int로 바꿨음

	int iNum = *((short*)(pI + 3));
	// pl + 3을 했으니 1010
	

	//3. 정답을 쓰시오 출력함수를 사용하여 미리알지않기 이유를 꼭말하기 
	char cArr[2] = { 2,1 }; // (char)1바이트로 2개의 배열을 생성함

	short* pS = (short*)cArr; // char을 short로 바꿨음

	iNum = *pS; // iNum에 pS를 넣었음
	
	// 답: 1바이트에서 2바이트로 바껴서 0000 0001 과 0000 0010이 합쳐져서 0000 0001 0000 0010이 되서 이것이 258이 된다.

	return 0;
}