#include <iostream>

typedef struct FStudent
{

	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
	char Name[10];

public:
	void PrintStudent()
	{
		std::cout << "학생 출력프로그램 " << std::endl;
	}

	void Initial(const char* name)
	{
		int iSize = 0;
		iKor = 0;
		iEng = 0;
		iMath = 0;
		fAvg = 0.f;
		iTotal = 0;
		//문자복사 
		iSize = strlen(name) + 1;
		strcpy_s(Name, iSize, name);
	}

	void StudentStudy()
	{
		std::cout << Name << "님이 공부하고 있습니다" << std::endl;
	}
}MYStudent;


struct Teacher
{
public:
	int ClassNumber;
	char Name[25];
	char Subject[25];


	void Initial(const char* name,const char* subname)  
	{
		int iSize = 0;
		
		//문자복사 
		iSize = strlen(name) + 1;
		strcpy_s(Name, iSize, name);

		iSize = 0;
		iSize = strlen(subname) + 1;
		strcpy_s(Subject, iSize, subname);
	}

	void IntroduceTC()
	{
		std::cout << Name << "선생님 안녕하세요 " << std::endl;
		std::cout << Subject << "과목을 가르키는 선생님 입니다" << std::endl;
	}

	void StudentCall(const char* name)
	{
		std::cout << Name << "선생님이 " << name << "학생을 부르고 있습니다" << std::endl;
	}
};

int main()
{
	//구조체란? 
	//다른 데이터(자료형)한번 묶어준다. 배열 같은경우에는 같은 데이터(자료형) 끼리 묶을수 있는데 구조체는 여러가지 데이터를 묶을수 있다.

	//c++에서는 구조체대신 클래스를 사용한다. 
	//둘의 차이점이 있다.
	//접근지정자를 지정해주지 않을때 
	//구조체는 public , 클래스는 private가 된다.

	//접근지정자
	//public,priavte,protected

	//public은 모두공유(외부 접근가능)
	//private 내 해당 객체만 공유 안정성이 어느정도 보장(외부 접근 불가능)
	//protected 상속끼리 공유 구조체는 사용 불가능

	//예전에는 구조체를 만들때 모두 초기화를 해줘야 됬다.
	//예전처럼 돌릴려면 프로젝트 속성에서 c,c++ -> 고급 -> c컴파일러로 변경해주면 c언어 전용 구조체로 사용할수 있다.
	
	 // MYStudent st = {0,0,0,0,0.f,"test"}; c언어방식...
	FStudent st = {};


	int iSize = sizeof(FStudent);
	
	
	st.Initial("박만냥");
	st.PrintStudent();
	st.StudentStudy();

	Teacher tc = {};

	tc.Initial("James","컴퓨터");
	tc.IntroduceTC();
	tc.StudentCall(st.Name);


	return 0;
}