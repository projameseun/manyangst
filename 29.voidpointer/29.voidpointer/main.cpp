#include <iostream>

void Func()
{
	int iNum = 200;
	
	short* sPtr = nullptr;

	
}

struct MyStruct
{
	int a;
	int b;

public:
	void Func()
	{
		std::cout << "test" << std::endl;
	}
};

int main()
{
	/*
		void(��ȿ��)
		1.�Լ� ��ȯ �������� ���Ǵ� ��� �Լ��� ���� ��ȯ ���� �ʵ��� �����Ѵ�.
		2.void* �ٸ� �������� ĳ������ ���� �ʴ��� �������� �Ҽ�����.
		void*�� �ڷ����� �������� ���� Ư�������� � �ڷ����̵� ������ �����ϴ�.
		�׷��� �󸶸�ŭ�� ũ�⸦ �о�ߵ����� �˼��� ��� �������� �Ұ����ϴ�.
		���� �ּҿ����ڵ� �Ұ����ϴ�.
		
	*/

	int* ptr = nullptr;

	void* vPtr = nullptr;

	int a = 0;
	short b = 0;
	float f = 0.f;
	double d = 0.;

	

	vPtr = &a;
	vPtr = &b;
	vPtr = &f;
	vPtr = &d;

	//*vPtr = 300;
	//vPtr + 1 

	//std::cout << sizeof(vPtr) << std::endl;

	vPtr = &a;

	//���� ����ȯ�� ����ؼ� �ִ¹�
	*((int*)vPtr) = 100;

	std::cout << *((int*)vPtr) << std::endl;
	//��ó�� ���� ���� ����ȯ�� �ؼ� � �ڷ����� ũ�⸦ ���� �ִ��� ���� �־��༭ �˷��ְԵǸ�
	//�ش� �ּҿ� ���������� �� ��ŭ�� �����͸� �о���̱� ������ �������� �Ҽ� �ִ�.


	return 0;
}