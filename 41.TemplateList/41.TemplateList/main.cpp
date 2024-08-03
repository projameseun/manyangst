#include <iostream>
#include "CList.h"
#include <list>
#include <vector>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CList<int> list;

	list.PushFront(10);
	list.PushFront(20);
	list.PushFront(30);
	list.PushFront(40);
	list.PushFront(50);

	std::vector <int> test;

	for (int i = 0; i < 10; ++i)
	{
		test.push_back(i+1);
	}


	for (int i = 0; i < test.size(); ++i)
	{
		std::cout << test[i] << std::endl;
	}


	return 0;
}