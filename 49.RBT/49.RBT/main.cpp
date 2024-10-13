#include <iostream>
#include "CBST.h"
#include <map>


int main()
{


	std::map<int, int> mapint;

	mapint.insert(std::make_pair(100,100));

	CBST<int, int> MyInt;

	MyInt.insert(make_mypair(100, 0));
	MyInt.insert(make_mypair(50, 0));
	MyInt.insert(make_mypair(25, 0));
	MyInt.insert(make_mypair(200, 0));
	
	
	
	return 0;
}