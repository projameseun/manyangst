#include <iostream>
#include "CBST.h"
#include <map>
#include <string>

using namespace std;

int main()
{


	std::map<int, int> mapint;

	
	

	mapint.insert(std::make_pair(100, 100));
	mapint.insert(std::make_pair(50, 100));
	mapint.insert(std::make_pair(25, 100));
	mapint.insert(std::make_pair(200, 100));
	mapint.insert(std::make_pair(300, 100));
	
	std::map<int, int>::iterator iter = mapint.begin();

	iter++;

	iter = mapint.insert(iter, std::make_pair(400, 300));
	
	int a = 0;


	CBST<int, int> MyInt;
	//CBST<char, char> myoat;

	
	///myoat.insert(make_mypair('a', 'a'));
	
	CBST<int, int>::iterator iter2;
	
	/*CBST<string, int> MyStr;

	MyStr.insert(make_mypair(static_cast<string>("은진수"), 0));
	MyStr.insert(make_mypair(static_cast<string>("박만냥"), 0));
	MyStr.insert(make_mypair(static_cast<string>("김민지"), 0));
	MyStr.insert(make_mypair(static_cast<string>("이태훈"), 0));
	MyStr.insert(make_mypair(static_cast<string>("정진모"), 0));
	MyStr.insert(make_mypair(static_cast<string>("하인태"), 0));
	MyStr.insert(make_mypair(static_cast<string>("자두림"), 0));
	MyStr.insert(make_mypair(static_cast<string>("박상철"), 0));
	

	CBST<string, int>::iterator iterstr;*/

	//iterstr = MyStr.begin();

	MyInt.insert(make_mypair(100, 0));
	MyInt.insert(make_mypair(50, 0));
	MyInt.insert(make_mypair(60, 0));
	MyInt.insert(make_mypair(20, 0));
	MyInt.insert(make_mypair(200, 0));
	MyInt.insert(make_mypair(150, 0));

	
	iter2 = MyInt.find(60);

	
	iter2 = MyInt.erase(iter2);

	iter2 = MyInt.begin();
	

	
	//
	//정수
	for (iter2; iter2 != MyInt.end() && iter2 != MyInt.GetNilNode(); ++iter2)
	{
		//iCount++;
		std::cout << (*iter2).first << std::endl;
		
	}
	//std::cout << iCount << std::endl;

	return 0;
}