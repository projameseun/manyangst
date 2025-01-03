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

	virtual void SpecialAbility() = 0;	//ĳ���͵鸸�� ������ų 
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

public:

	 void Attack() override
	{
		std::cout << m_Job << "�� ���� �Ͽ����ϴ�" << std::endl;
	}


	void SpecialAbility()override
	{
		std::cout << m_Job << "���� ��ų " << m_Heal << std::endl;
	}

	void HealSkill(int _amount)
	{
		m_HealAmout += _amount;
		std::cout << "�ٵ尡 ���� ����Ͽ����ϴ�" << std::endl;
		std::cout << "���� ���� " << m_HealAmout << " ��ŭ ���� �Ͽ����ϴ�" << std::endl;
	}

	
};