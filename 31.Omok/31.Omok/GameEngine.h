#pragma once
#include <Windows.h>
#include "Om.h"
#include "Stone.h"


class GameEngine
{
public:
	int m_Colum;
	int m_Row;
	Om* m_Om;
	MOUSE_EVENT_RECORD	 m_MSRecord;
	bool m_Black;

public:
	Stone m_GridType[19][39];  // yx


public:
	
	void GameInit();
	void GameStart(HANDLE handle, INPUT_RECORD *pRecord, DWORD NumRe);
	void GameRender(MOUSE_EVENT_RECORD mouseenvet);
	MOUSE_EVENT_RECORD GameUpdate(HANDLE handle, INPUT_RECORD *pRecord, DWORD NumRe);
	MOUSE_EVENT_RECORD PrcesssMouseEvent(MOUSE_EVENT_RECORD MSenvet);
	void gotoxy(int x, int y);
	void StoneInit();
	void JugMenet();
	
};

