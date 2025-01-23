#include "Music.h"

void Music::InitRecordName()
{
	//���� ���ڵ� �߰�
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
	std::cout << "�ȳ��ϼ��� �������α׷�  ��� �Դϴ�" << std::endl;
	std::cout << "���ϴ� �뷡���� ��ȣ�� �������ּ��� " << std::endl;
	
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
	//�ʱ�ȭ
	ZeroMemory(&m_MciOpen, sizeof(m_MciOpen));

	m_MciOpen.lpstrDeviceType = L"MPEGVideo"; //WaveVideo

	m_MciOpen.lpstrElementName = _rePath;

	//�����̸� 0 �ƴϸ� ��������
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
	
	// ���� ���� ��θ� ������ (�迭���� �ش� ��ȣ�� ��� ����)
	LPCWSTR selectedMusicPath = m_RecordPath[_num - 1];

	// ���õ� ���� ��ġ �ʱ�ȭ
	//InitMusiceDevic(selectedMusicPath);

	int iSelect = 0;

	std::cin >> iSelect;

	switch (iSelect)
	{
	case 1: // ���
		// ���� ���
		m_Result = mciSendCommand(m_MciOpen.wDeviceID, MCI_PLAY, 0, (DWORD_PTR)(LPVOID)&m_MciPlay);
		if (m_Result != 0)
		{
			std::cerr << "Error during playback: " << m_Result << std::endl;
		}
		break;

	case 2: // ����
		// ���� ����
		m_Result = mciSendCommand(m_MciOpen.wDeviceID, MCI_STOP, 0, (DWORD_PTR)(LPVOID)&m_MciPlay);
		if (m_Result != 0)
		{
			std::cerr << "Error during stop: " << m_Result << std::endl;
		}
		break;

	case 3: // �ٽ� ���
		// �̹� ���� ���¶�� �� ��ġ���� �ٽ� ���
		m_Result = mciSendCommand(m_MciOpen.wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)(LPVOID)&m_MciPlay);
		if (m_Result != 0)
		{
			std::cerr << "Error during seeking: " << m_Result << std::endl;
		}

		// �ٽ� ���� ���
		m_Result = mciSendCommand(m_MciOpen.wDeviceID, MCI_PLAY, 0, (DWORD_PTR)(LPVOID)&m_MciPlay);
		if (m_Result != 0)
		{
			std::cerr << "Error during playback restart: " << m_Result << std::endl;
		}
		break;

	default:
		std::cerr << "Invalid music control command" << std::endl;
		break;
	}

}
