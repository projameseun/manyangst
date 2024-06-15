#include <iostream>
#include <Windows.h>

#define MOUSE_BUTTON 0

void PrcesssMouseEvent(MOUSE_EVENT_RECORD mevent)
{
	switch (mevent.dwEventFlags)
	{
	case MOUSE_BUTTON: //��ư���°� ����Ȱ��
	{
		if (mevent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			std::cout << "Mouse Left Button Pressed" << std::endl;\
			std::cout << "Mouse Move to ( " << mevent.dwMousePosition.X << " , " << mevent.dwMousePosition.Y << ")" << std::endl;
		}
		else if (mevent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
		{
			std::cout << "Mouse Right Button Pressed" << std::endl;
		}
		else
		{
			std::cout << "Button released" << std::endl;
		}
	}
	case MOUSE_MOVED:
	{
//		std::cout << "Mouse Move to ( " << mevent.dwMousePosition.X << " , " << mevent.dwMousePosition.Y << ")" << std::endl;
	}
	default:
		break;
	}
}

int main()
{
	//Handle � Ű��� �����ص� ����.
	//c++���� �پ��� ���ҽ�(����,������,�������)�� �����ϱ����� �ڵ��� ����Ѵ�.
	//�ڵ��� void*�� �����Ǿ��ִ� ������ void*�� �������� ���Ƽ�..
	//������� �پ��� ���ҽ��� ���� �ٸ� ���ҽ����ٵ� �̰ɸ�� �����ϰ� ó���Ҽ� �մ� ������ �ִ�.

	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD savemode;	//unsigned long

	if (handle == INVALID_HANDLE_VALUE)
	{
		DWORD errocode = GetLastError();
		std::cout << "INVALID_HANDLE_VALUE Error :  " << errocode <<  std::endl;
	}

	//�ܼ� �������
	
	if (!GetConsoleMode(handle, &savemode))
	{
		DWORD errocode = GetLastError();
		std::cout << "GetConsoleMode Error :  " << errocode << std::endl;
	}

	//�÷��׶� Ư������ ���¸� ��Ÿ���� ������ �÷��׶�� �Ѵ�.
	//���� bool���̳� bit�� ǥ���� �ȴ�.

	//#define ENABLE_PROCESSED_INPUT              0x0001	Ư��Ű ���� �ý���ó�� ex) Ctrl + C���ձ�ɵ�...
	//#define ENABLE_LINE_INPUT                   0x0002	����ڰ� EnterŰ�� ������ ���� �Է¿� ���۰� ��ϵ��� �ʴ´�.
	//#define ENABLE_ECHO_INPUT                   0x0004	�Է��� ���ڸ� �ܼ�ȭ�鿡 �����Ѵ�. �� �÷��װ� �������� �ʴ´ٸ� �Էµ� ���ڴ� ȭ�鿡 ǥ�õ��� �ʴ´�.
	//#define ENABLE_WINDOW_INPUT                 0x0008	â �Է��� Ȱ��ȭ �Ҷ� ��� �ܼ� �Է¹��۰� â ũ�� ���� �̺�Ʈ�� ����Ѵ�
	//#define ENABLE_MOUSE_INPUT                  0x0010	���콺 �Է��� Ȱ��ȭ 
	//#define ENABLE_INSERT_MODE                  0x0020	���Ը�� Ȱ��ȭ
	//#define ENABLE_QUICK_EDIT_MODE              0x0040	���� ���� ���
	//#define ENABLE_EXTENDED_FLAGS               0x0080	�÷����� Ȱ��ȭ�� �����ϰ� �ϴ� ����
	//#define ENABLE_AUTO_POSITION                0x0100
	//#define ENABLE_VIRTUAL_TERMINAL_INPUT       0x0200

	DWORD mMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

	if (!SetConsoleMode(handle, mMode))
	{
		DWORD errocode = GetLastError();
		std::cout << "SetConsoleModeError :  " << errocode << std::endl;
	}


	INPUT_RECORD pRecord[128];
	DWORD NumRe; //�󸶸�ŭ������..

		while (true)
		{


			//�Է� �̺�Ʈ �б�
			if (!ReadConsoleInput(handle, pRecord, 128, &NumRe))
			{
				std::cout << "ReadConsoleInput Error" << std::endl;
				system("Pause");
				break;
			}

			for (DWORD i = 0; i < NumRe; ++i)
			{
				if (pRecord[i].EventType == MOUSE_EVENT)
				{
					//���콺�̺�Ʈ����
					//std::cout << "���콺 �̺�Ʈ���� " << std::endl;
					PrcesssMouseEvent(pRecord[i].Event.MouseEvent);
				}
			}
		}
	

	

	


	SetConsoleMode(handle, savemode);

	return 0;
}