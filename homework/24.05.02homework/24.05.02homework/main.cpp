#include <iostream>


namespace man // man이라는 네임스페이스를 만들었다!
{
	int iHP = 0;

	void Info() //void 와 info()가 머지..?
	{
		std::cout << "카멘 4관문중" << std::endl; // ""를 출력한다
		std::cout << "HP:" << iHP << std::endl; // HP를 출력한다.
	}

	void cout(char* nu) //  nu = 스킬
	{
		std::cout << nu << "로아콘]" << std::endl;
	}
}

int main()
{
char num1[25] = ""; // num1이라는 친구를 만듬

	man::Info(); //?
	std::cout << "mannyang1님이 떨어져 죽었습니다" << std::endl;
	std::cout << "헉" << std::endl;
	std::cin >> num1; //cin = input과 같은 역할
	man::cout(num1); //num1을 출력시킨다


	return 0;

}
