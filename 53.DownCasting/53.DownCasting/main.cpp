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

	virtual void SpecialAbility() = 0;	//캐릭터들만의 고유스킬 
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

public:

	 void Attack() override
	{
		std::cout << m_Job << "이 공격 하였습니다" << std::endl;
	}


	void SpecialAbility()override
	{
		std::cout << m_Job << "고유 스킬 " << m_Heal << std::endl;
	}

	void HealSkill(int _amount)
	{
		m_HealAmout += _amount;
		std::cout << "바드가 힐을 사용하였습니다" << std::endl;
		std::cout << "힐의 양이 " << m_HealAmout << " 만큼 증가 하였습니다" << std::endl;
	}

	
};