#pragma once
#include "Info.h"

//MCI -> Media Control Interface

class Music
{
private:
	MCI_OPEN_PARMS			m_MciOpen;			//���Ϸε�
	MCI_PLAY_PARMS			m_MciPlay;			//������ ���
	MCI_STATUS_PARMS		m_MciStatus;		//������ ����

	UINT					m_iDeiveID = 0;		//��� ��ġ�� 0�̸� ó������ ������
	DWORD					m_Result = 0;		//�����

	bool bMusic = false;						//�������α׷��� �����ϴ� ����
	bool bFlag = true;							//���������� �ִ� �ϴ� �÷���

	vector<LPCWSTR>			m_RecordName;		//�����̸�
	vector<LPCWSTR>			m_RecordPath;		//���

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

