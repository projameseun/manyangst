#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>

class ConsoleDoubleBuffer
{
private:
	HANDLE	m_Buffer[2];
	int		m_iActiveBuffer;		//���� Ȱ��ȭ�� �����ε���
	int		m_iWidth;
	int		m_iHeight;

public:
	ConsoleDoubleBuffer(int _width, int height) :
		m_iWidth(_width), m_iHeight(height), m_iActiveBuffer(0)
	{

		//���ۻ��� 
		//CreateConsoleScreenBuffer win api���� �����ϴ� �Լ��ν�, ���ο� �ܼ� ȭ�� ���۸� �����ϴ� ������ �Ѵ�.�� �Լ��� �ܼ� ����� �����Ҽ� �ִ� ��ũ��
		/*	_In_ DWORD dwDesiredAccess, ���ۿ� ���� �׼��� �������� �б�,���� ������ �ο��Ѵ�
			_In_ DWORD dwShareMode,		���ۿ����� ������� �Ϲ������� 0�� ����
			_In_opt_ CONST SECURITY_ATTRIBUTES* lpSecurityAttributes,	���ȼӼ��� �����ϴ� ����ü�� ���� �������̴� ���� NULL�� ����Ѵ�
			_In_ DWORD dwFlags,				������ ������ �����ϴ� �÷��� �Ϲ������� CONSOLE_TEXTMODE_BUFFER ����Ͽ� �ؽ�Ʈ��� ���۸� ����Ѵ�
			_Reserved_ LPVOID lpScreenBufferData	���ۿ����� ������ ������ ���� NULL�� ���� 
			);*/


		for (int i = 0; i < 2; ++i)
		{
	
			m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
			//�ܼ� ũ�⼳��
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