#include <iostream>
#include <vector>
#include "CArray.h"

class Test
{
private:
	Test()
	{

	}
	

};


int main()
{
	//Test ts;	//�Ұ��� �ϴ� Ŭ������ �����ڸ� ������ ȣ���ϰ� �Ǵµ�
				//�̰� private�� �߱� ������ �ܺο��� ������ �Ҽ� ���� ��Ȳ�� �ȴ�.
				//�׷��Ƿ� ������ ���Ѵ�
				//���߿� ������������ ���ӿ��� �����ϰ� ����ϴ� �̱��������� ����ϸ� �����ϴ�.
	
	




	CArray arr = {};

	

	arr.push_back(10); //�迭�� 10�� �ֱ�
	arr.push_back(20); //����
	arr.push_back(30);

	arr.resize(10);
	
	int iData = arr[1];
	
	arr[1] = 100;

	arr.OutPut();

	arr.push_back(40);
	arr.push_back(50);
	arr.push_back(60);
	arr.push_back(70);

	arr.OutPut();

	std::vector<int> test;

	test.push_back(10);
	test.push_back(20);
	test.push_back(30);
	test.push_back(40);


;
	return 0;
}