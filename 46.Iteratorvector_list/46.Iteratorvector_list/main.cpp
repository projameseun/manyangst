#include <iostream>
#include <list>
#include <vector>
#include "CVector.h"
#include "CList.h"

int main()
{

	//vector
	std::vector<int> test;


	CVector<int> VecInt;

	VecInt.push_back(10);
	VecInt.push_back(20);
	VecInt.push_back(30);
	VecInt.push_back(40);
	VecInt.push_back(50);
		
	CVector<int>::iterator iter = VecInt.begin();

	iter++;
	iter++;
	


	 iter = VecInt.earse(iter);
	


	for (int i = 0; i < VecInt.size(); ++i)
	{
		std::cout << VecInt[i] << std::endl;
	}

	system("cls");
	//list
	std::list<int> list;

	CList<int> cList;

	cList.push_back(10);
	cList.push_back(20);
	cList.push_back(30);
	cList.push_back(40);
	cList.push_back(50);

	CList<int>::iterator iter2;

	iter2 = cList.begin();

	iter2++;
	iter2++;

	iter2 = cList.earse(iter2);

	iter2 = cList.insert(iter2, 30);

	
	
	for (iter2 = cList.begin(); iter2 != cList.end(); ++iter2)
	{
		std::cout << *iter2 << std::endl;
	}

	int a = 0;
	
	return 0;
}