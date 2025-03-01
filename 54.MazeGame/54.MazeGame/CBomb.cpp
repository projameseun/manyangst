#include "CBomb.h"
#include "CMazeManager.h"
#include "CMaze.h"


CBomb::CBomb() : m_iPower(1), m_fBombTime(3.f)	
{
}

CBomb::~CBomb()
{
}

bool CBomb::Start()
{
	return true;
}

void CBomb::Update(float _fDeltaTime)
{

	m_fBombTime -= _fDeltaTime;
	if (m_fBombTime <= 0.f)
	{
		CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();

		pMaze->SetBlock(m_tPos, BLOCK::ROAD);


		//폭탄이 터지는 위,아래,왼쪽,오른쪽에 벽이 있는지 체크
		//0 위 , 1:아래 2:좌 3:우

		bool bomb[4] = {};
		int	iCount = 0;

		for (int i = 0; i < m_iPower; ++i)
		{
			if (iCount == 4)
				break;
			
			COORD tPos = m_tPos;
			
			if (!bomb[(int)DIR::UP])
			{
				tPos.Y -= (i + 1);
				if (tPos.Y >= 0)
				{
					if (pMaze->GetBlock(tPos) == BLOCK::WALL)
					{
						pMaze->SetBlock(tPos, BLOCK::ROAD);
						bomb[(int)DIR::UP] = true;
						++iCount;
					}
				}
			}//if (!bomb[(int)DIR::UP])

			tPos = m_tPos;

			//아래체크 
			if (!bomb[(int)DIR::DOWN])
			{
				tPos.Y += (i + 1);
				if (tPos.Y < pMaze->GetHeigth())
				{
					if (pMaze->GetBlock(tPos) == BLOCK::WALL)
					{
						pMaze->SetBlock(tPos, BLOCK::ROAD);
						bomb[(int)DIR::DOWN] = true;
						++iCount;
					}
				}
			}//if (!bomb[(int)DIR::UP])

			tPos = m_tPos;

			//왼쪽
			if (!bomb[(int)DIR::LEFT])
			{
				tPos.X -= (i + 1);
				if (tPos.X >=0)
				{
					if (pMaze->GetBlock(tPos) == BLOCK::WALL)
					{
						pMaze->SetBlock(tPos, BLOCK::ROAD);
						bomb[(int)DIR::LEFT] = true;
						++iCount;
					}
				}
			}//if (!bomb[(int)DIR::UP])

			tPos = m_tPos;

			//오른쪽
			if (!bomb[(int)DIR::RIGHT])
			{
				tPos.X += (i + 1);
				if (tPos.X <pMaze->GetWidth())
				{
					if (pMaze->GetBlock(tPos) == BLOCK::WALL)
					{
						pMaze->SetBlock(tPos, BLOCK::ROAD);
						bomb[(int)DIR::RIGHT] = true;
						++iCount;
					}
				}
			}//if (!bomb[(int)DIR::UP])



		}//for (int i = 0; i < m_iPower; ++i)
		
			//폭탄이터졌을때
		if (m_BombCallBack)
		{
			m_BombCallBack(this);

		}

		Destroy();
	}


	
}

void CBomb::Render(char* _pBuffer)
{
	CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();

	//제일뒤에 m_tPos.Y를 더해준 이유는 버퍼에는 각 줄마다\n이 존재해서 
	int idx = m_tPos.Y * pMaze->GetWidth() * 2 + m_tPos.X * 2 + m_tPos.Y;

	memcpy(&_pBuffer[idx], "♨", 2);
}
