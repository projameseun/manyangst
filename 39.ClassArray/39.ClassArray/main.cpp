#include <iostream>
#include <vector>
#include "CArray.h"

class Test
{
private:
	Test()
	{

	}
	

};


int main()
{
	//Test ts;	//불가능 하다 클래스는 생성자를 무조건 호출하게 되는데
				//이걸 private로 했기 때문에 외부에서 접근을 할수 없는 상황이 된다.
				//그러므로 오류를 범한다
				//나중에 디자인패턴중 게임에서 유용하게 사용하는 싱글톤패턴을 사용하면 가능하다.
	
	




	CArray arr = {};

	

	arr.push_back(10); //배열에 10을 넣기
	arr.push_back(20); //동일
	arr.push_back(30);

	arr.resize(10);
	
	int iData = arr[1];
	
	arr[1] = 100;

	arr.OutPut();

	arr.push_back(40);
	arr.push_back(50);
	arr.push_back(60);
	arr.push_back(70);

	arr.OutPut();

	std::vector<int> test;

	test.push_back(10);
	test.push_back(20);
	test.push_back(30);
	test.push_back(40);


;
	return 0;
}