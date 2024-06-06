#include <iostream>
#include <time.h>
#include <Windows.h>

int iPlayer[25];
int iAI[25];

int iPBingo = 0;
int iAIBingo = 0;

int iSelectMode = 0;

int iInput = 0;

int iGameStart = 0;

enum class AIMODE
{
	EASY = 1,
	HARD,
};

enum class LN_NUMBER
{
	LN_W1,
	LN_W2,
	LN_W3,
	LN_W4,
	LN_W5,

	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,

	LN_LD,	//�޴�
	LN_RD,	//����


};

void Init()
{
	for (int i = 0; i < 25; ++i)
	{
		iPlayer[i] = i + 1;
		iAI[i] = i + 1;
	}

}

void GameModeSlect()
{
	while (true)
	{
		system("cls");

		std::cout << "���� ��带 �������ּ��� " << std::endl;
		std::cout << "1. EASY MODE " << std::endl;
		std::cout << "2. HARD MODE " << std::endl;

		std::cin >> iSelectMode;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(50, '\n');
		}

		if (iSelectMode == (int)AIMODE::EASY)
		{
			iSelectMode = (int)AIMODE::EASY;
			break;
		}
		else if (iSelectMode == (int)AIMODE::HARD)
		{
			iSelectMode = (int)AIMODE::HARD;
			break;
		}
		else
		{

			continue;
		}

	}
}

void Shuffule()
{
	int iTemp, idx1, idx2 = 0;

	for (int i = 0; i < 1000; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iPlayer[idx1];
		iPlayer[idx1] = iPlayer[idx2];
		iPlayer[idx2] = iTemp;

		//AI
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAI[idx1];
		iAI[idx1] = iAI[idx2];
		iAI[idx2] = iTemp;

	}
}

//�����̳�������
void BingoEnd()
{
	
	if (iPBingo >= 5 && iAIBingo >= 5)
	{
		std::cout << "�����ϴ� ��" << std::endl;
		std::cout << "������ �����մϴ� " << std::endl;
		iGameStart = 0;
	}

	if (iPBingo >= 5)
	{
		std::cout << "Player 5����!!!" << std::endl;
		std::cout << "������ �����մϴ� " << std::endl;
		iGameStart = 0;

	}

	if (iAIBingo >= 5)
	{
		std::cout << "AI 5����!!!" << std::endl;
		std::cout << "������ �����մϴ� " << std::endl;
		iGameStart = 0;

	}


}

void AICheck()
{
	//�ϵ���
	int iChecCount = 0;
	int iSaveCount = 0;
	int iLine = 0;

	//����üũ
	for (int i = 0; i < 5; ++i)
	{
		iChecCount = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (iAI[i * 5 + j] == INT_MAX)
			{
				++iChecCount;
			}
		}//for (int j = 0; j < 5; ++j)

		if (iChecCount < 5 && iSaveCount < iChecCount)
		{
			iLine = i;
			iSaveCount = iChecCount;
		}
	}

	//������üũ
	for (int i = 0; i < 5; ++i)
	{
		iChecCount = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (iAI[j * 5 + i] == INT_MAX)
			{
				++iChecCount;
			}
		}//for (int j = 0; j < 5; ++j)

		if (iChecCount < 5 && iSaveCount < iChecCount)
		{
			iLine = i + 5;
			iSaveCount = iChecCount;
		}
	}

	iChecCount = 0;
	//�޴�

	for (int i = 0; i < 25; i+= 6)
	{
		if (iAI[i] == INT_MAX)
		{
			++iChecCount;
		}
	}

	if (iChecCount < 5 && iSaveCount < iChecCount)
	{
		iLine = (int)LN_NUMBER::LN_LD;
		iSaveCount = iChecCount;
	}

	//����
	iChecCount = 0;

	for (int i = 4; i <= 20; i += 4)
	{
		if (iAI[i] == INT_MAX)
		{
			++iChecCount;
		}
	}

	if (iChecCount < 5 && iSaveCount < iChecCount)
	{
		iLine = (int)LN_NUMBER::LN_RD;
		iSaveCount = iChecCount;
	}


	//������� �°� ���� üũ�� ���� �� ������ �˰� �Ȱ��̴�.
	if (iLine <= (int)LN_NUMBER::LN_W5)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (iAI[iLine * 5 + i] != INT_MAX)
			{
				iInput = iAI[iLine * 5 + i];
			}
		}
	}
	

	else if (iLine <= (int)LN_NUMBER::LN_H5)
	{
		for (int i = 0; i < 5; ++i)
		{
			//5 6 7 8 9 
			if (iAI[i * 5 +(iLine -5)] != INT_MAX)
			{
				iInput = iAI[i * 5 + (iLine - 5)];
			}
		}
	}
	else if (iLine == (int)LN_NUMBER::LN_LD)
	{
		for (int i = 0; i < 25; i += 6)
		{
			if (iAI[i] != INT_MAX)
			{
				iInput = iAI[i];
			}
		}
	}
	else if (iLine == (int)LN_NUMBER::LN_RD)
	{
		for (int i = 4; i <= 20; i += 4)
		{
			if (iAI[i] != INT_MAX)
			{
				iInput = iAI[i];
			}
		}
	}

	//�÷��̾�� AI���� INT_MAX�� �־��ָ� ��
	for (int i = 0; i < 25; ++i)
	{
		if (iAI[i] == iInput)
		{
			iAI[i] = INT_MAX;
		}
		if (iPlayer[i] == iInput)
		{
			iPlayer[i] = INT_MAX;
		}
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

	int iAICheck1 = 0;
	int iAICheck2 = 0;


	iPBingo = 0;
	iAIBingo = 0;

	for (int i = 0; i < 5; ++i)
	{
		iCheck1 = 0;
		iCheck2 = 0;

		iAICheck1 = 0;
		iAICheck2 = 0;

		for (int j = 0; j < 5; ++j)
		{
			//������
			if (iPlayer[i * 5 + j] == INT_MAX)
			{
				++iCheck1;
			}

			if (iAI[i * 5 + j] == INT_MAX)
			{
				++iAICheck1;
			}

			//������
			if (iPlayer[j * 5 + i] == INT_MAX)
			{
				++iCheck2;
			}

			if (iAI[j * 5 + i] == INT_MAX)
			{
				++iAICheck2;
			}
		}

		//���⼭ check�� ���� 5��� ������ ��� ���� �ٲ���̴�
		if (iCheck1 == 5)
		{
			++iPBingo;
		}
		if (iCheck2 == 5)
		{
			++iPBingo;
		}


		if (iAICheck1 == 5)
		{
			++iAIBingo;
		}
		if (iAICheck2 == 5)
		{
			++iAIBingo;
		}
	}

	iCheck1 = 0;

	iAICheck1 = 0;

	//�밢�� 
	for (int i = 0; i < 25; i += 6)
	{
		if (iPlayer[i] == INT_MAX)
		{
			++iCheck1;
		}

		if (iAI[i] == INT_MAX)
		{
			++iAICheck1;
		}

	}

	if (iCheck1 == 5)
	{
		++iPBingo;
	}

	if (iAICheck1 == 5)
	{
		++iAIBingo;
	}



	iCheck1 = 0;

	iAICheck1 = 0;

	for (int i = 0; i < 5; ++i)
	{
		if (iPlayer[i * 4 + 4] == INT_MAX)
		{
			++iCheck1;
		}

		if (iAI[i * 4 + 4] == INT_MAX)
		{
			++iAICheck1;
		}
	}

	if (iCheck1 == 5)
	{
		++iPBingo;
	}

	if (iAICheck1 == 5)
	{
		++iAIBingo;
	}



	

}

