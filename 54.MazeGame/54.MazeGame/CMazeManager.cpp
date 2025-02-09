#include "CMazeManager.h"
#include "CMaze.h"

CMazeManager* CMazeManager::m_pInst = nullptr;

CMazeManager::CMazeManager():
	m_bStart(false),
	m_fSecond({ 0,0 }),
	m_fPrevTime({ 0,0 })
{
}

CMazeManager::~CMazeManager()
{
	for (int i = 0; i < m_MazeArray.size(); ++i)
	{
		delete m_MazeArray[i];
	}
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
	
	//���ػ� Ÿ�̸� ���Ľ� Ȯ��
	if (!QueryPerformanceFrequency(&m_fSecond))
	{
		perror("���ػ� Ÿ�̸� �������� ����");

	}


	fclose(pFile);
	return true;
}


/*
	DeltaTime�̶�?
	FPS(Frame Per Second)�� �ʴ� �����Ӽ��� �ǹ��Ѵ�.
	�ַ� �����Ӱ��� �ð� ������ ����ϴµ� ����Ѵ�.
	Update,Render�Լ���  �� �����Ӹ��� ����Ǵ� �Լ��̴�.
	�ʴ� �������� 100�� �������ִ� ��ǻ�Ͷ�� �� ĳ���ʹ� 1������ ��ġ�� 100�� �ɰŴ�.
	�׷��� �������� 10�����ۿ� �ȵǴ� ��ǻ�Ͷ�� ��ĳ���ʹ� 10�� �ȴ�...
	�̷��� DeltaTime�� ����ϸ� �ȴ�.
	100FPS�� ��ǻ�Ϳ����� DeltaTime�� 1/100���̴�.
	10FPS�� ��ǻ�Ϳ����� DeltaTime�� 1/10���̴�.
	�̰� 1������ ������ ����غ���
	FPS 100===> 1������ �̵��Ÿ� = 100 * (1* 1/100) = 1
	FPS 10===> 1������ �̵��Ÿ� = 10 * (1* 1/10) = 1
	���� ���� ��������.
	1������ �̵��Ÿ� = FPS * (�����ǽ��ǵ尪 * DeltaTime)

	DletaTime�� ���������
	��ǻ���� ���κ��忡 ���ػ� Ÿ�̸Ӱ� �����Ѵ�. �� Ÿ�̸Ӵ� ��Ȯ�ϰ� ������ ���ļ�(1���� �� Ÿ�̸��� ���ɿ� �´� ������)�� ������ �ִ�.
	
	QueryPerformanceCounter
	�� �Լ��� ���ڷ� �Ѿ ������ �Լ��� ȣ��� ������ Ÿ�̸� ���� �Ѱ��ش�.
	���࿡ �������� �ʴ� ȯ���̶�� 0�� ��ȯ�Ѵ�. �׷����� ���Ǿ���.
	�� �Լ��� �ݺ������� ����ϰԵǸ� ���Ӿ��� ���ڰ� ī���� �Ǵ°� Ȯ���Ҽ� �ִ�.

	QueryPerformanceFrequency
	�� �Լ��� ���ڿ� ���� �ý����� ���ػ� Ÿ�̸��� ���ļ�(1�ʴ� ������)�� ��ȯ�Ѵ�
	�� ���� �Լ��� ȣ���ϴ� �ý��۸��� �ٸ��⶧���� (��ǻ�ͻ��) �Ĥ� ���͸��� ȣ������ ���� �ٸ����ִ�.

	DeltaTime(�����ӻ����� �ð�) = (���� ������ ������ī���� - ���� �������� ����ī����) / �ʴ� ������

*/

void CMazeManager::Update(int _idx, char* pBuffer)
{
	m_pCurrentMaze = m_MazeArray[_idx];


	//�̷��� ������ġ�� �����´�
	COORD tStartPos = m_pCurrentMaze->GetStartPos();

	//�̷��� ������ġ�� �÷��̾��� ��ġ������
	//�����÷��̾ ���� �������Ǹ� �����̰� �����°ű��� 

	m_pCurrentMaze->clear();
	

	system("cls");

	m_bStart = true;


	//�ʱ� �ð� ���
	QueryPerformanceCounter(&m_fPrevTime);

	while (m_bStart)
	{
	
		LARGE_INTEGER fCurrentTime;
		QueryPerformanceCounter(&fCurrentTime);
	
		
		//DeltaTime(�����ӻ����� �ð�) = (���� ������ ������ī���� - ���� �������� ����ī����) / �ʴ� ������
		float fDeltaTime = static_cast<float>(fCurrentTime.QuadPart - m_fPrevTime.QuadPart) / (float)m_fSecond.QuadPart;

		//�����ð��� ����ð����� ����
		m_fPrevTime = fCurrentTime;
		
		//MazeRender
		m_pCurrentMaze->Render(pBuffer);

		std::cout << pBuffer << std::endl;

		//Ű�� ���������� ��ٸ�
		while (_getch() != '\r')
		{
			char test = _getch();
			int a = 0;
		}
	
	}


}

int CMazeManager::MazeMainMenu()
{
	system("cls");
	
	for (int i = 0; i < m_MazeArray.size(); ++i)
	{
		cout << i + 1 << " : " << m_MazeArray[i]->GetName() << endl;
	}

	std::cout << m_MazeArray.size() + 1 << " : ����" << std::endl;	
	std::cout << "�̷θ� �������ּ���:";

	size_t iSelect = 0;
	
	std::cin >> iSelect;
	std::cin.ignore();

	if (iSelect < 1 || iSelect > m_MazeArray.size() + 1)
	{
		return 0;
	}
	

	return iSelect;
}
