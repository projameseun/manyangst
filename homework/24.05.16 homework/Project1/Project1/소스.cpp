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

	std::cout << "Ŭ������ �������ּ���" << std::endl;
	


	std::cout << "1.����" << std::endl;
	std::cout << "2.������" << std::endl;
	std::cout << "3.�ų�" << std::endl;
	std::cout << "4.������" << std::endl;
	std::cout << "5.����" << std::endl;
	std::cout << "6.����ȸ���Ʈ" << std::endl;
	std::cin >> iJobselect;

	system("cls");


	

	switch ((JOBCLASS)iJobselect)
	{
	case JOBCLASS::WARRIOR:
	{
		std::cout << "1.����Ŀ" << std::endl;
		std::cout << "2.Ȧ������Ʈ" << std::endl;
		std::cout << "3.���ε�" << std::endl;
		std::cout << "4.��Ʈ" << std::endl;
		std::cout << "5.�����̾�" << std::endl;
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

	std::cout << "���̵� �Է����ּ��� " << std::endl;
	std::cin >> sID;

	system("cls");

	std::cout << sID << " ���谡�� ȯ�� �մϴ� " << std::endl;



	//���� ���� 
	if (iJobselect == 1)//������
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
	else if (iJobselect == 2) //������
	{

	}
	else if (iJobselect == 3) //�ų�
	{

	}
	else if (iJobselect == 4) //������
	{

	}
	else if (iJobselect == 5) //��ؽ�
	{

	}
	else if (iJobselect == 6) //����
	{

	}

	//���� ���� 


	
	//Ŭ����,���� ���
	if (iJobselect == (int)JOBCLASS::WARRIOR)//������
	{

		
		if (iClassSelect ==(int)WARRIOR::BERSERKER )
		{
			std::cout << "���� : ����Ŀ " << std::endl;
			std::cout << "ü�� :" << iHP << std::endl;
			std::cout << "���� :" << iMP << std::endl;
			std::cout << "���ݷ� :" << iAttack	 << std::endl;
			std::cout << "���� :" << iDeffence << std::endl;
		}
		else if (iClassSelect == (int)WARRIOR::PALADIN)
		{
			std::cout << "���� : Ȧ�� " << std::endl;
			std::cout << "ü�� :" << iHP << std::endl;
			std::cout << "���� :" << iMP << std::endl;
			std::cout << "���ݷ� :" << iAttack << std::endl;
			std::cout << "���� :" << iDeffence << std::endl;
		}
		else if (iClassSelect == (int)WARRIOR::GUNLANCER)
		{
			std::cout << "���� : ���ε弭�� " << std::endl;
			std::cout << "ü�� :" << iHP << std::endl;
			std::cout << "���� :" << iMP << std::endl;
			std::cout << "���ݷ� :" << iAttack << std::endl;
			std::cout << "���� :" << iDeffence << std::endl;
		}
		else if (iClassSelect == (int)WARRIOR::DESTROYER)
		{
			std::cout << "���� : ��Ʈ " << std::endl;
			std::cout << "ü�� :" << iHP << std::endl;
			std::cout << "���� :" << iMP << std::endl;
			std::cout << "���ݷ� :" << iAttack << std::endl;
			std::cout << "���� :" << iDeffence << std::endl;

		}
		else if (iClassSelect == (int)WARRIOR::SLAYER)
		{
			std::cout << "���� : �����̾� " << std::endl;
			std::cout << "ü�� :" << iHP << std::endl;
			std::cout << "���� :" << iMP << std::endl;
			std::cout << "���ݷ� :" << iAttack << std::endl;
			std::cout << "���� :" << iDeffence << std::endl;
		}
	}
	else if (iJobselect == 2) //������
	{

	}
	else if (iJobselect == 3) //�ų�
	{

	}
	else if (iJobselect == 4) //������
	{

	}
	else if (iJobselect == 5) //��ؽ�
	{

	}
	else if (iJobselect == 6) //����
	{

	}
	else
	{
		std::cout << "�ƹ��͵� �������� �ʾҽ��ϴ�" << std::endl;
	}

	std::cout << "��մ� ������ �Ǽ��� !" << std::endl;

	

	/*int iChoice = 0;
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
	else if (iChoice == (int)food::OMURICE)
	{
		std::cout << sName << " ���� �ݰ����ϴ�" << std::endl;
		std::cout << "�������̽��� �����ϼ̽��ϴ�" << std::endl;
		std::cout << "Į�θ� : " << iCal << std::endl;
	}
	else if (iChoice == (int)food::MANJU)
	{
		std::cout << sName << " ���� �ݰ����ϴ�" << std::endl;
		std::cout << "���θ� �����ϼ̽��ϴ�" << std::endl;
		std::cout << "Į�θ� : " << iCal << std::endl;
	}
	else if (iChoice == (int)food::TAKOYAKI)
	{
		std::cout << sName << " ���� �ݰ����ϴ�" << std::endl;
		std::cout << "Ÿ�ھ߳��� �����ϼ̽��ϴ�" << std::endl;
		std::cout << "Į�θ� : " << iCal << std::endl;
	}
	else if (iChoice == (int)food::SPAGHETTI)
	{
		std::cout << sName << " ���� �ݰ����ϴ�" << std::endl;
		std::cout << "���İ�Ƽ�� �����ϼ̽��ϴ�" << std::endl;
		std::cout << "Į�θ� : " << iCal << std::endl;
	}
	else
	{
		std::cout << "�ƹ��͵� �������� �ʾҽ��ϴ�" << std::endl;
	}*/

	return 0;
}