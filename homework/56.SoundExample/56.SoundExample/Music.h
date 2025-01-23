#pragma once
#include "Info.h"

//MCI -> Media Control Interface

class Music
{
private:
	MCI_OPEN_PARMS			m_MciOpen;			//파일로드
	MCI_PLAY_PARMS			m_MciPlay;			//파일을 재생
	MCI_STATUS_PARMS		m_MciStatus;		//파일의 상태

	UINT					m_iDeiveID = 0;		//재생 위치값 0이면 처음으로 돌려줌
	DWORD					m_Result = 0;		//결과값

	bool bMusic = false;						//음악프로그램을 실행하는 변수
	bool bFlag = true;							//음악을껏다 켯다 하는 플래그

	vector<LPCWSTR>			m_RecordName;		//음악이름
	vector<LPCWSTR>			m_RecordPath;		//경로

public:
	const vector<LPCWSTR>& GetRecordName() const
	{
		return m_RecordName;
	}

	const vector<LPCWSTR>& GetRecordPath() const
	{
		return m_RecordPath;
	}

public:
	void InitRecordName();
	void InitRecordPath(vector<LPCWSTR> _reName);
	
	void MusicMenuPrint();
	WORD InitMusiceDevic(LPCWSTR& _rePath);

	void MusicUpdate(int _num);


};

