#include <iostream>



class Man
{
public:
	char* m_Name;
	int m_iAge;
};

int main()
{
	class Man Manyang;
	class Man James;

	Manyang.m_Name = (char*)malloc(25);
	James.m_Name = (char*)malloc(25);

	
	strcpy_s(Manyang.m_Name, 25, "Manyang");
	Manyang.m_iAge = 25;

	strcpy_s(James.m_Name, 25, "James");
	James.m_iAge = 37;

	//Manyang = James;	//얕은복사

	strcpy_s(James.m_Name, 25, Manyang.m_Name);	
	//문자열만 복사한거다 새 메모리를  할당한건 아니라는거
	//해당 NAME만 다른 메모리를 가리키데 되어 free햇을때 오류가 나지 않는다.
	//깊은복사는 객체의 새로운 복사본을 생성한다 
	//strcpy_s는 문자열을 복사할때 새메모리를 할당하지 않으므로 깊은복사가 아니다.


	strcpy_s(Manyang.m_Name, 25, "tEST");

	std::cout << Manyang.m_Name << " " << Manyang.m_iAge << std::endl;
	std::cout << James.m_Name << " " << James.m_iAge << std::endl;


	if (Manyang.m_Name != nullptr)
	{
		free(Manyang.m_Name);
		Manyang.m_Name = nullptr;
	}
	if (James.m_Name != nullptr)
	{
		free(James.m_Name);
		James.m_Name = nullptr;
	}

	
	
	
	return 0;

}