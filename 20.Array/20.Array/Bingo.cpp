#include <iostream>
#include <time.h>
#include <Windows.h>

int iNumber[25] = {};

int iBingo = 0;

void Init()
{
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

}

void Shuffule()
{
	int iTemp, idx1, idx2 = 0;

	for (int i = 0; i < 1000; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
}

void BingoCheck()
{
	//CHECK

		//���� �ٲ����� üũ�Ѵ� 
		//���� 5�� ���� 5�� �밢�� 2�� �� �����Ѵ�.
		//���߿� 5���̻��� �ϼ��ϸ� ���ӿ��� �¸� 
		//

		//�������� ���Ѵ�

	int iCheck1 = 0;
	int iCheck2 = 0;


	iBingo = 0;

	for (int i = 0; i < 5; ++i)
	{
		iCheck1 = 0;
		iCheck2 = 0;

		for (int j = 0; j < 5; ++j)
		{
			//������
			if (iNumber[i * 5 + j] == INT_MAX)
			{
				++iCheck1;
			}
			//������
			if (iNumber[j * 5 + i] == INT_MAX)
			{
				++iCheck2;
			}
		}

		//���⼭ check�� ���� 5��� ������ ��� ���� �ٲ���̴�
		if (iCheck1 == 5)
		{
			++iBingo;
		}
		if (iCheck2 == 5)
		{
			++iBingo;
		}
	}

	iCheck1 = 0;

	//�밢�� 
	for (int i = 0; i < 25; i += 6)
	{
		if (iNumber[i] == INT_MAX)
		{
			++iCheck1;
		}

	}

	if (iCheck1 == 5)
	{
		++iBingo;
	}



	iCheck1 = 0;

	for (int i = 0; i < 5; ++i)
	{
		if (iNumber[i * 4 + 4] == INT_MAX)
		{
			++iCheck1;
		}
	}

	if (iCheck1 == 5)
	{
		++iBingo;
	}
}

void GameStart()
{
	while (true)
	{
		system("cls");

		std::cout << "�����ټ� : " << iBingo << std::endl;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
					std::cout << "��\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				}
				else
				{
					std::cout << iNumber[i * 5 + j] << "\t";
				}
			}

			std::cout << std::endl;
		}//	for (int i = 0; i < 5; ++i)

		if (iBingo >=5 )
		{
			std::cout << "5����!!!" << std::endl;
			std::cout << "������ �����մϴ� " << std::endl;
			break;
		}

		std::cout << "���ڸ� �Է����ּ���(999 : ����) ";

		
		
		int iInput = 0;
		std::cin >> iInput;

		if (iInput == 999)
			break;

		else if (iInput <= 0 || iInput > 25)
		{
			continue;
		}

		//�տ��� �Է��� ���ڸ� �ٽ� �Է��ߴ��� üũ���ϱ����� bool������ �̿��Ѵ�.
		//true�� �ʱ�ȭ�� �������� �ߺ��� �Ǿ��ٶ�� ������ �صл��¿���
		//�Ʒ� for������ ���� ã���� ��� �ߺ��� �ȵȰ����� false�� ó���ϸ� �ȴ�
		//�Ʒ� for������ ���� ��ã�Ҵٸ� �̹� �Է��� ���̶�� ���� �̹Ƿ�
		//�ߺ��� ó���ϱ� ���ؼ��̴�.

		bool bAcc = true;

		//�츮�� �Է��� ���ڸ� �ڷ� ������ �ش�.
		for (int i = 0; i < 25; ++i)
		{
			//���� �Է��� ���ڰ� �������
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				bAcc = false;
				break;
			}
		}

		//���� �ߺ��� �Ǿ��ִٸ� �ٽ��Է� �ް� �Ѵ�
		if (bAcc)
			continue;

		//check
		BingoCheck();

		
	}
}


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	/*
		�������
		5 x 5 �� ȭ�鿡 ��������� �ϰ� ���� �Է� �Ѵ�
		
		
	*/
	
	Init();
	
	Shuffule();

	GameStart();
	
	

	
	//���� aI���������� 
	//�̰͵� �̴�... AI�Ӹ��� �������� 

	


	

	return 0;
}