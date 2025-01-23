#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>

class ConsoleDoubleBuffer
{
private:
	HANDLE	m_Buffer[2];
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


		for (int i = 0; i < 2; ++i)
		{
	
			m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
			//콘솔 크기설정
			COORD	tBufferSize = { static_cast<SHORT>(m_iWidth),static_cast<SHORT>(m_iHeight) };
			SMALL_RECT	rect = { 100,100,static_cast<SHORT>(m_iWidth - 1) ,static_cast<SHORT>(m_iHeight - 1) };
			SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize);
			SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect);
		}
	}

	void test()
	{
		SetConsoleActiveScreenBuffer(m_Buffer[0]);
	}

	~ConsoleDoubleBuffer()
	{
		for (int i = 0; i < 2; ++i)
		{
			CloseHandle(m_Buffer[i]);
		}
	}


};


int main()
{
	//system("mode con cols=30 lines=30");
	const int width = 100;
	const int height = 40;

	ConsoleDoubleBuffer console(width, height);

	//
	//console.test();

	while (true)
	{

		//system("cls");

		//std::cout << "Flickering";

		
	}
	return 0;
}