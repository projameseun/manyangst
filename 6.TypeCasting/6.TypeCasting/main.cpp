#include <iostream>

int main()
{
	/*
		����ȯ(TypeCasting)
		�� ��ȯ�� �ڷ����� ��ȯ��Ű�°��̴�.
		5������ ������ �ִ�
		c-style cast
	*/

	//c-style cast

	int a = 0;
	float b = 5.f;

	a = (float)3.222f; //����� ����ȯ (����ڰ� ���������� Ÿ�Ժ����ϴ°�)

	a = static_cast<float>(2.3f);

	a = a + 5.555f; //�Ͻ��� ����ȯ(�ڵ����� ����ȯ)

	//�Ͻ��� ����ȯ�� Data�� �ս��� �߻��Ҽ� �ֱ⶧���� ������ �ɼ� �ִ�.
	//ũ�Ⱑ ū�뼭 �����ŷ� ������ �ϰ� �Ǹ� �������� �ս��� �ü��ִ�. �׷��� Ȯ���Ҷ� �� ����ϴ� ���� ����.

	
	
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	//Ÿ��ĳ��Ʈ ������ 
	//static_cast,const_cast,dynamic_cast,reinterpreat_cast

	//static_cast
	int iNumber = 0;

	char cNumer = 0;

	float fNumber = 0.f;

	iNumber = 100;

	cNumer = static_cast<char>(iNumber);  //int -> char

	fNumber= static_cast<float>(cNumer);  //char ->float

	std::cout << cNumer << std::endl;

	std::cout << fNumber << std::endl;
	
	//const_cast
	//������� �����Ҷ� ����Ѵ� �����ͳ� ����(���ݷ���)�� ���ؼ� �����

	const volatile int conValue = 100;
	const volatile int* ptr = &conValue;
	
	int* ptr2 = const_cast<int*>(ptr);
	
	*ptr2 = 50;

	
	std::cout << conValue << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << *ptr2<< std::endl;

	//dynamci_cast
	//Ŭ�������� ��Ӱ���� �Ǿ������� ��ĳ���� �����ϴ� Ÿ�԰˻縦 ���� �ʱ� ������ �����ϴ�.
	//�̷��� �����ϰ� ����ϱ����ؼ� dynamic_cast�̴�.
	//��ȯ�� �����ϸ� nullptr�� ��ȯ�Ѵ� .. �̰� �˷��� ���߿� ���,��ĳ����,�ٿ�ĳ������ ������ �ϼž� �˼� ����

	//reinterpreat_cast
	//���� �ٸ� ������ �Ǵ� ���۷����� ��ȯ�ϴµ� ����Ѵ�
	
	
	


	


	return 0;
}