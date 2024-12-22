#include <iostream>

class CParent
{
private:
	int m_i;	//멤버변수
	double m_d;
	//short m_c[8];
protected:
	int m_j;

public:
	void Func()	//멤버함수
	{
		m_i = 10;
	}
	void Func2()	//멤버함수
	{
		m_i = 10;
	}

	void Func3()	//멤버함수
	{
		m_i = 10;
	}

	void Func4()	//멤버함수
	{
		m_i = 10;
	}
	void Func5()	//멤버함수
	{
		m_i = 10;
	}


	
};

class CChild : public CParent
{
public:
	int m_k;
	float m_f;



};

class Test
{

};

int main()
{
	//상속 
	//클래스간에 부모와 자식의 관계를 형성 시켜줄수 있는 기능이다.
	//A클래스 B클래스가 있을때 B가 A를 상속받고 있다면
	//A를 부모클래스(기본클래스) B를 자식클래스(파생클래스)라고 부른다.
	//B는 상속받고 A의 멤버함수,멤버변수를 물려받아 사용할수 있다.
	//이때 A에 ,pirvate로 되어 있다면 지삭에서는 접근 불가능

	CParent parent;		//객체

	//parent.m_i = 10;

	CChild child;

	size_t size = sizeof(CParent);

	
	//다음시간에 사이즈부터

	return 0;
}