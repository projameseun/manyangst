#pragma once
//게임에 필요한 라이브러리 ,모듈들을 담고있는 헤더
#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <conio.h>
#include <functional>
#include <string>

using namespace std;

enum class BLOCK
{
	ROAD = '0',
	WALL = '1',
	START = '2',
	EXIT = '3',
	BOMB = '4',
};

enum class DIR
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
};

#define RENDER_BUFFER_WIDTH	60
#define RENDER_BUFFER_HEIGHT 30

