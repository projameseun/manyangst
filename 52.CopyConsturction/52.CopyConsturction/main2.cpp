#include <iostream>
#include <string>


class Man
{
public:
	char* m_Name;
	int m_iAge;

public:
	Man& operator = (const Man& _other)
	{
		if (this != &_other)
		{
			if (m_Name)
			{
				delete[](m_Name);
				m_Name = nullptr;
			}


			m_iAge = _other.m_iAge;

			//새 메모리 할당
			if (_other.m_Name)
			{
				//c언어양식
			/*	m_Name = (char*)malloc(25);
				strcpy_s(m_Name, 25, _other.m_Name);*/
				

				size_t iLength = strnlen_s(_other.m_Name, 25);

				//c++방식
				m_Name = new char[iLength + 1];
				strcpy_s(m_Name, iLength + 1, _other.m_Name);

			}
			else
			{
				m_Name = nullptr;
			}

		}
		return *this;
	}

public:
	void Destroy()
	{
		if (m_Name != nullptr)
		{
			delete[](m_Name);
			m_Name = nullptr;
		}
	}

public:
	~Man()
	{
		Destroy();
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	class Man Manyang;
	class Man James;

	Manyang.m_Name = (char*)malloc(25);
	James.m_Name = (char*)malloc(25);

	size_t iManLength = strnlen_s(Manyang.m_Name, 25);
	size_t iJamesLength = strnlen_s(James.m_Name, 25);

	strcpy_s(Manyang.m_Name, iManLength, "Manyang");
	Manyang.m_iAge = 25;

	strcpy_s(James.m_Name, iJamesLength, "James");
	James.m_iAge = 37;

	 Manyang = James;	//얕은복사

	//strcpy_s(James.m_Name, 25, Manyang.m_Name);	
	//문자열만 복사한거다 새 메모리를  할당한건 아니라는거
	//해당 NAME만 다른 메모리를 가리키데 되어 free햇을때 오류가 나지 않는다.
	//깊은복사는 객체의 새로운 복사본을 생성한다 
	//strcpy_s는 문자열을 복사할때 새메모리를 할당하지 않으므로 깊은복사가 아니다.

	 //HEAP CORRUPTION DETECTED 
	 // 에러의 원인은malloc이나 new로 할당한 메모리의 영역보다 더 큰 영역에 접근하고자 했기 때문이다.
		
	 iManLength = 0;

	 iManLength = strnlen_s(Manyang.m_Name, 25);

	strcpy_s(Manyang.m_Name, iManLength, "tEST");

	std::cout << Manyang.m_Name << " " << Manyang.m_iAge << std::endl;
	std::cout << James.m_Name << " " << James.m_iAge << std::endl;



	
	return 0;

}