#include <iostream>
#include <time.h>

int main()
{
	/*
		����(�������Ǽ�)
		��ǻ�ʹ� �����̶�� ���� ����� ����.
		�����̶� �������� ���� ������ �ϴ°ǵ� �� �������� ���� ���ǽ������� ���� �� �� ���� ������ ��ǻ�ʹ� ����(���ǽ��Ǽ�)�� ���� ����� ����.
		�׷��Ƿ�, ��ǻ�ʹ� ��ġ ����ó�� ���̴� ������ �Է� ���� ��Ÿ���� �ִ°Ŵ�.
		��ǻ�Ͱ� ����� �� ������ ���� ����� ���ؼ� ������� ���� ��ġ �����ǰ��� ����ó�� ���̰� �ϴ°Ŵ�.

		rand()
		�������� �������̺��̶� ���� �����ϰ� �̸� �����ϴ°Ŵ�.
		rand()�Լ��� ���ο� RAND_MAX #define���� ���ǰ� �Ǿ� �ֲ� �� ���ڴ� 16������ �Ǿ� �ִµ�, 10������ �ٲٰ� �Ǹ� 32,767���� �Ǿ� �ִ�.
		�ᱹ rand()�Լ��� ǥ���Ҽ� �ִ� return���� 0 ~ 32,767���� ������ �Ŵ�.
		rand�Լ��� ���α׷��� ����ɶ� ���� �� �������� ������ ���α׷��� ������ ������ �ص� ������ ���� ������ �ȴ�.
	
	*/


	int iNumber = 0;

	iNumber = rand();

	/*std::cout << "1.rand : " << rand() << std::endl;
	std::cout << "2.rand : " << rand() << std::endl;
	std::cout << "3.rand : " << rand() << std::endl;
	std::cout << "4.rand : " << rand() << std::endl;
	std::cout << "5.rand : " << rand() << std::endl;*/

	/*
		rand�Լ��θ��� ǥ���� �Ҽ� ���� ������ ������ �ȴ�. srand(�õ尪) �Լ��̴�.
		srand(seed��) 
		srand�� rand�Լ��� ���� ���� �ʱ�ȭ �Ѵ�.�� �ʱ�ȭ�� �Ű������� �޴� seed���� �̿��ؼ� ����Ѵ�.
		�Ʒ����� srand ������ �ʱ�ȭ ������ seed���� �����ϸ� �ᱹ �Ȱ��� ���� �ݺ��Ǳ� ������ �츮�� ���ϴ� �����̾ƴϴ�.
		
	
	*/
	
	
	/*srand(1000);
	std::cout << "rand :" << rand() << std::endl;
	srand(500);
	std::cout << "rand :" << rand() << std::endl;
	srand(1233);
	std::cout << "rand :" << rand() << std::endl;
	srand(110);
	std::cout << "rand :" << rand() << std::endl;*/

	/*
		seed���� ��� ���Ҽ� �ִٸ� rand()�Լ��� ��� �ٸ����� ����Ҽ� �������̴�.
		�׷��� ������ �Ȱ� time�ð� �Լ��̴�.
		time�Լ�
		UTC(1972�� 1�� 1�� 0 �� 0�� ���� ����� ���� ǥ�ؽ�)�� �ð��� ���������� ��ȯ���ִ� �Լ��� time�Լ��̴�.
		���:seed���ȿ� time�̶�� �ð��Լ��� �־��ش�.
	*/
	
	//srand((unsigned int)time(NULL));
	srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "rand :" << rand() << std::endl;
	std::cout << "rand :" << rand() << std::endl;
	std::cout << "rand :" << rand() << std::endl;
	std::cout << "rand :" << rand() << std::endl;
	std::cout << "rand :" << rand() << std::endl;

	//�츮�� ������ ������ ���ھȿ��� ������ �����´�.
	//�̶� ����ϴ� ������ ��ⷯ��(������)�̴�.
	//ex) rand() % 5; === > � ���ڰ� �͵� 0 ~  4������ ����̵ȴ�.
	//rand() % 10; === > � ���ڰ� �͵� 0 ~  9������ ����̵ȴ�.
	//��Ģ�� n-1���� ����̵ȴ�.


	//0~2�������


	iNumber = rand() % 3;

	std::cout << iNumber << std::endl;

	//0~99

	iNumber = rand() % 100;

	/*iNumber = 1 % 10;
	iNumber = 2 % 10;
	iNumber = 3 % 10;
	iNumber = 4 % 10;
	iNumber = 5 % 10;
	iNumber = 6 % 10;
	iNumber = 7 % 10;
	iNumber = 8 % 10;
	iNumber = 9 % 10;
	iNumber = 10 % 10;

	iNumber = 11 % 10;
	iNumber = 12 % 10;
	iNumber = 13 % 10;
	iNumber = 14 % 10;
	iNumber = 15 % 10;
	iNumber = 16 % 10;
	iNumber = 17 % 10;
	iNumber = 18 % 10;
	iNumber = 19 % 10;
	iNumber = 20 % 10;*/

	//1~100������ ����غ�����

	iNumber = rand() % 100 +1;

	//100~ 199 
	iNumber = rand() % 100 + 100;

	float fRand = rand() % 10000 / 100.f; 
	//std::cout << "Rand :" << fRand << std::endl;


	
	//�ּҰ��ݷ� �ִ� ���ݷ�
	//500 ~ 1000
	int iMin = 500;
	int iMax = 1000;

	//��ȭ���α׷�
	if (fRand < 1.f)
	{
		std::cout << "������ ȹ��" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	else if (fRand < 30.f)
	{
		std::cout << "���� ȹ��" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	else if (fRand < 60.f)
	{
		std::cout << "��� ȹ��" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	else if (fRand < 80.f)
	{
		std::cout << "�Ϲ� ȹ��" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	else
	{
		std::cout << "������ ����" << std::endl;
		std::cout << "frand :" << fRand << std::endl;
	}
	int a = 0;



	return 0;
}