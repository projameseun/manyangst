#include <iostream>
#include <string.h>

namespace TYPEA
{

	enum ACar
	{
		AUDI = 1,
		BENZ,
		PHORCSHE,
		BMW,
		HYUNDAI,
		SAMSUNG,
	};
}

namespace TYPEB
{
	enum BCar
	{
		TOYOTA = 1,
		BENZ,
		SAMSUNG,
		PHORCSHE,
	};

}


enum class JOB
{
	GUNSLINGER =1,
	BARD,
	BATTLEMASTER,
	BERSERKER,
};

enum class JOB2
{
	GUNSLINGER = 1,
	BARD,
	INFIGHTER,
	BATTLEMASTER,
};








int main()
{
	/*
		switch(변수)
		{
			case 값(상수):
			코드
			break; break를 만나면 switch문을 나간다 
			case 값(상수):
			코드
			break break를 만나면 switch문을 나간다 
			....
			....
			....
			default: 위에 case를 모두 체크하고 다 넘어오게되면 들어온다. else와 같은 역할 
			break;




		}

		if랑 switch는 매우 비슷하다
		어떤걸 사용해도 무방하다.
		굳이 둘의 차이점을 얘기하면 속도의 차이가 있다 그런데 큰 차이가 없다..
		조건 검사가 2~3일때는 if가 빠르다. 조건검사가 많은경우에는 switch가 좀더 빠르다.
		그런더 이시간이 대략 0.4초 정도 밖에 안된다. 성능에 문제가 전혀 생기지 않는다.
	
	*/

	int iRoomNum = 3;

	
	std::cout << "<보고싶은 차를 선택해주세요> " << std::endl;
	std::cout << "1.아우디 2.벤츠 3.포르쉐 4.비엠더블유 5.나가기" << std::endl;

	std::cin >> iRoomNum;

	system("cls");


	switch (iRoomNum)
	{
	case TYPEA::AUDI:
		std::cout << "아우디 입니다" << std::endl;
		break;
	case TYPEB::BENZ:
		std::cout << "벤츠 입니다" << std::endl;
		break;
	case TYPEA::PHORCSHE:
		std::cout << "포르쉐 입니다" << std::endl;
		break;
	case TYPEA::BMW:
		std::cout << "비엠더블유 입니다" << std::endl;
		break;
	case TYPEA::HYUNDAI:
		std::cout << "현대 입니다" << std::endl;
		break;
	case TYPEA::SAMSUNG:
		std::cout << "삼성 입니다" << std::endl;
		break;
	default:
		std::cout << "손님이 떠났습니다" << std::endl;
		break;
	}

	//emum(열거형)
	//숫자에 이름을 부여하는 기능이다.
	//연속으로 나열된 숫자에 이름을 붙여줄때 사용할수 있다.
	/*
		enum 열거명 
		{

		};
		enum의 장점
		숫자를 문자로 표현 할수 있다. 사이트들어 갈때 아이피를 사용하지않고 dns를 사용해서 들어가는 거의 비슷하다.
		
		enum의 문제점
		별도의 이름공간(namespace)를 가지고 있지 않다는것
		enum를 사용하다 보면 중복되는게 나오게 된다. 오류를 범하게 되는데 사용자가 접두어,접미어에 타입을 붙여서 이름을 구분할수도 있지만 
		그것은 사용자가 임의의 변수이름을 잘 구분해서 지정하게 된거다.

		enum class(c++11)
		enum class가 나오게 된이유 : enum은 별도의 이름공간(namespcae)가 존재 하지 않는다.
		enum을 여러개 사용 하다보면 이름이 중복되는게 분명히 나온다.
		enum을 정확하게 구분하기 위해서 enum class가 도입된다고 한다.

	*/

	system("cls");

	int iJob = 0;
	int iAttack = 0, iDeffence = 0, iHP = 0, iMP =0;

	std::string sName = "test";
	

	std::cout << "<=========직업을 선택해주세요========>" << std::endl;
	std::cout << "1.건슬링어" << std::endl;
	std::cout << "2.바드" << std::endl;
	std::cout << "3.배틀마스터" << std::endl;
	std::cout << "4.버서커" << std::endl;
	std::cin >> iJob;

	system("cls");
	std::cout << "아이디를 적어주세요" << std::endl;
	std::cin >> sName;

	
	//switch 자동으로 열거만들기
	//switch를 자동완성한다 그다음 내가만든 이넘클래스를 하나 입력하고 ctrl + enter를 하면 자동으로 만들어진다
	switch ((JOB)iJob)
	{
	case JOB::GUNSLINGER:
		iAttack = 70;
		iDeffence = 20;
		iHP = 500;
		iMP = 1000;
		break;
	case JOB::BARD:
		break;
	case JOB::BATTLEMASTER:
		break;
	case JOB::BERSERKER:
		break;
	default:
		std::cout << "직업을 선택해주세요 " << std::endl;
		break;
	}


	if (iJob == (int)JOB::GUNSLINGER)
	{
		std::cout << sName <<" 모험가님 방갑습니다 " << std::endl;
		std::cout << "건슬링어를 선택 하셨습니다 " << std::endl;
		std::cout << "공격력 : "<< iAttack << std::endl;
		std::cout << "방어력 : "  << iDeffence << std::endl;
		std::cout << "체력 : " << iHP << std::endl;
		std::cout << "마나 : " << iMP<< std::endl;
	}
	else
	{
		std::cout << "아무것도 선택하지 않았습니다" << std::endl;
	}

	return 0;
}