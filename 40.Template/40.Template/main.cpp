#include <iostream>
#include "CArray.h"
#include <vector>
#define TEST 10

using namespace std;


//�Լ� ���ø�
template<typename T>
T	Add(T a, T b)
{
	return a + b;
}

template<class T>
void OutPut(T a)
{
	std::cout << a << std::endl;
}


class Player
{
public:
	int iHP;
	int iMP;

public:
	void Attack()
	{
	std:cout << "Attack!! " << std::endl;
	}
};

int main()
{
	/*
		�����ε��� ���ؼ� ���� �ڷ����� ��Ģ���� ����� ����� �ִµ�
		���࿡ �̰� �ϳ��� �Լ��� ���ؼ� �� �ڷ����� �� ��Ȳ�� �°� �������ټ� �ִٸ� ���� ȿ�����̰� ������� ���̴�.
		�̷��� ������ �Ȱ� ���ø��̴�.
		
		Ŭ���� ���ø��� ���Ǵ� ������Ͽ� ��������� �ȴ�.
		������ �����Ϸ��� ���ø��� �ν��Ͻ�ȭ�� ����� ó���ϱ� ���ؼ� �ʿ��� �ڵ尡 ���ø� ���ǿ� ���� ��� ���Ե� ��������� �־�� �ȴ�.
		���ø��� ������ �����̾ƴ� �ν��Ͻ�ȭ ������ ������ �˴ϴ�. 

		���ø� �ν��Ͻ�ȭ..
		���ø��� ��ü���� Ÿ������ ��ȯ�ϴ� ������ ���Ѵ�.

		�ν��Ͻ�
		class�� �Ҽӵ� �������� ��ü�� ���Ѵ�.
		ex) PlayerŬ������ �����ϰ� py�� ��ü�� �����ϰ� �Ǹ� py��� ��ü�� Player��� Ŭ������ �ν��Ͻ��� �ȴ�.
		
		
		
	
	*/

	int a = Add<int>(10, 10);

	float f = Add<float>(3.f, 3.f);

	double d = Add<double>(3.14, 567.1);

	OutPut<int>(a);
	OutPut<float>(d);
	OutPut<double>(d);


	std::cout << "Hellow" << std::endl;


	//cout << "Hellow " << endl;

	//Player py, py2, py3;

	CArray<float> arr;

	arr.push_back(10.35);
	arr.push_back(2.55);
	arr.push_back(11.545);

	arr.OutPut();
	

	std::cout << std::endl;
	CArray<int> arrint;

	
	arrint.push_back(10);
	arrint.push_back(20);
	arrint.push_back(30);

	int test = 300;

	arrint.Delete(1);


	arrint[1] = test;

	arrint.OutPut();


	
	


	
	return 0;
}