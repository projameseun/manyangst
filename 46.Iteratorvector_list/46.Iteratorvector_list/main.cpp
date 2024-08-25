#include <iostream>
#include <list>
#include <vector>
#include "CVector.h"

int main()
{
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
	
	return 0;
}