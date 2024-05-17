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


	std::cout << "¾î¶² À½½ÄÀ» ÁÖ¹®ÇÏ½Ã°Ú½À´Ï±î?" << std::endl;
	std::cout << "1.±èÄ¡ººÀ½¹ä" << std::endl;
	std::cout << "2.¿À¹Ç¶óÀÌ½º" << std::endl;
	std::cout << "3.¸¸µÎ" << std::endl;
	std::cout << "4.Å¸ÄÚ¾ß³¢" << std::endl;
	std::cout << "5.½ºÆÄ°ÔÆ¼" << std::endl;
	std::cin >> iChoice;

	std::cout << "ÀÌ¸§À» ÀÛ¼ºÇØÁÖ¼¼¿ä" << std::endl;
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
		std::cout << "ÁÖ¹®À» ÇØÁÖ¼¼¿ä"<< std::endl;
		break;
	}

	system("cls");

	if (iChoice == (int)food::KIMCHI_FRIED_RICE)
	{
		std::cout << sName << " °í°´´Ô ¹Ý°©½À´Ï´Ù" << std::endl;
		std::cout << "±èÄ¡ººÀ½¹äÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù" << std::endl;
		std::cout << "Ä®·Î¸® : " << iCal << std::endl;
	}
	if (iChoice == (int)food::OMURICE)
	{
		std::cout << sName << " °í°´´Ô ¹Ý°©½À´Ï´Ù" << std::endl;
		std::cout << "¿À¹«¶óÀÌ½º¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù" << std::endl;
		std::cout << "Ä®·Î¸® : " << iCal << std::endl;
	}
	if (iChoice == (int)food::MANJU)
	{
		std::cout << sName << " °í°´´Ô ¹Ý°©½À´Ï´Ù" << std::endl;
		std::cout << "¸¸µÎ¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù" << std::endl;
		std::cout << "Ä®·Î¸® : " << iCal << std::endl;
	}
	if (iChoice == (int)food::TAKOYAKI)
	{
		std::cout << sName << " °í°´´Ô ¹Ý°©½À´Ï´Ù" << std::endl;
		std::cout << "Å¸ÄÚ¾ß³¢¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù" << std::endl;
		std::cout << "Ä®·Î¸® : " << iCal << std::endl;
	}
	if (iChoice == (int)food::SPAGHETTI)
	{
		std::cout << sName << " °í°´´Ô ¹Ý°©½À´Ï´Ù" << std::endl;
		std::cout << "½ºÆÄ°ÔÆ¼¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù" << std::endl;
		std::cout << "Ä®·Î¸® : " << iCal << std::endl;
	}
	else
	{
		std::cout << "¾Æ¹«°Íµµ ¼±ÅÃÇÏÁö ¾Ê¾Ò½À´Ï´Ù" << std::endl;
	}

	return 0;
}