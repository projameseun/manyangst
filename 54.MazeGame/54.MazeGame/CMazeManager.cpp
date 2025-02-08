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
	fopen_s(&pFile, "MazeList.txt", "rt");

	if (!pFile)
	{
		perror("파일 열기 실패");
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
		size_t iLength = static_cast<int>(strlen(cLine));
		
		//\n까지 읽어오므로 마지막은 제거
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
		
		
		//맵의 정보를 담고있는 배열이있어야 된다.
		m_MazeArray.push_back(pMaze);


	}
	

	fclose(pFile);
	return false;
}

void CMazeManager::Update(int _idx, char* pBuffer)
{
}
