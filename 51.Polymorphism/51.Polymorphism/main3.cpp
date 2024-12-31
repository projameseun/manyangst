#include <iostream>
#include <vector>



//순수가상함수를 사용해서 만들어 보겠음

class Skill
{
public:
	virtual void Use() = 0;		//순수 가상함수 (자식에서 재정의를 하겠다는 의미가 있음)
	virtual ~Skill() {};	//가상 소멸자 

	
};

//공격 스킬 클래스
class AttackSkill : public Skill
{
public:
	void Use() override
	{
		std::cout << "공격 스킬 " << std::endl;
	}
};

//치유 스킬 클래스
class HealSkill : public Skill
{
public:
	void Use() override
	{
		std::cout << "치유 스킬 " << std::endl;
	}
};

//방어 스킬 클래스
class DeffenceSkill : public Skill
{
public:
	void Use() override
	{
		std::cout << "방어 스킬 " << std::endl;
	}
};

//스킬을 사용할 캐릭터 클래스

class Character
{
private:
	std::vector<Skill*> skills;	//캐릭터가 가질 스킬들
	
public:
	//스킬 추가
	void AddSkill(Skill* _skill)
	{
		skills.push_back(_skill);
	}
	
	//스킬 사용
	void UseSkills(int _num)
	{
		for (int i = 0; i < skills.size(); ++i)
		{
			if (i == _num - 1)
			{
				skills[i]->Use();
			}
		}
	}

public:
	~Character()
	{
		for (int i = 0; i < skills.size(); ++i)
		{
			delete skills[i];
		}
	}
};

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Character player;

	//스킬추가
	player.AddSkill(new AttackSkill());
	player.AddSkill(new HealSkill());
	player.AddSkill(new DeffenceSkill());



	while (true)
	{
		system("cls");
		std::cout << "<==========스킬 사용법 ============>" << std::endl;
		std::cout << "1.공격스킬 " << std::endl;
		std::cout << "2.힐스킬" << std::endl;
		std::cout << "3.방어스킬" << std::endl;
		std::cout << "-99.게임종료" << std::endl;

		int iNumber = 0;

		std::cin >> iNumber;
		getchar();
		if (iNumber == -99)
		{
			
			std::cout << "이용해 주셔서 감사합니다 " << std::endl;
			getchar();
			break;
		}

		if (iNumber >= 0 && iNumber <= 3)
		{
			player.UseSkills(iNumber);
	;		

		}
		else
		{
			std::cout << "스킬을 제대로 입력 해주세요" << std::endl;
		
			
			
		}

		getchar();
	}

	return 0;
}