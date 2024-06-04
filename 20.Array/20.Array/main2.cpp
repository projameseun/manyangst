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

		std::cout << "게임 모드를 선택해주세요 " << std::endl;
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

//게임이끝낫을때
void BingoEnd()
{
	
	if (iPBingo >= 5 && iAIBingo >= 5)
	{
		std::cout << "비겼습니다 굳" << std::endl;
		std::cout << "게임을 종료합니다 " << std::endl;
		iGameStart = 0;
	}

	if (iPBingo >= 5)
	{
		std::cout << "Player 5빙고!!!" << std::endl;
		std::cout << "게임을 종료합니다 " << std::endl;
		iGameStart = 0;

	}

	if (iAIBingo >= 5)
	{
		std::cout << "AI 5빙고!!!" << std::endl;
		std::cout << "게임을 종료합니다 " << std::endl;
		iGameStart = 0;

	}


}

void BingoCheck()
{
	//CHECK

		//별로 바뀐줄을 체크한다 
		//가로 5줄 세로 5줄 대각선 2줄 이 존재한다.
		//이중에 5줄이상을 완성하면 게임에서 승리 
		//

		//가로줄을 구한다

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
			//가로줄
			if (iPlayer[i * 5 + j] == INT_MAX)
			{
				++iCheck1;
			}

			if (iAI[i * 5 + j] == INT_MAX)
			{
				++iAICheck1;
			}

			//세로줄
			if (iPlayer[j * 5 + i] == INT_MAX)
			{
				++iCheck2;
			}

			if (iAI[j * 5 + i] == INT_MAX)
			{
				++iAICheck2;
			}
		}

		//여기서 check가 값이 5라면 한줄이 모두 별로 바뀐것이다
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

	//대각선 
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
					std::cout << "★\t";
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
					std::cout << "♥\t";
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

		std::cout << "숫자를 입력해주세요(999 : 종료) ";
	
}

bool InputNumber(bool acc)
{
	for (int i = 0; i < 25; ++i)
	{
		//내가 입력한 숫자가 있을경우
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

		//앞에서 입력한 숫자를 다시 입력했는지 체크를하기위해 bool변수를 이용한다.
		//true로 초기화를 한이유는 중복이 되었다라고 가정을 해둔상태에서
		//아래 for문에서 값을 찾았을 경우 중복이 안된것으로 false로 처리하면 된다
		//아래 for문에서 값을 못찾았다면 이미 입력한 값이라는 것이 이므로
		//중복을 처리하기 위해서이다.

		bool bAcc = true;

		//우리가 입력한 숫자를 ★로 변경해 준다.
		bAcc = InputNumber(bAcc);

		

		//모드선택 

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

			break;
		default:
			break;
		}


		//값이 중복이 되어있다면 다시입력 받게 한다
		if (bAcc)
			break;;




		break;
	}
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
			BingoCheck();
		}
		


	}
}


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	/*
		빙고게임
		5 x 5 로 화면에 빙고판출력 하고 숫자 입력 한다


	*/

	//게임모드 선택
	GameModeSlect();

	Init();

	Shuffule();

	GameStart();




	//숙제 aI만들어오세요 
	//이것도 됫다... AI머리가 좋아지게 






	return 0;
}