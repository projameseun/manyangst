#include "Calculate.h"
#include <iostream>



int Add(int a, int b)
{
	return a + b;
}

int Minus(int a, int b)
{
	return a - b;
}

int Multi(int a, int b)
{
	return a * b;
}

int Module(int a, int b)
{
	return a % b;
}

int Divide(int a, int b)
{
	return a / b;
}

void CalFunc()
{

	g_StaticNum++;
	g_StaticNum++;
	g_StaticNum++;

	std::cout << "CalFunc 함수의 스태틱 변수의 값 :" << g_StaticNum << std::endl;
}

void CalFunc2()
{
	g_StaticNum++;
	g_StaticNum++;
	g_StaticNum++;

	std::cout << "CalFunc2 함수의 스태틱 변수의 값 :" << g_StaticNum << std::endl;
}

void StaticAddress()
{
	std::cout << "CalFun 함수의 스태틱 변수의 주소값 : " << &g_StaticNum << std::endl;
}


void StaticAddress2()
{
	std::cout << "CalFun2 함수의 스태틱 변수의 주소값 : " << &g_StaticNum << std::endl;
}

void ExternFunc()
{
	g_Num++;
	g_Num++;
	std::cout << "ExternFunc 값 :" << g_Num << std::endl;
}
void ExternAddress()
{
	std::cout << "ExternlAdress 주소 값 :" << &g_Num << std::endl;
}


extern int g_Num = 0;