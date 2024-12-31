#include <iostream>
#include <vector>

class GameEngine
{
public:
	virtual void render() = 0;
	virtual void update() = 0;
	 virtual  ~GameEngine()  
	 {
		 std::cout << "GameEngine Destructor" << std::endl;
	 };
};

class player : public GameEngine
{
public:
	int* data = new (int[100]);

public:
	void render() override
	{
		std::cout << "Render Player" << std::endl;
	}
	void update() override
	{
		std::cout << "Update Player" << std::endl;
	}
	~player()
	{
		delete[] data;
		std::cout << "Player Destructor" << std::endl;
	}

};

class Monster : public GameEngine
{


public:
	void render() override
	{
		std::cout << "Render Monster" << std::endl;
	}
	void update() override
	{
		std::cout << "Update Monster" << std::endl;
	}


};


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	// ���������� ����ϴ� ����� �θ�Ŭ������ �����Լ��Ҹ��ڸ� ��������ߵȴ�.
	//�׷��� �޸𸮴��� ������ �Ҽ� �ִ�.
	//���� ���ε�

	GameEngine* pGameEngine = new player();


	Monster* pMonster = dynamic_cast<Monster*>(pGameEngine);


	if (pMonster != nullptr)
	{
		pMonster->render();
	}
	else
	{

	}

	

	pGameEngine->render();

	delete pGameEngine;

	return 0;
}