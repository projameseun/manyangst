#include <iostream>
#include <vector>

enum class SkillEnum
{
	FireBall ,
	IceArrow,	
	Heal ,
};


//기본 skill클래스 (다형성)

class Skill
{
public:
	virtual void Cast() const
	{
		std::cout << "기본 스킬을 사용 합니다" << std::endl;
	}

	virtual ~Skill()
	{

	}


};

class FireBall : public Skill
{
public:
	void Cast() const override
	{
		std::cout << "파이어볼 발동" << std::endl;
	}
};

class IceArrow: public Skill
{
public:
	void Cast() const override
	{
		std::cout << "아이스 에로우 발동" << std::endl;
	}
};


class Heal : public Skill
{
public:
	void Cast() const override
	{
		std::cout << "힐링 시전을 하였습니다" << std::endl;
	}
};


void UseSkill(Skill* skill)
{
	skill->Cast();
}


int main()
{
	FireBall fireball;
	IceArrow icearrow;
	Heal heal;

	std::vector<Skill*> skills;

	skills.push_back(&fireball);
	skills.push_back(&icearrow);
	skills.push_back(&heal);


	skills[(int)SkillEnum::FireBall]->Cast();
	skills[(int)SkillEnum::IceArrow]->Cast();
	skills[(int)SkillEnum::Heal]->Cast();

	//c++11 이상에 도입 범위기반 for문
	//for (Skill* skill : skills)
	//{
	//	UseSkill(skill);
	//}

	for (size_t i = 0; i < skills.size(); ++i)
	{
		UseSkill(skills[i]);
	}


	return 0;
}