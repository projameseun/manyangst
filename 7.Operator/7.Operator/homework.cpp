#include <iostream>


int main()
{
	//1.연산자를 사용하여서 값이 정확히 나올수 있게 출력해주세요
	std::cout << "100 + 20 = " << std::endl;
	std::cout << "100 - 20  = " << std::endl;
	std::cout << "100 * 20  = " << std::endl;
	std::cout << "100 / 20  = " <<  std::endl;
	std::cout << "100 % 20 = " << std::endl;


	//2.몇이나오는지 
	int iNumber = 0;

	iNumber = 100;

	iNumber += 100;
	++iNumber;
	++iNumber;
	//iNumber가 몇이 출력되는 써보세요

	//3 몇이나오는지 그리고 왜 그숫자가 나오는지 증명
	int a = 0;
	iNumber = 100;
	
	iNumber += a++;

	//4.모듈러스 연산자를 사용하면 짝수 홀수를 알수 있다 이유를 말해보세요 

	//5.제대로 연산될수 있게출력을 하시고 직접 주석으로 답을 적어주세요
	std::cout << "100 <= 200 && 200 == 200" << std::endl; 
	std::cout << "50 < 70 && 100 >= 50" << std::endl;

	std::cout << "50 < 100 || 200> 300" << std::endl;
	std::cout << "1000 < 5000 || 10 <30 " << std::endl;


	

}