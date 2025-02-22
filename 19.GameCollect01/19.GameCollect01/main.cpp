#include <iostream>
#include <time.h>

/*
	1~9사이의 랜던함 숫자 3개를 중복 없이 얻어온다.
	만약에 랜던함게 얻어온 숫자가 8,3,9 일 경우

	그후에 무한으로 반복한다.
	사용자는 3개의 숫자를 입력합니다.
	1 , 2, 4를 입력했다면 중복되는 숫자가 아예없으므로 out을 출력한다
	8 , 4, 5를 입력했다면 8은 숫자도 같은게 있는데 자리ㅏ까지 같으므로 strike로 처리한다
	나머지는 없으므로 1strike 0ball을 출력한다
	이런식으로 숫자가 같은데 자리까지 같다면 strike추가 자리가 다르면 ball로 추가해서
	표시해준다 .
	모든 숫자를 자리까지 맞췃다면 게임이 종료 된다.
*/

int main()
{

	srand(static_cast<unsigned int>(time(NULL)));


	int iNumber[9] = {};

	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}

	int iTemp, idx1, idx2 = 0;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
		
	}

	while (true)
	{
	
		std::cout << "*\t*\t*" << std::endl;
		std::cout << "숫자 3개를 입력 하세요 (0:종료) :";

		int iInput[3] = {};

		std::cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
		{
			break;
		}

		int iStrike = 0, iBall = 0;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
					{
						++iStrike;
					}
					else
					{
						++iBall;
					}
					break;
				}
			}
		}

		if (iStrike == 3)
		{
			std::cout << "숫자를 모두 맞췄습니다 " << std::endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
		{
			std::cout << "Out !! " << std::endl;
		}

		else
		{
			std::cout << "Strike : " << iStrike << "Ball : " << iBall << std::endl;
		}
	}
	


	return 0;
}