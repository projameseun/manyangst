#include <iostream>

int main()
{
	/*
		�������迭:�迭�� �迭�� �����Ѱ��̴�.
		int iNumber[5][10];
		�� ���·� �����ȴ�.
		�� �迭���� 5 * 10�� �ؼ� 50���� �ǰ� 200����Ʈ�� �����Ѵ� .
	*/

	int iNumber[5][10];
	iNumber[0][5] = 10;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			//i �� j�ǰ��� �̿��ؼ� 0 ~ 49������ ���� ��������� �ۼ��ѰŴ�.
			iNumber[i][j] = i * 10 + j+1;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << iNumber[i][j] << std::endl;
		}
	}
	

	
	return 0;
}