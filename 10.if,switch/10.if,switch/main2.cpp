#include <iostream>
#include <string.h>

namespace TYPEA
{

	enum ACar
	{
		AUDI = 1,
		BENZ,
		PHORCSHE,
		BMW,
		HYUNDAI,
		SAMSUNG,
	};
}

namespace TYPEB
{
	enum BCar
	{
		TOYOTA = 1,
		BENZ,
		SAMSUNG,
		PHORCSHE,
	};

}


enum class JOB
{
	GUNSLINGER =1,
	BARD,
	BATTLEMASTER,
	BERSERKER,
};

enum class JOB2
{
	GUNSLINGER = 1,
	BARD,
	INFIGHTER,
	BATTLEMASTER,
};








int main()
{
	/*
		switch(����)
		{
			case ��(���):
			�ڵ�
			break; break�� ������ switch���� ������ 
			case ��(���):
			�ڵ�
			break break�� ������ switch���� ������ 
			....
			....
			....
			default: ���� case�� ��� üũ�ϰ� �� �Ѿ���ԵǸ� ���´�. else�� ���� ���� 
			break;




		}

		if�� switch�� �ſ� ����ϴ�
		��� ����ص� �����ϴ�.
		���� ���� �������� ����ϸ� �ӵ��� ���̰� �ִ� �׷��� ū ���̰� ����..
		���� �˻簡 2~3�϶��� if�� ������. ���ǰ˻簡 ������쿡�� switch�� ���� ������.
		�׷��� �̽ð��� �뷫 0.4�� ���� �ۿ� �ȵȴ�. ���ɿ� ������ ���� ������ �ʴ´�.
	
	*/

	int iRoomNum = 3;

	
	std::cout << "<������� ���� �������ּ���> " << std::endl;
	std::cout << "1.�ƿ�� 2.���� 3.������ 4.�񿥴����� 5.������" << std::endl;

	std::cin >> iRoomNum;

	system("cls");


	switch (iRoomNum)
	{
	case TYPEA::AUDI:
		std::cout << "�ƿ�� �Դϴ�" << std::endl;
		break;
	case TYPEB::BENZ:
		std::cout << "���� �Դϴ�" << std::endl;
		break;
	case TYPEA::PHORCSHE:
		std::cout << "������ �Դϴ�" << std::endl;
		break;
	case TYPEA::BMW:
		std::cout << "�񿥴����� �Դϴ�" << std::endl;
		break;
	case TYPEA::HYUNDAI:
		std::cout << "���� �Դϴ�" << std::endl;
		break;
	case TYPEA::SAMSUNG:
		std::cout << "�Ｚ �Դϴ�" << std::endl;
		break;
	default:
		std::cout << "�մ��� �������ϴ�" << std::endl;
		break;
	}

	//emum(������)
	//���ڿ� �̸��� �ο��ϴ� ����̴�.
	//�������� ������ ���ڿ� �̸��� �ٿ��ٶ� ����Ҽ� �ִ�.
	/*
		enum ���Ÿ� 
		{

		};
		enum�� ����
		���ڸ� ���ڷ� ǥ�� �Ҽ� �ִ�. ����Ʈ��� ���� �����Ǹ� ��������ʰ� dns�� ����ؼ� ���� ���� ����ϴ�.
		
		enum�� ������
		������ �̸�����(namespace)�� ������ ���� �ʴٴ°�
		enum�� ����ϴ� ���� �ߺ��Ǵ°� ������ �ȴ�. ������ ���ϰ� �Ǵµ� ����ڰ� ���ξ�,���̾ Ÿ���� �ٿ��� �̸��� �����Ҽ��� ������ 
		�װ��� ����ڰ� ������ �����̸��� �� �����ؼ� �����ϰ� �ȰŴ�.

		enum class(c++11)
		enum class�� ������ ������ : enum�� ������ �̸�����(namespcae)�� ���� ���� �ʴ´�.
		enum�� ������ ��� �ϴٺ��� �̸��� �ߺ��Ǵ°� �и��� ���´�.
		enum�� ��Ȯ�ϰ� �����ϱ� ���ؼ� enum class�� ���Եȴٰ� �Ѵ�.

	*/

	system("cls");

	int iJob = 0;
	int iAttack = 0, iDeffence = 0, iHP = 0, iMP =0;

	std::string sName = "test";
	

	std::cout << "<=========������ �������ּ���========>" << std::endl;
	std::cout << "1.�ǽ�����" << std::endl;
	std::cout << "2.�ٵ�" << std::endl;
	std::cout << "3.��Ʋ������" << std::endl;
	std::cout << "4.����Ŀ" << std::endl;
	std::cin >> iJob;

	system("cls");
	std::cout << "���̵� �����ּ���" << std::endl;
	std::cin >> sName;

	
	//switch �ڵ����� ���Ÿ����
	//switch�� �ڵ��ϼ��Ѵ� �״��� �������� �̳�Ŭ������ �ϳ� �Է��ϰ� ctrl + enter�� �ϸ� �ڵ����� ���������
	switch ((JOB)iJob)
	{
	case JOB::GUNSLINGER:
		iAttack = 70;
		iDeffence = 20;
		iHP = 500;
		iMP = 1000;
		break;
	case JOB::BARD:
		break;
	case JOB::BATTLEMASTER:
		break;
	case JOB::BERSERKER:
		break;
	default:
		std::cout << "������ �������ּ��� " << std::endl;
		break;
	}


	if (iJob == (int)JOB::GUNSLINGER)
	{
		std::cout << sName <<" ���谡�� �氩���ϴ� " << std::endl;
		std::cout << "�ǽ���� ���� �ϼ̽��ϴ� " << std::endl;
		std::cout << "���ݷ� : "<< iAttack << std::endl;
		std::cout << "���� : "  << iDeffence << std::endl;
		std::cout << "ü�� : " << iHP << std::endl;
		std::cout << "���� : " << iMP<< std::endl;
	}
	else
	{
		std::cout << "�ƹ��͵� �������� �ʾҽ��ϴ�" << std::endl;
	}

	return 0;
}