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

	//가위바위보
	
	

	while (true)
	{
		system("cls");
		int iPlayer = 0;
		int iResult = 0;
		std::cout << "<<========가위바위보게임 ========>>" << std::endl;
		std::cout << "1.가위 2.바위 3. 보 4.나가기" << std::endl;

		std::cin >> iPlayer;

		int iCom = rand() % 3 + 1;
		
		//예외처리
		if (iPlayer == (int)SRP::EXIT)
		{
			break;
		}

		if (iPlayer < 1 || iPlayer >3)
		{
			continue;
		}

		//게임시작

		iResult = iPlayer - iCom;
		

		std::cout << iPlayer << std::endl;
		std::cout << iCom << std::endl;

		if (iResult == 1 || iResult == -2)
		{
			std::cout << "Player 승리 " << std::endl;
		}
		else if (iPlayer == iCom)
		{
			std::cout << "비김" << std::endl;
		}
		else
		{
			std::cout << "Com 승리 " << std::endl;
		}



		
		system("pause");
	}


	//자판기게임
	//1게임처럼 하기위해서 while를 사용한다
	//2.골드가 존재한다 
	//3.골드가 0이되면 게임 자동종료
	// 4.중복구매(욕심나면) 커피2 콜라3 
	//메뉴 음료수메뉴랑 나가기 를 만들어주세요 
	//


	return 0;
}