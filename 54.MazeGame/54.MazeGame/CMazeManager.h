#pragma once
#include "GameInfo.h"

class CMazeManager
{
private:
	static CMazeManager* m_pInst;

public:
	static CMazeManager* GetInst()
	{
		//�̱����̶� ?
		//������������ ������ ������ �ϳ��̰�
		//�ϳ��� ��ü(�ν��Ͻ�)�� ���� �����ϴ� ����̴�.
		if (!m_pInst)
		{
			m_pInst = new CMazeManager;

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
	CMazeManager();
	~CMazeManager();

private:
	vector<class CMaze*>	m_MazeArray;
	class CMaze*			m_pCurrentMaze;

public:
	bool Start();
	void Update(int _idx, char* pBuffer);
	
	
};

