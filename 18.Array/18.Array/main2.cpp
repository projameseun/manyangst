#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

int ixpos = 0;
int iypos = 0;

void gotoxy(int _x, int _y)
{
	COORD pos = { _x,_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ResetPos()
{
	ixpos = 50;
	iypos = 2;
}

enum class SelectNumber
{
	HolZZac = 1,
	GaWiBaWiBo = 2,
	BaseBall ,
	Taxi ,
	Bingo,
	EXIT,
};

void HolZZacRender()
{
	

	int iSelect = 0;
	while (true)
	{
		system("cls");
		ResetPos();
		gotoxy(ixpos, iypos);
		std::cout << "1.게임시작하기";
		iypos++;
		gotoxy(ixpos, iypos);
		std::cout << "2.나가기 ";
		iypos++;
		gotoxy(ixpos, iypos);

		std::cin >> iSelect;

		if (iSelect == 1)
		{
			system("cls");
			
			int iPlayer = 0;
			

			std::cout << "1:홀 2:짝을 입력해주세요";

			std::cin >> iPlayer;
			int iCom = rand() % 2 + 1;

			if (iPlayer != 1 && iPlayer != 2)
			{
				std::cout << "잘못눌르셨습니다" << std::endl;
				system("pause");
				continue;
			}
			

			if (iPlayer == iCom)
			{
				std::cout << "Player : " << iPlayer << std::endl;
				std::cout << "Com : " << iCom<< std::endl;
				std::cout << "이겼습니다 " << std::endl;
				system("pause");
			}
			else
			{
				std::cout << "Player : " << iPlayer << std::endl;
				std::cout << "Com : " << iCom << std::endl;
				std::cout << "틀렸습니다 " << std::endl;
				system("pause");;
			}
			


		}
		else if (iSelect == 2)
		{
			break;
		}

		else
		{
			continue;
		}
	}
}




int main()
{

	srand(static_cast<unsigned int>(time(NULL)));

	int GameStart = 1;
	
	while (GameStart == 1)
	{
		
		int iSelect = 0;

		

		//1.홀짝게임
		ResetPos();
		gotoxy(ixpos, iypos);
		std::cout << "<<==========종합게임===========>>";
		iypos++;
		gotoxy(ixpos, iypos);
		std::cout << "1.홀짝게임 ";
		iypos++;
		gotoxy(ixpos, iypos);
		std::cout << "2.가위바위보게임";
		iypos++;
		gotoxy(ixpos, iypos);
		std::cout << "3.야구게임 ";
		iypos++;
		gotoxy(ixpos, iypos);
		std::cout << "4.택시게임";
		iypos++;
		gotoxy(ixpos, iypos);
		std::cout << "5.빙고게임";
		iypos++;
		gotoxy(ixpos, iypos);
		std::cout << "6.나가기";
		iypos++;
		gotoxy(ixpos, iypos);
		
		
		std::cin >> iSelect;


		switch ((SelectNumber)iSelect)
		{
		case SelectNumber::HolZZac:
			HolZZacRender();
			break;
		case SelectNumber::GaWiBaWiBo:
			break;
		case SelectNumber::BaseBall:
			break;
		case SelectNumber::Taxi:
			break;
		case SelectNumber::Bingo:
			break;
		case SelectNumber::EXIT:
			GameStart = 0;
			break;
		default:
			break;
		}

		
		
	

	}

	system("cls");

	std::cout << "수고 하셨습니다 종료할려면 ENTER를 눌러주세요" << std::endl;
	system("pause");
	


	
	return 0;
}
