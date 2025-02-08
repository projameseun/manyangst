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
	fopen_s(&pFile, "MazeList.txt", "rt");

	if (!pFile)
	{
		perror("���� ���� ����");
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
		size_t iLength = static_cast<int>(strlen(cLine));
		
		//\n���� �о���Ƿ� �������� ����
		if (cLine[iLength - 1] == '\n')
		{
			--iLength;
			cLine[iLength] = 0;
		}
		
		CMaze* pMaze = new CMaze;
		
		if(!pMaze->Start(cLine))
		{ 
			delete pMaze;
			fclose(pFile);
			return false;
			
		}
		
		
		//���� ������ ����ִ� �迭���־�� �ȴ�.
		m_MazeArray.push_back(pMaze);


	}
	

	fclose(pFile);
	return false;
}

void CMazeManager::Update(int _idx, char* pBuffer)
{
}
