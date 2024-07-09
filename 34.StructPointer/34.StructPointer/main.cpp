#include <iostream>

//구조체와 포인터..
typedef struct Player
{
private:
	int iHP;
	int iMP;
	int iAttack;
	int iDeffence;
	float fSpeed;

public:
	void Init()
	{
		iHP = 100;
		iMP = 100;
		iAttack = 10;
		iDeffence = 50;
		fSpeed = 10.f;
	}

	void Attack()
	{
		std::cout << "Player Attack" << std::endl;
	}

	void Die()
	{
		std::cout << "Player DIE" << std::endl;
	}

	void Running()
	{
		std::cout << "Player Running " << std::endl;
	}

	void PlayerInfo(int hp, int mp)
	{
		std::cout << "Player  " << std::endl;
		std::cout << "HP : " << hp << std::endl;
		std::cout << "MP : " << mp << std::endl;
		std::cout << "ATTACK : " << iAttack << std::endl;
		std::cout << "DEFFENCE : " << iDeffence << std::endl;
		std::cout << "SPEED : " << fSpeed << std::endl;
	}

	int GetHP()
	{
		return iHP;
	}

	int GetMP()
	{
		return iMP;
	}

	void SetHP(int hp)
	{
		iHP = hp;
	}
	
	void SetMP(int mp)
	{
		iMP = mp;
	}


	
}MYPLAYER;


int main()
{
	MYPLAYER Player = {};

	Player.Init();
	Player.Attack();

	MYPLAYER* pPlayer = &Player;

	//(*pPlayer).GetHP();
	std::cout << pPlayer->GetHP() << std::endl;
	
	system("cls");


	Player.PlayerInfo(Player.GetHP(), Player.GetMP());
	
	pPlayer->SetHP(50);

	Player.PlayerInfo(Player.GetHP(), Player.GetMP());

	std::cout << (*pPlayer).GetHP() << std::endl;
	std::cout << (*pPlayer).GetMP() << std::endl;



	return 0;
}