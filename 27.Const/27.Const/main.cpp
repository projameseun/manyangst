#include <iostream>

int main()
{
	//const는 상수이다.
	
	volatile const int iNum = 100;

	//const라는 키워드가 붙었다고 우리가 말하는 진짜 상수가 아니다
	//중요한건 문법적으로 막아주고 있는 것이다.
	
	//100 = 300;
	//iNum = 500;

	int a = 100;
	int b = a + 100; 

	//a + 100 = 300;

	int* ptr = nullptr;

	ptr = (int*)&iNum;

	*ptr = 50;

	std::cout << "iNum = " << iNum << std::endl;

	//위와 같이 강제 형변환을 하여서 넣게 되면 50이 나올거라고 생각하는데 100이 나온다.
	//이유는 컴파일러 입장에서는 const iNum이 상수라고 본거다.
	//디스어셈블리어를 보면 50이 들어간걸 확이까지는 가능하다.
	//근데 cpu가 연산을 할때 레지스터 메모리가 존재하는데 임시값을 저장하고 있다.
	//상수는 컴파일러 입장에서는 바뀌지 않는 수이기 때문에 레지스터 메모리에서 이거하고 바로 쓰게 된것이다.

	/*
		cpu안에 레지스터는 정확히 얘기를 해보면 메모리가 아니다.
		임시 데이터를 저장하는 공간인데 단지 휘발성으로 데이터를 저장하는 공간이다.
		이 덕분에 cpu안에서 실행하면 굉장히 빨리 처리할수있다.

		cpu에 임시데이터를 저장하는공간 레지스터가 있다
		cpu가 메로리로 접근할때 버스라는게 존재한다.
		이 버스에 메모리가 크면 클수록 공간차지를 많이하게 되고
		메모리는 특성상 기록된 내용들을 유지하기 위해서 주기적으로 정부를 다시 써야된다.
		그런데 다시 쓰는 작업이 시간을 또 소모하게 된다.
		레지스터는 cpu랑 매우 가까워
		일 반데이터들은 버스틀 통해서 cpu를 가게 된다. 머릿속으로 그려봤을때 더 가까운게 빠를 수밖에 없는게 당연하다.
		
	*/


	return 0;
}