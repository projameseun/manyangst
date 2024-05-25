#include <iostream>



enum class Bard
{
	SoundShock = 0x1,  //1,
	RhapsodyofLight =0x2, // 2광시곡
	WindofMusic =0x4, //4
	SonicVibration= 0x8, // 8 음진
	HeavenlyTune = 0x10, //16
	Symphonia = 0x20,  //32 
	Harp = 0x40,  //64 
	
};

const unsigned int SLEEP = 1;
const unsigned int HUNGRY = 2;
const unsigned int UPSET = 4;
const unsigned int COLD = 8;
const unsigned int HOT = 16;

//#define SLEEP = 1;
//#define HUNGRY = 2;
//#define UPSET = 4;
//#define COLD = 8;
//#define HOT = 16;





int main()
{
	/*
		비트단위 논리 연산자 : AND(&) ,OR(|),NOT(~), XOR(^)
		값 대 값을 연산하여 결과로 값이 나오게 한다.

		110 & 52 = 
	&	0110 1110
		0011 0100
		==========
		0010 0100
		36이 된다.

		110 | 52 = 
	|	0110 1110
		0011 0100
		===========
		0111 1110
		14+16+32+64 =126 이된다.

		A		B		XOR
		false	false	false
		false	true	true	
		true	false	true
		true	true	false

		XOR은 두개가 같으면 false 다르면 true가 나온다.
		
		110 ^ 52 =
	^	0110 1110
		0011 0100
		================
		0101 1010 
		10 + 16+64 = 90이 된다.

		NOT ~연산자는 1은0, 0은 1로 변경된다.(1의보수)
		~110
		0110 1110
		=========
		1001 0001


	
	*/

	std::cout << "110 & 52 = " << (110 & 52) << std::endl;
	std::cout << "110 | 52 = " << (110 | 52) << std::endl;
	std::cout << "110 ^ 52 = " << (110 ^ 52) << std::endl;

	//쉬프트 연산자 : << , >> 2가지 방법이 있다.
	
	unsigned int a = 3;
	
	a = a << 5;  //2의 n승 * 배수 // 2의5승은 32 * 3 = 96 이 나온다. 빠른 곱하기 라고도 부른다.
	//a <<= 5;
	
	a = 0;

	unsigned char b = 8;

	b >>= 3; //2의 n승 나누기 // 2의 3승은 8 / 8 = 1 이 나온다, 빠른 나누기 라고도 부른다.
	

	/*
	왼쪽 으로 2비트만큼 이동 하게 되면은 앞에 최상위비트가 2개사라지고 뒤에는 0이라는 숫자가 나오게 된다.
	30 << 2 = 
	0001 1110
	0111 1000
	120이 된다.

	30 << 3 = 
	1111 0000
	240이 된다 .

	30 << 2 = 2의 2승 * 30 / 120
	30 << 3 = 2의 3승 * 30 /240

	오른쪽으로 2비트만큼 이동하게 되면 맨 오른쪽으로 갈때마다 사라진다.
	30 >> 2 = 
	0001 1110
	111
	7이 된다.

	30 >> 3 
	0001 1110
	11 
	3이 된다 .

	30 >> 2 = 2의2승 / 30 = 7이된다
	30 >> 3 = 2의 3승 / 30 = 3이된다.
	

	*/

	//게임에서 비트연산자를 사용하는 방법.


	//const unsigned int SLEEP = 1;
	//const unsigned int HUNGRY = 2;
	//const unsigned int UPSET = 4;
	//const unsigned int COLD = 8;
	//const unsigned int HOT = 16;

	char PlayerState = 0;
	//State ===> 00000000
	//| (OR)연산자를 이용하면 값을 넣어줄수 있다.
	//플레이어에게 Sleep를 넣어보겠습니다.
	PlayerState |= SLEEP;

	//&(and)연산자를 이용해서 확인을 할수 있다.
	if (PlayerState & SLEEP)
	{
		std::cout << "플레이어가 잠을 자고 있습니다" << std::endl;
	}

	// ^(XOR)연산자는 없으면 넣고 있으면 뺀다.

	PlayerState ^= SLEEP;
	PlayerState ^= SLEEP;
	if (PlayerState & SLEEP)
	{
		std::cout << "플레이어가 또다시 자고 있습니다" << std::endl;
	}

	//특정 자리 비트제거
	//해당 변수에 ~(NOT)연산자를 해주고 &연산자로 연산을 한다.

	PlayerState = PlayerState & ~SLEEP;

	//State &= ~SLEEP;
	
	PlayerState |= HUNGRY;
	PlayerState |= UPSET;
	

	if (PlayerState & UPSET && PlayerState & HUNGRY)
	{
		std::cout << "플레이어가 배가 고파서 화가 많이나있습니다" << std::endl;
	}

	////////////로스트아크...방식

	int iPlayer = 0;

	iPlayer |= (int)Bard::SoundShock;
	
	if (iPlayer &= (int)Bard::SoundShock)
	{
		std::cout << "사운드 쇼크 발동" << std::endl;
	}
	
	iPlayer &= ~(int)Bard::SoundShock;

	iPlayer |= (int)Bard::Symphonia;

	if (iPlayer &= (int)Bard::Symphonia)
	{
		std::cout << "심포니아 발동" << std::endl;
	}
	
	
	//1.확인,2.넣는거,3.넣다뺏다 ,4 빼기

	return 0;
}