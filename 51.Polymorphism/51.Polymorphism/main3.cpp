#include <iostream>
#include <vector>



//���������Լ��� ����ؼ� ����� ������

class Skill
{
public:
	virtual void Use() = 0;		//���� �����Լ� (�ڽĿ��� �����Ǹ� �ϰڴٴ� �ǹ̰� ����)
	virtual ~Skill() {};	//���� �Ҹ��� 

	
};

//���� ��ų Ŭ����
class AttackSkill : public Skill
{
public:
	void Use() override
	{
		std::cout << "���� ��ų " << std::endl;
	}
};

//ġ�� ��ų Ŭ����
class HealSkill : public Skill
{
public:
	void Use() override
	{
		std::cout << "ġ�� ��ų " << std::endl;
	}
};

//��� ��ų Ŭ����
class DeffenceSkill : public Skill
{
public:
	void Use() override
	{
		std::cout << "��� ��ų " << std::endl;
	}
};

//��ų�� ����� ĳ���� Ŭ����

class Character
{
private:
	std::vector<Skill*> skills;	//ĳ���Ͱ� ���� ��ų��
	
public:
	//��ų �߰�
	void AddSkill(Skill* _skill)
	{
		skills.push_back(_skill);
	}
	
	//��ų ���
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

	//��ų�߰�
	player.AddSkill(new AttackSkill());
	player.AddSkill(new HealSkill());
	player.AddSkill(new DeffenceSkill());



	while (true)
	{
		system("cls");
		std::cout << "<==========��ų ���� ============>" << std::endl;
		std::cout << "1.���ݽ�ų " << std::endl;
		std::cout << "2.����ų" << std::endl;
		std::cout << "3.��ų" << std::endl;
		std::cout << "-99.��������" << std::endl;

		int iNumber = 0;

		std::cin >> iNumber;
		getchar();
		if (iNumber == -99)
		{
			
			std::cout << "�̿��� �ּż� �����մϴ� " << std::endl;
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
			std::cout << "��ų�� ����� �Է� ���ּ���" << std::endl;
		
			
			
		}

		getchar();
	}

	return 0;
}