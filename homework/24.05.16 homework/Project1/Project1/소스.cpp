#include <iostream>
#include <string.h>
/*
enum class WARRIOR
{
	BERSERKER,
	PALADIN,
	GUNLANCER,
	DESTROYER,
	SLAYER,
};
enum class MARTIAL_ARTIST
{
	STRIKER,
	WARDANCER,
	SCRAPPER,
	SOULFIST,
	GLAIVER,
	BREAKER,
};
enum class GUNNER
{
	GUNSLINGER,
	ARTILLERIST,
	DEADEYE,
	SHARPSHOOTER,
	MACHINIST,
};
enum class MAGE
{
	BARD,
	SORCERESS,
	ARCANIST,
	SUMMONER,
};
enum class ASSASSIN
{
	SOULEATER,
	REAPER,
	DEATHBLADE,
	SHADOWHUNTER,
};
enum class SPECIALIST
{
	ARTIST,
	AEROMANCER,
};
*/

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
	system("cls");

	int iChoice = 0;
	int iCal = 0;
	char cDrink = 0;

	std::string sName = "test";


	std::cout << "� ������ �ֹ��Ͻðڽ��ϱ�?" << std::endl;
	std::cout << "1.��ġ������" << std::endl;
	std::cout << "2.���Ƕ��̽�" << std::endl;
	std::cout << "3.����" << std::endl;
	std::cout << "4.Ÿ�ھ߳�" << std::endl;
	std::cout << "5.���İ�Ƽ" << std::endl;
	std::cin >> iChoice;

	std::cout << "�̸��� �ۼ����ּ���" << std::endl;
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
		std::cout << "�ֹ��� ���ּ���"<< std::endl;
		break;
	}

	system("cls");

	if (iChoice == (int)food::KIMCHI_FRIED_RICE)
	{
		std::cout << sName << " ���� �ݰ����ϴ�" << std::endl;
		std::cout << "��ġ�������� �����ϼ̽��ϴ�" << std::endl;
		std::cout << "Į�θ� : " << iCal << std::endl;
	}
	if (iChoice == (int)food::OMURICE)
	{
		std::cout << sName << " ���� �ݰ����ϴ�" << std::endl;
		std::cout << "�������̽��� �����ϼ̽��ϴ�" << std::endl;
		std::cout << "Į�θ� : " << iCal << std::endl;
	}
	if (iChoice == (int)food::MANJU)
	{
		std::cout << sName << " ���� �ݰ����ϴ�" << std::endl;
		std::cout << "���θ� �����ϼ̽��ϴ�" << std::endl;
		std::cout << "Į�θ� : " << iCal << std::endl;
	}
	if (iChoice == (int)food::TAKOYAKI)
	{
		std::cout << sName << " ���� �ݰ����ϴ�" << std::endl;
		std::cout << "Ÿ�ھ߳��� �����ϼ̽��ϴ�" << std::endl;
		std::cout << "Į�θ� : " << iCal << std::endl;
	}
	if (iChoice == (int)food::SPAGHETTI)
	{
		std::cout << sName << " ���� �ݰ����ϴ�" << std::endl;
		std::cout << "���İ�Ƽ�� �����ϼ̽��ϴ�" << std::endl;
		std::cout << "Į�θ� : " << iCal << std::endl;
	}
	else
	{
		std::cout << "�ƹ��͵� �������� �ʾҽ��ϴ�" << std::endl;
	}

	return 0;
}