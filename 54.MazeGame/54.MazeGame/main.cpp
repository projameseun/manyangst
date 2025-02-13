#include "GameInfo.h"
#include "CGameManager.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(static_cast<unsigned int>(time(0)));

	
	if (!CGameManager::GetInst()->Start())
	{
		CGameManager::DestroyInst();
		return 0;
	}

	//���ӽ��డ��
	CGameManager::GetInst()->Update();
	

	CGameManager::DestroyInst();

	//���� ��ź�����
	//1.��ź���� 
	//2.��ź��ġ 
	//3.��ź�� �ð��������� ���ĵǸ� ���� �νñ� 

	return 0;
}