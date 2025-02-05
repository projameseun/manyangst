#include "CMazeManager.h"
#include "CMaze.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

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
		

		int Width = 0;
		int Height = 0;
		int iLength = 0;  // 각 줄의 길이를 너비로 설정
		char maze[100][100];


		// 읽어온 줄을 maze 배열에 저장
		for (int j = 0; j < Width; ++j)
		{
			maze[i][j] = cLine[j];  // i번째 줄, j번째 문자를 maze 배열에 저장
		}
	


		


	}
	

	fclose(pFile);
	return false;
}

void CMazeManager::Update(int _idx, char* pBuffer)
{
		// 미로 그리기
	for (int i = 0; i < Height; ++i)
	{

	}

	
}
