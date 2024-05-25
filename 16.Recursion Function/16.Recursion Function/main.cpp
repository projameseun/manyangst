#include <iostream>

/*
	���(Ruecursion)�Լ���
	�Լ� �ȿ��� �ڱ� �ڽ��� �Լ��� ȣ���ϴ� ���
	����� �Ҷ� ȣ�� ���ÿ� ����Ŭ���� �ϰԵǸ� �ٸ��ʵ� ���� ����
	
	�Լ��ȿ��� �ڱ� �Լ��� ��Ӻҷ�����(����Լ�) ������ �Ѱ�ġ�� �����ϰ� �Ǵµ�
	�̸� ���� ���� �÷ο��� �Ѵ�.
*/


int FactorialFor(int _Count)
{
	int iValue = 1;

	for (int i = 0; i < _Count - 1; ++i)
	{
		//iValue = iValue * (i + 2);
		iValue *= (i + 2);
	}

	//�̰� ����Լ� �´µ� �ɰ��� ������ ����� ���ÿ� ��� �޸𸮰��� �׿��� ���ÿ��� �÷ο찡 �����.
	//FactorialFor(4);

	return iValue;
}

//���丮�� ����Լ�
int Factorial_Re(int _Count)
{
	if (_Count == 1)
	{
		return 1;
	}

	return _Count * Factorial_Re(_Count - 1);
}


int main()
{
	//���丮�� for��
	
	int FacNum = 5;
	int iValue = 1;

	for (int i = 0; i < FacNum - 1; ++i)
	{
		//iValue = iValue * (i + 2);
		iValue *= (i + 2);
	}


	std::cout << "FactorialForMun :" << iValue << std::endl;

	//���丮�� for�� �Լ�
	
	iValue = FactorialFor(5);

	std::cout << "FactorialForMunFunction : " << iValue << std::endl;

	//���丮�� ����Լ�
	
	iValue = Factorial_Re(5);

	std::cout << "Factorial_ReFunction : " << iValue << std::endl;


	//�Ǻ���ġ�ؾߵ�
	
	//������� �������Ѱ� https ://bozeury.tistory.com/entry/%EA%BC%AC%EB%A6%AC-%EC%9E%AC%EA%B7%80-%EC%B5%9C%EC%A0%81%ED%99%94Tail-Recursion

	return 0;
}