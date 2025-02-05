#include "CMaze.h"

CMaze::CMaze()
{
}

CMaze::~CMaze()
{
}

bool CMaze::Start(const char* pFileName)
{
	memset(m_strName, 0, 64);

	FILE* pFile = nullptr;
	
	//파일열기
	fopen_s(&pFile, pFileName, "rt");
	

	if (!pFile)
	{
		return false;
	}

	//파일열기 성공

	
	return false;
}

void CMaze::Render(char* pBuffer)
{
}
