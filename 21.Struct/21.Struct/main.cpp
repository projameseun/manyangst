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
		std::cout << "�л� ������α׷� " << std::endl;
	}

	void Initial(const char* name)
	{
		int iSize = 0;
		iKor = 0;
		iEng = 0;
		iMath = 0;
		fAvg = 0.f;
		iTotal = 0;
		//���ں��� 
		iSize = strlen(name) + 1;
		strcpy_s(Name, iSize, name);
	}

	void StudentStudy()
	{
		std::cout << Name << "���� �����ϰ� �ֽ��ϴ�" << std::endl;
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
		
		//���ں��� 
		iSize = strlen(name) + 1;
		strcpy_s(Name, iSize, name);

		iSize = 0;
		iSize = strlen(subname) + 1;
		strcpy_s(Subject, iSize, subname);
	}

	void IntroduceTC()
	{
		std::cout << Name << "������ �ȳ��ϼ��� " << std::endl;
		std::cout << Subject << "������ ����Ű�� ������ �Դϴ�" << std::endl;
	}

	void StudentCall(const char* name)
	{
		std::cout << Name << "�������� " << name << "�л��� �θ��� �ֽ��ϴ�" << std::endl;
	}
};

int main()
{
	//����ü��? 
	//�ٸ� ������(�ڷ���)�ѹ� �����ش�. �迭 ������쿡�� ���� ������(�ڷ���) ���� ������ �ִµ� ����ü�� �������� �����͸� ������ �ִ�.

	//c++������ ����ü��� Ŭ������ ����Ѵ�. 
	//���� �������� �ִ�.
	//���������ڸ� ���������� ������ 
	//����ü�� public , Ŭ������ private�� �ȴ�.

	//����������
	//public,priavte,protected

	//public�� ��ΰ���(�ܺ� ���ٰ���)
	//private �� �ش� ��ü�� ���� �������� ������� ����(�ܺ� ���� �Ұ���)
	//protected ��ӳ��� ���� ����ü�� ��� �Ұ���

	//�������� ����ü�� ���鶧 ��� �ʱ�ȭ�� ����� ���.
	//����ó�� �������� ������Ʈ �Ӽ����� c,c++ -> ��� -> c�����Ϸ��� �������ָ� c��� ���� ����ü�� ����Ҽ� �ִ�.
	
	 // MYStudent st = {0,0,0,0,0.f,"test"}; c�����...
	FStudent st = {};


	int iSize = sizeof(FStudent);
	
	
	st.Initial("�ڸ���");
	st.PrintStudent();
	st.StudentStudy();

	Teacher tc = {};

	tc.Initial("James","��ǻ��");
	tc.IntroduceTC();
	tc.StudentCall(st.Name);


	return 0;
}