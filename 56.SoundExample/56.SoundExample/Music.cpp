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

void Music::MusicUpdate(int _num)
{

	//1.재생 
	//2.멈춤
	//3.다시재생
}
