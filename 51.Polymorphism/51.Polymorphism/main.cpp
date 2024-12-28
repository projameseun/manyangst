#include <iostream>

class CParent
{
public:
	virtual void virutalFunc() //가상함수
	{
		std::cout << "부모 가상함수" << std::endl;
	}



	void OutPut()
	{
		std::cout << "부모 출력" << std::endl;
	}

	//virtual void PureVirutalFunc() = 0;


};

class CChild : public CParent
{
public:
	int m_Data = 300;

public:
	 void virutalFunc() override
	{
		std::cout << "자식 가상함수" << std::endl;
	}
	void OutPut()
	{
		std::cout << "자식 출력" << std::endl;
	}

	void OnlyChildFunc()
	{
		std::cout << "자식 함수만 같는 기능" << std::endl;
	}

	/*void PureVirutalFunc()override
	{
		std::cout << "자식 재정의" << std::endl;
	}*/


	
};

int main()
{
	CParent Parent;
	CChild Child;

	CParent* pParent = nullptr;
	//CChild* pChild = (CChild*)&Parent; 다운캐스팅 문제가 될수 있다.
	

	//pParent = &Parent;
	pParent = &Child;		//업캐스팅
	pParent->OutPut();		//정적바인딩 
	pParent->virutalFunc();		//가상함수

	//부모로다시주소
	pParent = &Parent;
	pParent->OutPut();		//정적바인딩 
	pParent->virutalFunc();		//가상함수

	//pParent는 child주소를 넘겨서 다형성이 된것처럼 보이지만 
	//파생된 클래스 OutPtu()함수는 부모를 불러오게 된다.

	//이럴때는 가상함수를 사용해야 가능해 진다.
	//가상 함수를 사용하면 구별이 가능해 진다.
	//가상함수를 사용하면 부모클래스 하나로만 모든 자식클래스를 사용되고 접근이 가능해진다.

	/*
		가상함수를 사용하게 되면 왜 찾을수 있냐?
		가상함수를 사용하면 동적 바인딩이 이루어진다.
		동적바인딩이 일어난다는 것은 런타임 때 실제 객체의 타입을 기반으로 적절한 함수를 찾아 호출하게 된다.
		이걸 만들수 있는 이유가 바로 가상함수테이블(Virutal Function Table,VTable) 이라고 부른다.


		가상함수테이블(VTable)
		VTable은 각 클래스에 대해서 컴파일러가 자동으로 생성하는 테이블이다.
		이 테이블은 해당 클래스의 정의된 가상 함수들의 주소를 저장하고 있다.
		
		각 객체들은 VTable 포인터를 가지고 있으며, 이 포인터는 객체가 속한 클래스의 VTable을 가리키게 된다.
		즉,객체가 생성될 시점에 그 객체가 속한 클래스의 VTable연결이 된다.
		그래서 가상함수가 호출될때 올바른 함수가 실행되도록 가능해지는 것이다.

		ex)CParent,CChild에 대해 Vatable생성 되며
		각 클래스에서 오버라이딩한 함수들의 주소가 테이블에 기록이 된다.
		객체들은 VTable포인터를 가지게 된다.
		그리고 이 포인터는 그 객체가 속한 클래스의 VTable을 가리키며, 객체가 호출하는 가상함 수의 실제 구현을 찾아준다.

	*/

	((CChild*)pParent)->OutPut();					//자식이 호출된다	 (부모가 호출되는게 이론상 맞다)
	((CChild*)pParent)->virutalFunc();				//우리가 원하지 않은 부모가 호출이된다.

	
	//dynamic_cast<CChild*>(pParent)->virutalFunc(); //런타임때 터지게 된다.
	//다이나믹 캐스팅은 실제 객체가 해당클래스 타입일 경우에만 다운캐스팅을 허용하고 그렇지 않으면 nullptr을 반환한다.

	//다운캐스팅을 사용했을때 문제가되는거 

	
	//((CChild*)pParent)->OutPut();는 잘못된 캐스팅방법이다. 
	//c++에서는 강제 형변환이 컴파일 오류를 발생시키지 않는다.
	//컴파일러는 형변환이 잘못되었음에도 경고하지 않고 실행시간에 잘못된 동작을 발생할수 있다.
	//메모리 접근 오류를 발생시키지는 않지만 예기치 않은 함수 호출이 일어 날수 있다.

	//이유는 OutPut()함수는 정작바인딩을 사용하기 때문이다.
	//정적 바인딩인 컴파일에서 어떤 함수가 호출될지 결정힌다.
	//이미 OutPut함수는 어떤 함수가 실행될지 컴파일에서 결정이 났다.
	//또 한 정적 바인딩은 함수호출이 형변환된 타입에 결정이난다.
	//즉 pParent가 가리키는 객체가 Parnet라고 해도
	//강제 형 변환을 통해서 CChild*로 처리되기 때문에 CChild의 OutPut()함수를 호출하게 된다.

	//그래서 프로그램상 오류로는 나오지 않지만 잘못쓰게되면 오류가 된다.
	//그러므로 다운캐스팅을 사용할때는 다이나믹 캐스팅을 사용해서 정확한 캐스팅이 되지 않으면 nullptr을 뽀ㅃ아내서 확실하게 검사하는게 맞다.
	//또한 성공이 제대로 이루어 지면 반환이 제대로 나오고 실패하면 nullptㄱ을 반환하게 되서 오류를 방지할수 있다.

	//정의되지 않는행동(Undefine Behavior)
	//c++에서는 UB는 프로그램이 실행될떄 예측할수 없고 명확하게 정의되지 않는 행동을 말한다
	//어떤 특정코드가 어떻게 동작할지 대한 규칙이 명확하게 명시되지 않은 경우 컴파일러가 해당코드를 어떻게 처리할지 자유롭게 결정하는 상황을 말한다.
	//이러한 행동은 예기치 않게 충돌하는 원인 또는 원하지 않는 값을 출력할수도 있다.

	//((CChild*)pParent)->OutPut() 정의되지 않는 행동을 유발할수 있다.
	//pParent는 실제 Parent가리키고 있는데 이를 CChild*로 변환을 하게되면 
	//Parnet의 객체가 실제로 CChild객체가 아니기 때문에 구조와 맞지 않느 접근을 시도하게 되는셈이다.
	//컴파일러는 이 형변환을 허용하지만 실제로 잘못된 타입의 객체를 다루게 되면
	//정확한 메모리 레이아웃을 알수없게 되므로 예측불가능한 방식으로 이루어진다.

	//클래스 객체는 메모리에서 저장이 어떻게 되는지..
	//각 멤버변수의 공간,가상함수 테이블같은 추가적인 데이터가 포함될수 있다. 이들이 모여서 객체의 메모리 레이아웃을 형성한다.

	//형변환은 개발자가 객체의 실제타입에 대한 책임을 지는 방식이다.
	//그래서 특히나 개발자가 실체 타입이 무엇인지 명확하게 사용해서 변환을 해야된다.
	//c++철학 을 가볍게 얘기해주면 가능한 컴파일러가 아닌 사용자가 제어할수 있도록하고,언어의 안정성보다는 성능과 유연성을 우선시하게 되어있다.


	//다이나믹 캐스팅예시

	{
		
		CParent Parent;
		CChild Child;

		CParent* pParent = &Child;

		pParent = &Parent;

		//CChild* pChild = static_cast<CChild*>(pParent);

		CChild* pChild = dynamic_cast<CChild*>(pParent);

		if (pChild != nullptr)
		{
			std::cout << pChild->m_Data << std::endl;	
			pChild->OnlyChildFunc();						//정적바인딩이여서 컴파일러가 UB를 발생시켜서 자식이 나오게 된거다 

		}
		else
		{
			std::cout << "nullptr 입니다" << std::endl;
		}



	}

	//가상함수 뒤에 = 0 을 붙여주면 순수가상함수라고 부른다.
	//순수가상함수는 구현부분을 만들어도되고 안만들어도 된다.
	//순수가상함수를 가지고 있는 클래스를추상 클래스라고 부른다.
	//추상클래스는 객체 생성이 불가능하다.
	//만약 자식클래스에서 순수가상함수가 재정의가 안되어 있다면
	//자식클래스 또한 추상클래스가 된다.
	//그렇기 때문에 자식클래스에서는 객체를 생성하는 클래스라면
	//반드시 순수가상함수를 재정의해주어야 된다.

	



	return 0;
}