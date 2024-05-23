#include <iostream>



enum class Bard
{
	SoundShock = 0x1,  //1,
	RhapsodyofLight =0x2, // 2���ð�
	WindofMusic =0x4, //4
	SonicVibration= 0x8, // 8 ����
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
		��Ʈ���� �� ������ : AND(&) ,OR(|),NOT(~), XOR(^)
		�� �� ���� �����Ͽ� ����� ���� ������ �Ѵ�.

		110 & 52 = 
	&	0110 1110
		0011 0100
		==========
		0010 0100
		36�� �ȴ�.

		110 | 52 = 
	|	0110 1110
		0011 0100
		===========
		0111 1110
		14+16+32+64 =126 �̵ȴ�.

		A		B		XOR
		false	false	false
		false	true	true	
		true	false	true
		true	true	false

		XOR�� �ΰ��� ������ false �ٸ��� true�� ���´�.
		
		110 ^ 52 =
	^	0110 1110
		0011 0100
		================
		0101 1010 
		10 + 16+64 = 90�� �ȴ�.

		NOT ~�����ڴ� 1��0, 0�� 1�� ����ȴ�.(1�Ǻ���)
		~110
		0110 1110
		=========
		1001 0001


	
	*/

	std::cout << "110 & 52 = " << (110 & 52) << std::endl;
	std::cout << "110 | 52 = " << (110 | 52) << std::endl;
	std::cout << "110 ^ 52 = " << (110 ^ 52) << std::endl;

	//����Ʈ ������ : << , >> 2���� ����� �ִ�.
	
	unsigned int a = 3;
	
	a = a << 5;  //2�� n�� * ��� // 2��5���� 32 * 3 = 96 �� ���´�. ���� ���ϱ� ��� �θ���.
	//a <<= 5;
	
	a = 0;

	unsigned char b = 8;

	b >>= 3; //2�� n�� ������ // 2�� 3���� 8 / 8 = 1 �� ���´�, ���� ������ ��� �θ���.
	

	/*
	���� ���� 2��Ʈ��ŭ �̵� �ϰ� �Ǹ��� �տ� �ֻ�����Ʈ�� 2��������� �ڿ��� 0�̶�� ���ڰ� ������ �ȴ�.
	30 << 2 = 
	0001 1110
	0111 1000
	120�� �ȴ�.

	30 << 3 = 
	1111 0000
	240�� �ȴ� .

	30 << 2 = 2�� 2�� * 30 / 120
	30 << 3 = 2�� 3�� * 30 /240

	���������� 2��Ʈ��ŭ �̵��ϰ� �Ǹ� �� ���������� �������� �������.
	30 >> 2 = 
	0001 1110
	111
	7�� �ȴ�.

	30 >> 3 
	0001 1110
	11 
	3�� �ȴ� .

	30 >> 2 = 2��2�� / 30 = 7�̵ȴ�
	30 >> 3 = 2�� 3�� / 30 = 3�̵ȴ�.
	

	*/

	//���ӿ��� ��Ʈ�����ڸ� ����ϴ� ���.


	//const unsigned int SLEEP = 1;
	//const unsigned int HUNGRY = 2;
	//const unsigned int UPSET = 4;
	//const unsigned int COLD = 8;
	//const unsigned int HOT = 16;

	char PlayerState = 0;
	//State ===> 00000000
	//| (OR)�����ڸ� �̿��ϸ� ���� �־��ټ� �ִ�.
	//�÷��̾�� Sleep�� �־�ڽ��ϴ�.
	PlayerState |= SLEEP;

	//&(and)�����ڸ� �̿��ؼ� Ȯ���� �Ҽ� �ִ�.
	if (PlayerState & SLEEP)
	{
		std::cout << "�÷��̾ ���� �ڰ� �ֽ��ϴ�" << std::endl;
	}

	// ^(XOR)�����ڴ� ������ �ְ� ������ ����.

	PlayerState ^= SLEEP;
	PlayerState ^= SLEEP;
	if (PlayerState & SLEEP)
	{
		std::cout << "�÷��̾ �Ǵٽ� �ڰ� �ֽ��ϴ�" << std::endl;
	}

	//Ư�� �ڸ� ��Ʈ����
	//�ش� ������ ~(NOT)�����ڸ� ���ְ� &�����ڷ� ������ �Ѵ�.

	PlayerState = PlayerState & ~SLEEP;

	//State &= ~SLEEP;
	
	PlayerState |= HUNGRY;
	PlayerState |= UPSET;
	

	if (PlayerState & UPSET && PlayerState & HUNGRY)
	{
		std::cout << "�÷��̾ �谡 ���ļ� ȭ�� ���̳��ֽ��ϴ�" << std::endl;
	}

	////////////�ν�Ʈ��ũ...���

	int iPlayer = 0;

	iPlayer |= (int)Bard::SoundShock;
	
	if (iPlayer &= (int)Bard::SoundShock)
	{
		std::cout << "���� ��ũ �ߵ�" << std::endl;
	}
	
	iPlayer &= ~(int)Bard::SoundShock;

	iPlayer |= (int)Bard::Symphonia;

	if (iPlayer &= (int)Bard::Symphonia)
	{
		std::cout << "�����Ͼ� �ߵ�" << std::endl;
	}
	
	
	//1.Ȯ��,2.�ִ°�,3.�ִٻ��� ,4 ����

	return 0;
}