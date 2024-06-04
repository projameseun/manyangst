#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>

int iNumber[25];
int iBingo = 0;

int iAiNumber[25];
int iBingoAI = 0;

void Init()
{
    for (int i = 0; i < 25; ++i)
    {
        iNumber[i] = i + 1;
        iAiNumber[i] = i + 1;
    }
}

void shuffle(int arr[25])
{
    int iTemp, idx1, idx2 = 0;

    for (int i = 0; i < 1000; ++i)
    {
        idx1 = rand() % 25;
        idx2 = rand() % 25;

        iTemp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = iTemp;
    }
}

int AIchNumber()
{
    int choice;
    do {
        choice = rand() % 25 + 1;
    } while (iAiNumber[choice - 1] == INT_MAX);
    return choice;
}

void BingoCheck(int arr[25], int& bingoCount)
{
    int iCheck1 = 0;
    int iCheck2 = 0;

    bingoCount = 0;

    // 가로, 세로 빙고 체크
    for (int i = 0; i < 5; ++i)
    {
        int iCheck1 = 0;
        int iCheck2 = 0;

        for (int j = 0; j < 5; ++j)
        {
            if (arr[i * 5 + j] == INT_MAX)
                ++iCheck1;

            if (arr[j * 5 + i] == INT_MAX)
                ++iCheck2;
        }

        if (iCheck1 == 5) // 가로 빙고
            ++bingoCount;
        if (iCheck2 == 5) // 세로 빙고
            ++bingoCount;
    }

    // 대각선 빙고 체크
    iCheck1 = 0;
    iCheck2 = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (arr[i * 5 + i] == INT_MAX)
            ++iCheck1;
        if (arr[i * 5 + (4 - i)] == INT_MAX)
            ++iCheck2;
    }
    if (iCheck1 == 5) // 왼쪽 위에서 오른쪽 아래로 내려가는 대각선 빙고
        ++bingoCount;
    if (iCheck2 == 5) // 오른쪽 위에서 왼쪽 아래로 내려가는 대각선 빙고
        ++bingoCount;
}

void PrintBoard(int arr[25])
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (arr[i * 5 + j] == INT_MAX)
            {
                std::cout << "☆\t"; // 별표 칠해주기
            }
            else
            {
                std::cout << arr[i * 5 + j] << "\t"; // 숫자 출력
            }
        }
        std::cout << std::endl; // 5칸씩 띄우게 하기
    }
}

