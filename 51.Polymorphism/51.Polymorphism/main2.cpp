#include <iostream>
#include <vector>

enum class SkillEnum
{
	FireBall ,
	IceArrow,	
	Heal ,
};


//�⺻ skillŬ���� (������)

class Skill
{
public:
	virtual void Cast() const
	{
		std::cout << "�⺻ ��ų�� ��� �մϴ�" << std::endl;
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
		std::cout << "���̾ �ߵ�" << std::endl;
	}
};

class IceArrow: public Skill
{
public:
	void Cast() const override
	{
		std::cout << "���̽� ���ο� �ߵ�" << std::endl;
	}
};


class Heal : public Skill
{
public:
	void Cast() const override
	{
		std::cout << "���� ������ �Ͽ����ϴ�" << std::endl;
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

	//c++11 �̻� ���� ������� for��
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