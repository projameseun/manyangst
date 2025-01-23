#include "Info.h"
#include "Music.h"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Music mic;

	mic.InitRecordName();
	
	mic.InitRecordPath(mic.GetRecordName());
	//레코드의 경로추가 

	vector<LPCWSTR> rePath;

	//노래시작
	while (true)
	{
		system("cls");

		std::cout << "1. 일반 재생" << std::endl;
		std::cout << "2. 랜덤 재생" << std::endl;
		std::cout << "3. 나가기" << std::endl;

		int iSelect = 0;

		std::cin >> iSelect;

		if (iSelect < 0 || iSelect >3)
		{
			std::cout << "선택을 잘못 하였습니다 다시 선택해주세요" << std::endl;
			Sleep(500);
			continue;
		}

		if (iSelect == (int)MenuSelect::DefaultPlay)
		{
			//1.뮤직재생목록
			mic.MusicMenuPrint();

			//2.레코드패스를 이용해서 뮤직을 Device
			for (int i = 0; i < mic.GetRecordName().size(); ++i)
			{
				rePath = mic.GetRecordPath();
				mic.InitMusiceDevic(rePath[i]);
			}
			
			

		}
		else if (iSelect == (int)MenuSelect::RandomPlay)
		{
			
		}
		else if (iSelect == (int)MenuSelect::EXIT)
		{
			std::cout << "이용해 주셔서 감사합니다" << std::endl;
			Sleep(700);
			break;
		}

		//노래 재생 목록번호
		iSelect = 0;

		std::cin >> iSelect;

		if (iSelect < 1 || iSelect > 10)
		{
			std::cout << "선택을 잘못 하였습니다 다시 선택해주세요" << std::endl;
			Sleep(500);
			continue;
		}

		//노래시작 
		mic.MusicUpdate(iSelect);
	}

	return 0;
}

