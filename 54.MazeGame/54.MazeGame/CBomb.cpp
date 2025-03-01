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


		//��ź�� ������ ��,�Ʒ�,����,�����ʿ� ���� �ִ��� üũ
		//0 �� , 1:�Ʒ� 2:�� 3:��

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

			//�Ʒ�üũ 
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

			//����
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

			//������
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
		
			//��ź����������
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

	//���ϵڿ� m_tPos.Y�� ������ ������ ���ۿ��� �� �ٸ���\n�� �����ؼ� 
	int idx = m_tPos.Y * pMaze->GetWidth() * 2 + m_tPos.X * 2 + m_tPos.Y;

	memcpy(&_pBuffer[idx], "��", 2);
}
