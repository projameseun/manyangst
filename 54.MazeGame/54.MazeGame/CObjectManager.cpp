#include "CObjectManager.h"
#include "CPlayer.h"

CObjectManager* CObjectManager::m_pInst = nullptr;

CObjectManager::CObjectManager() : m_pPlayer(nullptr)
{
}

CObjectManager::~CObjectManager()
{
    for (int i = 0; i < m_ObjArray.size(); ++i)
    {
		delete m_ObjArray[i];
		m_ObjArray[i] = nullptr;
    }

    delete m_pPlayer;
    m_pPlayer = nullptr;
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
    
	vector<CObject*>::iterator iter = m_ObjArray.begin();
    vector<CObject*>::iterator iterend = m_ObjArray.end();

	for (; iter != iterend;)
	{
        if (!(*iter)->GetActive())
        {
            delete(*iter);
			iter = m_ObjArray.erase(iter);
			iterend = m_ObjArray.end();
            continue;
        }

        (*iter)->Update(_fDeltaTime);
        ++iter;
		
	}
    

}

void CObjectManager::Render(char* _pBuffer)
{
    //������,��ź,���͵� ������Ʈ���� Render ����


	for (int i = 0; i < m_ObjArray.size(); ++i)
	{
		m_ObjArray[i]->Render(_pBuffer);
	}

    m_pPlayer->Render(_pBuffer);
}

void CObjectManager::ClearObj()
{
	for (int i = 0; i < m_ObjArray.size(); ++i)
	{
		delete m_ObjArray[i];
	}

	m_ObjArray.clear();
}
