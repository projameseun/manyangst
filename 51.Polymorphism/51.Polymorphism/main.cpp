#include <iostream>

class CParent
{
public:
	virtual void virutalFunc() //�����Լ�
	{
		std::cout << "�θ� �����Լ�" << std::endl;
	}

	void OutPut()
	{
		std::cout << "�θ� ���" << std::endl;
	}

};

class CChild : public CParent
{
public:
	int m_Data = 300;

public:
	 void virutalFunc() override
	{
		std::cout << "�ڽ� �����Լ�" << std::endl;
	}
	void OutPut()
	{
		std::cout << "�ڽ� ���" << std::endl;
	}

	void OnlyChildFunc()
	{
		std::cout << "�ڽ� �Լ��� ���� ���" << std::endl;
	}

	
};

int main()
{
	CParent Parent;
	CChild Child;

	CParent* pParent = nullptr;
	//CChild* pChild = (CChild*)&Parent; �ٿ�ĳ���� ������ �ɼ� �ִ�.
	

	//pParent = &Parent;
	pParent = &Child;		//��ĳ����
	pParent->OutPut();		//�������ε� 
	pParent->virutalFunc();		//�����Լ�

	return 0;
}