void GameRender()
{
	
		std::cout << "<===========Player==========>" << std::endl;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iPlayer[i * 5 + j] == INT_MAX)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
					std::cout << "��\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				}
				else
				{
					std::cout << iPlayer[i * 5 + j] << "\t";
				}
			}

			std::cout << std::endl;
		}//	for (int i = 0; i < 5; ++i)

		std::cout << "Player : " << iPBingo << std::endl;

		//AI

		std::cout << "<=============AI==============>" << std::endl;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iAI[i * 5 + j] == INT_MAX)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
					std::cout << "��\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				}
				else
				{
					std::cout << iAI[i * 5 + j] << "\t";
				}
			}

			std::cout << std::endl;
		}//	for (int i = 0; i < 5; ++i)


		std::cout << "AI : " << iAIBingo << std::endl;

		BingoEnd();

		std::cout << "���ڸ� �Է����ּ���(999 : ����) ";
	
}

bool InputNumber(bool acc)
{
	for (int i = 0; i < 25; ++i)
	{
		//���� �Է��� ���ڰ� �������
		if (iPlayer[i] == iInput)
		{
			iPlayer[i] = INT_MAX;
			acc = false;

		}

		if (iAI[i] == iInput)
		{
			iAI[i] = INT_MAX;

		}
	}

	return acc;
}

void GameUpdate()
{
	while (true)
	{
		iInput = 0;
		std::cin >> iInput;

		if (iInput == 999)
		{
			iGameStart = 0;
			break;
		}

		else if (iInput <= 0 || iInput > 25)
		{
			
			break;
		}

		//�տ��� �Է��� ���ڸ� �ٽ� �Է��ߴ��� üũ���ϱ����� bool������ �̿��Ѵ�.
		//true�� �ʱ�ȭ�� �������� �ߺ��� �Ǿ��ٶ�� ������ �صл��¿���
		//�Ʒ� for������ ���� ã���� ��� �ߺ��� �ȵȰ����� false�� ó���ϸ� �ȴ�
		//�Ʒ� for������ ���� ��ã�Ҵٸ� �̹� �Է��� ���̶�� ���� �̹Ƿ�
		//�ߺ��� ó���ϱ� ���ؼ��̴�.

		bool bAcc = true;

		//�츮�� �Է��� ���ڸ� �ڷ� ������ �ش�.
		bAcc = InputNumber(bAcc);

		

		//��弱�� 

		switch ((AIMODE)iSelectMode)
		{
		case AIMODE::EASY:
			while (true)
			{
				int i = rand() % 25;
				if (iAI[i] == INT_MAX)
				{
					continue;
				}
				else if (iAI[i] != INT_MAX)
				{
					iInput = iAI[i];
					break;
				}
			}
			if (iPBingo >= 5 || iAIBingo >= 5)
			{
				break;
			}
			bAcc = InputNumber(bAcc);
			break;
		case AIMODE::HARD:
		

			AICheck();
		
			break;
		default:
			break;
		}


		//���� �ߺ��� �Ǿ��ִٸ� �ٽ��Է� �ް� �Ѵ�
		if (bAcc)
			break;;




		break;
	}

	BingoCheck();
}



void GameStart()
{

	iGameStart = 1;
	while (iGameStart == 1)
	{
		system("cls");

		
			GameRender();

		if (iGameStart == 1)
		{
			GameUpdate();

			int a = 0;
			//check
			
		}
		


	}
}


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	/*
		�������
		5 x 5 �� ȭ�鿡 ��������� �ϰ� ���� �Է� �Ѵ�


	*/

	//���Ӹ�� ����
	GameModeSlect();

	Init();

	Shuffule();

	GameStart();




	//���� aI���������� 
	//�̰͵� �̴�... AI�Ӹ��� �������� 






	return 0;
}