#pragma once


//���� - > �ɼ� -> ȯ�� -> Ű���忡 ���� ���� ���ϴ� ����Ű ����� �ִ�.


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

//�ܺκ���
//�ܺκ����� �������ϰ� ��������̵� ������ ���ǰ� �Ǿ� �־ߵǰ� ��������̵� ���Ǹ� �Ҽ� �ִ�. ���� �ּҸ� �Ѱ����� �����Ѵ�
extern int g_Num;