#include <iostream>

int main()
{
	/*
		���ǹ�:if , switch
		���ǹ��̶�? � Ư�� ���ǽ��� �ο��ϰ� �ش� ������ �����ϸ� ������ ������ �����ϴ� ����
		if��
		if(���ǽ�)
		{

		}�ڵ��

		���ǽ��� true�̸� �ڵ���� ������ �ǰ�, false�� if ���ǹ��� ������ �ȴ�.

	*/

	if (true)
	{
		std::cout << "���� �Դϴ�" << std::endl;
	}
	if (false)
	{
		std::cout << "���� �Դϴ�" << std::endl;
	}

	/*
		else:if���� ���� ����Ҽ� �ִ�.
		if�� 1���� else�� �� �� �ִ�.
		else�� ���������� ����� �Ұ����ϴ�.
	*/

	int iNumber = 300;

	if (iNumber == 100)
	{
		std::cout << "iNumber = " << iNumber << std::endl;
	}
	else
	{
		std::cout << "iNumber�� 100 �̾ƴմϴ� " << std::endl;
	}

	/*
		else if: if�� �Ʒ��ü� �ִ�. else�� �ٸ��� �������� ����� �ִ�.
		else if�� ���������� ����� �Ұ��� �ϴ�.
	*/

	int iEchidnaHP = 100000;

	int iDamage = 99000;
	;

	iEchidnaHP -= iDamage;

	if (iEchidnaHP <= 100000 && iEchidnaHP > 80000)
	{
		std::cout << "1��° �̺�Ʈ �߻�" << std::endl;
	}
	else if (iEchidnaHP <= 80000 && iEchidnaHP > 50000)
	{
		std::cout << "2��° �̺�Ʈ �߻�" << std::endl;
	}
	else if (iEchidnaHP <= 50000 && iEchidnaHP > 1300)
	{
		std::cout << "3��° �̺�Ʈ �߻�" << std::endl;
	}
	else if (iEchidnaHP <= 1300 && iEchidnaHP > 200)
	{
		std::cout << "4��° �̺�Ʈ �߻�" << std::endl;
	}
	else
	{
		std::cout << "5��° �̺�Ʈ �߻�" << std::endl;
	}

	//�л� ��� ���α׷�
	
	int iKOR = 0;
	int iENG = 0;
	int iMATH = 0;
	int iTOTAL = 0;


	float fAVG = 0.f;
	
	//ȭ���� �����ִ� �Լ� windows.h
	system("cls");

	std::cout << "�������� : ";
	std::cin >> iKOR;
	system("cls");
	std::cout << "�������� : ";
	std::cin >> iENG;
	system("cls");
	std::cout << "�������� : ";
	std::cin >> iMATH;
	system("cls");

	std::cout << "���� ���� :" << iKOR << std::endl;
	std::cout << "���� ���� :" << iENG << std::endl;
	std::cout << "���� ���� :" << iMATH << std::endl;
	
	iTOTAL = iKOR + iENG + iMATH;

	fAVG = iTOTAL / 3.f;

	std::cout << "��� ���� : " << static_cast<int>(fAVG) << "�Դϴ�" << std::endl;

	if (fAVG >= 90.f)
	{
		std::cout << "���� �մϴ� A�Դϴ�" << std::endl;
	}
	else if (fAVG >= 80.f && fAVG < 90.f)
	{
		std::cout << "���� �մϴ� B�Դϴ�" << std::endl;
	}
	else if (fAVG >= 70.f && fAVG < 80.f)
	{
		std::cout << "���� �մϴ� C�Դϴ�" << std::endl;
	}
	else
	{
		std::cout << "D�Դϴ� �й� �ϼ���!" << std::endl;
	}
 

	

	return 0;
}