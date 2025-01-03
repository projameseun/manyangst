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
		std::cout << "Player 얕은복사" << std::endl;
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
		std::cout << "Player 소멸자 " << std::endl;
	}

	//function
public:
	void PlayerInfo()
	{
		std::cout << "아이디 : " << m_Name <<  std::endl;
		std::cout << "체력 : " << m_iHp<< std::endl;
		std::cout << "마력: " << m_iMp << std::endl;
		std::cout << "스피드: " << m_fSpeed<< std::endl;
		std::cout << "아이템 : " << m_Item->m_Name << std::endl;
		std::cout << "아이템번호 : " << m_Item->iCase<< std::endl;
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

	//복사생성자 
	CPlayer player("힐바드세여", 100, 100, 100, "하프", 1);		//캐릭터생성

	//player.PlayerInfo();
	

	//얕은복사 
	//포인터 주소만 복사해서 두객체가 동일한 공간을 참조
	//CPlayer player2 = player;



	//깊은복사
	CPlayer player2(player, true);

	player2.SetItemString("장검");

	player.PlayerInfo();
	std::cout << std::endl;
	player2.PlayerInfo();

//	system("cls");



	//댕글링포인터 
	//더이상 유효하지 않은 메모리 주소를 가리키는 포인터를 말한다.
	//댕글링 포인터 위험성
	//해제된 메모리를 참조하거나 수정하려면, 프로그램이 비정상적으로 종료되어서 메모리 손상을 발생시킨다.
	//댕글링 포인터는 런타임때 특정상황에만 발생할수 있어서 찾기가 매우어렵다.
	


	return 0;
}