#include "CMazeManager.h"
#include "CMaze.h"
CMazeManager* CMazeManager::m_pInst = nullptr;

CMazeManager::CMazeManager()
{
}

CMazeManager::~CMazeManager()
{
}

bool CMazeManager::Start()
{
	FILE* pFile = nullptr;

	//r : �б� w :����, a : �̾��
	//t : �ؽ�Ʈ���� , b:���̳ʸ�����
	fopen_s(&pFile, "Maze1.txt", "rt");

	if (!pFile)
	{
		return false;
	}

	char cLine[256] = {};

	fgets(cLine, 256, pFile);

	int iCount = atoi(cLine);
	
	for (int i = 0; i < iCount; ++i)
	{

		//memset(cLine, 0, 256);
		fgets(cLine, 256, pFile);


		//���ڿ� ����
		int iLength = static_cast<int>(strlen(cLine));
		
		//\n���� �о���Ƿ� �������� ����
		if (cLine[iLength - 1] == '\n')
		{
			--iLength;
			cLine[iLength] = 0;
		}
		

		
		

		


	}
	

	fclose(pFile);
	return false;
}

void CMazeManager::Update(int _idx, char* pBuffer)
{
}