void GameStart()
{
    while (true)
    {
        system("cls");
        std::cout << "사용자 빙고 줄: " << iBingo << std::endl;
        std::cout << "컴퓨터 빙고 줄: " << iBingoAI << std::endl;

        std::cout << "사용자 빙고판:" << std::endl;
        PrintBoard(iNumber);

        std::cout << "컴퓨터 빙고판:" << std::endl;
        PrintBoard(iAiNumber);

        std::cout << "숫자를 입력해주세요: ";
        std::cout << "나가시려면 999를 눌러주세요" << std::endl;

        int iInput = 0;
        std::cin >> iInput;

        if (iBingo >= 5 || iBingoAI >= 5)
        {
            if (iBingo >= 5)
                std::cout << "사용자가 이겼습니다" << std::endl;
            else
                std::cout << "AI가 이겼습니다" << std::endl;
            break;
        }

        if (iInput == 999)
        {
            break;
        }

        if (iInput <= 0 || iInput > 25)
        {
            continue;
        }

        bool bAcc = true;

        for (int i = 0; i < 25; ++i)
        {
            if (iNumber[i] == iInput)
            {
                iNumber[i] = INT_MAX;
                bAcc = false;
                break;
            }
        }

        if (bAcc)
            continue;

        BingoCheck(iNumber, iBingo);

        int aiChoice = AIchNumber();
        std::cout << "AI가 " << aiChoice << "를 선택했습니다." << std::endl;
        for (int i = 0; i < 25; ++i)
        {
            if (iAiNumber[i] == aiChoice)
            {
                iAiNumber[i] = INT_MAX;
                break;
            }
        }

        BingoCheck(iAiNumber, iBingoAI);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    Init();
    shuffle(iNumber);
    shuffle(iAiNumber);

    GameStart();

    return 0;
}

//#include <iostream>
//#include <Windows.h>
//#include <time.h>
//#include <conio.h>
//
////int iNumber[5][5] = {};
//int iNumber[25];
//
//int iBingo = 0;
//
//int iAiNumber[25];
//
//int iBingoAI = 0;
//
////void Init()
////{
////	for (int i = 0; i < 5; ++i)
////	{
////		for (int j = 0; j < 5; ++j)
////		{
////			iNumber[i][j] = i * 5 + j + 1;
////			
////		}
////	}
////}
////
////
////
////
////void shuffle()
////{
////	int iTemp, idx1, idx2, idx3, idx4 = 0;
////
////	for (int i = 0; i < 1000; ++i)
////	{
////		idx1 = rand() % 25;
////		idx2 = rand() % 25;
////		idx3 = rand() % 25;
////		idx4 = rand() % 25;
////
////		iTemp = iNumber[idx1][idx2];
////		iNumber[idx1][idx2] = iNumber[idx3][idx4];
////		iNumber[idx3][idx4] = iTemp;
////	}
////}
//
//
//
//int AIchNumber()
//{
//	int choice;
//	do {
//		choice = rand() % 25 + 1;
//	} while (iAiNumber[choice - 1] == INT_MAX);
//	return choice;
//}
//void Init()
//{
//	for (int i = 0; i < 25; ++i)
//	{
//		iNumber[i] = i + 1;
//	}
//
//}
//
//void shuffle()
//{
//	int iTemp, idx1, idx2 = 0;
//
//	for (int i = 0; i < 1000; ++i)
//	{
//		idx1 = rand() % 25;
//		idx2 = rand() % 25;
//
//		iTemp = iNumber[idx1];
//		iNumber[idx1] = iNumber[idx2];
//		iNumber[idx2] = iTemp;
//	}
//}
//
//
//
//void BingoCheck()
//{
//	int iCheck1 = 0;
//	int iCheck2 = 0;
//
//	iBingo = 0;
//
//	// 가로, 세로 빙고 체크
//	for (int i = 0; i < 5; ++i)
//	{
//		int iCheck1 = 0;
//		int iCheck2 = 0;
//
//		for (int j = 0; j < 5; ++j)
//		{
//			if (iNumber[i * 5 + j] == INT_MAX)
//				++iCheck1;
//
//			if (iNumber[j * 5 + i] == INT_MAX)
//				++iCheck2;
//		}
//
//		if (iCheck1 == 5) // 가로 빙고
//			++iBingo;
//		if (iCheck2 == 5) // 세로 빙고
//			++iBingo;
//	}
//
//	// 대각선 빙고 체크
//
//	for (int i = 0; i < 5; ++i)
//	{
//		if (iNumber[i * 5 + i] == INT_MAX)
//			++iCheck1;
//		if (iNumber[i * 5 + (4 - i)] == INT_MAX)
//			++iCheck2;
//	}
//	if (iCheck1 == 5) // 왼쪽 위에서 오른쪽 아래로 내려가는 대각선 빙고
//		++iBingo;
//	if (iCheck2 == 5) // 오른쪽 위에서 왼쪽 아래로 내려가는 대각선 빙고
//		++iBingo;
//}
//
//void GameStart()
//{
//	while (true)
//	{
//		system("cls");
//		std::cout << "사용자빙고 줄 : " << iBingo << std::endl; //이친구는 맨 윗줄 빙고 줄 나오게 하는것
//		std::cout << "컴퓨터빙고 줄 : " << iBingoAI << std::endl;
//		for (int i = 0; i < 5; ++i)
//		{
//			for (int j = 0; j < 5; ++j)
//			{
//				if (iNumber[i * 5 + j] == INT_MAX)
//				{
//					std::cout << "☆\t"; // 별표 칠해주기
//				}
//				else
//				{
//					std::cout << iNumber[i * 5 + j] << "\t"; //이친구는 빙고 나오게 하는것
//				}
//			}
//			std::cout << std::endl; // 5칸씩 띄우게 하기
//		}
//
//		std::cout << "숫자를 입력해주세요" << std::endl;
//		std::cout << "나가시려면 999를 눌러주세요" << std::endl;
//
//		int iInput = 0;
//		std::cin >> iInput;
//
//
//
//
//		if (iBingo >= 5 || iBingoAI >= 5) // 빙고 이기면 나오게 하기
//		{
//			if (iBingo >= 5)
//				std::cout << "사용자가 이겼습니다" << std::endl;
//			else
//				std::cout << "AI가 이겼습니다" << std::endl;
//			break;
//		}
//
//		if (iInput == 999) // 999면 정지 
//		{
//			break;
//		}
//
//		else if (iInput <= 0 || iInput > 25) // 음수거나 25가 넘으면 컨티뉴 하기
//		{
//			continue;
//		}
//
//
//		bool bAcc = true;
//
//		for (int i = 0; i < 25; ++i)
//		{
//			if (iNumber[i] == iInput)
//			{
//				iNumber[i] = INT_MAX;
//				bAcc = false;
//				break;
//			}
//		}
//		//값이 중복이 있으면 다시입력받게 하기
//		if (bAcc)
//			continue;
//
//		BingoCheck();
//
//		int aiChoice = AIchNumber();
//		std::cout << "AI가 " << aiChoice << "를 선택했습니다." << std::endl;
//		for (int i = 0; i < 25; ++i)
//		{
//			if (iAiNumber[i] == aiChoice)
//			{
//				iAiNumber[i] = INT_MAX;
//				break;
//			}
//		}
//		BingoCheck();
//	}
//}
//
//
//
//int main()
//{
//	srand(static_cast<unsigned int>(time(NULL)));
//
//	Init();
//	shuffle();
//	GameStart();
//
//
//
//	return 0;
//}
