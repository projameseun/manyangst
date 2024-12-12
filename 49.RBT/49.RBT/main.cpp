#include <iostream>
#include "CBST.h"
#include <map>
#include <string>

using namespace std;

int main()
{


	std::map<int, int> mapint;

	


	

	/*mapint.insert(std::make_pair(100, 100));
	mapint.insert(std::make_pair(50, 100));
	mapint.insert(std::make_pair(25, 100));
	mapint.insert(std::make_pair(200, 100));
	mapint.insert(std::make_pair(300, 100));
	*/
	std::map<int, int>::iterator iter = mapint.begin();

	//iter++;

	//iter = mapint.insert(iter, std::make_pair(400, 300));
	
	int a = 0;


	CBST<int, int> MyInt;
	//CBST<char, char> myoat;

	MyInt.insert(make_mypair(1, 0));
	MyInt.insert(make_mypair(2, 0));
	MyInt.insert(make_mypair(3, 0));
	MyInt.insert(make_mypair(4, 0));
	MyInt.insert(make_mypair(5, 0));
	MyInt.insert(make_mypair(6, 0));
	MyInt.insert(make_mypair(7, 0));
	MyInt.insert(make_mypair(8, 0));
	MyInt.insert(make_mypair(9, 0));
	MyInt.insert(make_mypair(10, 0));

	MyInt.insert(make_mypair(11, 0));
	MyInt.insert(make_mypair(12, 0));
	MyInt.insert(make_mypair(13, 0));
	MyInt.insert(make_mypair(14, 0));
	MyInt.insert(make_mypair(15, 0));
	MyInt.insert(make_mypair(16, 0));
	MyInt.insert(make_mypair(17, 0));
	MyInt.insert(make_mypair(18, 0));
	MyInt.insert(make_mypair(19, 0));
	MyInt.insert(make_mypair(20, 0));
	MyInt.insert(make_mypair(21, 0));
	MyInt.insert(make_mypair(22, 0));

	
	///myoat.insert(make_mypair('a', 'a'));
	
	CBST<int, int>::iterator iter2;
	
	CBST<string, int> MyStr;

	//int
	//MyInt.insert(make_mypair(100, 0));					//				 100
	//MyInt.insert(make_mypair(60, 0));					//           
	//MyInt.insert(make_mypair(25, 0));
	//MyInt.insert(make_mypair(200, 0));
	//MyInt.insert(make_mypair(250, 0));



	//스트링
	//MyStr.insert(make_mypair(static_cast<string>("루피"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("나미"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("조로"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("상디"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("쵸파"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("징베"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("로빈"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("프랑키"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("브룩"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("샹크스"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("버기"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("미호크"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("티치"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("빅맘"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("핸콕"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("비비"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("우타"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("카이도"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("페로나"), 0));
	//MyStr.insert(make_mypair(static_cast<string>("모모노스케"), 0));
	//

	CBST<string, int>::iterator iterstr;

	//iterstr = MyStr.begin();

	//iterstr = MyStr.find("상디");
	//iterstr = MyStr.erase(iterstr);


	//iterstr = MyStr.find("핸콕");
	//iterstr = MyStr.erase(iterstr);


	//iterstr = MyStr.find("징베");
	//iterstr = MyStr.erase(iterstr);



	//iterstr = MyStr.find("카이도");
	//iterstr = MyStr.erase(iterstr);
	

	iter2 = MyInt.begin();
	

	iter2 = MyInt.find(18);
	iter2 = MyInt.erase(iter2);
	
	//
	//정수
	//for (iter2; iter2 != MyInt.end() && iter2 != MyInt.GetNilNode(); ++iter2)
	//{
	//	//iCount++;
	//	std::cout << (*iter2).first << std::endl;
	//	
	//}
	//std::cout << iCount << std::endl;


	//스트링
	//for (iterstr; iterstr != MyStr.end() && iterstr != MyStr.GetNilNode(); ++iterstr)
	//{
	//	//iCount++;
	//	std::cout << (*iterstr).first << std::endl;

	//}

	return 0;
}