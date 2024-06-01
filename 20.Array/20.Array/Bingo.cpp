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

		//별로 바뀐줄을 체크한다 
		//가로 5줄 세로 5줄 대각선 2줄 이 존재한다.
		//이중에 5줄이상을 완성하면 게임에서 승리 
		//

		//가로줄을 구한다

	int iCheck1 = 0;
	int iCheck2 = 0;


	iBingo = 0;

	for (int i = 0; i < 5; ++i)
	{
		iCheck1 = 0;
		iCheck2 = 0;

		for (int j = 0; j < 5; ++j)
		{
			//가로줄
			if (iNumber[i * 5 + j] == INT_MAX)
			{
				++iCheck1;
			}
			//세로줄
			if (iNumber[j * 5 + i] == INT_MAX)
			{
				++iCheck2;
			}
		}

		//여기서 check가 값이 5라면 한줄이 모두 별로 바뀐것이다
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

	//대각선 
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

		std::cout << "빙고줄수 : " << iBingo << std::endl;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
					std::cout << "★\t";
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
			std::cout << "5빙고!!!" << std::endl;
			std::cout << "게임을 종료합니다 " << std::endl;
			break;
		}

		std::cout << "숫자를 입력해주세요(999 : 종료) ";

		
		
		int iInput = 0;
		std::cin >> iInput;

		if (iInput == 999)
			break;

		else if (iInput <= 0 || iInput > 25)
		{
			continue;
		}

		//앞에서 입력한 숫자를 다시 입력했는지 체크를하기위해 bool변수를 이용한다.
		//true로 초기화를 한이유는 중복이 되었다라고 가정을 해둔상태에서
		//아래 for문에서 값을 찾았을 경우 중복이 안된것으로 false로 처리하면 된다
		//아래 for문에서 값을 못찾았다면 이미 입력한 값이라는 것이 이므로
		//중복을 처리하기 위해서이다.

		bool bAcc = true;

		//우리가 입력한 숫자를 ★로 변경해 준다.
		for (int i = 0; i < 25; ++i)
		{
			//내가 입력한 숫자가 있을경우
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				bAcc = false;
				break;
			}
		}

		//값이 중복이 되어있다면 다시입력 받게 한다
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
		빙고게임
		5 x 5 로 화면에 빙고판출력 하고 숫자 입력 한다
		
		
	*/
	
	Init();
	
	Shuffule();

	GameStart();
	
	

	
	//숙제 aI만들어오세요 
	//이것도 됫다... AI머리가 좋아지게 

	


	

	return 0;
}