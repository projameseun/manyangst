#include <iostream>


enum class artist
{
	shield = 0x1, //쉴드
	Hopper = 0x2, // 콩콩이
	Sprinkle = 0x4, //흩뿌리기
	Starry_Night = 0x8, //미리내
	Door_of_Illusion = 0x10, //환문
	Sunsketch = 0x20,  //해그리기

};



int main()
{
	int iPlayer = 0;

	iPlayer |= (int)artist::shield;

	if (iPlayer &= (int)artist::shield)
	{
		std::cout << "도화가님이 쉴드를 주셨습니다" << std::endl;
	}

	iPlayer &= ~(int)artist::shield; 

	if (iPlayer &= (int)artist::shield)
	{
		std::cout << "잘 빠졌는지 확인 용" << std::endl;
	}



	iPlayer |= (int)artist::Hopper;

	if (iPlayer &= (int)artist::Hopper)
	{
		std::cout << "도화가님이 콩콩이를 사용하셨습니다" << std::endl;
	}

	iPlayer ^= (int)artist::Hopper;

	if (iPlayer &= (int)artist::Hopper)
	{
		std::cout << "콩콩이 빠졌는지 확인" << std::endl;
	}

	// 확인 , 넣기, 넣었다 빼기, 빼기
	return 0;
}