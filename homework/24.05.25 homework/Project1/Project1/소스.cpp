#include <iostream>


enum class artist
{
	shield = 0x1, //����
	Hopper = 0x2, // ������
	Sprinkle = 0x4, //��Ѹ���
	Starry_Night = 0x8, //�̸���
	Door_of_Illusion = 0x10, //ȯ��
	Sunsketch = 0x20,  //�ر׸���

};



int main()
{
	int iPlayer = 0;

	iPlayer |= (int)artist::shield;

	if (iPlayer &= (int)artist::shield)
	{
		std::cout << "��ȭ������ ���带 �ּ̽��ϴ�" << std::endl;
	}

	iPlayer &= ~(int)artist::shield; 

	if (iPlayer &= (int)artist::shield)
	{
		std::cout << "�� �������� Ȯ�� ��" << std::endl;
	}



	iPlayer |= (int)artist::Hopper;

	if (iPlayer &= (int)artist::Hopper)
	{
		std::cout << "��ȭ������ �����̸� ����ϼ̽��ϴ�" << std::endl;
	}

	iPlayer ^= (int)artist::Hopper;

	if (iPlayer &= (int)artist::Hopper)
	{
		std::cout << "������ �������� Ȯ��" << std::endl;
	}

	// Ȯ�� , �ֱ�, �־��� ����, ����
	return 0;
}