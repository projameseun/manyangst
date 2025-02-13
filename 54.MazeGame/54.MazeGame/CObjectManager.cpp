#include "CObjectManager.h"
#include "CPlayer.h"

CObjectManager* CObjectManager::m_pInst = nullptr;

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
    for (int i = 0; i < m_ObjArray.size(); ++i)
    {
		delete m_ObjArray[i];
    }

    delete m_pPlayer;
    
}

bool CObjectManager::Start()
{
    m_pPlayer = new CPlayer;

    if (!m_pPlayer->Start())
    {
        return false;
    }
    

    return true;
}

void CObjectManager::Update(float _fDeltaTime)
{
	m_pPlayer->Update(_fDeltaTime);

    //������,��ź,���͵� ������Ʈ���� ������Ʈ�� ����
    

}

void CObjectManager::Render(char* _pBuffer)
{
    //������,��ź,���͵� ������Ʈ���� Render ����

    m_pPlayer->Render(_pBuffer);
}

void CObjectManager::ClearObj()
{
}
