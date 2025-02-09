#include "CGameManager.h"
#include "CMazeManager.h"

CGameManager* CGameManager::m_pInst = nullptr;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	//여러가지 게임요소들을 삭제해주는 곳
	CMazeManager::DestroyInst();
}

// 게임의 요소들을 초기화 하는곳
bool CGameManager::Start()
{
	memset(m_RenderBuffer, 0, RENDER_BUFFER_HEIGHT * RENDER_BUFFER_WIDTH);

	
	//미로 초기화 
	if (!CMazeManager::GetInst()->Start())
	{
		return false;
	}

	//플레이어초기화

	//아이템 초기화


	return true;
}

//게임에 요소들을 업데이트 하는곳
void CGameManager::Update()
{
	while (true)
	{
		size_t iMenu = CMazeManager::GetInst()->MazeMainMenu();

		if (iMenu == CMazeManager::GetInst()->GetMazeCount() + 1)
		{
			return;
		}
		else if (iMenu == 0)
		{
			continue;
		}

		//맵을 업데이트하는곳
		CMazeManager::GetInst()->Update(iMenu - 1, m_RenderBuffer);
	}
}

