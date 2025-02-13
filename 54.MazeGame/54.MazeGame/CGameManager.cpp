#include "CGameManager.h"
#include "CMazeManager.h"
#include "CObjectManager.h"

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

	
	//������Ʈ �ʱ�ȭ��
	if (!CObjectManager::GetInst()->Start())
	{
		return false;
	}

	//�̷� �ʱ�ȭ 
	if (!CMazeManager::GetInst()->Start())
	{
		return false;
	}


	return true;
}

//���ӿ� ��ҵ��� ������Ʈ �ϴ°�
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

		//���� ������Ʈ�ϴ°�
		CMazeManager::GetInst()->Update(iMenu - 1, m_RenderBuffer);
	}
}

