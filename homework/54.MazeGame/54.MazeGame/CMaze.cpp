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
	
	//���Ͽ���
	fopen_s(&pFile, pFileName, "rt");
	

	if (!pFile)
	{
		return false;
	}

	//���Ͽ��� ����

	
	return false;
}

void CMaze::Render(char* pBuffer)
{
}
