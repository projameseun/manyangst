#include <iostream>

int main()
{
	/*
		이차원배열:배열에 배열을 선언한것이다.
		int iNumber[5][10];
		의 형태로 구성된다.
		총 배열수는 5 * 10을 해서 50개가 되고 200바이트를 차지한다 .
	*/

	int iNumber[5][10];
	iNumber[0][5] = 10;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			//i 와 j의값을 이용해서 0 ~ 49까지에 값이 만들어지게 작성한거다.
			iNumber[i][j] = i * 10 + j+1;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << iNumber[i][j] << std::endl;
		}
	}
	

	
	return 0;
}