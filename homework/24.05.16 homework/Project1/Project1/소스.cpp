#include <iostream>
#include <string.h>



enum class JOBCLASS
{
	WARRIOR =1,
	MARTIAL_ARTIST,
	GUNNER,
	MAGE,
	ASSASSIN,
	SPECIALIST,
};

enum class WARRIOR
{
	BERSERKER=1,
	PALADIN,
	GUNLANCER,
	DESTROYER,
	SLAYER,
};
enum class MARTIAL_ARTIST
{
	STRIKER= 1,
	WARDANCER,
	SCRAPPER,
	SOULFIST,
	GLAIVER,
	BREAKER,
};
enum class GUNNER
{
	GUNSLINGER =1,
	ARTILLERIST,
	DEADEYE,
	SHARPSHOOTER,
	MACHINIST,
};
enum class MAGE
{
	BARD =1,
	SORCERESS,
	ARCANIST,
	SUMMONER,
};
enum class ASSASSIN
{
	SOULEATER =1,
	REAPER,
	DEATHBLADE,
	SHADOWHUNTER,
};
enum class SPECIALIST
{
	ARTIST =1,
	AEROMANCER,
};


enum class food
{
	KIMCHI_FRIED_RICE = 1,
	OMURICE,
	MANJU,
	TAKOYAKI,
	SPAGHETTI,
};

