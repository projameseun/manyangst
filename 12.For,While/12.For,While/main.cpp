#include <iostream>

void Clear()
{
	system("cls");
}

void Pause()
{
	system("pause");
}

int main()
{

	//system("mode con:cols=150 lines=30");
	/*
		�ݺ���(loop):���α׷� ������ �Ȱ��� ����� ���� Ƚ����ŭ �ݺ��Ͽ� �����ϵ��� �����ϴ� ��ɹ��̴�.
		�ܼ��ϰ� ����ϸ� ������ �ڵ带 �ݺ��ؼ� ���� ��ų�� Ȱ���ϴ� ����̴�.

		for��
		for(�ʱⰪ; ���ǽ�; ������)
		{

			�ڵ��;
		}�� ���·� �����ȴ�.

		1.�ʱⰪ�� for���� ���۵� �� 1���� ������ �ȴ�.
		2.���ǽ��� �Ź� �ݺ��� �� �� ���� üũ�ϰ� �ǰ� ���ǽ��� true�϶� �ڵ�� ���� �ڵ尡 ������ �ǰ� false�� �Ǹ� for���� ���� ������ �ȴ�.
		3.�������� �ڵ尡 1�� ���� �Ǹ� �������� ���� �ǰ� �� �� �Ŀ� ������ üũ�ȴ�.

		for�� �������
		�ʱⰪ -> ���ǽ� -> �ڵ���� -> ������ -> ���ǽ� -> �ڵ���� -> ������ -> ���ǽ� -> �ڵ���� ...false�϶� for�� ���� 

		�ݺ��� ����
		break�� ����ϰ� �Ǹ� �ݺ����� ���������� �ȴ�.
		continue�� ����ϸ� �ݺ����� ���������� ���ƿ��� �ȴ�.
	
	*/

	int iNumber = 1;
	int iTotal = 0;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << std::endl;
	}

	//���� ������ �����Ҷ�
	for(; iNumber <= 10;++iNumber)
	{
		iTotal += iNumber;
	}
	
	std::cout << "iTotal = " << iTotal << std::endl;

	iNumber = 0;
	//for���� ���ѷ����� ����� ���
	for (; ; )
	{
		iNumber++;
		
		if (iNumber == 100)
		{
			break;
		}
		

		std::cout << "iNumber = " <<iNumber<< std::endl;
	}

	
	//for���� �̿��Ͽ� ������2��
	for (int i = 1; i < 10; ++i)
	{
		std::cout << "2 * " << i << " = " << i * 2 << std::endl;
	}
	
	Clear();

	//������ 5���� �������� 
	for (int i = 1; i < 10; ++i)
	{
		std::cout << "5 * " << i << " = " << i * 5 << std::endl;
	}

	Clear();

	//���� for��
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << " i " << i << " j :" << j << std::endl;
		}
	}

	Clear();

	for (int i = 0; i < 10; ++i)
	{
		if (i == 8)
			continue;

		for (int j = 0; j < 10; ++j)
		{
			std::cout << " i " << i << "  j :" << j << std::endl;
		}
	}

	Clear();
	
	//������ 2~9 �ܱ��� ��������
	for (int i = 2; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			if (j == 1)
			{
				std::cout << i << "��: " << std::endl;
				//std::cout << i << " * " << j << " = " << i * j << "\t  ";
				
			}
			std::cout << i << " * " << j << " = " << i * j << std::endl;
			
		}

		//std::cout << std::endl;									
	}


	return 0;
}