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
		std::cout << m_Job << "�� ���� �Ͽ����ϴ�" << std::endl;
	}

	virtual void CharacterInfo()
	{
		std::cout << "���� : " << m_Job << "HP : " << m_HP << std::endl;
	}



	virtual void SpecialAbility() {}	//ĳ���͵鸸�� ������ų 
	virtual void SuperSkill() {}	//ĳ���͵鸸�� ������ų 
};

class Bard : public Character
{
public:
	int m_HealAmout;  //���Ǿ� 
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
		std::cout << m_Job << "�� ���� �Ͽ����ϴ�" << std::endl;
	}


	void SpecialAbility()override
	{
		std::cout << m_Job << "���� ��ų " << m_Heal << std::endl;
	}

	void SuperSkill() override
	{
		std::cout << "�ٵ� �ʰ��� ��ų" << std::endl;
	}

	void HealSkill(int _amount)
	{
		m_HealAmout += _amount;
		std::cout << "�ٵ尡 ���� ����Ͽ����ϴ�" << std::endl;
		std::cout << "���� ���� " << m_HealAmout << " ��ŭ ���� �Ͽ����ϴ�" << std::endl;
	}

	
};

class BattleMaster : public Character
{
public :
	string m_SweepingKic;	//��õ��
	string m_WindsWhisper;	//�ټ�

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
		std::cout << m_Job << "�� ���� �Ͽ����ϴ�" << std::endl;
	}


	void SpecialAbility()override
	{
		std::cout << m_Job << "���� ��ų " << m_SweepingKic << std::endl;
		std::cout << m_Job << "���� ��ų " << m_WindsWhisper << std::endl;
	}

	void SuperSkill() override	//�ʰ�����ų
	{
		std::cout << "��Ʋ������  �ʰ��� ��ų" << std::endl;
	}

	void Passive() 
	{
		std::cout << "��Ʋ �������� �нú� �ߵ�" << std::endl;
	}
};

void GameEngine(vector<Character*>& player)
{
	for (int i = 0; i < player.size(); ++i)
	{
		player[i]->CharacterInfo();
		player[i]->Attack();

		//�ٿ�ĳ������ ����ؼ� �� ������ ĳ���͸��� ��ų�� ����
		//�ٿ�ĳ������ ����� �Ͼ�� �ʾҴµ� ������ �ʾҾ�
		//������ nullptr�� ��µ��� ������ �ʾҴٸ� �⺻ ������ �Ǿ��־ �׷���
		//���࿡ ������ �ְԵȴٸ� ������ ������ �Ǿ��ִ�.
		//�׸��� ���̳��� ĳ������ ��������� �ڽ��� �����Լ����� �����Լ��� �ƴ� �������ε����� ��������ִµ�
		// ���࿡ �������� ����� ������. ��? �����Լ����̺��� ���� �ּҸ� �˰��ִµ� �� �ּҸ� �����Ҽ� ���⶧����
		
		
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

	
	player.push_back(new Bard("�ٵ�", 70,100,"��"));
	player.push_back(new BattleMaster("��Ʋ������", 100, "��õ��", "�ٶ��Ǽӻ���"));

	GameEngine(player);


	return 0;
}