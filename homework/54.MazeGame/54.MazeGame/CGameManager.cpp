#include "CGameManager.h"
#include "CMazeManager.h"
#include "CPlayer.h"

CGameManager* CGameManager::m_pInst = nullptr;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	//�������� ���ӿ�ҵ��� �������ִ� ��
	CMazeManager::DestroyInst();
}

// ������ ��ҵ��� �ʱ�ȭ �ϴ°�
bool CGameManager::Start()
{
	memset(m_RenderBuffer, 0, RENDER_BUFFER_HEIGHT * RENDER_BUFFER_WIDTH);

	
	//�̷� �ʱ�ȭ 
	if (!CMazeManager::GetInst()->Start())
	{
		return false;
	}

	//�÷��̾��ʱ�ȭ

	//������ �ʱ�ȭ


	return true;
}


//���ӿ� ��ҵ��� ������Ʈ �ϴ°�
void CGameManager::Update()
{
    // �÷��̾� �Է� ó��
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        m_player.MoveUp();  // CPlayer ��ü�� MoveUp ȣ��
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        m_player.MoveDown();  // CPlayer ��ü�� MoveDown ȣ��
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        m_player.MoveLeft();  // CPlayer ��ü�� MoveLeft ȣ��
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        m_player.MoveRight();  // CPlayer ��ü�� MoveRight ȣ��
    }

    // �̷� ���� ������Ʈ
    CMazeManager::GetInst()->Update(0, m_RenderBuffer); 
}

