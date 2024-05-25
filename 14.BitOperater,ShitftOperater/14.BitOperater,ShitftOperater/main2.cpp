#include <iostream>

int main()
{
	//Bit연산자 + Shift연산자를 이용해서 RGB만들어보기
	//32비트 칼라 0 ~ 255숫자만을 넣는다.

	unsigned int iColor = 0;

	unsigned char iAlpha = 100;
	unsigned char iRed = 56;
	unsigned char iGreen = 200;
	unsigned char iBlue = 140;


	iColor = iAlpha;
	iColor <<= 8;

	iColor |= iRed;
	iColor <<= 8;

	iColor |= iGreen;
	iColor <<= 8;

	iColor |= iBlue;


	std::cout << "COLOR = " << iColor << std::endl;

	//f:15이기때문에 2진수로 나타내면 1111 이 된다. 이걸이용해서 ff 를하면 8비트 11111111을 만들수있고 &연산을 사용하면 내가원하느 ㄴ칼라만 뽑을수 있다.
	std::cout << "Blue = " << (iColor & 0x00000000ff) << std::endl;
	std::cout << "Green = " << (iColor >> 8 & 0x00000000ff) << std::endl;
	std::cout << "Red = " << (iColor >> 16 & 0x00000000ff) << std::endl;
	std::cout << "Alpha = " << (iColor >> 24 & 0x00000000ff) << std::endl;


	return 0;
}