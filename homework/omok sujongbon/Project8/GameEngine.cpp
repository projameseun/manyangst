#include "GameEngine.h"




#define MOUSE_BUTTON 0



void GameEngine::gotoxy(int x, int y)
{
	COORD _pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _pos);



}

MOUSE_EVENT_RECORD GameEngine::PrcesssMouseEvent(MOUSE_EVENT_RECORD mevent)
{
	switch (mevent.dwEventFlags)
	{
	case MOUSE_BUTTON: //버튼상태가 변경된경우
	{
		if (mevent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			GameRender(mevent);
			/*std::cout << "Mouse Left Button Pressed" << std::endl; \
				std::cout << "Mouse Move to ( " << mevent.dwMousePosition.X << " , " << mevent.dwMousePosition.Y << ")" << std::endl;*/
		}
		else if (mevent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
		{
			//std::cout << "Mouse Right Button Pressed" << std::endl;
		}
		else
		{
			//std::cout << "Button released" << std::endl;
		}
	}
	case MOUSE_MOVED:
	{
		//		std::cout << "Mouse Move to ( " << mevent.dwMousePosition.X << " , " << mevent.dwMousePosition.Y << ")" << std::endl;
	}
	default:
		break;
	}

	return mevent;
}


void GameEngine::GameInit()
{
	m_Colum = 19;
	m_Row = 19;
	m_Black = true;		//true 흑돌 , false 백돌

}

void GameEngine::GameStart(HANDLE handle, INPUT_RECORD* pRecord, DWORD NumRe)
{

	//입력 이벤트 읽기
	GameInit();
	m_Om->OmokMap(m_Colum, m_Row);




	while (true)
	{
		if (!ReadConsoleInput(handle, pRecord, 128, &NumRe))
		{
			std::cout << "ReadConsoleInput Error" << std::endl;
			system("Pause");
			break;
		}


		m_MSRecord = GameUpdate(handle, pRecord, NumRe);
	}
}

void GameEngine::GameRender(MOUSE_EVENT_RECORD MSenvet)
{
	int iMouseX = MSenvet.dwMousePosition.X;
	int iMouseY = MSenvet.dwMousePosition.Y;


	if (iMouseX % 2 == 0 || iMouseX == 0)
	{
		gotoxy(iMouseX, iMouseY);
		if (iMouseX >= 1 && iMouseX <= BOARD_SIZE && iMouseY >= 1 && iMouseY <= BOARD_SIZE)
		{
			if (m_Black == true) //흑돌
			{


				std::cout << "●";
				gotoxy(13, 13);
				//std::cout << "Mouse Move to ( " << MSenvet.dwMousePosition.X << " , " << MSenvet.dwMousePosition.Y << ")";
				m_Black = !m_Black;
			}
			else if (m_Black == false) //백돌
			{
				std::cout << "○";
				//std::cout << "Mouse Move to ( " << MSenvet.dwMousePosition.X << " , " << MSenvet.dwMousePosition.Y << ")";
				m_Black = !m_Black;
			}
		}
	}
	


}

MOUSE_EVENT_RECORD GameEngine::GameUpdate(HANDLE handle, INPUT_RECORD* pRecord, DWORD NumRe)
{

	//MOUSE Evnent
	for (DWORD i = 0; i < NumRe; ++i)
	{
		if (pRecord[i].EventType == MOUSE_EVENT)
		{
			//마우스이벤트시작
			//std::cout << "마우스 이벤트시작 " << std::endl;
			pRecord[i].Event.MouseEvent = PrcesssMouseEvent(pRecord[i].Event.MouseEvent);

			return pRecord[i].Event.MouseEvent;
		}


		
	}


}




