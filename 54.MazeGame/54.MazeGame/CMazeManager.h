#pragma once
#include "GameInfo.h"

class CMazeManager
{
private:
	static CMazeManager* m_pInst;

public:
	static CMazeManager* GetInst()
	{
		//싱글톤이란 ?
		//디자인패턴의 여라가지 종류중 하나이고
		//하나의 객체(인스턴스)를 만들어서 관리하는 기법이다.
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

