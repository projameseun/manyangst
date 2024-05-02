#include "test.h"
#include <iostream>

test::test()
{
	iHp = 0;
	iMp = 0;
}
test::~test()
{

}

void test::MonsterSetting()
{
	iHp = 100;
	iMp = 100;
}

void test::MonsterCout()
{
	std::cout << iHp << std::endl;
	std::cout << iMp << std::endl;
}