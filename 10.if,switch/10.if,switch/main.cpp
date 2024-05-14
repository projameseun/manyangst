#include <iostream>

int main()
{
	/*
		조건문:if , switch
		조건문이란? 어떤 특정 조건식을 부여하고 해당 조건을 만족하면 지정한 문장을 수행하는 문법
		if문
		if(조건식)
		{

		}코드블럭

		조건식이 true이면 코드블럭이 실행이 되고, false면 if 조건문을 나가게 된다.

	*/

	if (true)
	{
		std::cout << "진실 입니다" << std::endl;
	}
	if (false)
	{
		std::cout << "거짓 입니다" << std::endl;
	}

	/*
		else:if문과 같이 사용할수 있다.
		if문 1개당 else가 올 수 있다.
		else는 독립적으로 사용이 불가능하다.
	*/

	int iNumber = 300;

	if (iNumber == 100)
	{
		std::cout << "iNumber = " << iNumber << std::endl;
	}
	else
	{
		std::cout << "iNumber는 100 이아닙니다 " << std::endl;
	}

	/*
		else if: if문 아래올수 있다. else와 다르게 여러개를 만들수 있다.
		else if는 독립적으로 사용이 불가능 하다.
	*/

	int iEchidnaHP = 100000;

	int iDamage = 99000;
	;

	iEchidnaHP -= iDamage;

	if (iEchidnaHP <= 100000 && iEchidnaHP > 80000)
	{
		std::cout << "1번째 이벤트 발생" << std::endl;
	}
	else if (iEchidnaHP <= 80000 && iEchidnaHP > 50000)
	{
		std::cout << "2번째 이벤트 발생" << std::endl;
	}
	else if (iEchidnaHP <= 50000 && iEchidnaHP > 1300)
	{
		std::cout << "3번째 이벤트 발생" << std::endl;
	}
	else if (iEchidnaHP <= 1300 && iEchidnaHP > 200)
	{
		std::cout << "4번째 이벤트 발생" << std::endl;
	}
	else
	{
		std::cout << "5번째 이벤트 발생" << std::endl;
	}

	//학생 평균 프로그램
	
	int iKOR = 0;
	int iENG = 0;
	int iMATH = 0;
	int iTOTAL = 0;


	float fAVG = 0.f;
	
	//화면을 지워주는 함수 windows.h
	system("cls");

	std::cout << "국어점수 : ";
	std::cin >> iKOR;
	system("cls");
	std::cout << "영어점수 : ";
	std::cin >> iENG;
	system("cls");
	std::cout << "수학점수 : ";
	std::cin >> iMATH;
	system("cls");

	std::cout << "국어 점수 :" << iKOR << std::endl;
	std::cout << "영어 점수 :" << iENG << std::endl;
	std::cout << "수학 점수 :" << iMATH << std::endl;
	
	iTOTAL = iKOR + iENG + iMATH;

	fAVG = iTOTAL / 3.f;

	std::cout << "평균 점수 : " << static_cast<int>(fAVG) << "입니다" << std::endl;

	if (fAVG >= 90.f)
	{
		std::cout << "축하 합니다 A입니다" << std::endl;
	}
	else if (fAVG >= 80.f && fAVG < 90.f)
	{
		std::cout << "축하 합니다 B입니다" << std::endl;
	}
	else if (fAVG >= 70.f && fAVG < 80.f)
	{
		std::cout << "축하 합니다 C입니다" << std::endl;
	}
	else
	{
		std::cout << "D입니다 분발 하세요!" << std::endl;
	}
 

	

	return 0;
}