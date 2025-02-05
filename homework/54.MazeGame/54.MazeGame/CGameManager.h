#pragma once
#include "GameInfo.h"
#include "CPlayer.h"

class CGameManager
{
private:
	static CGameManager* m_pInst;

	char m_RenderBuffer[RENDER_BUFFER_HEIGHT * RENDER_BUFFER_WIDTH];
	CPlayer m_player;
public:
	static CGameManager* GetInst()
	{
		//�̱����̶� ?
		//������������ ������ ������ �ϳ��̰�
		//�ϳ��� ��ü(�ν��Ͻ�)�� ���� �����ϴ� ����̴�.
		if (!m_pInst)
		{
			m_pInst = new CGameManager;
			
		}
		return m_pInst;
	}

	static void DestroyInst()
	{
		if (m_pInst)
		{
			delete m_pInst;
			m_pInst = nullptr;
		}

	}

private:
	CGameManager();
	~CGameManager();

	
public:
	bool Start();
	void Update();
	


};

