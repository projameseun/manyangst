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
		perror("파일 열기 실패");	
		return false;
	}

	//파일열기 성공

	char cLine[256] = {};

	fgets(cLine, 256, pFile);

	//파씽(Parsing)
	//문장을 그것을 이루고 있는 구성 성분으로 분해하고(잘라내고) 
	// 그들 사이의 위계 관계를 분석하여 문장의 구조를 결정하는 것을 말한다
	//가공을 해가는 과정이기도 하다.

	//hello strtok func !\0 이걸 strtok 함수를 사용하게 되면
	//hello\0strtok\0func\0!\0 이런식으로 변환이 된다.
	//원본 데이터의 무결성을 보장해야 되는경우에는 절대로 사용해서는 안된다.
	//무결성이란 간단하게 변경되지 않은 상태를 말한다.

	//_Check_return_
	//	_ACRTIMP char* __cdecl strtok_s(
	//		_Inout_opt_z_                 char* _String,			분리할 문자열의 주소를 나타낸다.함수가 처음호출될 때 분리할 문자열의 시작주소를 전달해야 하며, 이후 호출에서는 NULL을 전달하이 이전호출의 상태를 이어간다.
	//		_In_z_                        char const* _Delimiter,	구분자를 나타낸다 예를들어 ,면 쉼표로 문자열을 나뉜다
	//		_Inout_ _Deref_prepost_opt_z_ char** _Context			문자열 분리 상태를 저장하는 포인터
	//	);
	//strtok_s 는 내부적으로 상태를 저장하지 않는다. 대신 호출자가 제공한 context를 사용하여 상태를 저장한다.
	//안정성을 극복하기위해 설계된것이다.

	char* pContext = nullptr;
	char* pWidth = nullptr;
	char* pHeight = nullptr;

	pWidth = strtok_s(cLine, ", ", &pContext);
	pHeight = strtok_s(NULL, ", ", &pContext);
	m_iWidth = atoi(pWidth);
	m_iHeight = atoi(pHeight);

	m_pBlocklOrigin = new char* [m_iHeight];
	m_pBlock = new char* [m_iHeight];

	for (int i = 0; i < m_iHeight; ++i)
	{
		m_pBlocklOrigin[i] = new char[m_iWidth];
		m_pBlock[i] = new char[m_iWidth];

		memset(cLine, 0, 256);

		fgets(cLine, 256, pFile);

		//맵의 본체랑 맵의정보를 담는 블락
		memcpy(m_pBlocklOrigin[i], cLine, m_iWidth);	//맵 본체
		memcpy(m_pBlock[i], cLine, m_iWidth);			//맵의 ㅈ어보를 담는 블락

		for (int j = 0; j < m_iWidth; ++j)
		{
			
		}

		//std::cout << m_pBlocklOrigin[i] << std::endl;
	}

	fclose(pFile);
	return true;
}

void CMaze::Render(char* pBuffer)
{
}
