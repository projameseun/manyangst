#include <iostream>
#include <time.h>
#include <algorithm>

bool iCompare(int a, int b)
{
	return a > b;  //��������
	//return a > b;  //��������

}

int main()
{
	/*
		�迭:���� �ڷ����� ���� �������� �ѹ��� ���� �Ҽ� �ְ� ���ִ� ����̴�.
		�迭�� �޸𸮰� ���������� ���� �ִ�.

		���� Ÿ�� �迭��[����] ������ ����� �����ϴ�.
		�� ���·� ����

		�迭�� ���� ����
		������ �޸𸮸� ���鶧 �Ȱ��� �����͸� �׷����� ��� ǥ�� �Ҷ� �迭 ������ ����Ѵ�.
	*/

	int iStudent[100];
	//��ó�� ����� �Ǹ� �л� 100���� �����Ҽ� �ִ� �޸𸮰� ������̴�.
	//�� ��ҿ� �����ϱ� ���ؼ� ����ϴ°��� �ε����̴�.
	//�ε����� 0 ���� ���� �����Ѵ�.

	//�迭 �ʱ�ȭ 
	
	int iNum[10] = {}; //��� 0 ���� �ʱ�ȭ �Ѵ�.
	//int iNum[10] = { 0, };
	//int iNum[10] = { 0,0,0,0,0,0,0,0,0,0,0, };

	int iNum2[] = { 100,200,59,29,20,50,102 }; 

	int iAraay[10] = { 1,2,3 }; //0,1,2�� �ε����� 1,2,3���� ���Եǰ� �������� 0���� �ʱ�ȭ �Ѵ�.

	iAraay[0] = 10;
	iAraay[8] = 199;

	std::cout << "iArray[0] =" << iAraay[0] << "  iArray[7] =" << iAraay[8];
	std::cout << std::endl;

	//�迭�� ���Ұ��� = sizeof(�迭��) / sizeof(�ڷ���)
	size_t iSize = 0;

	iSize = sizeof(iAraay) / sizeof(int); //�迭�ǰ����� ���ѰŴ�

	for (int i = 0; i < iSize; ++i)
	{
		iAraay[i] = i + 1;
	}

	for (int i = 0; i < iSize; ++i)
	{
		std::cout << "iArray[";
		std::cout << i << "] " << iAraay[i] << std::endl;
	}

	float fArray[100] = { 0.f };

	std::cout << "fArray : " << sizeof(fArray) << std::endl;


	//���ڿ� �迭
	char data[6] = { 'H','A','P','P' ,'Y' }; //���ڿ��ǳ��� NULL,0���� ǥ���Ѵ� �׷��� �����Ϸ��� �� �迭�� ����� ������ ���ڿ��̶�°��� �˼� �ִ�.

	char data2[6] = "Happy";

	char data3[25] = "�ȳ��ϼ���"; //�ѱ��� 2����Ʈ ����� 1����Ʈ

	std::cout << data << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data3 << std::endl;

	system("cls");

	//�ζ� ���α׷�
	//1~45������ ������ ������ 6���� ���ڸ� �����´�.
	//���� �ߺ��Ǹ� �ȵȴ�.
	//��������,�������� 

	iSize = 0;

	int iLotto[45] = {};

	iSize = sizeof(iLotto) / sizeof(int);

	for (int i = 0; i < iSize; ++i)
	{
		iLotto[i] = i + 1;
	}

	srand(static_cast<unsigned int>(time(NULL)));
	
	int iTemp, idx1, idx2 = 0;

	//Shuffle
	for (int i = 0; i < 1000; ++i)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;

	}

	/*for (int i = 0; i < iSize; ++i)
	{
		std::cout <<" iLotto[ " << i+1 << "]  " << iLotto[i] << std::endl;
	}*/


	//STL(standard ���̺귯��)

	//std::sort(iLotto, iLotto + 6);
	std::sort(iLotto, iLotto + 6, iCompare);

	//�������� ��������
	
	/*for (int i = 0; i < 5; ++i)
	{
		for (int j = i + 1; j < 6; ++j)
		{
			if (iLotto[i] > iLotto[j])
			{
				iTemp = iLotto[i];
				iLotto[i] = iLotto[j];
				iLotto[j] = iTemp;
			}
		}
	}*/
	


	
	for (int i = 0; i < 6; ++i)
	{
		std::cout << iLotto[i] << std::endl;
	}

	//�����ð��� �ζǰ���, ������� ...
	

	return 0;
}