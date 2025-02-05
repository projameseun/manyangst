#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>

using namespace std;

/*
	���۶�?
	�ӽ� �޸𸮰����̴�.

	1.�޸� ���� ����
	�����͸� �Ͻ������� �����ϴ� �޸� �����̴�.
	�������� ����� �ӵ��� �����ϰ� �������� �ϰ����� �����ϸ�, ȿ������ ������ ó���� �����ϰ� �Ѵ�.
	InptuOutput,��Ʈ��ũ���,�׷��� ������ ��� ���ȴ�.

	2.ȭ�� ����
	�ܼ� ���ø����̼ǿ��� ȭ�鿡 ����� �ؽ�Ʈ��,�׷����� �ӽ÷� �����ϴ� �޸� �����̴�.	
	ȭ�鿡 ǥ�õ� ������ �����ϰ� ������۸��� ���� ȭ�� �������� ���δ�.
	
*/

class ConsoleDoubleBuffer
{
private:
	HANDLE	m_Buffer[2];			//HANDLE�� �����쿡�� ���Ǵ� �ڵ��� ��Ÿ���� ���������̴�. �ڵ��� �����쿡�� ���Ǵ� ��ü�� �ĺ��ϴµ� ����Ѵ�. �����Ϳ� ������ �������Ѵ�.
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


		//for (int i = 0; i < 2; ++i)
		//{
	
		//	m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		//	//�ܼ� ũ�⼳��
		//	COORD	tBufferSize = { static_cast<SHORT>(m_iWidth),static_cast<SHORT>(m_iHeight) };
		//	SMALL_RECT	rect = { 100,100,static_cast<SHORT>(m_iWidth - 1) ,static_cast<SHORT>(m_iHeight - 1) };
		//	SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize);	//���Լ��� ���ؼ� �ܼ�ȭ�� ������ ũ�⸦ �����ϸ�, �ܼ�â�� ũ��� �ڵ����� ������� �ʴ´�. ����� �ܼ� ȭ�� ������ ũ��� �ܼ�â�� ũ��� �����̴�. 
		//	SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect);         //�ܼ� ȭ�� ������ âũ��� ��ġ�� �����ϴ� �Լ��̴�.
		//}

		//�ڵ� ���� ����ó��
		//1. ���ܼ��� �߻�(throw) : ���ܰ� �߻��ϸ� throw Ű���带 ����Ͽ� ���� ��ü�� �����ϴ�.
		//2. ����ó�� (catch) : ���ܰ� �߻��ϸ� �Լ��� ȣ�� ���� ������ �Լ����� catch����� ����Ͽ� ���ܸ� ó���մϴ�.
		//3. ���ܹ�ó��: ���࿡ ���ܸ� ó���� catch����� ������, ���α׷��� ���������� ����ȴ�.

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
		
		//���ۿ� ���� �ؽ�Ʈ���
		COORD tCoord = { static_cast<SHORT>(x),static_cast<SHORT>(y) };
		DWORD dwWritten;
		WriteConsoleOutputCharacterA(m_Buffer[m_iActiveBuffer], str.c_str(), str.length(), tCoord, &dwWritten);
		//������ �ܼ� ȭ�� ������ Ư����ġ�� �ؽ�Ʈ�� ����ϴ� �����̴�. ���� ȭ�鿡 �ٷ� ��µǴ°��� �ƴ϶� �츮�� ���� ȭ����ۿ� �ؽ�Ʈ�� �����ϴ°Ŵ�.
	}

	void Render()
	{
		//������ �ܼ�ȭ�� ���۸� Ȱ��ȭ�ϸ�,�ش� ������ ������ �ܼ�â�� ǥ���ϴ� ����. �����ܼ�ȭ�� ������ �ϳ��� �����Ͽ� ���� Ȱ��ȭ�� ���۷� ����.
		SetConsoleActiveScreenBuffer(m_Buffer[m_iActiveBuffer]);
		m_iActiveBuffer = 1 - m_iActiveBuffer;
	}

	void clear()
	{
		//�ܼ�ȭ�� ���۸� ����� ����
		COORD tCoord = { 0,0 };
		DWORD dwWritten;
		FillConsoleOutputCharacter(m_Buffer[m_iActiveBuffer], ' ', m_iWidth * m_iHeight, tCoord, &dwWritten);	//������ ���ڷ� ä���.
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
			//�ܼ� ȭ�� ���������
			console.clear();

			console.Draw(ix, iy, "Flickering!");
			//
			////����ȭ��
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