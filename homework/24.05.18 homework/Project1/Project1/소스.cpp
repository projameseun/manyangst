#include <iostream>
#include <time.h>

int main()
{

	//최소공격력 최대 공격력
	//500 ~ 1000

	srand(static_cast<unsigned int>(time(NULL)));

	int iMin = 500;
	int iMax = 1000;
	int iAttack = 0;


	iAttack = rand() % (1000- 500 +1) + 500;
	
	//iAttack = rand() % 500 + 500;

	std::cout << "데미지 :" << iAttack << std::endl;
	std::cout << "최소데미지 :" << iMin << std::endl;
	std::cout << "최대데미지 :" << iMax << std::endl;
	
	
	//강화프로그램
	
	//std::cout << "전체 카드팩을 까시겠습니까?" << std::endl;
	// 취소 / 확인 해서 cin으로 확인을 적으면 확률이 작동하여 무슨 카드가 나오는지에 따라 if&switch문으로 코멘트가 나오게 만들어보기

	float fRand = rand() % 100 / 1.f;
	
	if (fRand < 0.5f)
	{
		std::cout << "전설 카드팩" << std::endl;
		std::cout << "확률 :" << fRand << "%" << std::endl;
	}
	else if (fRand < 9.5f)
	{
		std::cout << "영웅 카드팩" << std::endl;
		std::cout << "확률 :" << fRand << "%" << std::endl;
	}
	else if (fRand < 40.f)
	{
		std::cout << "희귀 카드팩" << std::endl;
		std::cout << "확률 :" << fRand << "%" << std::endl;
	}
	else if (fRand < 70.f)
	{
		std::cout << "고급 카드팩" << std::endl;
		std::cout << "확률 :" << fRand << "%" << std::endl;
	}
	else if (fRand < 100.f)
	{
		std::cout << "일반 카드팩" << std::endl;
		std::cout << "확률 :" << fRand << "%" << std::endl;
	}
	else
	{
		std::cout << "아이템 없음" << std::endl;
		std::cout << "확률 :" << fRand << "%" << std::endl;
	}
	int a = 0;



	return 0;
}