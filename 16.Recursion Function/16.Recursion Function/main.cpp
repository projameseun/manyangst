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

//�Ǻ���ġ ���� 
int Fibonacci(int _Num)
{
	int iPreNum = 1;
	int iPreNum2 = 1;

	int iResult = 0;

	if (_Num == 1 || _Num == 2)
	{
		return 1;
	}

	//_Num 3�̻� 
	for (int i = 0; i < _Num -2; ++i)
	{
		iResult = iPreNum + iPreNum2;

		//������ �߸��ϸ� �̻��� ���� ���� �ȴ�.
		/*iPreNum2 = iResult;
		iPreNum = iPreNum2;*/

		iPreNum = iPreNum2;
		iPreNum2 = iResult;
		
	}
	
	return iResult;
}

int Fibonacci_Re(int _Num)
{
	if (_Num == 1 || _Num == 2)
	{
		return 1;
	}

	return Fibonacci_Re(_Num - 1) + Fibonacci_Re(_Num - 2);


}

int FactorialTraill(int n , int acc)  // 
{
	if (n == 1)
	{
		return acc;
	}

	return FactorialTraill(n - 1, acc * n); //�Ϲ� ��Ϳ����� n * Fatorial(n - 1) �� �޸� ��ȯ������ �߰� ������ ���� ����
}

int FatorialTest(int n)
{
	return FactorialTraill(n, 1);
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


	iValue = 0;
	//�Ǻ���ġ�ؾߵ�
	//1 1 2 3 5 8 13 21 34 55 89....
	
	

	//�Ǻ���ġ�ؾߵ�
	iValue = Fibonacci(5);

	std::cout << "Fibonacci: " << iValue << std::endl;
	
	//������� �������Ѱ� https ://bozeury.tistory.com/entry/%EA%BC%AC%EB%A6%AC-%EC%9E%AC%EA%B7%80-%EC%B5%9C%EC%A0%81%ED%99%94Tail-Recursion

	iValue = Fibonacci_Re(5);

	std::cout << "Fibonacci_Re: " << iValue << std::endl;

	//�������
	iValue = FatorialTest(4);

	std::cout << "FatorialTraill: " << iValue << std::endl;

	return 0;
}