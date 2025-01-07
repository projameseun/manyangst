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

	//r : 읽기 w :쓰기, a : 이어쓰기
	//t : 텍스트파일 , b:바이너리파일
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


		//문자열 길이
		int iLength = static_cast<int>(strlen(cLine));
		
		//\n까지 읽어오므로 마지막은 제거
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
