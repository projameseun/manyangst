#include <iostream>
#include <time.h>

int main()
{

	//�ּҰ��ݷ� �ִ� ���ݷ�
	//500 ~ 1000

	srand(static_cast<unsigned int>(time(NULL)));

	int iMin = 500;
	int iMax = 1000;
	int iAttack = 0;


	iAttack = rand() % (1000- 500 +1) + 500;
	
	//iAttack = rand() % 500 + 500;

	std::cout << "������ :" << iAttack << std::endl;
	std::cout << "�ּҵ����� :" << iMin << std::endl;
	std::cout << "�ִ뵥���� :" << iMax << std::endl;
	
	
	//��ȭ���α׷�
	
	//std::cout << "��ü ī������ ��ðڽ��ϱ�?" << std::endl;
	// ��� / Ȯ�� �ؼ� cin���� Ȯ���� ������ Ȯ���� �۵��Ͽ� ���� ī�尡 ���������� ���� if&switch������ �ڸ�Ʈ�� ������ ������

	float fRand = rand() % 100 / 1.f;
	
	if (fRand < 0.5f)
	{
		std::cout << "���� ī����" << std::endl;
		std::cout << "Ȯ�� :" << fRand << "%" << std::endl;
	}
	else if (fRand < 9.5f)
	{
		std::cout << "���� ī����" << std::endl;
		std::cout << "Ȯ�� :" << fRand << "%" << std::endl;
	}
	else if (fRand < 40.f)
	{
		std::cout << "��� ī����" << std::endl;
		std::cout << "Ȯ�� :" << fRand << "%" << std::endl;
	}
	else if (fRand < 70.f)
	{
		std::cout << "��� ī����" << std::endl;
		std::cout << "Ȯ�� :" << fRand << "%" << std::endl;
	}
	else if (fRand < 100.f)
	{
		std::cout << "�Ϲ� ī����" << std::endl;
		std::cout << "Ȯ�� :" << fRand << "%" << std::endl;
	}
	else
	{
		std::cout << "������ ����" << std::endl;
		std::cout << "Ȯ�� :" << fRand << "%" << std::endl;
	}
	int a = 0;



	return 0;
}