#include <iostream>


/*
숙제 1.
이중 for문을 활용해서 아래 모양들을 출력한다.
1-1.
*
**
***
****
*****

1-2.
*****
****
***
**
*

1-3.
	*
   **
  ***
 ****
*****

1-4.
*****
 ****
  ***
   **
	*

1-5.
   *
  ***
 *****
*******

1-6.
   *
  ***
 *****
*******
 *****
  ***
   *
*/



int main()
{
	/*
		while 주로 무한 루프를 돌릴때 많이 사용한다.
		게임을 만들때 무한으로 돌릴때 많이 사용한다.
		while(조건식) //조건식이 거짓일때 나오게 된다. , break를 만나면 나게 된다.
		{

		}

		do while : 처음 한번은 무조건 동작이 되고 그 후에 조건식을 체크하여 false면 빠져나간다.
		do
		{
			코드
		}while(조건식);
		
	*/

	int iGameStart = 0;

	iGameStart = 1;

	/*while (iGameStart)
	{
		system("cls");
		std::cout << "게임 시작 " << std::endl;

		for (int i = 0; i < 1000; ++i)
		{
			std::cout << i << std::endl;
		}

		iGameStart = 0;
		
	}*/

	int iNum = 1;

	do
	{
		iNum++;
		std::cout << "iNum = " << iNum <<std::endl;
		
	} while (iNum == 0);




	return 0;
}