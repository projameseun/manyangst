#include <iostream>

class CParent
{
private:
	int m_i;	//�������
	double m_d;
	//short m_c[8];
protected:
	int m_j;

public:
	void Func()	//����Լ�
	{
		m_i = 10;
	}
	void Func2()	//����Լ�
	{
		m_i = 10;
	}

	void Func3()	//����Լ�
	{
		m_i = 10;
	}

	void Func4()	//����Լ�
	{
		m_i = 10;
	}
	void Func5()	//����Լ�
	{
		m_i = 10;
	}


	
};

class CChild : public CParent
{
public:
	int m_k;
	float m_f;



};

class Test
{

};

int main()
{
	//��� 
	//Ŭ�������� �θ�� �ڽ��� ���踦 ���� �����ټ� �ִ� ����̴�.
	//AŬ���� BŬ������ ������ B�� A�� ��ӹް� �ִٸ�
	//A�� �θ�Ŭ����(�⺻Ŭ����) B�� �ڽ�Ŭ����(�Ļ�Ŭ����)��� �θ���.
	//B�� ��ӹް� A�� ����Լ�,��������� �����޾� ����Ҽ� �ִ�.
	//�̶� A�� ,pirvate�� �Ǿ� �ִٸ� ���迡���� ���� �Ұ���

	CParent parent;		//��ü

	//parent.m_i = 10;

	CChild child;

	size_t size = sizeof(CParent);

	
	//�����ð��� ���������

	return 0;
}