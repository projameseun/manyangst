#pragma once

//---------------������ ����� ����߰�
#pragma comment(lib,"winmm.lib")

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include <string>
#include <vector>
#include <time.h>
#include <conio.h>

using namespace std;


enum class MusingNumber
{
	TroyeSIvan = 1,
	Maroon5,
	YouDaEn,
	AnnerMarie,
	JangBeomJun,
	GyungSeo,
	AllTimeLow,
	OnePiece,
	PostMalone,
	SungSiKyung,
	
};

enum class MenuSelect
{
	DefaultPlay =1,
	RandomPlay,
	EXIT,
};