#include <iostream>
#include <time.h>
#include <Windows.h>

//Rock Paper Scissors

enum class SRP
{
	S = 1,
	R ,
	P  ,
	EXIT ,

};


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	//����������
	
	

	while (true)
	{
		system("cls");
		int iPlayer = 0;
		int iResult = 0;
		std::cout << "<<========�������������� ========>>" << std::endl;
		std::cout << "1.���� 2.���� 3. �� 4.������" << std::endl;

		std::cin >> iPlayer;

		int iCom = rand() % 3 + 1;
		
		//����ó��
		if (iPlayer == (int)SRP::EXIT)
		{
			break;
		}

		if (iPlayer < 1 || iPlayer >3)
		{
			continue;
		}

		//���ӽ���

		iResult = iPlayer - iCom;
		

		std::cout << iPlayer << std::endl;
		std::cout << iCom << std::endl;

		if (iResult == 1 || iResult == -2)
		{
			std::cout << "Player �¸� " << std::endl;
		}
		else if (iPlayer == iCom)
		{
			std::cout << "���" << std::endl;
		}
		else
		{
			std::cout << "Com �¸� " << std::endl;
		}



		
		system("pause");
	}


	//���Ǳ����
	//1����ó�� �ϱ����ؼ� while�� ����Ѵ�
	//2.��尡 �����Ѵ� 
	//3.��尡 0�̵Ǹ� ���� �ڵ�����
	// 4.�ߺ�����(��ɳ���) Ŀ��2 �ݶ�3 
	//�޴� ������޴��� ������ �� ������ּ��� 
	//


	return 0;
}