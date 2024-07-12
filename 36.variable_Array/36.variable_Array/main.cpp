#include <iostream>
#include "Array.h"
#include <time.h>
#define MAXSIZE 10

int main()
{
	srand(time(NULL));

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//가별배열 

	/*int a = 100;

	int arr[a] = {};*/

	FArray vArr = {};

	InitArr(&vArr);

	for (int i = 0; i < 50; ++i)
	{
		PushBack(&vArr, rand()%1000);
	}

	for (int i = 0; i < vArr.iSize; ++i)
	{
		std::cout << vArr.pInt[i] << std::endl;
	}
	


	int a = 0;





	return 0;
}