int main()
{
	
	int iJobselect = 0;
	int iClassSelect = 0;

	int iHP = 0;
	int iMP = 0;
	int iAttack = 0;
	int iDeffence = 0;
	std::string sID = "";

	std::cout << "클래스를 선택해주세요" << std::endl;
	


	std::cout << "1.전사" << std::endl;
	std::cout << "2.무도가" << std::endl;
	std::cout << "3.거너" << std::endl;
	std::cout << "4.마법사" << std::endl;
	std::cout << "5.도적" << std::endl;
	std::cout << "6.스페셜리스트" << std::endl;
	std::cin >> iJobselect;

	system("cls");


	

	switch ((JOBCLASS)iJobselect)
	{
	case JOBCLASS::WARRIOR:
	{
		std::cout << "1.버서커" << std::endl;
		std::cout << "2.홀리라이트" << std::endl;
		std::cout << "3.워로드" << std::endl;
		std::cout << "4.디트" << std::endl;
		std::cout << "5.슬레이어" << std::endl;
		std::cin >> iClassSelect;

	}

		break;
	case JOBCLASS::MARTIAL_ARTIST:
		break;
	case JOBCLASS::GUNNER:
		break;
	case JOBCLASS::MAGE:
		break;
	case JOBCLASS::ASSASSIN:
		break;
	case JOBCLASS::SPECIALIST:
		break;
	default:
		break;
	}

	system("cls");

	std::cout << "아이디를 입력해주세요 " << std::endl;
	std::cin >> sID;

	system("cls");

	std::cout << sID << " 모험가님 환영 합니다 " << std::endl;



	//직업 세팅 
	if (iJobselect == 1)//워리어
	{


		if (iClassSelect == (int)WARRIOR::BERSERKER)
		{
			iHP = 1000;
			iMP = 0;
			iAttack = 500;
			iDeffence = 100;
		}
		else if (iClassSelect == (int)WARRIOR::PALADIN)
		{
			iHP = 10000;
			iMP = 20;
			iAttack = 10000;
			iDeffence = 200;
		}
		else if (iClassSelect == (int)WARRIOR::GUNLANCER)
		{
			iHP = 100000;
			iMP = 100;
			iAttack = 10;
			iDeffence = 5000;
		}
	
		else if (iClassSelect == (int)WARRIOR::DESTROYER)
		{
			iHP = 1000;
			iMP = 0;
			iAttack = 500;
			iDeffence = 100;
		}
		else if (iClassSelect == (int)WARRIOR::SLAYER)
		{
			iHP = 1000;
			iMP = 1000;
			iAttack = -50;
			iDeffence = 100;
		}
	}
	else if (iJobselect == 2) //무도가
	{

	}
	else if (iJobselect == 3) //거너
	{

	}
	else if (iJobselect == 4) //마법사
	{

	}
	else if (iJobselect == 5) //어쌔신
	{

	}
	else if (iJobselect == 6) //스페
	{

	}

	//직업 세팅 


	
	//클래스,직업 출력
	if (iJobselect == (int)JOBCLASS::WARRIOR)//워리어
	{

		
		if (iClassSelect ==(int)WARRIOR::BERSERKER )
		{
			std::cout << "직업 : 버서커 " << std::endl;
			std::cout << "체력 :" << iHP << std::endl;
			std::cout << "마나 :" << iMP << std::endl;
			std::cout << "공격력 :" << iAttack	 << std::endl;
			std::cout << "방어력 :" << iDeffence << std::endl;
		}
		else if (iClassSelect == (int)WARRIOR::PALADIN)
		{
			std::cout << "직업 : 홀리 " << std::endl;
			std::cout << "체력 :" << iHP << std::endl;
			std::cout << "마나 :" << iMP << std::endl;
			std::cout << "공격력 :" << iAttack << std::endl;
			std::cout << "방어력 :" << iDeffence << std::endl;
		}
		else if (iClassSelect == (int)WARRIOR::GUNLANCER)
		{
			std::cout << "직업 : 워로드서폿 " << std::endl;
			std::cout << "체력 :" << iHP << std::endl;
			std::cout << "마나 :" << iMP << std::endl;
			std::cout << "공격력 :" << iAttack << std::endl;
			std::cout << "방어력 :" << iDeffence << std::endl;
		}
		else if (iClassSelect == (int)WARRIOR::DESTROYER)
		{
			std::cout << "직업 : 디트 " << std::endl;
			std::cout << "체력 :" << iHP << std::endl;
			std::cout << "마나 :" << iMP << std::endl;
			std::cout << "공격력 :" << iAttack << std::endl;
			std::cout << "방어력 :" << iDeffence << std::endl;

		}
		else if (iClassSelect == (int)WARRIOR::SLAYER)
		{
			std::cout << "직업 : 슬레이어 " << std::endl;
			std::cout << "체력 :" << iHP << std::endl;
			std::cout << "마나 :" << iMP << std::endl;
			std::cout << "공격력 :" << iAttack << std::endl;
			std::cout << "방어력 :" << iDeffence << std::endl;
		}
	}
	else if (iJobselect == 2) //무도가
	{

	}
	else if (iJobselect == 3) //거너
	{

	}
	else if (iJobselect == 4) //마법사
	{

	}
	else if (iJobselect == 5) //어쌔신
	{

	}
	else if (iJobselect == 6) //스페
	{

	}
	else
	{
		std::cout << "아무것도 선택하지 않았습니다" << std::endl;
	}

	std::cout << "재밌는 모험이 되세요 !" << std::endl;

	

	/*int iChoice = 0;
	int iCal = 0;
	char cDrink = 0;

	std::string sName = "test";


	std::cout << "어떤 음식을 주문하시겠습니까?" << std::endl;
	std::cout << "1.김치볶음밥" << std::endl;
	std::cout << "2.오므라이스" << std::endl;
	std::cout << "3.만두" << std::endl;
	std::cout << "4.타코야끼" << std::endl;
	std::cout << "5.스파게티" << std::endl;
	std::cin >> iChoice;

	std::cout << "이름을 작성해주세요" << std::endl;
	std::cin >> sName;

	system("cls");

	switch ((food)iChoice)
	{
	case food::KIMCHI_FRIED_RICE:
		iCal = 482;
		break;
	case food::OMURICE:
		iCal = 314;
		break;
	case food::MANJU:
		iCal = 128;
		break;
	case food::TAKOYAKI:
		iCal = 245;
		break; 
	case food::SPAGHETTI:
		iCal = 510;
		break;

	default:
		std::cout << "주문을 해주세요"<< std::endl;
		break;
	}

	system("cls");

	if (iChoice == (int)food::KIMCHI_FRIED_RICE)
	{
		std::cout << sName << " 고객님 반갑습니다" << std::endl;
		std::cout << "김치볶음밥을 선택하셨습니다" << std::endl;
		std::cout << "칼로리 : " << iCal << std::endl;
	}
	else if (iChoice == (int)food::OMURICE)
	{
		std::cout << sName << " 고객님 반갑습니다" << std::endl;
		std::cout << "오무라이스를 선택하셨습니다" << std::endl;
		std::cout << "칼로리 : " << iCal << std::endl;
	}
	else if (iChoice == (int)food::MANJU)
	{
		std::cout << sName << " 고객님 반갑습니다" << std::endl;
		std::cout << "만두를 선택하셨습니다" << std::endl;
		std::cout << "칼로리 : " << iCal << std::endl;
	}
	else if (iChoice == (int)food::TAKOYAKI)
	{
		std::cout << sName << " 고객님 반갑습니다" << std::endl;
		std::cout << "타코야끼를 선택하셨습니다" << std::endl;
		std::cout << "칼로리 : " << iCal << std::endl;
	}
	else if (iChoice == (int)food::SPAGHETTI)
	{
		std::cout << sName << " 고객님 반갑습니다" << std::endl;
		std::cout << "스파게티를 선택하셨습니다" << std::endl;
		std::cout << "칼로리 : " << iCal << std::endl;
	}
	else
	{
		std::cout << "아무것도 선택하지 않았습니다" << std::endl;
	}*/

	return 0;
}