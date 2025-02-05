#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>

using namespace std;

/*
	버퍼란?
	임시 메모리공간이다.

	1.메모리 공간 버퍼
	데이터를 일시적으로 저장하는 메모리 공간이다.
	데이터의 입출력 속도를 조절하고 데이터의 일관성을 유지하며, 효율적인 데이터 처리를 가능하게 한다.
	InptuOutput,네트워크통신,그래픽 렌더링 등에서 사용된다.

	2.화면 버퍼
	콘솔 애플리케이션에서 화면에 출력할 텍스트나,그래픽을 임시로 저장하는 메모리 공간이다.	
	화면에 표시될 내용을 저장하고 더블버퍼링을 통해 화면 깜빡임을 줄인다.
	
*/

class ConsoleDoubleBuffer
{
private:
	HANDLE	m_Buffer[2];			//HANDLE은 윈도우에서 사용되는 핸들을 나타내는 데이터형이다. 핸들은 윈도우에서 사용되는 객체를 식별하는데 사용한다. 포인터와 유사한 역할을한다.
	int		m_iActiveBuffer;		//현재 활성화된 버퍼인덱스
	int		m_iWidth;
	int		m_iHeight;

public:
	ConsoleDoubleBuffer(int _width, int height) :
		m_iWidth(_width), m_iHeight(height), m_iActiveBuffer(0)
	{

		//버퍼생성 
		//CreateConsoleScreenBuffer win api에서 제공하는 함수로써, 새로운 콘솔 화면 버퍼를 생성하는 역할을 한다.이 함수는 콘솔 출력을 제어할수 있는 스크린
		/*	_In_ DWORD dwDesiredAccess, 버퍼에 대한 액세스 권한지정 읽기,쓰기 권한을 부여한다
			_In_ DWORD dwShareMode,		버퍼에대한 공유모드 일반적으로 0을 쓴다
			_In_opt_ CONST SECURITY_ATTRIBUTES* lpSecurityAttributes,	보안속성을 지정하는 구조체에 대한 포인터이다 보통 NULL을 사용한다
			_In_ DWORD dwFlags,				버퍼의 동작을 제어하는 플래그 일반적으로 CONSOLE_TEXTMODE_BUFFER 사용하여 텍스트모드 버퍼를 사용한다
			_Reserved_ LPVOID lpScreenBufferData	버퍼에대한 데이터 포인터 보통 NULL로 설정 
			);*/


		//for (int i = 0; i < 2; ++i)
		//{
	
		//	m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		//	//콘솔 크기설정
		//	COORD	tBufferSize = { static_cast<SHORT>(m_iWidth),static_cast<SHORT>(m_iHeight) };
		//	SMALL_RECT	rect = { 100,100,static_cast<SHORT>(m_iWidth - 1) ,static_cast<SHORT>(m_iHeight - 1) };
		//	SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize);	//이함수를 통해서 콘솔화면 버퍼의 크기를 번경하면, 콘솔창의 크기는 자동으로 변경되지 않는다. 결론은 콘솔 화면 버퍼의 크기와 콘솔창의 크기는 별개이다. 
		//	SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect);         //콘솔 화면 버퍼의 창크기와 위치를 설정하는 함수이다.
		//}

		//코드 개선 예외처리
		//1. 예외설정 발생(throw) : 예외가 발생하면 throw 키워드를 사용하여 예외 객체를 던집니다.
		//2. 예외처리 (catch) : 예외가 발생하면 함수나 호출 스택 상위에 함수에서 catch블록을 사용하여 예외를 처리합니다.
		//3. 예외미처리: 만약에 예외를 처리할 catch블록이 없으면, 프로그램은 비정상적을 종료된다.

		for (int i = 0; i < 2; ++i)
		{
			m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
			if (m_Buffer[i] == INVALID_HANDLE_VALUE)
			{
				
				throw std::runtime_error("failed");

			}

			COORD tBufferSize = { static_cast<SHORT>(m_iWidth), static_cast<SHORT>(m_iHeight) };
			if (!SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize))
			{
				CloseHandle(m_Buffer[i]);
				throw std::runtime_error("failed");
			}

			SMALL_RECT rect = { 0,0,static_cast<SHORT>(m_iWidth - 1),static_cast<SHORT>(m_iHeight - 1) };	
			if (!SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect))
			{
				CloseHandle(m_Buffer[i]);
				throw std::runtime_error("failed");
			}
		}
	}


	~ConsoleDoubleBuffer()
	{
		for (int i = 0; i < 2; ++i)
		{
			CloseHandle(m_Buffer[i]);
		}
	}

	void Draw(int x, int y, const std::string& str)
	{
		
		//버퍼에 대한 텍스트출력
		COORD tCoord = { static_cast<SHORT>(x),static_cast<SHORT>(y) };
		DWORD dwWritten;
		WriteConsoleOutputCharacterA(m_Buffer[m_iActiveBuffer], str.c_str(), str.length(), tCoord, &dwWritten);
		//지정된 콘솔 화면 버퍼의 특정위치에 텍스트를 출력하는 역할이다. 실제 화면에 바로 출력되는것이 아니라 우리가 만든 화면버퍼에 텍스트를 저장하는거다.
	}

	void Render()
	{
		//지정된 콘솔화면 버퍼를 활성화하며,해당 버퍼의 내용을 콘솔창에 표기하는 역할. 여러콘솔화면 버퍼중 하나를 선택하여 현재 활성화된 버퍼로 설정.
		SetConsoleActiveScreenBuffer(m_Buffer[m_iActiveBuffer]);
		m_iActiveBuffer = 1 - m_iActiveBuffer;
	}

	void clear()
	{
		//콘솔화면 버퍼를 지우는 역할
		COORD tCoord = { 0,0 };
		DWORD dwWritten;
		FillConsoleOutputCharacter(m_Buffer[m_iActiveBuffer], ' ', m_iWidth * m_iHeight, tCoord, &dwWritten);	//지정된 문자로 채운다.
		FillConsoleOutputAttribute(m_Buffer[m_iActiveBuffer], FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, m_iWidth * m_iHeight, tCoord, &dwWritten);
	}
};


int main()
{
	//system("mode con cols=30 lines=30");
	const int width = 100;
	const int height = 50;

	
	
	int ix = 0;
	int iy = 0;


	COORD tCoord = { 0,0 };

	//
	//console.test();
	
	try
	{
		ConsoleDoubleBuffer console(width, height);
		while (true)
		{
			//system("cls");
			//콘솔 화면 버퍼지우기
			console.clear();

			console.Draw(ix, iy, "Flickering!");
			//
			////현재화면
			console.Render();


			ix++;
			Sleep(20);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	
	return 0;
}