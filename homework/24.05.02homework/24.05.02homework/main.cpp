#include <iostream>


namespace man // man�̶�� ���ӽ����̽��� �������!
{
	int iHP = 0;

	void Info() //void �� info()�� ����..?
	{
		std::cout << "ī�� 4������" << std::endl; // ""�� ����Ѵ�
		std::cout << "HP:" << iHP << std::endl; // HP�� ����Ѵ�.
	}

	void cout(char* nu) //  nu = ��ų
	{
		std::cout << nu << "�ξ���]" << std::endl;
	}
}

int main()
{
char num1[25] = ""; // num1�̶�� ģ���� ����

	man::Info(); //?
	std::cout << "mannyang1���� ������ �׾����ϴ�" << std::endl;
	std::cout << "��" << std::endl;
	std::cin >> num1; //cin = input�� ���� ����
	man::cout(num1); //num1�� ��½�Ų��


	return 0;

}
