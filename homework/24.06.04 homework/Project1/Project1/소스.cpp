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

    // ����, ���� ���� üũ
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

        if (iCheck1 == 5) // ���� ����
            ++bingoCount;
        if (iCheck2 == 5) // ���� ����
            ++bingoCount;
    }

    // �밢�� ���� üũ
    iCheck1 = 0;
    iCheck2 = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (arr[i * 5 + i] == INT_MAX)
            ++iCheck1;
        if (arr[i * 5 + (4 - i)] == INT_MAX)
            ++iCheck2;
    }
    if (iCheck1 == 5) // ���� ������ ������ �Ʒ��� �������� �밢�� ����
        ++bingoCount;
    if (iCheck2 == 5) // ������ ������ ���� �Ʒ��� �������� �밢�� ����
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
                std::cout << "��\t"; // ��ǥ ĥ���ֱ�
            }
            else
            {
                std::cout << arr[i * 5 + j] << "\t"; // ���� ���
            }
        }
        std::cout << std::endl; // 5ĭ�� ���� �ϱ�
    }
}

void GameStart()
{
    while (true)
    {
        system("cls");
        std::cout << "����� ���� ��: " << iBingo << std::endl;
        std::cout << "��ǻ�� ���� ��: " << iBingoAI << std::endl;

        std::cout << "����� ������:" << std::endl;
        PrintBoard(iNumber);

        std::cout << "��ǻ�� ������:" << std::endl;
        PrintBoard(iAiNumber);

        std::cout << "���ڸ� �Է����ּ���: ";
        std::cout << "�����÷��� 999�� �����ּ���" << std::endl;

        int iInput = 0;
        std::cin >> iInput;

        if (iBingo >= 5 || iBingoAI >= 5)
        {
            if (iBingo >= 5)
                std::cout << "����ڰ� �̰���ϴ�" << std::endl;
            else
                std::cout << "AI�� �̰���ϴ�" << std::endl;
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
        std::cout << "AI�� " << aiChoice << "�� �����߽��ϴ�." << std::endl;
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
//	// ����, ���� ���� üũ
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
//		if (iCheck1 == 5) // ���� ����
//			++iBingo;
//		if (iCheck2 == 5) // ���� ����
//			++iBingo;
//	}
//
//	// �밢�� ���� üũ
//
//	for (int i = 0; i < 5; ++i)
//	{
//		if (iNumber[i * 5 + i] == INT_MAX)
//			++iCheck1;
//		if (iNumber[i * 5 + (4 - i)] == INT_MAX)
//			++iCheck2;
//	}
//	if (iCheck1 == 5) // ���� ������ ������ �Ʒ��� �������� �밢�� ����
//		++iBingo;
//	if (iCheck2 == 5) // ������ ������ ���� �Ʒ��� �������� �밢�� ����
//		++iBingo;
//}
//
//void GameStart()
//{
//	while (true)
//	{
//		system("cls");
//		std::cout << "����ں��� �� : " << iBingo << std::endl; //��ģ���� �� ���� ���� �� ������ �ϴ°�
//		std::cout << "��ǻ�ͺ��� �� : " << iBingoAI << std::endl;
//		for (int i = 0; i < 5; ++i)
//		{
//			for (int j = 0; j < 5; ++j)
//			{
//				if (iNumber[i * 5 + j] == INT_MAX)
//				{
//					std::cout << "��\t"; // ��ǥ ĥ���ֱ�
//				}
//				else
//				{
//					std::cout << iNumber[i * 5 + j] << "\t"; //��ģ���� ���� ������ �ϴ°�
//				}
//			}
//			std::cout << std::endl; // 5ĭ�� ���� �ϱ�
//		}
//
//		std::cout << "���ڸ� �Է����ּ���" << std::endl;
//		std::cout << "�����÷��� 999�� �����ּ���" << std::endl;
//
//		int iInput = 0;
//		std::cin >> iInput;
//
//
//
//
//		if (iBingo >= 5 || iBingoAI >= 5) // ���� �̱�� ������ �ϱ�
//		{
//			if (iBingo >= 5)
//				std::cout << "����ڰ� �̰���ϴ�" << std::endl;
//			else
//				std::cout << "AI�� �̰���ϴ�" << std::endl;
//			break;
//		}
//
//		if (iInput == 999) // 999�� ���� 
//		{
//			break;
//		}
//
//		else if (iInput <= 0 || iInput > 25) // �����ų� 25�� ������ ��Ƽ�� �ϱ�
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
//		//���� �ߺ��� ������ �ٽ��Է¹ް� �ϱ�
//		if (bAcc)
//			continue;
//
//		BingoCheck();
//
//		int aiChoice = AIchNumber();
//		std::cout << "AI�� " << aiChoice << "�� �����߽��ϴ�." << std::endl;
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
