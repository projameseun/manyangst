#include <iostream>

int main()
{
	/*
		아스키코드(ASCII) ===> American Standard Code for Information Interchange
		컴퓨터에서는 숫자를 이용해서 인식을 하는데 문자를 표현하려면 숫자를 이용해서는 불가능하다...
		그래서 나오게 된 방법이 아스키코드이다.
		아스키코드는 문자 표현을 위해서 나오게 된 것이다.
		
		아스키코드 0 ~ 127로 이루어져 있었다 char형 변수로 저장되어있다.
		1byte내에서 문자등을 표현할수 있다는건 매우 기발한거다...
		
		근데 아스키코드를 이용해서 다른언어를(영어를 뺀 나머지) 표현하기에는 1byte로는 부족했다.
		
		그래서 8비트확장한 아스키코드가 나왔는데 이걸 우린 ANSI코드라고 부른다.
		우리는 지금은 128 + 128 = 256(8bit)의 데이터를 표현할수 있는 ASCII를 사용한다.

		한국,중국,일본,유럽등 문자가 많은 국가에서 제한적이었다.
		그래서 용 량을 크게 확장한 2byte(2의16승) 유니코드가 등장함.

		근데 지금은 이것도 모자라서 4byte유니코드를 사용하고 있다.

		유니코드의 종류 --> ASCII,UTF-8,UTF-16,UTF-32
		UTF8 -->유니코드를 이용하는 인코딩(사용자가 입력한 문자나 기호들을 컴퓨터가 이용할수 있는 신호로 만들어주는것) 방식중하나
		
		한글은 2byte이다.
		한글은 너무 많은 문자가 있기 때문에 1byte에 담을수가 없어서 2byte로 사용한다.

		


	*/


	char sName[25] = "은진수";

	std::cout << sName << std::endl;


	return 0;
}