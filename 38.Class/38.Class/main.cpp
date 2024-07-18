#include <iostream>



/*
	Ŭ����: c++���� ��ü ���� ���α׷����� �����ϱ� ���� ���Ǵ� �����̴�.
	����ü�� ������ ����� ������� ����� �Ǵµ� ����ü������ �����鸸 ��Ƶΰ� ���������
	Ŭ���������� �ʿ��� �Լ����� �����ΰ� ��� �Ҽ� �ִ�.
	c++������ ����ü������ Ŭ������ �����ϰ� �Լ��� ���� ����� �ϴ°��� �����ϰ� ����� ����(c++�����Ϸ�)

	Ŭ������ 4�����Ӽ�
	ĸ��ȭ : �����ִ� ���� Ȥ�� ��ɵ��� �ϳ��� �����ִ� ����� ���Ѵ�.
	
	����ȭ:Ŭ������ ���� Ȥ�� ��ɵ��� �ܺο� �����ϴ� ������ �����ϴ� ���̴�.
	
	Ŭ������ ����:�ش� Ŭ������ ������� �Լ� ���� ���Ѵ�.

	����������
	-public : Ŭ������ ���� Ȥ�� �ܺ� ���� ���� ����� �����ϴ�.
	-private: Ŭ������ ���δ� ����� �����ϳ� �ܺο����� ����� �Ұ����ϴ�.
	-protected : ��� ���� ��...

	��Ӽ�,������ ===> ����� ����...


	this �ڱ� �ڽ��� �޸��̴�.

*/

class CPlayer
{
	//�������
public:
	char	m_StrName[25];
	int		m_iAttack;
	int		m_Deffence;
	int*	m_pInt;

private:
	int		m_iHp;
	int		m_iMaxHp;

public:
	//��� �Լ�
	int GetHP()
	{
		return this->m_iHp;
	}
	void SetHP(int _hp)
	{
		this->m_iHp = _hp;
	}

public:
	//�����ڿ� �Ҹ��ڴ� Ŭ������ �̸��� ���� �Լ��̴�.
	//�� �Լ����� ��ȯ Ÿ���� ����.
	//���� ���� ,�Ҹ��ڸ� ������ �ʾҴٸ� default ������ default �Ҹ��ڰ� ���������.
	//����ڰ� ������ְ� �Ǹ� ������� �����ڿ� �Ҹ��ڸ� ����ϰ� �ȴ�.
	//������:��ü�� �����Ҷ� ȣ��Ǵ� �Լ��̴�.
	//�̷� Ư¡ ������ �ʱ�ȭ�� ����Ҷ� ȿ�����̴�.
	//�����ڴ� �����ε��� �����ϴ�.
	//�������� ���ڸ� Ȱ���ؼ� ���� �����ڸ� �����ε� �س��� ����ϴ� ���� �����ϴ�.

	 CPlayer()
	{
		std::cout << "CPlayer ������ ȣ��" << std::endl;

		m_pInt = new int;
		*m_pInt = 999;
	}
	 CPlayer(const char* _name)
	 {
		 std::cout << "CPlayer ������ " << _name << " ȣ�� " << std::endl;
	 }

	 CPlayer(const char* _name, int _att, int _def, int* _pint, int _hp, int _mxhp) : 
		 m_StrName("james"),
		 m_iAttack(_att),
		 m_Deffence(_def),
		 m_pInt(_pint),
		 m_iHp(_hp),
		 m_iMaxHp(_mxhp)
	 {

	 }
	 //CPlayer(const char* _name, int _att, int _def, int* _pint, int _hp, int _mxhp)
	 //{
		// strcpy_s(m_StrName, _name);
		// m_iAttack = _att;
		// m_Deffence = _def;
		// m_pInt = _pint;
		// m_iHp = _hp;
		// m_iMaxHp = _mxhp;
	 //}
	~CPlayer()
	{
		std::cout << "CPlayer �Ҹ��� ȣ�� " << std::endl;

		if (m_pInt != nullptr)
		{
			delete m_pInt;
			m_pInt = nullptr;
			
		}
	}


};

class CPoint
{
public:
	int x;
	int y;

public:
	CPoint()
	{
		x = 0;
		y = 0;
	}
	~CPoint()
	{

	}

	//������ �����ε�
	//�ڷ��� * ������ - �����ͺ��� ����
	//*�����ͺ��� -- ������
	//&���� --- ������ �ּҰ� ��ȯ
	//�ڷ��� & ������ --- ���۷��� ��������


	//���� ������
	 CPoint& operator = (const CPoint& _Other) 
	{
		x = _Other.x;
		y = _Other.y;

	
		return *this;
	}

	 CPoint& operator + (const CPoint& _Other)
	{
		CPoint result;
		result.x = x + _Other.x;
		result.y = y + _Other.y;

		return result;
	}

	 CPoint& operator + (int iNum) 
	{
		CPoint result;
		result.x = x +iNum;
		result.y = y +iNum;

	

		return result;
	}
};




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CPlayer player;
	CPlayer player2("James",10,10,nullptr,100,100);

	std::cout << player2.m_StrName << std::endl;
	std::cout << player2.m_iAttack<< std::endl;
	std::cout << player2.m_Deffence << std::endl;
	std::cout << player2.GetHP() << std::endl;

	player2.SetHP(1000);
	std::cout << player2.GetHP() << std::endl;
	
	
	//std::cout << *(player.m_pInt) << std::endl;

	CPoint pt1, pt2, pt3;

	pt2.x = 100;
	pt2.y = 100;

	pt1 = pt2;

	pt3 = pt1 + pt2;

	//pt3 = pt1 + 100;
	
	//���۷���
	{
		/*
			���� �������� ���� ���Ѵٸ�
			���۷����� ����� ���ÿ� �ʱ�ȭ�� �ݵ�� �ؾߵǰ� �ٸ� ������ ����ų�� ����.
			������ �����ʹ� �ٸ������� ����ų�� �ִ�.

			�����Ϸ� ����
			���۷����� �����ϰ� �������� �ݸ�, �����ʹ� �����ϰ� �����Ҽ� �־�.
			����� ����
			���۷����� �����ʹ� ���������γ� �������� ..���̰� �ִ�.
		*/
		
		int a = 100;
		int b = 200;
		
		//int* ptr = &a;
	
		//int* const ptr = &a;
		
		
		//*ptr = 200;


		//const int* const ptr = &a;
		const int& ref = a;
	
		//ref = 200;
		

	}


	int test = 0;


	
	return 0;
}