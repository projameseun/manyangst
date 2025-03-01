#include "CPlayer.h"
#include "CMaze.h"
#include "CMazeManager.h"
#include "CObjectManager.h"
#include "CBomb.h"

CPlayer::CPlayer() :
	m_fSpeed(10.f)
	, m_fX(0.f)
	, m_fY(0.f)
{
}

CPlayer::~CPlayer()
{
	//f
}

bool CPlayer::Start()
{
	return true;
}

void CPlayer::Update(float _fDeltaTime)
{  
	//맵의 정보를 가져오기
	CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_fY -= m_fSpeed * _fDeltaTime;

		if (m_fY <= -1.f)
		{
			m_fY += 1.f;
			
			--m_tPos.Y;
			if (m_tPos.Y < 0)
			{
				m_tPos.Y = 0;
			}

			else
			{
				BLOCK eBlock = pMaze->GetBlock(m_tPos);
				
				//이동할 위치가 벽이라면 이전으로 돌린다.
				if (eBlock == BLOCK::WALL)
				{
					++m_tPos.Y;
				}
			}
			
			
		}

	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_fY += m_fSpeed * _fDeltaTime;

		if (m_fY >= 1.f)
		{
			m_fY -= 1.f;

			++m_tPos.Y;
			if (m_tPos.Y >= pMaze->GetHeigth())
			{
				m_tPos.Y = pMaze->GetHeigth() - 1;
			}

			else
			{
				BLOCK eBlock = pMaze->GetBlock(m_tPos);

				//이동할 위치가 벽이라면 이전으로 돌린다.
				if (eBlock == BLOCK::WALL)
				{
					--m_tPos.Y;
				}
			}


		}

	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_fX -= m_fSpeed * _fDeltaTime;

		if (m_fX <= -1.f)
		{
			m_fX += 1.f;

			--m_tPos.X;
			if (m_tPos.X < 0)
			{
				m_tPos.X = 0;
			}

			else
			{
				BLOCK eBlock = pMaze->GetBlock(m_tPos);

				//이동할 위치가 벽이라면 이전으로 돌린다.
				if (eBlock == BLOCK::WALL)
				{
					++m_tPos.X;
				}
			}


		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_fX += m_fSpeed * _fDeltaTime;

		if (m_fX >= 1.f)
		{
			m_fX -= 1.f;

			++m_tPos.X;
			if (m_tPos.X >= pMaze->GetWidth())
			{
				m_tPos.X = pMaze->GetWidth() - 1;
			}

			else
			{
				BLOCK eBlock = pMaze->GetBlock(m_tPos);

				//이동할 위치가 벽이라면 이전으로 돌린다.
				if (eBlock == BLOCK::WALL)
				{
					--m_tPos.X;
				}
			}


		}
	}


	if (pMaze->GetBlock(m_tPos) == BLOCK::EXIT)
	{
		CMazeManager::GetInst()->Exit();
	}
	
	//폭탄추가 

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		
		//CBomb* pBomb = CObjectManager::GetInst()->CreateObject<CBomb>(m_tPos);
		CBomb* pBomb = CObjectManager::GetInst()->CreateObjcet<CBomb>(m_tPos);
		
		//pBomb->SetBombCallBack(this, &CPlayer::BombCallBack);
	}

}

void CPlayer::Render(char* _pBuffer)
{
	CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();

	//제일뒤에 m_tPos.Y를 더해준 이유는 버퍼에는 각 줄마다\n이 존재해서 
	int idx = m_tPos.Y * pMaze->GetWidth() * 2 + m_tPos.X * 2 + m_tPos.Y;

	memcpy(&_pBuffer[idx], "읏", 2);
	
}

void CPlayer::BombCallBack(CBomb* _pBomb)
{
	//폭탄이터졋다 

}
