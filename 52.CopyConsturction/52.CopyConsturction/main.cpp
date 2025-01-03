#include <iostream>
#include <string>

using namespace std;


class CItem
{
public:
	std::string m_Name;
	int iCase;

public:
	CItem() :
		iCase(0)
	{
		
	}
	CItem(const std::string& _itemName, int _case) :
		m_Name(_itemName) , iCase(_case)
	{
		
	}
	
	
};

class CPlayer
{
private:
	std::string m_Name;
	int m_iHp;
	int m_iMp;
	float m_fSpeed;
	CItem* m_Item;

	//constructor
public:
	CPlayer(const std::string& _name, int _hp, int _mp, float _speed, const std::string& _itemName, int _case) :
		m_Name(_name), m_iHp(_hp), m_iMp(_mp), m_fSpeed(_speed)
	{
		m_Item = new CItem(_itemName, _case);
	}
	//Shallow copy
	CPlayer(const CPlayer& _player) :
		m_Name(_player.m_Name), m_iHp(_player.m_iHp), m_iMp(_player.m_iMp), m_fSpeed(_player.m_fSpeed),m_Item(_player.m_Item)
	{
		std::cout << "Player ��������" << std::endl;
	}
	//DeepCopy
	CPlayer(const CPlayer& _player , bool _copy) :
		m_Name(_player.m_Name), m_iHp(_player.m_iHp), m_iMp(_player.m_iMp), m_fSpeed(_player.m_fSpeed)
	
	{
		if (_copy)
		{
			m_Item = new CItem(*_player.m_Item);
		}
		else
		{
			m_Item = _player.m_Item;
		}
	}
	//desconstructor
	~CPlayer()
	{
		
		delete m_Item;
		std::cout << "Player �Ҹ��� " << std::endl;
	}

	//function
public:
	void PlayerInfo()
	{
		std::cout << "���̵� : " << m_Name <<  std::endl;
		std::cout << "ü�� : " << m_iHp<< std::endl;
		std::cout << "����: " << m_iMp << std::endl;
		std::cout << "���ǵ�: " << m_fSpeed<< std::endl;
		std::cout << "������ : " << m_Item->m_Name << std::endl;
		std::cout << "�����۹�ȣ : " << m_Item->iCase<< std::endl;
	}

	void SetString(std::string _str)
	{
		m_Name = _str;
	}

	void SetItemString(string _str)
	{
		m_Item->m_Name = _str;
	}

	void Delete(CItem* _item)
	{
		delete _item;
	}

	CItem* GetItem() const
	{
		return m_Item;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//��������� 
	CPlayer player("���ٵ弼��", 100, 100, 100, "����", 1);		//ĳ���ͻ���

	//player.PlayerInfo();
	

	//�������� 
	//������ �ּҸ� �����ؼ� �ΰ�ü�� ������ ������ ����
	//CPlayer player2 = player;



	//��������
	CPlayer player2(player, true);

	player2.SetItemString("���");

	player.PlayerInfo();
	std::cout << std::endl;
	player2.PlayerInfo();

//	system("cls");



	//��۸������� 
	//���̻� ��ȿ���� ���� �޸� �ּҸ� ����Ű�� �����͸� ���Ѵ�.
	//��۸� ������ ���輺
	//������ �޸𸮸� �����ϰų� �����Ϸ���, ���α׷��� ������������ ����Ǿ �޸� �ջ��� �߻���Ų��.
	//��۸� �����ʹ� ��Ÿ�Ӷ� Ư����Ȳ���� �߻��Ҽ� �־ ã�Ⱑ �ſ��ƴ�.
	


	return 0;
}