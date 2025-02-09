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
	
	//고해상도 타이머 주파스 확인
	if (!QueryPerformanceFrequency(&m_fSecond))
	{
		perror("고해상도 타이머 지원하지 않음");

	}


	fclose(pFile);
	return true;
}


/*
	DeltaTime이란?
	FPS(Frame Per Second)는 초당 프레임수를 의미한다.
	주로 프레임간의 시간 간격을 계산하는데 사용한다.
	Update,Render함수는  매 프레임마다 실행되는 함수이다.
	초당 프레임이 100을 보장해주는 컴퓨터라면 이 캐릭터는 1초후의 위치는 100이 될거다.
	그러나 프레임이 10정도밖에 안되는 컴퓨터라면 이캐릭터는 10이 된다...
	이럴때 DeltaTime을 사용하면 된다.
	100FPS의 컴퓨터에서는 DeltaTime은 1/100초이다.
	10FPS의 컴퓨터에서는 DeltaTime은 1/10초이다.
	이걸 1초후의 값으로 계산해보면
	FPS 100===> 1초후의 이동거리 = 100 * (1* 1/100) = 1
	FPS 10===> 1초후의 이동거리 = 10 * (1* 1/10) = 1
	둘의 값이 같아진다.
	1초후의 이동거리 = FPS * (임의의스피드값 * DeltaTime)

	DletaTime을 직접만들기
	컴퓨터의 메인보드에 고해상도 타이머가 존재한다. 이 타이머는 정확하고 일정한 주파수(1초의 각 타이머의 성능에 맞는 진동수)를 가지고 있다.
	
	QueryPerformanceCounter
	이 함수는 인자로 넘어간 변수의 함수가 호출된 시점의 타이머 값을 넘겨준다.
	만약에 지원되지 않는 환경이라면 0을 반환한다. 그럴일은 거의없다.
	이 함수를 반복문으로 출력하게되면 끊임없이 숫자가 카운팅 되는걸 확인할수 있다.

	QueryPerformanceFrequency
	이 함수는 인자에 현재 시스템의 고해상도 타이머의 주파수(1초당 진동수)를 반환한다
	이 값은 함수를 호출하는 시스템마다 다르기때문에 (컴퓨터사양) 컴ㅍ ㅠ터마다 호출했을 값이 다를수있다.

	DeltaTime(프래임사이의 시간) = (현제 프레임 진동수카운팅 - 이전 프레임의 진동카운팅) / 초당 진동수

*/

void CMazeManager::Update(int _idx, char* pBuffer)
{
	m_pCurrentMaze = m_MazeArray[_idx];


	//미로의 시작위치를 가져온다
	COORD tStartPos = m_pCurrentMaze->GetStartPos();

	//미로의 시작위치를 플레이어의 위치로지정
	//숙제플레이어를 띄우기 여유가되면 움직이고 나가는거까지 

	m_pCurrentMaze->clear();
	

	system("cls");

	m_bStart = true;


	//초기 시간 기록
	QueryPerformanceCounter(&m_fPrevTime);

	while (m_bStart)
	{
	
		LARGE_INTEGER fCurrentTime;
		QueryPerformanceCounter(&fCurrentTime);
	
		
		//DeltaTime(프래임사이의 시간) = (현제 프레임 진동수카운팅 - 이전 프레임의 진동카운팅) / 초당 진동수
		float fDeltaTime = static_cast<float>(fCurrentTime.QuadPart - m_fPrevTime.QuadPart) / (float)m_fSecond.QuadPart;

		//이전시간을 현재시간으로 갱신
		m_fPrevTime = fCurrentTime;
		
		//MazeRender
		m_pCurrentMaze->Render(pBuffer);

		std::cout << pBuffer << std::endl;

		//키를 누를때까지 기다림
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

	std::cout << m_MazeArray.size() + 1 << " : 종료" << std::endl;	
	std::cout << "미로를 선택해주세요:";

	size_t iSelect = 0;
	
	std::cin >> iSelect;
	std::cin.ignore();

	if (iSelect < 1 || iSelect > m_MazeArray.size() + 1)
	{
		return 0;
	}
	

	return iSelect;
}
