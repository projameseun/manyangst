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

	return 0;
}