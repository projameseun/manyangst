#include <iostream>



/*
	클래스: c++에서 객체 지향 프로그래밍을 지원하기 위해 사용되는 문법이다.
	구조체와 굉장히 흡사한 방식으로 사용이 되는데 구조체에서는 변수들만 모아두고 사용했지만
	클래스에서는 필요한 함수들을 만들어두고 사용 할수 있다.
	c++에서는 구조체에서도 클래스와 동일하게 함수를 만들어서 사용을 하는것을 가능하게 만들어 놨다(c++컴파일러)

	클래스의 4가지속성
	캡슐화 : 관련있는 변수 혹은 기능들을 하나로 묶어주는 기능을 말한다.
	
	은닉화:클래스의 변수 혹은 기능들을 외부에 공개하는 수준을 설정하는 것이다.
	
	클래스의 내부:해당 클래스에 만들어진 함수 안을 말한다.

	접근지정자
	-public : 클래스의 내부 혹은 외부 어디든 접근 사용이 가능하다.
	-private: 클래스의 내부는 사용이 가능하나 외부에서는 사용이 불가능하다.
	-protected : 상속 배우고 들어감...

	상속성,다형성 ===> 상속을 배우고...


	this 자기 자신의 메모리이다.

*/

class CPlayer
{
	//멤버변수
public:
	char	m_StrName[25];
	int		m_iAttack;
	int		m_Deffence;
	int*	m_pInt;

private:
	int		m_iHp;
	int		m_iMaxHp;

public:
	//멤버 함수
	int GetHP()
	{
		return this->m_iHp;
	}
	void SetHP(int _hp)
	{
		this->m_iHp = _hp;
	}

public:
	//생성자와 소멸자는 클래스의 이름과 동일 함수이다.
	//이 함수들은 반환 타입이 없다.
	//만약 생성 ,소멸자를 만들지 않았다면 default 생성자 default 소멸자가 만들어진다.
	//사용자가 만들어주게 되면 만들어준 생성자와 소멸자를 사용하게 된다.
	//생성자:객체를 생성할때 호출되는 함수이다.
	//이런 특징 때문에 초기화를 사용할때 효울적이다.
	//생성자는 오버로딩이 가능하다.
	//여러가지 인자를 활용해서 여러 생성자를 오버로딩 해놓고 사용하는 것이 가능하다.

	 CPlayer()
	{
		std::cout << "CPlayer 생성자 호출" << std::endl;

		m_pInt = new int;
		*m_pInt = 999;
	}
	 CPlayer(const char* _name)
	 {
		 std::cout << "CPlayer 생성자 " << _name << " 호출 " << std::endl;
	 }

	 CPlayer(const char* _name, int _att, int _def, int* _pint, int _hp, int _mxhp) : 
		 m_StrName("james"),
		 m_iAttack(_att),
		 m_Deffence(_def),
		 m_pInt(_pint),
		 m_iHp(_hp),
		 m_iMaxHp(_mxhp)
	 {

	 }
	 //CPlayer(const char* _name, int _att, int _def, int* _pint, int _hp, int _mxhp)
	 //{
		// strcpy_s(m_StrName, _name);
		// m_iAttack = _att;
		// m_Deffence = _def;
		// m_pInt = _pint;
		// m_iHp = _hp;
		// m_iMaxHp = _mxhp;
	 //}
	~CPlayer()
	{
		std::cout << "CPlayer 소멸자 호출 " << std::endl;

		if (m_pInt != nullptr)
		{
			delete m_pInt;
			m_pInt = nullptr;
			
		}
	}


};

class CPoint
{
public:
	int x;
	int y;

public:
	CPoint()
	{
		x = 0;
		y = 0;
	}
	~CPoint()
	{

	}

	//연산자 오버로딩
	//자료형 * 변수명 - 포인터변수 선언
	//*포인터변수 -- 역참조
	//&변수 --- 본인의 주소값 반환
	//자료형 & 변수명 --- 레퍼런스 변수선언


	//대입 연산자
	 CPoint& operator = (const CPoint& _Other) 
	{
		x = _Other.x;
		y = _Other.y;

	
		return *this;
	}

	 CPoint& operator + (const CPoint& _Other)
	{
		CPoint result;
		result.x = x + _Other.x;
		result.y = y + _Other.y;

		return result;
	}

	 CPoint& operator + (int iNum) 
	{
		CPoint result;
		result.x = x +iNum;
		result.y = y +iNum;

	

		return result;
	}
};




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CPlayer player;
	CPlayer player2("James",10,10,nullptr,100,100);

	std::cout << player2.m_StrName << std::endl;
	std::cout << player2.m_iAttack<< std::endl;
	std::cout << player2.m_Deffence << std::endl;
	std::cout << player2.GetHP() << std::endl;

	player2.SetHP(1000);
	std::cout << player2.GetHP() << std::endl;
	
	
	//std::cout << *(player.m_pInt) << std::endl;

	CPoint pt1, pt2, pt3;

	pt2.x = 100;
	pt2.y = 100;

	pt1 = pt2;

	pt3 = pt1 + pt2;

	//pt3 = pt1 + 100;
	
	//레퍼런스
	{
		/*
			둘의 차이점을 굳이 말한다면
			레퍼런스는 선언과 동시에 초기화를 반드시 해야되고 다른 변수를 가리킬수 없다.
			하지만 포인터는 다른변수를 가르킬수 있다.

			컴파일러 입장
			레퍼런스는 안전하고 제한적인 반면, 포인터는 유연하고 위험할수 있어.
			사용자 입장
			레퍼런스와 포인터는 문법적으로나 사용법에서 ..차이가 있다.
		*/
		
		int a = 100;
		int b = 200;
		
		//int* ptr = &a;
	
		//int* const ptr = &a;
		
		
		//*ptr = 200;


		//const int* const ptr = &a;
		const int& ref = a;
	
		//ref = 200;
		

	}


	int test = 0;


	
	return 0;
}