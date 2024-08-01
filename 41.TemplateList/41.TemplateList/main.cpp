#include <iostream>
#include "CList.h"

int main()
{
	CList<int> list;

	list.PushBack(10);
	list.PushBack(20);
	list.PushBack(30);
	list.PushBack(40);
	list.PushBack(50);

	return 0;
}