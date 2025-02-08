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
		perror("���� ���� ����");	
		return false;
	}

	//���Ͽ��� ����

	char cLine[256] = {};

	fgets(cLine, 256, pFile);

	//�ľ�(Parsing)
	//������ �װ��� �̷�� �ִ� ���� �������� �����ϰ�(�߶󳻰�) 
	// �׵� ������ ���� ���踦 �м��Ͽ� ������ ������ �����ϴ� ���� ���Ѵ�
	//������ �ذ��� �����̱⵵ �ϴ�.

	//hello strtok func !\0 �̰� strtok �Լ��� ����ϰ� �Ǹ�
	//hello\0strtok\0func\0!\0 �̷������� ��ȯ�� �ȴ�.
	//���� �������� ���Ἲ�� �����ؾ� �Ǵ°�쿡�� ����� ����ؼ��� �ȵȴ�.
	//���Ἲ�̶� �����ϰ� ������� ���� ���¸� ���Ѵ�.

	//_Check_return_
	//	_ACRTIMP char* __cdecl strtok_s(
	//		_Inout_opt_z_                 char* _String,			�и��� ���ڿ��� �ּҸ� ��Ÿ����.�Լ��� ó��ȣ��� �� �и��� ���ڿ��� �����ּҸ� �����ؾ� �ϸ�, ���� ȣ�⿡���� NULL�� �������� ����ȣ���� ���¸� �̾��.
	//		_In_z_                        char const* _Delimiter,	�����ڸ� ��Ÿ���� ������� ,�� ��ǥ�� ���ڿ��� ������
	//		_Inout_ _Deref_prepost_opt_z_ char** _Context			���ڿ� �и� ���¸� �����ϴ� ������
	//	);
	//strtok_s �� ���������� ���¸� �������� �ʴ´�. ��� ȣ���ڰ� ������ context�� ����Ͽ� ���¸� �����Ѵ�.
	//�������� �غ��ϱ����� ����Ȱ��̴�.

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

		//���� ��ü�� ���������� ��� ���
		memcpy(m_pBlocklOrigin[i], cLine, m_iWidth);	//�� ��ü
		memcpy(m_pBlock[i], cLine, m_iWidth);			//���� ����� ��� ���

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
