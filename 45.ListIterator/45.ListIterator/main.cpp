#include <iostream>
#include <list>
#include "CList.h"

/*

*/

int main()
{
	CList<int> myList;

	myList.PushBack(10);
	myList.PushBack(20);
	myList.PushBack(40);

	CList<int>::iterator iter = myList.begin();

	++iter;
	++iter;

	iter = myList.insert(iter, 30);

	myList.erase(iter); // 30이 사라졌는지 확인

	int iTest = *iter;

	int a = 0;

	for (iter = myList.begin(); iter != myList.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	

	


	return 0;
}