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

	//게임실행가능
	CGameManager::GetInst()->Update();
	

	CGameManager::DestroyInst();

	//숙제 폭탄만들기
	//1.폭탄세기 
	//2.폭탄설치 
	//3.폭탄이 시간이지나서 폭파되면 벽을 부시기 

	return 0;
}