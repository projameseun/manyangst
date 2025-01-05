#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Character
{
protected:
	string	m_Job;
	int		m_HP;

public:
	Character(const string& _name, int _hp) :
		m_Job(_name), m_HP(_hp)
	{
		
	}

	virtual ~Character()
	{

	}

public:
	virtual void Attack()
	{
		std::cout << m_Job << "이 공격 하였습니다" << std::endl;
	}

	virtual void CharacterInfo()
	{
		std::cout << "직업 : " << m_Job << "HP : " << m_HP << std::endl;
	}



	virtual void SpecialAbility() {}	//캐릭터들만의 고유스킬 
	virtual void SuperSkill() {}	//캐릭터들만의 고유스킬 
};

class Bard : public Character
{
public:
	int m_HealAmout;  //힐의양 
	string m_Heal;

public:
	Bard(const string& _name, int _hp, int _healamout, const string& _heal) :
		Character(_name, _hp), m_HealAmout(_healamout), m_Heal(_heal)
	
	{

	}

	~Bard()
	{

	}

public:

	 void Attack() override
	{
		std::cout << m_Job << "이 공격 하였습니다" << std::endl;
	}


	void SpecialAbility()override
	{
		std::cout << m_Job << "고유 스킬 " << m_Heal << std::endl;
	}

	void SuperSkill() override
	{
		std::cout << "바드 초각성 스킬" << std::endl;
	}

	void HealSkill(int _amount)
	{
		m_HealAmout += _amount;
		std::cout << "바드가 힐을 사용하였습니다" << std::endl;
		std::cout << "힐의 양이 " << m_HealAmout << " 만큼 증가 하였습니다" << std::endl;
	}

	
};

class BattleMaster : public Character
{
public :
	string m_SweepingKic;	//방천격
	string m_WindsWhisper;	//바속

public:
	BattleMaster(const string& _job, int _hp,  const string& _skill, const string& _skill2) :
		Character(_job, _hp), m_SweepingKic(_skill), m_WindsWhisper(_skill2)
	{

	}
	~BattleMaster()
	{

	}

public:
	void Attack() override
	{
		std::cout << m_Job << "이 공격 하였습니다" << std::endl;
	}


	void SpecialAbility()override
	{
		std::cout << m_Job << "고유 스킬 " << m_SweepingKic << std::endl;
		std::cout << m_Job << "고유 스킬 " << m_WindsWhisper << std::endl;
	}

	void SuperSkill() override	//초각성스킬
	{
		std::cout << "배틀마스터  초각성 스킬" << std::endl;
	}

	void Passive() 
	{
		std::cout << "배틀 마스터의 패시브 발동" << std::endl;
	}
};

void GameEngine(vector<Character*>& player)
{
	for (int i = 0; i < player.size(); ++i)
	{
		player[i]->CharacterInfo();
		player[i]->Attack();

		//다운캐스팅을 사용해서 각 고유의 캐릭터만의 스킬을 구현
		//다운캐스팅이 제대로 일어나지 않았는데 터지지 않았어
		//심지어 nullptr이 됬는데도 터지지 않았다면 기본 구현만 되어있어서 그렇다
		//만약에 변수를 넣게된다면 무조건 터지게 되어있다.
		//그리고 다이나믹 캐스팅을 사용했을때 자식의 고유함수들은 가상함수가 아닌 정적바인딩으로 만들어져있는데
		// 만약에 동적으로 만들면 터진다. 왜? 가상함수테이블이 실제 주소를 알고있는데 그 주소를 접근할수 없기때문에
		
		
		if (Bard* bard = dynamic_cast<Bard*>(player[i]))
		{
			bard->HealSkill(100);
		}
	
		
		else if (BattleMaster* master = dynamic_cast<BattleMaster*>(player[i]))
		{
			master->Passive();
		}
		
	}
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<Character*> player;

	
	player.push_back(new Bard("바드", 70,100,"힐"));
	player.push_back(new BattleMaster("배틀마스터", 100, "방천격", "바람의속삭임"));

	GameEngine(player);


	return 0;
}