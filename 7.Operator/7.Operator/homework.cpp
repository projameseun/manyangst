#include <iostream>


int main()
{
	//1.�����ڸ� ����Ͽ��� ���� ��Ȯ�� ���ü� �ְ� ������ּ���
	std::cout << "100 + 20 = " << std::endl;
	std::cout << "100 - 20  = " << std::endl;
	std::cout << "100 * 20  = " << std::endl;
	std::cout << "100 / 20  = " <<  std::endl;
	std::cout << "100 % 20 = " << std::endl;


	//2.���̳������� 
	int iNumber = 0;

	iNumber = 100;

	iNumber += 100;
	++iNumber;
	++iNumber;
	//iNumber�� ���� ��µǴ� �Ẹ����

	//3 ���̳������� �׸��� �� �׼��ڰ� �������� ����
	int a = 0;
	iNumber = 100;
	
	iNumber += a++;

	//4.��ⷯ�� �����ڸ� ����ϸ� ¦�� Ȧ���� �˼� �ִ� ������ ���غ����� 

	//5.����� ����ɼ� �ְ������ �Ͻð� ���� �ּ����� ���� �����ּ���
	std::cout << "100 <= 200 && 200 == 200" << std::endl; 
	std::cout << "50 < 70 && 100 >= 50" << std::endl;

	std::cout << "50 < 100 || 200> 300" << std::endl;
	std::cout << "1000 < 5000 || 10 <30 " << std::endl;


	

}