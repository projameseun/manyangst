#pragma once
//���ӿ� �ʿ��� ���̺귯�� ,������ ����ִ� ���
#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <conio.h>

using namespace std;

enum class BLOCK
{
	ROAD = '0',
	WALL = '1',
	START = '2',
	EXIT = '3',
};

#define RENDER_BUFFER_WIDTH	60
#define RENDER_BUFFER_HEIGHT 30

