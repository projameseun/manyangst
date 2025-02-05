#include "CGameManager.h"
#include "CMazeManager.h"
#include "CPlayer.h"

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
    // 플레이어 입력 처리
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        m_player.MoveUp();  // CPlayer 객체의 MoveUp 호출
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        m_player.MoveDown();  // CPlayer 객체의 MoveDown 호출
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        m_player.MoveLeft();  // CPlayer 객체의 MoveLeft 호출
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        m_player.MoveRight();  // CPlayer 객체의 MoveRight 호출
    }

    // 미로 상태 업데이트
    CMazeManager::GetInst()->Update(0, m_RenderBuffer); 
}

