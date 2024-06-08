#pragma once


//도구 - > 옵션 -> 환경 -> 키보드에 들어가면 내가 원하는 단축키 만들수 있다.


static int g_StaticNum;


int Add(int a, int b);
int Minus(int a, int b);
int Multi(int a, int b);
int Module(int a, int b);
int Divide(int a, int b);

void CalFunc();
void CalFunc2();
void StaticAddress();
void StaticAddress2();
void ExternFunc();
void ExternAddress();

//외부변수
//외부변수는 선언을하고 어느파일이든 무조건 정의가 되어 있야되고 어느파일이든 정의를 할수 있다. 또한 주소를 한가지로 공유한다
extern int g_Num;