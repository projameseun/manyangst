#include "Music.h"

void Music::InitRecordName()
{
	//음악 레코드 추가
	m_RecordName.push_back(L"TroyeSIvan");
	m_RecordName.push_back(L"Maroon5");
	m_RecordName.push_back(L"YouDaEn");
	m_RecordName.push_back(L"AnnerMarie");
	m_RecordName.push_back(L"JangBeomJun");
	m_RecordName.push_back(L"GyungSeo");
	m_RecordName.push_back(L"AllTimeLow");
	m_RecordName.push_back(L"OnePiece");
	m_RecordName.push_back(L"PostMalone");
	m_RecordName.push_back(L"SungSiKyung");


}

void Music::InitRecordPath(vector<LPCWSTR> _reName)
{
	for (int i = 0; i < _reName.size(); ++i)
	{

		switch (MusingNumber(i+1))
		{
		case MusingNumber::TroyeSIvan:
			m_RecordPath.push_back(L".\\Music\\seventeen.mp3");
			break;
		case MusingNumber::Maroon5:
			m_RecordPath.push_back(L".\\Music\\Memories.mp3");
			break;
		case MusingNumber::YouDaEn:
			m_RecordPath.push_back(L".\\Music\\Jisang.mp3");
			break;
		case MusingNumber::AnnerMarie:
			m_RecordPath.push_back(L".\\Music\\2002.mp3");
			break;
		case MusingNumber::JangBeomJun:
			m_RecordPath.push_back(L".\\Music\\jangbumzun.mp3");
			break;
		case MusingNumber::GyungSeo:
			m_RecordPath.push_back(L".\\Music\\gyungseo.mp3");
			break;
		case MusingNumber::AllTimeLow:
			m_RecordPath.push_back(L".\\Music\\timebomb.mp3");
			break;
		case MusingNumber::OnePiece:
			m_RecordPath.push_back(L".\\Music\\onepiece.mp3");
			break;
		case MusingNumber::PostMalone:
			m_RecordPath.push_back(L".\\Music\\postmalone.mp3");
			break;
		case MusingNumber::SungSiKyung:
			m_RecordPath.push_back(L".\\Music\\sungsikyung.mp3");
			break;
		default:
			break;
		}
	}

	int a = 0;

}

void Music::MusicMenuPrint()
{
	system("cls");
	std::cout << "안녕하세요 음악프로그램  목록 입니다" << std::endl;
	std::cout << "원하는 노래를의 번호를 선택해주세요 " << std::endl;
	
	for (int i = 0; i < m_RecordName.size(); ++i)
	{
		if (i == 10)
		{
			std::wcout << i + 1 << " . " << m_RecordName[i] << std::endl;
			continue;
		}
		std::wcout << i + 1 << "  . " << m_RecordName[i] << std::endl;
	}
	
	
}

WORD Music::InitMusiceDevic(LPCWSTR& _rePath)
{
	//초기화
	ZeroMemory(&m_MciOpen, sizeof(m_MciOpen));

	m_MciOpen.lpstrDeviceType = L"MPEGVideo"; //WaveVideo

	m_MciOpen.lpstrElementName = _rePath;

	//정상이면 0 아니면 나머지값
	m_Result = mciSendCommand(m_MciOpen.wDeviceID, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)(LPVOID)&m_MciOpen);

	m_iDeiveID = m_MciOpen.wDeviceID;

	if (m_Result == 0)
	{
		return m_Result;
	}
	else
	{
		std::cerr << "Error === > " << m_Result;
	}
	


	return 0;
}

void Music::UpdateMusic(int _ReNum)
{

	int iReNumber = 0;
	iReNumber = _ReNum;

	m_Result = mciSendCommand(iReNumber, MCI_PLAY,MCI_DGV_PLAY_REPEAT, (DWORD_PTR)(LPVOID)&m_MciOpen);

	if (m_Result == 0)
	{
		bMusic = true;
	}
	
	while (bMusic)
	{
		system("cls");
		MusicMenuPrint();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);		//Yellow
		std::wcout << m_RecordName[iReNumber - 1] << "실행 중입니다" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );


		std::cout << "다른 노래를 재생할려면 번호를 입력해주세요" << std::endl;
		std::cout << "프로그램을 종료 할려면 99를 입력해주세요 " << std::endl;
		std::cout << "일시정지하고 다시 키실려면 11을 눌러주세요 " << std::endl;

		int iSelect = 0;

		std::cin >> iSelect;


		
		 if (iSelect == 99)
		{
			DestroyMusic();
			bMusic = false;
		}

		else if (iSelect == 11)
		{
			bFlag = !bFlag;
			if (bFlag == false)
			{
				PauseMusic(iReNumber);
			}
			else
			{
				PlayMusic(iReNumber);
			}

			continue;
		}

		else if (iSelect < 1 || iSelect > 10)
		{
			std::cout << "선택을 잘못 하였습니다 다시 선택해주세요" << std::endl;
			Sleep(500);
			continue;
		}

		ResetMusic(_ReNum);
		UpdateMusic(iSelect);
		
		

	}//	while (bMusic)

	//1.재생 
	//2.멈춤
	//3.다시재생
}

void Music::DestroyMusic()
{
	if (m_iDeiveID > 0)
	{
		for (int i = 0; i < 20; ++i)
		{
			mciSendCommand(i, MCI_CLOSE, 0, (DWORD_PTR)(LPVOID)NULL);
		}
	}
}

void Music::PauseMusic(int _ReNum)
{
	mciSendCommand(_ReNum, MCI_PAUSE, MCI_SEEK_TO_START, (DWORD_PTR)(LPVOID)NULL);
}

void Music::PlayMusic(int _ReNum)
{
	mciSendCommand(_ReNum, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)(LPVOID)&m_MciOpen);
}

void Music::ResetMusic(int _ReNum)
{
	mciSendCommand(_ReNum, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)(LPVOID)NULL);
	
}
